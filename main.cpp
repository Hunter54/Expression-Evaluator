#include <iostream>
#include <stack>
#include "Parse_evaluate.h"
#include <string>
using namespace std;
int main() {

    string a;
    a="(2+5*9)/(2+6/2)+2";
    cout<<endl<<Expression::infixToPrefix(a);

    return 0;
}