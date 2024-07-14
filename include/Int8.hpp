/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** Int8
*/

#ifndef INT8_HPP_
#define INT8_HPP_
#include "IOperand.hpp"
#include "Operand.hpp"

class Int8 : public AOperand<int8_t>
{
    public:
	  Int8(const std::string &value) : AOperand(value) {}

    IOperand* operator+(const IOperand&) const;
    IOperand* operator-(const IOperand&) const;
    IOperand* operator*(const IOperand&) const;
    IOperand* operator/(const IOperand&) const;
    IOperand* operator%(const IOperand&) const;

    ~Int8() = default;
};

template<>
eOperandType
AOperand<int8_t>::getType() const
{
  return INT8;
}

#endif /* !INT8_HPP_ */
