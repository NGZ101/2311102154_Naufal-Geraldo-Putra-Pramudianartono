#include <iostream> 
using namespace std;
int main() {
    int maks, a, i=1, lokasi;

    // Input panjang array
    cout << "Masukkan panjang array: ";
    cin >> a;

    // Deklarasi array
    int array[a];

    // Input elemen array
    cout << "Masukkan " << a << " angka \n";
    for(i=0; i<a; i++) {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }

    // Logika pencari elemen terbesar dan lokasinya
    maks = array[0];
    for(i=0; i<a; i++) {
        if(array[i] > maks) {
            maks = array[i];
            lokasi = i;
        }
    }

    // Menampilkan elemen terbesar dan lokasinya
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}