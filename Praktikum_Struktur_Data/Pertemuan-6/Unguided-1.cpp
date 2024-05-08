#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

bool is_palindrom_154(string word_154) {
    stack<char> letter_stack_154;
    string cleaned_word_154;
    for(char w: word_154) {
        if(isalnum(w)) {
            cleaned_word_154 += tolower(w);
            letter_stack_154.push(tolower(w));
        }
    } 
    for(char w: cleaned_word_154) {
        if(w != letter_stack_154.top()) {
            return false;
        }
        letter_stack_154.pop();
    }
    return true;
}

int main() {
    string input_154;
    cout << "==== Program Deteksi Palindrom Naufal Geraldo ====" << endl;
    cout << "\n";
    cout << "Masukkan sebuah string: ";
    getline(cin, input_154);
    if (is_palindrom_154(input_154)) {
        cout << "String tersebut adalah palindrom" << endl;
    }
    else {
        cout << "String tersebut bukan palindrom" << endl; 
    }

    return 0;
}