#include "Logger.h"
#include <filesystem>
#include  <iostream>


Logger::Logger(const std::string& fileName) {
    logFile.open("../" + fileName, std::ios::app);
    if (!logFile.is_open()) {
        throw std::runtime_error("Eroare la deschiderea fisierului de log.");
    } else {
        std::cout << "Fisierul " << fileName << " a fost deschis cu succes.\n";
    }
}

Logger *Logger::getInstance(const std::string &fileName) {
    static Logger instance(fileName);
    return &instance;
}


void Logger::log(const std::string& message) {
    if (logFile.is_open()) {
        logFile << message << std::endl;
        logFile.flush();
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}
