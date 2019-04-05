//
// Created by IONUT on 26.03.2019.
//
#include <string.h>
#include <stack>
#include <string>

using namespace std;
#ifndef EVALUATOR_PARSE_EVALUATE_H
#define EVALUATOR_PARSE_EVALUATE_H

namespace Expression{

    string infixToPrefix(string infix);
    int evaluate(string expresion);
}

#endif //EVALUATOR_PARSE_EVALUATE_H
