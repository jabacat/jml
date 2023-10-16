/**
 * This is the header for the logger.
 * Very little of the logger will be exposed through the API.
 * Author: Jake Roggenbuck
 * 10-08-23
 */

#pragma once

#include <iostream>
#include <jml/jmldefs.h>

namespace jml {

enum JML_LOCAL Severity { DEBUG, INFO, WARN, ERR, FATAL };

static const std::string severity_text[] = {"DEBUG", "INFO", "WARN", "ERR",
                                            "FATAL"};

const JML_LOCAL std::string get_severity_text(enum Severity s);

class JML_LOCAL Log {
  private:
    enum Severity severity;
    std::string message;

  public:
    Log& operator<<(enum Severity s);
    Log& operator<<(std::string m);
    Log& operator<<(int m);

    enum Severity get_severity();
    std::string get_message();

    Log(enum Severity s = WARN);
    Log(enum Severity s, std::string m);
};

class JML_LOCAL Logger {
  private:
    enum Severity global_log_level;
    static Logger *_instance;

    Logger(enum Severity s = WARN);

  public:
    static Logger *Instance(enum Severity s = WARN);

    std::string render(Log l);

    // Add log to the logs vector and display it if it's the correct logging
    // level or more severe
    void log(enum Severity s, std::string m);
    void log(Log l);

    void set_global_log_level(enum Severity s);
};

} // namespace jml
