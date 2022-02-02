//
// Created by Illia Plaksa on 02.02.2022.
//

#ifndef TASKMANAGER_LOGGING_LOGGING_H_
#define TASKMANAGER_LOGGING_LOGGING_H_

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace logging
{
    void init(const boost::log::trivial::severity_level& level); // Initializes logging with specified log level
}

#endif //TASKMANAGER_LOGGING_LOGGING_H_
