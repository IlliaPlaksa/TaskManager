//
// Created by Illia Plaksa on 02.02.2022.
//

#include "Logging.h"

void logging::init(const std::string& file_name, const boost::log::trivial::severity_level& level)
{
    boost::log::register_simple_formatter_factory<boost::log::trivial::severity_level, char>("Severity");

    boost::log::add_file_log
        (
            boost::log::keywords::file_name = file_name,
            boost::log::keywords::auto_flush = true,
            boost::log::keywords::open_mode = std::ios_base::app,
            boost::log::keywords::format =
                "[%TimeStamp%] Thread:[%ThreadID%] Verbosity:[%Severity%] PID:[%ProcessID%] Message: %Message%"
        );

    boost::log::core::get()->set_filter
        (
            boost::log::trivial::severity >= level
        );

    boost::log::add_common_attributes();
}

boost::log::trivial::severity_level logging::CreateSeverityLevelFrom(const std::string& level)
{
    auto result = boost::log::trivial::severity_level{};

    if (!boost::log::trivial::from_string(level.c_str(), level.size(), result))
        result = boost::log::trivial::severity_level::info;

    return result;
}