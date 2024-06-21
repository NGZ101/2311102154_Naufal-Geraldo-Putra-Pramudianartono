#include <iostream>

using namespace std;

int a, b, c, d, luas_154, t, keliling_154;

void logika_luas_154() {
    luas_154 = a+b+c+d;
    cout << "Luas: " << a << " + " << b << " + " << c << " + " << d << " = " << luas_154 << endl;
}

void logika_keliling_154() {
    keliling_154 = a*t;
    cout << "Keliling: " << a << " * " << t << " = " << keliling_154 << endl;
}

int main() {
    cout << "Masukkan a: ";
    cin >> a;
    cout << "Masukkan b: ";
    cin >> b;
    cout << "Masukkan c: ";
    cin >> c;
    cout << "Masukkan d: ";
    cin >> d;
    cout << "Masukkan tinggi: ";
    cin >> t;
    logika_luas_154();
    logika_keliling_154();
}