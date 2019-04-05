//
// Created by IONUT on 05.04.2019.
//

#include "Parse_evaluate.h"

namespace Expression {
    namespace {
        int getPriority(char C) {
            if (C == '-' || C == '+')
                return 1;
            else if (C == '*' || C == '/')
                return 2;
            else if (C == '^')
                return 3;
            return 0;
        }

        bool isOperator(char c) {
            return (!isalpha(c) && !isdigit(c));
        }
    }

    int Expression::evaluate(string expression) {

        stack<char> operands;
        int a;
        int b;
        int n = expression.length();
        while (n >= 0) {
            if (isOperator(expression[n])) {

                a = operands.top();
                operands.pop();
                b = operands.top();
                operands.pop();

                switch (expression[n]) {
                    case '+':
                        operands.push(a + b);
                        break;
                    case '-':
                        operands.push(a - b);
                        break;
                    case '*':
                        operands.push(a * b);
                        break;
                    case '/':
                        operands.push(a / b);
                        break;
                    case '^': {
                        for (int i = 0; i < b; i++) {
                            a += a;
                        }
                        operands.push(a);
                        break;
                    }
                }

            } else if (!isOperator(expression[n])) {

            }
        }
    }

    string infixToPrefix(const string &infix) {

        stack<char> operators;

        // stack for operands.
        stack<string> operands;

        for (char i : infix) {

            // If current character is an
            // opening bracket, then
            // push into the operators stack.
            if (i == '(') {
                operators.push(i);
            }

                // If current character is a
                // closing bracket, then pop from
                // both stacks and push result
                // in operands stack until
                // matching opening bracket is
                // not found.
            else if (i == ')') {
                while (!operators.empty() &&
                       operators.top() != '(') {

                    // operand 1
                    string op1 = operands.top();
                    operands.pop();

                    // operand 2
                    string op2 = operands.top();
                    operands.pop();

                    // operator
                    char op = operators.top();
                    operators.pop();

                    // Add operands and operator
                    // in form operator +
                    // operand1 + operand2.
                    string tmp;
                    tmp += op;
                    tmp += op2;
                    tmp += op1;
                    operands.push(tmp);
                }

                // Pop opening bracket from
                // stack.
                operators.pop();
            }

                // If current character is an
                // operand then push it into
                // operands stack.
            else if (!isOperator(i)) {
                operands.push(string(1, i));
            }

                // If current character is an
                // operator, then push it into
                // operators stack after popping
                // high priority operators from
                // operators stack and pushing
                // result in operands stack.
            else {
                while (!operators.empty() &&
                       getPriority(i) <=
                       getPriority(operators.top())) {

                    string op1 = operands.top();
                    operands.pop();

                    string op2 = operands.top();
                    operands.pop();

                    char op = operators.top();
                    operators.pop();

                    string tmp;
                    tmp += op;
                    tmp += op2;
                    tmp += op1;
                    operands.push(tmp);
                }

                operators.push(i);
            }
        }

        // Pop operators from operators stack
        // until it is empty and add result
        // of each pop operation in
        // operands stack.
        while (!operators.empty()) {
            string op1 = operands.top();
            operands.pop();

            string op2 = operands.top();
            operands.pop();

            char op = operators.top();
            operators.pop();

            string tmp;
            tmp += op;
            tmp += op2;
            tmp += op1;
            operands.push(tmp);
        }

        // Final prefix expression is
        // present in operands stack.
        return operands.top();
    }
}