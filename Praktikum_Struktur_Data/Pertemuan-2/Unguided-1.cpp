#include <iostream>
using namespace std;

int main() {
    int i_154, ukuran_154, ukuran_ganjil_154 = 0, ukuran_genap_154 = 0; 
    /* ukuran untuk array harus diinisialisasi nilai awalnya jika tidak diinisialisasi 
    nilai awalnya, ukuran array tersebut akan dihitung dengan nilai yang tidak valid */
    // i_154 tidak butuh diinisialisasi nilai awal pada bagian karena akan terjadi pada for loop array
    //ukuran_154 akan diinisialisasi nilai awal oleh user

    // Input ukuran array
    cout << "Masukkan Ukuran Array: ";
    cin >> ukuran_154;

    // Mendeklarasikan array setelah input ukuran
    int array_154[ukuran_154];

    // Input elemen array
    cout << "Masukkan " << ukuran_154 << " angka \n";
    for(i_154 = 0; i_154 < ukuran_154; i_154++) {
        cin >> array_154[i_154];
        if (array_154[i_154] % 2 == 0) {
            ukuran_genap_154++;
        } else {
            ukuran_ganjil_154++;
        }
    }
    
    // Mendeklarasikan array genap dan ganjil setelah menghitung ukuran
    int array_genap_154[ukuran_genap_154];
    int array_ganjil_154[ukuran_ganjil_154];
    
    // Mendeklarasikan index array genap dan ganjil
    int i_genap_154 = 0; // kedua index tersebut harus diinisialisasi bernilai 0 jika tidak akan terjadi segmentation fault (program error)
    int i_ganjil_154 = 0; // karena tanpa inisialisasi, nilai awal dari indeks ini tidak dapat dipastikan

    // Memindahkan elemen-elemen array ke dalam array genap atau ganjil
    for(i_154 = 0; i_154 < ukuran_154; i_154++) {
        if(array_154[i_154] % 2 == 0) {
            array_genap_154[i_genap_154++] = array_154[i_154];
        } else {
            array_ganjil_154[i_ganjil_154++] = array_154[i_154];
        }
    }
    
    // Menampilkan array
    cout << "Array: ";
    for(i_154 = 0; i_154 < ukuran_154; i_154++) {
        cout << array_154[i_154] << " " ;
    }
    cout << endl;

    // Menampilkan array genap
    cout << "Genap: ";
    for(i_154 = 0; i_154 < ukuran_genap_154; i_154++) {
        cout << array_genap_154[i_154] << " ";
    }
    cout << endl;

    // Menampilkan array ganjil
    cout << "Ganjil: ";
    for(i_154 = 0; i_154 < ukuran_ganjil_154; i_154++) {
        cout << array_ganjil_154[i_154] << " ";
    }
    cout << endl;
    
    return 0;
}