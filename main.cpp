#include <iostream>
#include <stack>
#include "Parse_evaluate.h"
#include <string>
#include <math.h>
using namespace std;
using namespace Expression;
int main() {

    string a;
    //"2*(50+21)-6/(30-25)+25"
    a="2^1";
    cout<<infixToPrefix(a)<<endl;
    cout<<endl<<evaluate(infixToPrefix(a));

    return 0;
}