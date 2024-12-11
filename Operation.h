#ifndef OPERATION_H
#define OPERATION_H

#include <string>
#include <iostream>
#include <memory>

class Operation {
protected:
    std::string description; // Variabila membru

public:
    explicit Operation(const std::string& desc) : description(desc) {}
    virtual ~Operation() = default;

    virtual std::string getDescription() const { // Declarația corectă
        return description;
    }

    virtual void execute() const = 0; // Funcție virtuală pură
    virtual std::unique_ptr<Operation> clone() const = 0; // Funcție virtuală pură
};


#endif //OPERATION_H
