//
// Created by Illia Plaksa on 25.01.2022.
//

#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

#include "model/TaskManager.h"
#include "server/RequestHandlerImpl.h"

#include "Logging.h"

#include <boost/program_options.hpp>
namespace po = boost::program_options;

int main(int argc, char** argv)
{
    auto log_file_name = std::string{"server.log"};
    auto severity_level = boost::log::trivial::severity_level{};

    std::string verbosity_str;

    try
    {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce help message")

            ("verbosity",
             po::value<std::string>(&verbosity_str)->default_value("info"),
             "sets log verbosity: debug, info, warn, error, fatal");

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
    }
    catch (std::exception& e)
    {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    }

    logging::init(log_file_name, severity_level);

    std::string server_address("0.0.0.0:50051");
    auto model = std::unique_ptr<Model>(new TaskManager{std::make_unique<IdGenerator>()});

    auto service = RequestHandlerImpl{std::move(model)};

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    BOOST_LOG_TRIVIAL(info) << "Server started listening on " << server_address;

    server->Wait();

    BOOST_LOG_TRIVIAL(info) << "Server shut down";

    return 0;
}