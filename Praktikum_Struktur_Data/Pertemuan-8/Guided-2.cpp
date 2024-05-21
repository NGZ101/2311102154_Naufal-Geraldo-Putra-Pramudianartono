#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int dataArray[7] = {1,8,2,5,4,9,7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for(i = 0; i < 7; i++) {
        min = i;
        for(j = i + 1; j < 7; j++) {
            if(dataArray[j] < dataArray[min]) {
                min = j;
            }
        }
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}

void binarysearch() {
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = 6; // Corrected 6 to match array bounds
    while(!b_flag && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(dataArray[tengah] == cari) {
            b_flag = true;
        }
        else if (dataArray[tengah] < cari) {
            awal = tengah + 1;
        }
        else {
            akhir = tengah - 1;
        }
    }
    if(b_flag) {
        cout << "\n Data ditemukan pada indeks ke- " << tengah << endl;
    }
    else {
        cout << "\n Data tidak ditemukan \n";
    }
}

int main() {
    cout << "\t BINARY SEARCH" << endl;
    cout << "\n Data: ";

    //Tampilkan data awal
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    cout << "\n Masukkan data yang ingin Anda cari: ";
    cin >> cari;

    cout << "\n Data diurutkan: ";

    //Urutkan data dengan selection sort
    selection_sort();

    //Tampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    binarysearch();
    
    _getche();
    return 0;
}