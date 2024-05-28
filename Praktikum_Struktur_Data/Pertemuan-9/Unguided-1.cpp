#include <iostream>
#include <vector> 
#include <iomanip> 

using namespace std;

int main() {
    int NaufalG_2311102154; 
    cout << "==== Program Jauh Kota Naufal Geraldo ====" << endl;
    do {
    cout << "Masukkan banyak Simpul: "; 
    cin >> NaufalG_2311102154;
    vector<string> cities(NaufalG_2311102154); // vector ini digunakan untuk menyimpan nama-nama simpul
    cout << "Masukkan nama simpul" << endl;
    for(int i = 0; i < NaufalG_2311102154; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> cities[i]; // cities[i] ini digunakan untuk menyimpan nama simpul
        cout << endl;
    }
    vector<vector<int>> Matrix_2139(NaufalG_2311102154, vector<int>(NaufalG_2311102154)); // vector ini digunakan untuk menyimpan jarak antar simpul, vector<int> ini digunakan untuk menyimpan jarak antar simpul
    cout << "Berapa jauh kota ?\n";
    for(int i = 0; i < NaufalG_2311102154; i++) {
        for(int j = 0; j < NaufalG_2311102154; j++) { // perulangan ini digunakan untuk menginput jarak antar simpul
            cout << cities[i] << " --> " << cities[j] << " = ";
            cin >> Matrix_2139[i][j]; // Matrix_2139 ini digunakan untuk menyimpan jarak antar simpul, i adalah simpul asal dan j adalah simpul tujuan
        }
    }
    cout << "==== Graph Jauh Kota ====";
    cout << "\n           ";
    for(const auto& city : cities) { // barisan ini digunakan untuk menampilkan nama-nama simpul, const auto& digunakan untuk mengambil nilai dari vector cities
        cout << setw(10) << city;
    }
    cout << endl;
    for(int i = 0; i < NaufalG_2311102154; ++i) { // perulangan ini digunakan untuk menampilkan jarak antar simpul
        cout << setw(10) << cities[i];
        for(int j = 0; j < NaufalG_2311102154; ++j) {
            cout << setw(10) << Matrix_2139[i][j]; // perulangan ini digunakan untuk Matrix_2139[i][j]
        }
        cout << endl;
    }
    } 
    while(NaufalG_2311102154 != 0); // perulangan ini digunakan untuk mengulang program jika NaufalG_2311102154 tidak sama dengan 0
    cout << "Terima kasih telah menggunakan program ini!";
    return 0;
}