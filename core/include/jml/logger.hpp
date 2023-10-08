/**
 * This is the header for the logger.
 * Very little of the logger will be exposed through the API.
 * Author: Jake Roggenbuck
 * 10-08-23
 */

#pragma once

#include <iostream>
#include <vector>

namespace jml {

enum Severity { DEBUG, INFO, WARN, ERR, FATAL };

static const std::string severity_text[] = {"DEBUG", "INFO", "WARN", "ERR",
                                            "FATAl"};

const std::string get_severity_text(enum Severity s);

class Log {
  private:
    const enum Severity severity;
    const std::string message;

  public:
    Log(enum Severity s, std::string m);
    // Render the log message to a string
    std::string render();
    // Render and then print the message to stderr for WARN and FATAL
    // and to stdout for DEBUG and INFO
    void print();
    const enum Severity get_severity();
};

class Logger {
  private:
    std::vector<Log> logs;
    enum Severity global_log_level;

  public:
    Logger();
    Logger(enum Severity global_log_level);
    // Add log to the logs vector and display it if it's the correct logging
    // level or more severe
    void log(enum Severity s, std::string m);
    void set_global_log_level(enum Severity s);
};

} // namespace jml
