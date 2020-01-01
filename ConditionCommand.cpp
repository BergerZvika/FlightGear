//
// Created by zvi on 12/25/19.
//

#include "ConditionCommand.h"
#include "Lexer.h"

//constractor
ConditionCommand :: ConditionCommand(list<list<string>> commandList, string command,  string left, string sign, string right){
    this->commandList = commandList;
    this->command = command;
    this->left = left;
    this->sign = sign;
    this->right = right;
}

//this function check if condition is true or false.
bool ConditionCommand ::condition() {
    if (sign == "=" && i.interpret(left) == i.interpret(right)) {
        return true;
    } else if (sign == "==" && i.interpret(left) == i.interpret(right)) {
        return true;
    } else if (sign == ">" && i.interpret(left) > i.interpret(right)) {
        return true;
    } else if(sign == "<" && i.interpret(left) < i.interpret(right)) {
        return true;
    } else if(sign == ">=" && i.interpret(left) >= i.interpret(right)) {
        return true;
    } else if(sign == "<=" && i.interpret(left) <= i.interpret(right)) {
        return true;
    } else if(sign == "!=" && i.interpret(left) != i.interpret(right)) {
        return true;
    }
    //the condition is false.
    return false;
}

//this function execute if or while command
int ConditionCommand :: execute() {
    Lexer l = Lexer();
    if (this->command == "if" && this->condition()) {
        l.parser(this->commandList);
    } else if (this->command == "while") {
        while (this->condition()) {
            l.parser(this->commandList);
        }
    }
    return  0;
}