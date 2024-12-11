#ifndef CUSTOMEXCEPTIONS_H
#define CUSTOMEXCEPTIONS_H

#include <exception>
#include <string>

class CustomException : public std::exception {
protected:
    std::string message;

public:
    explicit CustomException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidSizeException : public CustomException {
public:
    explicit InvalidSizeException(const std::string& msg = "Invalid size for array.")
        : CustomException(msg) {}
};

class InvalidIndexException : public CustomException {
public:
    explicit InvalidIndexException(const std::string& msg = "The index is out of bounds.")
        : CustomException(msg) {}
};

class EmptyArrayException : public CustomException {
public:
    explicit EmptyArrayException(const std::string& msg = "The operation cannot be performed on an empty array.")
        : CustomException(msg) {}
};

class InvalidOperationException : public CustomException {
public:
    explicit InvalidOperationException(const std::string& msg = "Operation cannot be performed.")
        : CustomException(msg) {}
};


#endif
