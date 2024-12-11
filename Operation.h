#ifndef OPERATION_H
#define OPERATION_H

#include <string>
#include <iostream>
#include <memory>

class Operation {
protected:
    std::string description;

public:
    explicit Operation(const std::string& desc) : description(desc) {}
    virtual ~Operation() = default;

    virtual std::string getDescription() const {
        return description;
    }

    virtual void execute() const = 0;
    virtual std::unique_ptr<Operation> clone() const = 0;
};


#endif
