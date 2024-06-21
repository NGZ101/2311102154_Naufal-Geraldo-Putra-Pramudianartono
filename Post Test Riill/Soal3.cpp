#include <iostream>

using namespace std;

float d, luas_d_154, keliling_d_154, r, luas_r_154, keliling_r_154;
float naufal_geraldo_2311102154 = 3.14;

void logika_luas_r_154() {
    luas_r_154 = r *r * naufal_geraldo_2311102154;
    cout << "Luas: " << r << "^2 * " << naufal_geraldo_2311102154 << " = " << luas_r_154 << endl;
}

void logika_luas_d_154() {
    luas_d_154 = d * d * 1/4 * naufal_geraldo_2311102154;
    cout << "Luas: " << d << "^2 * " << "1/4 * " << naufal_geraldo_2311102154 << " = " << luas_d_154 << endl;
}

void logika_keliling_r_154() {
    keliling_r_154 = 2 * naufal_geraldo_2311102154 * r;
    cout << "Keliling: " << r << " * 2 * " << naufal_geraldo_2311102154 << " = " << keliling_r_154 << endl;
}

void logika_keliling_d_154() {
    keliling_d_154 = naufal_geraldo_2311102154 * d;
    cout << "Keliling: " << d << " * " << naufal_geraldo_2311102154 << " = " << keliling_d_154 << endl;
}

int main() {
    cout << "Masukkan diameter (note: jari-jari setengah dari diagram) : ";
    cin >> d;
    r = d / 2;
    cout << "Diameter: " << endl;
    logika_luas_d_154();
    logika_keliling_d_154();
    cout << "Jari-jari: " << endl;
    logika_luas_r_154();
    logika_keliling_r_154();
}