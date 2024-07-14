/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** Operand
*/

#include "../include/Operand.hpp"
#include "../include/Factory.hpp"
#include "../include/Error.hpp"

template<typename T>
IOperand* AOperand<T>::operator+(const IOperand& rhs) const
{
    T leftValue = std::stod(this->toString());
    T rightValue = std::stod(rhs.toString());

    if (rightValue == 0) {
        throw DivisionByZeroError();
    }

    T result = leftValue + rightValue;
    return Factory::createOperand(this->getType(), std::to_string(result));
}

template<typename T>
IOperand* AOperand<T>::operator-(const IOperand& rhs) const
{
    T leftValue = std::stod(this->toString());
    T rightValue = std::stod(rhs.toString());

    if (rightValue == 0) {
        throw DivisionByZeroError();
    }

    T result = leftValue - rightValue;
    return Factory::createOperand(this->getType(), std::to_string(result));
}
template<typename T>
IOperand* AOperand<T>::operator*(const IOperand& rhs) const
{
    T leftValue = std::stod(this->toString());
    T rightValue = std::stod(rhs.toString());

    if (rightValue == 0) {
        throw DivisionByZeroError();
    }

    T result = leftValue * rightValue;
    return Factory::createOperand(this->getType(), std::to_string(result));
}

template<typename T>
IOperand* AOperand<T>::operator/(const IOperand& rhs) const
{
    T leftValue = std::stod(this->toString());
    T rightValue = std::stod(rhs.toString());

    if (rightValue == 0) {
        throw DivisionByZeroError();
    }

    T result = leftValue / rightValue;
    return Factory::createOperand(this->getType(), std::to_string(result));
}

template<typename T>
IOperand* AOperand<T>::operator%(const IOperand& rhs) const
{
    T lval = std::stod(this->toString());
    T cval = std::stod(rhs.toString());

    if (cval == 0)
        throw DivisionByZeroError();

    return Factory::createOperand(this->getType(), std::to_string(static_cast<int>(lval) % static_cast<int>(cval)));
}

