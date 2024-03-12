//Naufal Geraldo Putra Pramudianartono - NIM: 2311102154

#include <iostream>
#include <cctype> // Untuk input tolower() (dan toupper()) agar input user dapat dibaca walaupun user memakai huruf besar

using namespace std;

char pilih_154; // Data primitif 1 huruf untuk menu
float bil1_154, bil2_154; // Data primitif float untuk menginput 2 bilangan

void mulaiprogram_154() { // Fungsi untuk menampilkan menu pilihan
    cout << "PROGRAM KALKULATOR 2 BILANGAN \n";
    cout << "a. Penjumlahan (+) \n";
    cout << "b. Pengurangan (-) \n";
    cout << "c. Perkalian (*) \n";
    cout << "d. Pembagian (/) \n";
    cout << "Masukkan Pilihan : ";
    cin >> pilih_154;
    pilih_154 = tolower(pilih_154);
}

float tambah_154() { // Fungsi Penjumlahan
    cout << "\n--- PENJUMLAHAN ---" << endl;
    cout << "Bilangan pertama : ";
    cin >> bil1_154;
    cout << "Bilangan kedua : ";
    cin >> bil2_154;
    cout << bil1_154 << " + " << bil2_154  << " = ";
    return bil1_154 + bil2_154; // Mengoutput hasil penjumlahan
}

float kurang_154() { // Fungsi Pengurangan
    cout << "\n--- PENGURANGAN ---" << endl;
    cout << "Bilangan pertama : ";
    cin >> bil1_154;
    cout << "Bilangan kedua : ";
    cin >> bil2_154;
    cout << bil1_154 << " - " << bil2_154  << " = ";
    return bil1_154 - bil2_154; // Mengoutput hasil pengurangan
}

float kali_154() { // Fungsi Perkalian
    cout << "\n--- PERKALIAN ---" << endl;
    cout << "Bilangan pertama : ";
    cin >> bil1_154;
    cout << "Bilangan kedua : ";
    cin >> bil2_154;
    cout << bil1_154 << " * " << bil2_154  << " = ";
    return bil1_154 * bil2_154; // Mengoutput hasil perkalian
}

float bagi_154() { // Fungsi Pembagian
    cout << "\n--- PEMBAGIAN ---" << endl;
    cout << "Bilangan pertama : ";
    cin >> bil1_154;
    cout << "Bilangan kedua : ";
    cin >> bil2_154;
    cout << bil1_154 << " / " << bil2_154  << " = ";
    return bil1_154 / bil2_154; // Mengoutput hasil pembagian  
}

int main() {
    do { // Looping menu pilihan
        mulaiprogram_154();
        switch (pilih_154) { // Switch case untuk memilih menu
            case 'a':
                cout << tambah_154() << "\n" << endl; // Menjalankan fungsi penjumlahan jika a dipilih 
                break;
            case 'b':
                cout << kurang_154() << "\n" << endl; // Menjalankan fungsi pengurangan jika b dipilih 
                break;
            case 'c':
                cout << kali_154() << "\n" << endl; // Menjalankan fungsi perkalian jika c dipilih 
                break;         
            case 'd':
                cout << bagi_154() << "\n" << endl; // Menjalankan fungsi pembagian jika d dipilih
                break;
            default:
                cout << "ERROR PILIHAN INVALID \n" << endl;
                return 0;
        }
    } while (pilih_154 != 0); // Looping akan terus berjalan selama user tidak memilih 0

    return 0;
}