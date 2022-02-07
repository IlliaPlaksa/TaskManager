//
// Created by Illia Plaksa on 25.01.2022.
//

#include "controller/RemoteController.h"
#include "cli/include/StepMachine.h"

#include "Logging.h"

#include <boost/program_options.hpp>
namespace po = boost::program_options;

std::string CreateAddress(const std::string& host, const std::string& port)
{
    return host + ":" + port;
}

int main(int argc, char** argv)
{
    logging::init("client.log",boost::log::trivial::severity_level::info);

    std::string host; // default address of server
    std::string port;

    auto log_file_name = std::string{"client.log"};
    auto severity_level = boost::log::trivial::severity_level{};
    std::string verbosity_str;
try
   {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce help message")

            ("verbosity",
             po::value<std::string>(&verbosity_str)->default_value("info"),
           "sets log verbosity: debug, info, warn, error, fatal")
            ("host",
             po::value<std::string>(&host)->default_value("localhost"),
             "sets server address")

            ("port",
             po::value<std::string>(&port)->default_value("50051"),
             "sets port for sending messages");

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help"))
        {
            std::cout << desc << "\n";
            return 1;
        }

        severity_level = logging::CreateSeverityLevelFrom(verbosity_str);

        std::cout << "Log verbosity set to " << boost::log::trivial::to_string(severity_level) << ".\n";
        std::cout << "Server address was set to " << host << ".\n";
        std::cout << "Port was set to " << port << ".\n";

    }
    catch (std::exception& e)
    {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    }

    logging::init(log_file_name, severity_level);

    auto channel_address = CreateAddress(host, port);

    auto channel = grpc::CreateChannel(
        channel_address, grpc::InsecureChannelCredentials()
    );
    auto stub = service::RequestHandler::NewStub(channel);

    auto controller = std::make_shared<RemoteController>(std::move(stub));

    auto console_manipulator = std::make_shared<ConsoleManipulator>(std::cout, std::cin);
    auto step_factory = std::shared_ptr<StepFactory>{new StepFactory{console_manipulator}};

    auto view = std::shared_ptr<View>{new StepMachine{step_factory, controller}};

    BOOST_LOG_TRIVIAL(info) << "Client started with channel at " << channel_address;

    view->Run();

    BOOST_LOG_TRIVIAL(info) << "Client shut down";
    return 0;
}