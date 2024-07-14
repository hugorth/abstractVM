/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** Float
*/

#ifndef FLOAT_HPP_
#define FLOAT_HPP_
#include "IOperand.hpp"
#include "Operand.hpp"

class Float : public AOperand<float> {
public:
    Float(const std::string&);
    IOperand* operator%(const IOperand&) const;

    ~Float() = default;
};

template<>
eOperandType AOperand<float>::getType() const
{
  return (FLOAT);
}

#endif /* !FLOAT_HPP_ */
