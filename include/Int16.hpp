/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** Int16
*/

#ifndef INT16_HPP_
#define INT16_HPP_
#include "IOperand.hpp"
#include "Operand.hpp"

class Int16 : public AOperand<int16_t> {
public:
    Int16(const std::string&);

    ~Int16() = default;
};

template<>
eOperandType
AOperand<int16_t>::getType() const
{
  return INT16;
}

#endif /* !INT16_HPP_ */

