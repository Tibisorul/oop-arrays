#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger {
private:
   Logger(const std::string &fileName);
    std::ofstream logFile;

public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger* getInstance(const std::string &fileName = "log.txt");

    void log(const std::string& message);

    ~Logger();


};

#endif //LOGGER_H
