/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** Double
*/

#include "../include/Double.hpp"
#include "../include/Factory.hpp"
#include <math.h>
#include <sstream>

Double::Double(const std::string &value) : AOperand(value)
{
}

IOperand*
Double::operator%(const IOperand& rhs) const {
    float leftValue = std::stof(this->toString());
    float rightValue = std::stof(rhs.toString());

    if (rightValue == 0.0f)
        throw DivisionByZeroError();

    float result = std::fmod(leftValue, rightValue);
    return Factory::createOperand(this->getType(), std::to_string(result));
}
