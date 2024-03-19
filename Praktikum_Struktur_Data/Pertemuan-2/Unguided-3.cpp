#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

char pilih_154, pilih2_154;
int i_154, ukuran_154, maks_154, min_154, rata_154;
double total_154;

// Fungsi menampilkan input ukuran 
void awal_154() {
    cout << "Masukkan ukuran array: ";
    cin >> ukuran_154;
}

// Fungsi menampilkan menu pilihan awal 
void menu_154() {
    cout << "A. Cari nilai maksimum \n";
    cout << "B. Cari nilai minimum \n";
    cout << "C. Cari nilai rata-rata \n";
    cout << "Pilihan anda: ";
    cin >> pilih_154;
    pilih_154 = toupper(pilih_154);
}

// Fungsi menampilkan menu pilihan pengurangan program
void akhir_154() {
    cout << "Apakah anda ingin mulai dari ulang ? (Y/N)";
    cin >> pilih2_154;
    pilih2_154 = toupper(pilih2_154);
}


int main() {
    start: // Destinasi untuk goto pada fungsi akhir jika memilih 'Y'
    awal_154();
    int array_154[ukuran_154];
    for (i_154 = 0; i_154 < ukuran_154; i_154++) {
        cout << "Input bilangan ke-" << i_154 + 1 <<" : ";
        cin >> array_154[i_154];
    }
    menu_154();
    switch (pilih_154) { // Switch case untuk pemilihan menu awal
    case 'A': // Menentukan nilai terbesar 
        maks_154 = array_154[0];
        for (i_154 = 0; i_154 < ukuran_154; i_154++) {
            if (array_154[i_154] > maks_154) {
                maks_154= array_154[i_154]; // Untuk bagian ini maks_154 harus didepan array jika tidak akan error
            }
        }
        cout << "Nilai maksimum adalah " << maks_154 << endl;
        break;
    case 'B': // Menentukan nilai terkecil
        min_154 = array_154[0];
        for (i_154 = 0; i_154 < ukuran_154; i_154++) {
            if (array_154[i_154] < min_154) {
                min_154= array_154[i_154]; // Untuk bagian ini min_154 harus didepan array jika tidak akan error
            }
        }
        cout << "Nilai minimum adalah " << min_154 << endl;
        break;
    case 'C': // Menentukan nilai rata-rata
        for (i_154 = 0; i_154 < ukuran_154; i_154++) {
            total_154 += array_154[i_154];
            rata_154 = total_154 / ukuran_154;
        }
        cout << "Nilai rata-rata adalah " << setprecision(2) << rata_154 << endl;
        break;
    default:
        cout << "ERROR MASUKKAN PILIHAN YANG VALID \n";
        break;
    }

    start2: // Destinasi goto pada bagian default
    akhir_154();
    switch (pilih2_154) {
    case 'Y':
        goto start;
        break;
    case 'N':
        cout << "Selamat Tinggal \n";
        break;
    default:
        cout << "ERROR PILIHAN INVALID \n";
        goto start2;
        break;
    }
}