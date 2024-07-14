/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** Double
*/

#ifndef DOUBLE_HPP_
#define DOUBLE_HPP_
#include "IOperand.hpp"
#include "Operand.hpp"

class Double : public AOperand<double> {
public:
    Double(const std::string&);
    IOperand* operator%(const IOperand&) const;

    ~Double() = default;
};

template<>
eOperandType AOperand<double>::getType() const
{
  return DOUBLE;
}

#endif /* !DOUBLE_HPP_ */
