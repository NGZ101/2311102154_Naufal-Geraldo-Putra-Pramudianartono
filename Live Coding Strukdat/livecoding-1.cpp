#include <iostream>

using namespace std;

int maks = 10, input;
int arr[7] = {12, 5, 3, 8, 10, 11};
void cari() {
    for(int i = 0; i < maks; i++) {
        if(input == arr[i]) {
            cout << "data ditemukan di indes ke-" << i << endl;
        }
        else {
            cout << "data tidak ditemukan" << endl;
        }
    }
}

int main() {
    cout << "Data: 12, 5, 3, 8, 10, 11" << endl;
    cout << "Masukkan nilai yang dicari: ";
    cin >> input;
    cari();

    return 0;
}