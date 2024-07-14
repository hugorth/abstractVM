/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** AbstractVM
*/

#include "../include/AbstractVM.hpp"
#include <sstream>
#include <iomanip>

AbstractVM::AbstractVM() {
    std::fill(_registers.begin(), _registers.end(), nullptr);
    handlers["push"] = [this](std::shared_ptr<const IOperand> op) { this->_push(op); };
    handlers["pop"] = [this](std::shared_ptr<const IOperand> op) { this->_pop(op); };
    handlers["clear"] = [this](std::shared_ptr<const IOperand> op) { this->_clear(op); };
    handlers["dup"] = [this](std::shared_ptr<const IOperand> op) { this->_dup(op); };
    handlers["swap"] = [this](std::shared_ptr<const IOperand> op) { this->_swap(op); };
    handlers["dump"] = [this](std::shared_ptr<const IOperand> op) { this->_dump(op); };
    handlers["assert"] = [this](std::shared_ptr<const IOperand> op) { this->_assert(op); };
    handlers["add"] = [this](std::shared_ptr<const IOperand> op) { this->_add(op); };
    handlers["sub"] = [this](std::shared_ptr<const IOperand> op) { this->_sub(op); };
    handlers["mul"] = [this](std::shared_ptr<const IOperand> op) { this->_mul(op); };
    handlers["div"] = [this](std::shared_ptr<const IOperand> op) { this->_div(op); };
    handlers["mod"] = [this](std::shared_ptr<const IOperand> op) { this->_mod(op); };
    handlers["load"] = [this](std::shared_ptr<const IOperand> op) { this->_load(op); };
    handlers["store"] = [this](std::shared_ptr<const IOperand> op) { this->_store(op); };
    handlers["print"] = [this](std::shared_ptr<const IOperand> op) { this->_print(op); };
    handlers["exit"] = [this](std::shared_ptr<const IOperand> op) { this->_exit(op); };
}

void AbstractVM::executeInstruction(const std::string& instruction, std::shared_ptr<const IOperand> value) {
    auto it = handlers.find(instruction);
    if (it != handlers.end()) {
        it->second(value);
    } else {
        throw std::runtime_error("Error: Unknown instruction");
    }
}


eOperandType AbstractVM::getHigherPrecisionType(const IOperand* op1, const IOperand* op2)
{
    return op1->getType() > op2->getType() ? op1->getType() : op2->getType();
}

void AbstractVM::_push(std::shared_ptr<const IOperand> value) {
    const std::string valueStr = value->toString();
    const eOperandType type = value->getType();
    const IOperand* operand = _factory.createOperand(type, valueStr);
    _stack.push_back(operand);
}

void AbstractVM::_pop(std::shared_ptr<const IOperand> operand) {
    if (_stack.empty()) {
        throw std::runtime_error("Error: Cannot pop from an empty stack");
    }
    delete _stack.back();
    _stack.pop_back();
}

void AbstractVM::_clear(std::shared_ptr<const IOperand> operand) {
    while (!_stack.empty()) {
        delete _stack.back();
        _stack.pop_back();
    }
}

void AbstractVM::_dup(std::shared_ptr<const IOperand> operand) {
    if (_stack.empty()) {
        throw std::runtime_error("Error: Cannot duplicate an empty stack");
    }
    const IOperand* backOperand = _stack.back();
    const IOperand* duplicatedOperand = _factory.createOperand(backOperand->getType(), backOperand->toString());
    _stack.push_back(duplicatedOperand);
}

void AbstractVM::_swap(std::shared_ptr<const IOperand> operand) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Error: Not enough operands on the stack to swap");
        while (!_stack.empty()) {
            delete _stack.back();
        }
    }
    const IOperand* operand1 = _stack.back();
    _stack.pop_back();
    const IOperand* operand2 = _stack.back();
    _stack.pop_back();
    _stack.push_back(operand1);
    _stack.push_back(operand2);
}

void AbstractVM::_dump(std::shared_ptr<const IOperand> operand) {
    std::vector<const IOperand*> tempStack = _stack;
    while (!tempStack.empty()) {
        const IOperand* operand = tempStack.back();
        std::string strValue = operand->toString();
        std::stringstream ss;
        double value = std::stod(strValue);

        ss << std::fixed << std::setprecision(7) << value;
        std::string formatted = ss.str();
        formatted.erase(formatted.find_last_not_of('0') + 1, std::string::npos);
        if (formatted.back() == '.') {
            formatted.pop_back();
        }
        std::cout << formatted << std::endl;
        tempStack.pop_back();
    }
}

void AbstractVM::_assert(std::shared_ptr<const IOperand> operand) {
    if (_stack.empty()) {
        throw std::runtime_error("Error: Cannot assert on an empty stack");
    }
    const IOperand* backOperand = _stack.back();
    std::string operandStr = operand->toString();
    const IOperand* assertedOperand = _factory.createOperand(operand->getType(), operandStr);
    if (backOperand->toString() != assertedOperand->toString()) {
        throw std::runtime_error("Assertion failed: back stack value does not match the asserted value");
        while (!_stack.empty()) {
            delete _stack.back();
        }
    }
}

void AbstractVM::_add(std::shared_ptr<const IOperand> operand) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Error: Not enough operands on the stack to perform addition");
        while (!_stack.empty()) {
            delete _stack.back();
        }
    }
    const IOperand* operand2 = _stack.back();
    _stack.pop_back();
    const IOperand* operand1 = _stack.back();
    _stack.pop_back();

    eOperandType higherType = getHigherPrecisionType(operand1, operand2);
    const IOperand* convertedOp1 = _factory.createOperand(higherType, operand1->toString());
    const IOperand* convertedOp2 = _factory.createOperand(higherType, operand2->toString());

    const IOperand* result = *convertedOp1 + *convertedOp2;

    _stack.push_back(result);
}

void AbstractVM::_sub(std::shared_ptr<const IOperand> operand) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Error: Not enough operands on the stack to perform subtraction");
        while (!_stack.empty()) {
            delete _stack.back();
        }
    }
    const IOperand* operand2 = _stack.back();
    _stack.pop_back();
    const IOperand* operand1 = _stack.back();
    _stack.pop_back();

    eOperandType higherType = getHigherPrecisionType(operand1, operand2);
    const IOperand* convertedOp1 = _factory.createOperand(higherType, operand1->toString());
    const IOperand* convertedOp2 = _factory.createOperand(higherType, operand2->toString());

    const IOperand* result = *convertedOp1 - *convertedOp2;

    _stack.push_back(result);
}

void AbstractVM::_mul(std::shared_ptr<const IOperand> operand) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Error: Not enough operands on the stack to perform multiplication");
        while (!_stack.empty()) {
            delete _stack.back();
        }
    }
    const IOperand* operand2 = _stack.back();
    _stack.pop_back();
    const IOperand* operand1 = _stack.back();
    _stack.pop_back();

    eOperandType higherType = getHigherPrecisionType(operand1, operand2);
    const IOperand* convertedOp1 = _factory.createOperand(higherType, operand1->toString());
    const IOperand* convertedOp2 = _factory.createOperand(higherType, operand2->toString());

    const IOperand* result = *convertedOp1 * *convertedOp2;

    _stack.push_back(result);
}

void AbstractVM::_div(std::shared_ptr<const IOperand> operand) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Error: Not enough operands on the stack for division");
        while (!_stack.empty()) {
            delete _stack.back();
        }
    }
    const IOperand* operand2 = _stack.back(); 
    _stack.pop_back();
    const IOperand* operand1 = _stack.back();
    _stack.pop_back();
    eOperandType higherType = getHigherPrecisionType(operand1, operand2);
    const IOperand* convertedOp1 = _factory.createOperand(higherType, operand1->toString());
    const IOperand* convertedOp2 = _factory.createOperand(higherType, operand2->toString());
    if (std::stod(operand2->toString()) == 0) {
        throw std::runtime_error("Error: Division by zero");
    }

    const IOperand* result = *convertedOp1 / *convertedOp2;

    _stack.push_back(result);
}

void AbstractVM::_mod(std::shared_ptr<const IOperand> perand) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Error: Not enough operands on the stack for modulo");
        while (!_stack.empty()) {
            delete _stack.back();
        }
    }
    const IOperand* operand2 = _stack.back();
    _stack.pop_back();
    const IOperand* operand1 = _stack.back();
    _stack.pop_back();

    eOperandType higherType = getHigherPrecisionType(operand1, operand2);
    const IOperand* convertedOp1 = _factory.createOperand(higherType, operand1->toString());
    const IOperand* convertedOp2 = _factory.createOperand(higherType, operand2->toString());

    if (std::stod(operand2->toString()) == 0) {
        throw std::runtime_error("Error: Modulo by zero");
    }

    const IOperand* result = *convertedOp1 % *convertedOp2;

    _stack.push_back(result);
}

void AbstractVM::_load(std::shared_ptr<const IOperand> operand) {
    const int registerIndex = std::stoi(operand->toString());
    if (!_registers[registerIndex]) {
        throw std::runtime_error("Error: Register is empty");
    }

    if (registerIndex < 0 || registerIndex > 15) {
        throw std::runtime_error("Error: Register index out of bounds");
    }

    _stack.push_back(_factory.createOperand(_registers[registerIndex]->getType(), _registers[registerIndex]->toString()));

}

void AbstractVM::_store(std::shared_ptr<const IOperand> operand)
{
    if (_stack.empty()) {
        throw std::runtime_error("Error: Cannot store from an empty stack");
    }

    const IOperand* backOperand = _stack.back();
    int registerIndex = std::stoi(operand->toString());

    if (registerIndex < 0 || registerIndex > 15) {
        throw std::runtime_error("Error: Register index out of bounds");
    }
    const IOperand* valueToStore = _stack.back();
    delete _registers[registerIndex];
    _registers[registerIndex] = _factory.createOperand(valueToStore->getType(), valueToStore->toString());
    delete _stack.back();
    _stack.pop_back();
}

void  AbstractVM::_print(std::shared_ptr<const IOperand> operand) {
    if (_stack.empty()) {
        throw std::runtime_error("Error: Cannot print from an empty stack");
    }
    const IOperand* backOperand = _stack.back();
    if (backOperand->getType() != INT8) {
        throw std::runtime_error("Error: Operand is not of type int8");
        while (!_stack.empty()) {
            delete _stack.back();
        }
    }
    char c = std::stoi(backOperand->toString());
    std::cout << c << std::endl;
}

void AbstractVM::_exit(std::shared_ptr<const IOperand> operand) {
    for (const IOperand* operand : _registers) {
        if (operand != nullptr) {
            delete operand;
        }
    }
}
