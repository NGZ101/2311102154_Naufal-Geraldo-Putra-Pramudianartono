#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

// Inisialisasi array dengan data yang diberikan
int data_154[10] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};

int banyak_empat_154;
int elemen_target_154 = 4;

// Fungsi untuk mencari elemen target dan menghitung jumlah kemunculannya
void cari_empat_154() {
    for(int i = 0; i < 10; i++) {
        if(elemen_target_154 == data_154[i]) { // Periksa apakah elemen saat ini sama dengan elemen target
            banyak_empat_154++; // Tambahkan jumlah jika ditemukan kecocokan
        } 
    }
    if(banyak_empat_154 > 0) {
        cout << "Banyak elemen 4 dalam data array adalah: " << banyak_empat_154;
    }
    else {
        cout << "Data array tidak memiliki elemen 4";
    }

}

int main() {
    cout << "==== Program Pencari Elemen 4 Naufal Geraldo ====" << endl;
    cout << "data: (9, 4, 1, 4, 7, 10, 5, 4, 12, 4)" << endl;
    cari_empat_154();

    return 0;
}