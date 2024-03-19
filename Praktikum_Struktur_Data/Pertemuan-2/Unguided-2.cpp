#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI

int main() {

    // Deklarasi array
    int ukuran_baris_154, ukuran_kolom_154, ukuran_irisan_154, i_baris_154, i_kolom_154, i_irisan_154;
    cout << "Masukan ukuran baris: "; 
    cin >> ukuran_baris_154;
    cout << "Masukan ukuran kolom: "; 
    cin >> ukuran_kolom_154;
    cout << "Masukan ukuran irisan: "; 
    cin >> ukuran_irisan_154;
    int arr[ukuran_baris_154][ukuran_kolom_154][ukuran_irisan_154];

    // Input elemen
    for(i_baris_154 = 0; i_baris_154 < ukuran_baris_154; i_baris_154++) {
        for(i_kolom_154 = 0; i_kolom_154 < ukuran_kolom_154; i_kolom_154++) {
            for(i_irisan_154 = 0; i_irisan_154 < ukuran_irisan_154; i_irisan_154++){
                cout << "Input Array ["<< i_baris_154 <<"] ["<< i_kolom_154 <<"] ["<< i_irisan_154 <<"] = ";
                cin >> arr[i_baris_154][i_kolom_154][i_irisan_154];
            }
        }
        cout << endl;
    }

    // Tampilan array
    for(i_baris_154 = 0; i_baris_154 < ukuran_baris_154; i_baris_154++) {
        for(i_kolom_154 = 0; i_kolom_154 < ukuran_kolom_154; i_kolom_154++) {
            for(i_irisan_154 = 0; i_irisan_154 < ukuran_irisan_154; i_irisan_154++) {
                cout << arr[i_baris_154][i_kolom_154][i_irisan_154] << " " << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}