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
            return (!isalpha(c) && !isdigit(c) && c != ' ');
        }

        void add_to_operands(stack<string> *operands, stack<char> *operators) {
            // operand 1
            string op1 = operands->top();
            operands->pop();

            // operand 2
            string op2 = operands->top();
            operands->pop();

            // operator
            char op = operators->top();
            operators->pop();

            // Add operands and operator
            // in form operator +
            // operand1 + operand2.
            string tmp;
            tmp += op;
            tmp += op2;
            tmp += op1;
            operands->push(tmp);
        }

    }

    float evaluate(const string expression) {

        stack<float> operands;
        float a;
        float b;
        float near;
        int n = expression.length() - 1;
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
                        operands.push((int) ((a / b) * 100.0) / 100.0);
                        break;
                    case '^': {
                        near = 1;
                        if (b == 0) {
                            operands.push(near);

                        } else {
                            near = a;
                            for (int i = 1; i < b; i++) {
                                near *= a;
                            }
                            operands.push(near);
                        }
                        break;
                    }
                }

            } else if (!isOperator(expression[n]) && expression[n] != ' ') {
                string temp;
                while (expression[n] != ' ' && !isOperator(expression[n])) {
                    temp = expression[n] + move(temp);
                    n--;
                }
                operands.push(stof(temp));
                n++;
            }
            n--;
        }
        return operands.top();
    }


    string infixToPrefix(const string infix) {
        // stack for operators.
        stack<char> operators;

        // stack for operands.
        stack<string> operands;

        for (int i = 0; i < infix.length(); i++) {

            // If current character is an
            // opening bracket, then
            // push into the operators stack.
            if (infix[i] == '(') {
                operators.push(infix[i]);
            }

                // If current character is a
                // closing bracket, then pop from
                // both stacks and push result
                // in operands stack until
                // matching opening bracket is
                // not found.
            else if (infix[i] == ')') {
                while (!operators.empty() &&
                       operators.top() != '(') {

                    add_to_operands(&operands, &operators);
                }

                // Pop opening bracket from
                // stack.
                operators.pop();
            }

                // If current character is an
                // operand then push it into
                // operands stack.
            else if (!isOperator(infix[i])) {
                string op;
                while (infix[i] != '(' && infix[i] != ')' && !isOperator(infix[i])) {
                    op += infix[i];
                    i++;
                }
                i--;
                op += ' ';
                operands.push(op);
                //operands.push(string(1, infix[i]));
            }

                // If current character is an
                // operator, then push it into
                // operators stack after popping
                // high priority operators from
                // operators stack and pushing
                // result in operands stack.
            else {
                while (!operators.empty() &&
                       getPriority(infix[i]) <=
                       getPriority(operators.top())) {

                    add_to_operands(&operands, &operators);
                }

                operators.push(infix[i]);
            }
        }

        // Pop operators from operators stack
        // until it is empty and add result
        // of each pop operation in
        // operands stack.
        while (!operators.empty()) {

            add_to_operands(&operands, &operators);
        }

        // Final prefix expression is
        // present in operands stack.
        return operands.top();
    }

}