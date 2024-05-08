#include <iostream>
#include <stack>

using namespace std;

string normal_154(string word_154) {
  stack<char> letter_stack_154; 
  for(int i = 0; i < word_154.length(); i++) { 
    letter_stack_154.push(word_154[i]);
  }
  string reverse_154; 
  while(!letter_stack_154.empty()) {
    reverse_154 += letter_stack_154.top();
    letter_stack_154.pop();
  }
  return reverse_154;
}

int main() {
  string word_154;
  cout << "==== Program Pembalik Kata Naufal Geraldo ====" << endl;
  cout << "\n";
  do {
  cout << "Masukkan kata yang akan dibalik: ";
  getline(cin, word_154);
  string reverse_154 = normal_154(word_154);  
  cout << "Kata yang dibalik: " << reverse_154 << endl;
  cout << "Note : untuk menghentikan program inputkan 0." << endl;

  } while(word_154 != "0");
  return 0;
}