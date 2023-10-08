/**
 * This is the header for the logger.
 * Very little of the logger will be exposed through the API.
 * Author: Jake Roggenbuck
 * 10-08-23
 */

#pragma once

#include <iostream>

namespace jml {

enum Severity { DEBUG, INFO, WARN, ERR, FATAL };

static const std::string severity_text[] = {"DEBUG", "INFO", "WARN", "ERR",
                                            "FATAl"};

const std::string get_severity_text(enum Severity s);

class Log {
  private:
    enum Severity severity;
    std::string message;

  public:
    Log &operator<<(enum Severity s);
    Log &operator<<(std::string m);
    Log &operator<<(int m);

    enum Severity get_severity();
    std::string get_message();

    Log();
    Log(enum Severity s);
    Log(enum Severity s, std::string m);
};

class Logger {
  private:
    enum Severity global_log_level;
    static Logger *_instance;

    Logger();
    Logger(enum Severity s);

  public:
    static Logger *Instance();
    static Logger *Instance(enum Severity s);

    std::string render(Log l);

    // Add log to the logs vector and display it if it's the correct logging
    // level or more severe
    void log(enum Severity s, std::string m);
    void log(Log l);

    void set_global_log_level(enum Severity s);
};

} // namespace jml
