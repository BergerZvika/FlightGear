//
// Created by zvi on 12/25/19.
//

#ifndef FLIGHTGEAR_CONDITIONCOMMAND_H
#define FLIGHTGEAR_CONDITIONCOMMAND_H

#include <list>
#include "Command.h"
#include "Interpreter.h"

class ConditionCommand: public Command {
    string command;
    string left;
    string sign;
    string right;
    list<list<string>> commandList;
    Interpreter i;
public:
    ConditionCommand(list<list<string>> commandList, string command,  string left, string sign, string right);
    int execute() override ;
    bool condition();
};

#endif //FLIGHTGEAR_CONDITIONCOMMAND_H
