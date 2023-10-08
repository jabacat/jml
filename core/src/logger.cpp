#include <internal/logger.hpp>
#include <iostream>
#include <string>

namespace jml {

const std::string get_severity_text(enum Severity s) {
    return severity_text[(int)s];
}

enum Severity Log::get_severity() { return this->severity; }

std::string Log::get_message() { return this->message; }

Log &Log::operator<<(enum Severity s) {
    this->severity = s;
    return *this;
}

Log &Log::operator<<(std::string m) {
    this->message += m;
    return *this;
}

Log &Log::operator<<(int m) {
    this->message += std::to_string(m);
    return *this;
}

Log::Log() {}
Log::Log(enum Severity s) : severity(s) {}
Log::Log(enum Severity s, std::string m) : severity(s), message(m) {}

Logger *Logger::_instance = 0;
Logger *Logger::Instance() {
    if (_instance == 0) {
        _instance = new Logger;
    }
    return _instance;
}

Logger *Logger::Instance(enum Severity s) {
    if (_instance == 0) {
        _instance = new Logger(s);
    }
    return _instance;
}

Logger::Logger() { this->global_log_level = WARN; }

Logger::Logger(enum Severity s) { this->global_log_level = s; }

std::string Logger::render(Log l) {
    return "[" + get_severity_text(l.get_severity()) + "]: " + l.get_message();
}

void Logger::log(enum Severity s, std::string m) {
    Log l = Log(s, m);
    this->log(l);
}

void Logger::log(Log l) {
    // Print log if log level is low enough for l
    if (l.get_severity() >= this->global_log_level) {
        switch (l.get_severity()) {
        case DEBUG:
        case INFO:
            std::cout << this->render(l);
            return;
        case WARN:
        case ERR:
        case FATAL:
            std::cerr << this->render(l);
            return;
        }
    }
}

void Logger::set_global_log_level(enum Severity s) {
    this->global_log_level = s;
}

} // namespace jml
