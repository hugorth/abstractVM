/*
** EPITECH PROJECT, 2024
** syn_pool
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <string>

class LexicalOrSyntacticalError : public std::exception {
public:
    const char* what() const noexcept override {
        return "Lexical or syntactical error detected.";
    }
};

class UnknownInstruction : public std::exception {
public:
    const char* what() const noexcept override {
        return "Unknown instruction encountered.";
    }
};

class OverflowError : public std::exception {
public:
    const char* what() const noexcept override {
        return "Overflow on a value.";
    }
};

class UnderflowError : public std::exception {
public:
    const char* what() const noexcept override {
        return "Underflow on a value.";
    }
};

class EmptyStackPopError : public std::exception {
public:
    const char* what() const noexcept override {
        return "Pop instruction on an empty stack.";
    }
};

class DivisionByZeroError : public std::exception {
public:
    const char* what() const noexcept override {
        return "Division or modulo by zero.";
    }
};

class MissingExitInstructionError : public std::exception {
public:
    const char* what() const noexcept override {
        return "The program does not have an exit instruction.";
    }
};

class AssertNotVerifiedError : public std::exception {
public:
    const char* what() const noexcept override {
        return "An assert instruction is not verified.";
    }
};

class InsufficientStackSizeError : public std::exception {
public:
    const char* what() const noexcept override {
        return "The stack strictly has less than two values during the execution of an arithmetical instruction.";
    }
};

#endif /* !ERROR_HPP_ */
