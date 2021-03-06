#include <iostream>
#include <stack>
#include "Parse_evaluate.h"
#include <string>

using namespace std;

int main() {

    string a;
    int c;
    do{

        cout<<"\n\n\n__________MENU__________";
        cout<<"\n 1-Enter new expression:";
        cout<<"\n 2-Parse to prefix notation";
        cout<<"\n 3-Evaluate expression";
        cout<<"\n 4-Display expression";
        cout<<"\n 0-Exit\n";
        cout<<"\n\nYour option: ";

        cin>>c;
        switch(c){
            case 1:{
                cout<<"Give a new infix expression: ";
                cin>>a;
                break;
            }
            case 2:{

                if(a.empty()){
                    cout<<"No expression to parse";
                }
                else {
                    cout << "Prefix notation of the expression is: " << Expression::infixToPrefix(a);
                }
                break;
            }
            case 3:{
                if(a.empty()){
                    cout<<"No expression to evaluate";
                }
                else {
                    cout << "Expression value is: " << Expression::evaluate(Expression::infixToPrefix(a));
                }
                break;
            }
            case 4:{
                cout<<"Expression is :"<<a;
                break;
            }
            case 0:{
                break;
            }
        }
    }while(c!=0);

    //"2*(50+21)-6/(30-25)+25"
//    a="((12+32)*2)/5";
//    cout<<infixToPrefix(a)<<endl;
//    cout<<endl<<evaluate(infixToPrefix(a));

    return 0;
}