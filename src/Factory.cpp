/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** Factory
*/

#include "../include/Factory.hpp"
#include "../include/Int8.hpp"
#include "../include/Int16.hpp"
#include "../include/Int32.hpp"
#include "../include/Float.hpp"
#include "../include/Double.hpp"
#include <memory>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <map>
#include <unordered_map>

Factory::Factory() {
    this->operand[INT8] = [this](const std::string &value) -> std::shared_ptr<IOperand> {
        return std::shared_ptr<IOperand>(this->createInt8(value));
    };
    this->operand[INT16] = [this](const std::string &value) -> std::shared_ptr<IOperand> {
        return std::shared_ptr<IOperand>(this->createInt16(value));
    };
    this->operand[INT32] = [this](const std::string &value) -> std::shared_ptr<IOperand> {
        return std::shared_ptr<IOperand>(this->createInt32(value));
    };
    this->operand[FLOAT] = [this](const std::string &value) -> std::shared_ptr<IOperand> {
        return std::shared_ptr<IOperand>(this->createFloat(value));
    };
    this->operand[DOUBLE] = [this](const std::string &value) -> std::shared_ptr<IOperand> {
        return std::shared_ptr<IOperand>(this->createDouble(value));
    };
}

Factory::~Factory()
{
}

IOperand* Factory::createFloat(const std::string &value) {
    float cValue;
    std::istringstream iss(value);
    iss >> cValue;
    if (iss.fail() || !iss.eof() || std::isinf(cValue) || std::isnan(cValue)) {
        throw std::runtime_error("overflow for float");
    }
    if (cValue < std::numeric_limits<float>::lowest() || cValue > std::numeric_limits<float>::max()) {
        throw std::runtime_error("overflow for float");
    }
    return new Float(value);
}

IOperand* Factory::createDouble(const std::string &value) {
    double cValue = std::stod(value);
    return new Double(std::to_string(cValue));
}

IOperand* Factory::createInt8(const std::string &value) {
        long long cValue = std::stoll(value);
    if (cValue < std::numeric_limits<int8_t>::min() || cValue > std::numeric_limits<int8_t>::max())
        throw std::out_of_range("Value is out of range");
    return new Int8(std::to_string(cValue));

}

IOperand* Factory::createInt16(const std::string &value) {
        long long cValue = std::stoll(value);
    if (cValue < std::numeric_limits<int16_t>::min() || cValue > std::numeric_limits<int16_t>::max())
        throw std::out_of_range("Value is out of range");
    return new Int16(std::to_string(cValue));

}

IOperand* Factory::createInt32(const std::string &value) {
        long long cValue = std::stoll(value);
    if (cValue < std::numeric_limits<int32_t>::min() || cValue > std::numeric_limits<int32_t>::max())
        throw std::out_of_range("Value is out of range");
    return new Int32(std::to_string(cValue));

}

IOperand*
Factory::createOperand(eOperandType type, const std::string& value) {
    static Factory factory;

    switch (type) {
        case INT8:
            return factory.createInt8(value);
        case INT16:
            return factory.createInt16(value);
        case INT32:
            return factory.createInt32(value);
        case FLOAT:
            return factory.createFloat(value);
        case DOUBLE:
            return factory.createDouble(value);
        default:
            throw std::invalid_argument("Unknown operand type");
    }
}

eOperandType Factory::getOperandType(const std::string &type) const
{
    static const std::unordered_map<std::string, eOperandType> _type = {
        {"int8", eOperandType::INT8},
        {"int16", eOperandType::INT16},
        {"int32", eOperandType::INT32},
        {"float", eOperandType::FLOAT},
        {"double", eOperandType::DOUBLE}
    };

    auto it = _type.find(type);
    if (it != _type.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("Unknown operand type: " + type);
    }
}