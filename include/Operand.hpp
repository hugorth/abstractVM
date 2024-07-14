/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** Operand
*/

#ifndef OPERAND_HPP_
#define OPERAND_HPP_
#include "IOperand.hpp"
# include <regex>
# include <fstream>
# include <list>
# include <iostream>

template<typename T>
class AOperand : public IOperand
{
protected:
  std::string _value;
public:
	AOperand(const std::string& value): _value(value){ }
	std::string toString() const {
		return (this->_value);
	}
	virtual IOperand* operator+(const IOperand&) const;
	virtual IOperand* operator-(const IOperand&) const;
	virtual IOperand* operator*(const IOperand&) const;
	virtual IOperand* operator/(const IOperand&) const;
	virtual IOperand* operator%(const IOperand&) const;
	virtual eOperandType getType() const;
  	~AOperand(){};
};

template class AOperand<int8_t>;
template class AOperand<int16_t>;
template class AOperand<int32_t>;
template class AOperand<float>;
template class AOperand<double>;

#endif /* !OPERAND_HPP_ */
