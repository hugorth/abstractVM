/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** IOperand
*/

#ifndef IOPERAND_HPP_
    #define IOPERAND_HPP_
    #include <iostream>
    #include <string.h>
    #include "Error.hpp"

enum eOperandType
  {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE
};

class IOperand
{
    public:
    virtual std::string toString() const = 0;
    virtual eOperandType getType() const = 0;

    virtual IOperand* operator+(const IOperand&) const = 0;
    virtual IOperand* operator-(const IOperand&) const = 0;
    virtual IOperand* operator*(const IOperand&) const = 0;
    virtual IOperand* operator/(const IOperand&) const = 0;
    virtual IOperand* operator%(const IOperand&) const = 0;

    virtual ~IOperand() {}
};
#endif /* !IOPERAND_HPP_ */
