/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** main
*/

#include "../include/IOperand.hpp"
#include "../include/Error.hpp"
#include "../include/Operand.hpp"
#include "../include/Factory.hpp"
#include "../include/AbstractVM.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <string.h>
#include <memory>

void processLine(AbstractVM &vm, std::string &line, bool &exitExecuted)
{
    static Factory factory;
    size_t commentPos = line.find(';');
    if (commentPos != std::string::npos) {
        line = line.substr(0, commentPos);
    }
    line = std::regex_replace(line, std::regex("\\s+"), " ");
    line = std::regex_replace(line, std::regex("^\\s+|\\s+$"), "");

    if (line.empty() || line[0] == ';') return;

    std::regex instrRegex(R"((push|pop|dump|clear|dup|swap|assert|add|sub|mul|div|mod|load|store|print|exit)\s*(?:\s+(int8|int16|int32|float|double)\s*\(\s*([-]?\d+([.\s]*\d*)*)\s*\))?)");
    std::smatch matches;

    if (std::regex_match(line, matches, instrRegex)) {
        std::string instruction = matches[1];
        if (instruction == "exit") {
            exitExecuted = true; 
        }
        if (matches.size() > 2 && matches[2].matched) {
            std::string valueType = matches[2];
            std::string valueStr = std::regex_replace(matches[3].str(), std::regex("[\\s]*"), "");
            eOperandType type = factory.getOperandType(valueType);
            const IOperand* operand = factory.createOperand(type, valueStr);
            std::shared_ptr<const IOperand> sharedOperand(operand);
            vm.executeInstruction(instruction, sharedOperand);
        } else {
            vm.executeInstruction(instruction, std::shared_ptr<const IOperand>(nullptr));
        }
    } else {
        throw std::runtime_error("Unknown or malformed instruction");
    }
}

int withFile(std::string line, AbstractVM &vm, char **av, bool &exitExecuted)
{
    std::string filePath = av[1];
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filePath);
        return 84;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        return 0;
    }
    while (getline(file, line)) {
        processLine(vm, line, exitExecuted);
    }
    file.close();
    return 0;
}

int withoutFile(std::string line, AbstractVM &vm, bool &exitExecuted, std::vector<std::string> lines)
{
    while (getline(std::cin, line) && line != ";;") {
        lines.push_back(line);
    }
    while (!lines.empty()) {
        line = lines.front();
        lines.erase(lines.begin());
        processLine(vm, line, exitExecuted);
    }
    return 0;
}

int main(int ac, char **av)
{
    AbstractVM vm;
    bool exitExecuted = false;
    std::vector<std::string> lines;
    try {
        std::string line;
        if (ac == 2) {
            withFile(line, vm, av, exitExecuted);
        } else if (ac == 1) {
            withoutFile(line, vm, exitExecuted, lines);
        } else {
            throw std::runtime_error("Usage: ./abstract_vm [file]");
            return 84;
        }
        if (!exitExecuted) {
            throw std::runtime_error("Error: Missing exit instruction");
            return 84;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
    return 0;
}