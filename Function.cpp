//
// Created by zvi on 12/26/19.
//

#include "Function.h"
#include "Lexer.h"

extern Interpreter i;

Function :: Function(list<list<string>> commandList, vector<string> vars) {
    this->vars = vars;
    this->commandList = commandList;
}

void Function :: setVariables(list<string> num) {
    i.setVariables(this->vars, num);
}

int Function :: execute() {
    Lexer l;
    l.parser(this->commandList);
}