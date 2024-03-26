#include <iostream>
#include <iomanip>

using namespace std;

// Tipe Data Primitif

int main(){
    char op;
    float num1, num2;

    // it allows user to enter operator i.e. +,-,*,/
    cout << "Enter operator (+,-,*,/)";
    cin >> op;

    // it allows user to enter the operands
    cout << "Enter 2 operands: ";
    cin >> num1 >> num2;

    // switch statements begins
    switch (op)
    {
    case '+' :
        cout << "Result: " << num1+num2;
        break;
    case '-' :
        cout << "Result: " << num1-num2;
        break;
    case '*' :
        cout << "Result: " << num1*num2;
        break;
    case '/' :
        if(num2 !=0){
            cout << "Result: " << num1/num2;
        }
        else{
            cout << "ERROR! DEVISION BY 0 IS NOT ALLOWED";
        }
        break; 
    // if the operator is other than +, -, * or /,
    // error message will display_154
    default:
       cout << "ERROR! OPERATOR NOT CORRECT";
        break;
    } // switch statement ends
    return 0;
}