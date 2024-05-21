#include <iostream>
#include <cctype> 

using namespace std;

string kalimat_154;
char cari_huruf_154;

// Fungsi untuk melakukan binary search pada sebuah string
int binarySearch_154(string kalimat, char cari) {
    int awal = 0;
    int akhir = kalimat.length() - 1;

    // Konversi huruf yang dicari ke huruf kapital
    cari = toupper(cari);

    while (awal <= akhir) {
        int tengah = (awal + akhir) / 2;

        // Konversi huruf pada posisi tengah ke huruf kapital
        char hurufTengah = toupper(kalimat[tengah]);

        if (hurufTengah == cari) {
            return tengah; // Huruf ditemukan pada indeks tengah
        } else if (hurufTengah < cari) {
            awal = tengah + 1; // Cari di bagian kanan
        } else {
            akhir = tengah - 1; // Cari di bagian kiri
        }
    }

    return -1; // Huruf tidak ditemukan
}

int main() {
    cout << "==== Program Pencari Char Naufal Geraldo ====" << endl;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat_154);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> cari_huruf_154;

    int posisi_154 = binarySearch_154(kalimat_154, cari_huruf_154);

    if (posisi_154 != -1) {
        cout << "Huruf '" << cari_huruf_154 << "' ditemukan pada posisi " << posisi_154 << " dalam kalimat." << endl;
    } else {
        cout << "Huruf '" << cari_huruf_154 << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}