/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** Int8
*/

#include "../include/Int8.hpp"
#include "../include/Factory.hpp"
#include "../include/Error.hpp"
#include "../include/Operand.hpp"

IOperand* Int8::operator+(const IOperand& rhs) const {
    int lCValue = std::stoi(this->toString());
    int rCValue = std::stoi(rhs.toString());

    int resultValue = lCValue + rCValue;
    std::string resultStr = std::to_string(resultValue);

    return Factory::createOperand(getType(), resultStr);
}

IOperand* Int8::operator-(const IOperand& rhs) const {
    int lCValue = std::stoi(this->toString());
    int rCValue = std::stoi(rhs.toString());

    int resultValue = lCValue - rCValue;
    std::string resultStr = std::to_string(resultValue);

    return Factory::createOperand(getType(), resultStr);
}

IOperand* Int8::operator*(const IOperand& rhs) const {
    int lCValue = std::stoi(this->toString());
    int rCValue = std::stoi(rhs.toString());

    int resultValue = lCValue * rCValue;
    std::string resultStr = std::to_string(resultValue);

    return Factory::createOperand(getType(), resultStr);
}

IOperand* Int8::operator/(const IOperand& rhs) const {
    int lCValue = std::stoi(this->toString());
    int rCValue = std::stoi(rhs.toString());

    if (rCValue == 0)
        throw DivisionByZeroError();

    int resultValue = lCValue / rCValue;
    std::string resultStr = std::to_string(resultValue);

    return Factory::createOperand(getType(), resultStr);
}

IOperand* Int8::operator%(const IOperand& rhs) const {
    int lCValue = std::stoi(this->toString());
    int rCValue = std::stoi(rhs.toString());

    if (rCValue == 0)
        throw DivisionByZeroError();

    int resultValue = lCValue % rCValue;
    std::string resultStr = std::to_string(resultValue);

    return Factory::createOperand(getType(), resultStr);
}
