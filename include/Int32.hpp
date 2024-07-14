/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** Int32
*/

#ifndef INT32_HPP_
#define INT32_HPP_

#include "IOperand.hpp"
#include "Operand.hpp"

class Int32 : public AOperand<int32_t> {
public:
    Int32(const std::string&);

    ~Int32() = default;
};

template<>
eOperandType
AOperand<int32_t>::getType() const
{
  return INT32;
}

#endif /* !INT32_HPP_ */
