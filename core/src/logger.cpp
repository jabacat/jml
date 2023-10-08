#include <iostream>
#include <jml/logger.hpp>

namespace jml {

const std::string get_severity_text(enum Severity s) {
    return severity_text[(int)s];
}

Log::Log(enum Severity s, std::string m) : severity(s), message(m) {}

std::string Log::render() {
    std::string text = get_severity_text(this->severity);
    std::string message = "[" + text + "]: " + this->message;
    return message;
}

void Log::print() {
    // Check what file to output the log to
    switch (this->severity) {
    case DEBUG:
    case INFO:
        std::cout << this->render();
        return;
    case WARN:
    case ERR:
    case FATAL:
        std::cerr << this->render();
        return;
    }
}

const enum Severity Log::get_severity() { return this->severity; }

Logger::Logger() { this->global_log_level = WARN; }

Logger::Logger(enum Severity s) { this->global_log_level = s; }

void Logger::log(enum Severity s, std::string m) {
    Log l = Log(s, m);
    this->logs.push_back(l);

    // Print log if log level is low enough for l
    if (this->global_log_level <= l.get_severity()) {
        l.print();
    }
}

void Logger::set_global_log_level(enum Severity s) {
    this->global_log_level = s;
}

} // namespace jml
