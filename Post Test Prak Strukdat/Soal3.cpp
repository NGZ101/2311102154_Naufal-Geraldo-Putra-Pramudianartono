#include <iostream>

using namespace std;

float kelvin, celcius, naufal_2311102154 = 273.15;

void kelvin_to_celcius() {
    cout << "Masukkan kelvin: ";
    cin >> kelvin;
    celcius = kelvin - naufal_2311102154;
    cout << "Celcius: " << kelvin  << " - 273.15 = " << celcius;
}

void celcius_to_kelvin() {
    cout << "Masukkan celcius: ";
    cin >> celcius;
    kelvin = celcius + naufal_2311102154;
    cout << "Kelvin: " << celcius << "+ 273.15 = " << kelvin;
}

int main() {
    int pilihan;
    cout << "Pilih jenis konversi suhu:" << endl;
    cout << "1. Kelvin ke Celcius" << endl;
    cout << "2. Celcius ke Kelvin" << endl;
    cout << "Masukkan pilihan (1 atau 2): ";
    cin >> pilihan;

    if (pilihan == 1) {
        kelvin_to_celcius();
    } else if (pilihan == 2) {
        celcius_to_kelvin();
    } else {
        cout << "Pilihan tidak valid." << endl;
    }

    return 0;
}