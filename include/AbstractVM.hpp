/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** AbstractVM
*/

#ifndef ABSTRACTVM_HPP_
#define ABSTRACTVM_HPP_

#include <iostream>
#include <stack>
#include <vector>
#include <stdexcept>
#include "../include/Factory.hpp"
#include "../include/IOperand.hpp"
#include "../include/Error.hpp"
#include <array>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <functional>

class AbstractVM {
private:
    std::vector<const IOperand*> _stack;
    std::array<IOperand*, 16> _registers{nullptr};
    Factory _factory;
    std::map<std::string, std::function<void(std::shared_ptr<const IOperand>)>> handlers;

    void _push(std::shared_ptr<const IOperand> operand);
    void _pop(std::shared_ptr<const IOperand> operand);
    void _clear(std::shared_ptr<const IOperand>operand);
    void _dup(std::shared_ptr<const IOperand>operand);
    void _swap(std::shared_ptr<const IOperand>operand);
    void _dump(std::shared_ptr<const IOperand>operand);
    void _assert(std::shared_ptr<const IOperand>operand);
    void _add(std::shared_ptr<const IOperand>operand);
    void _sub(std::shared_ptr<const IOperand>operand);
    void _mul(std::shared_ptr<const IOperand>operand);
    void _div(std::shared_ptr<const IOperand>operand);
    void _mod(std::shared_ptr<const IOperand>operand);
    void _load(std::shared_ptr<const IOperand>operand);
    void _store(std::shared_ptr<const IOperand>operand);
    void  _print(std::shared_ptr<const IOperand>operand);
    void _exit(std::shared_ptr<const IOperand>operand);

public:
    AbstractVM();
    ~AbstractVM() = default;
    std::string formatted;
    void executeInstruction(const std::string& instruction, std::shared_ptr<const IOperand> value);
    eOperandType getHigherPrecisionType(const IOperand* op1, const IOperand* op2);

};

#endif /* !ABSTRACTVM_HPP_ */
