//
// Created by Illia Plaksa on 02.02.2022.
//

#include "Logging.h"

void logging::init(const boost::log::trivial::severity_level& level)
{
    boost::log::register_simple_formatter_factory<boost::log::trivial::severity_level, char>("Severity");

    boost::log::add_file_log
        (
            boost::log::keywords::file_name = "sample.log",
            boost::log::keywords::auto_flush = true,
            boost::log::keywords::format = "[%TimeStamp%] [%ThreadID%] [%Severity%] [%ProcessID%] %Message%"
        );

    boost::log::core::get()->set_filter
        (
            boost::log::trivial::severity >= level
        );

    boost::log::add_common_attributes();
}