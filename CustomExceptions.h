#ifndef CUSTOMEXCEPTIONS_H
#define CUSTOMEXCEPTIONS_H

#include <exception>
#include <string>

// Clasa de bază pentru excepții personalizate
class CustomException : public std::exception {
protected:
    std::string message;

public:
    explicit CustomException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Excepție pentru dimensiune invalidă
class InvalidSizeException : public CustomException {
public:
    explicit InvalidSizeException(const std::string& msg = "Dimensiune invalidă pentru array.")
        : CustomException(msg) {}
};

// Excepție pentru index invalid
class InvalidIndexException : public CustomException {
public:
    explicit InvalidIndexException(const std::string& msg = "Indexul este în afara limitelor.")
        : CustomException(msg) {}
};

// Excepție pentru operații pe array gol
class EmptyArrayException : public CustomException {
public:
    explicit EmptyArrayException(const std::string& msg = "Operația nu poate fi efectuată pe un array gol.")
        : CustomException(msg) {}
};

#endif // CUSTOMEXCEPTIONS_H
