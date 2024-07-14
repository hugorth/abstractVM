/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** Float
*/

#include "../include/Float.hpp"
#include "../include/Factory.hpp"
#include <math.h>
#include <sstream>

Float::Float(const std::string &value) : AOperand(value)
{
}

IOperand*
Float::operator%(const IOperand& rhs) const {
    float leftValue = std::stof(this->toString());
    float rightValue = std::stof(rhs.toString());

    if (rightValue == 0.0f)
        throw DivisionByZeroError();

    float result = std::fmod(leftValue, rightValue);
    return Factory::createOperand(this->getType(), std::to_string(result));
}
