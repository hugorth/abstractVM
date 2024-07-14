/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_
#include "IOperand.hpp"
#include "map"
#include <functional>
#include <memory>
class Factory {
    public:
        Factory();
        ~Factory();
        static IOperand* createOperand(eOperandType, const std::string&);
        eOperandType getOperandType(const std::string &type) const;

    protected:
    private:
        std::map<eOperandType, std::function<std::shared_ptr<IOperand>(const std::string&)>> operand;
        IOperand *createDouble (const std::string &value);
        IOperand *createFloat (const std::string &value);
        IOperand* createInt8(const std::string &value);
        IOperand* createInt16(const std::string &value);
        IOperand* createInt32(const std::string &value);
        template<class T> struct always_false : std::false_type {};
};

#endif /* !FACTORY_HPP_ */
