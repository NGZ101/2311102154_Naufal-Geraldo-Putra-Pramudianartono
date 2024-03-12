// 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map

// Naufal Geraldo Putra Pramudianartono - 2311102154


/*
Perbedaan Array dengan Map
= Array
  - Hanya dapat menggunakan tipe data primitif
  - Harus menggunakan bilangan bulat non-negatif dan mulai berurutan dari 0
  - Harus dideklarasikan dengan ukuran yang tetap
  - Biasa digunakan untuk menyimpan data yang berurutan

= Map
  - Dapat menggunakan tipe data apapun
  - Dapat menggunakan nilai berapa pun & tidak harus berurutan
  - Map dapat dideklarasikan dengan ukuran yang dinamis
  - Biasa digunakan untuk menyimpan data yang tidak berurutan
1. Indeks
- Array harus bilangan bulat non-negatif & mulai berurutan dari 0
- Map dapat berupa nilai berapa pun & tidak harus berurutan
2. Ukuran
- Array harus dideklarasikan dengan ukuran yang tetap
- Map dapat dideklarasikan dengan ukuran yang dinamis
3. Tipe Data
- Array hanya dapat menggunakan tipe data primitif
- Map dapat menggunakan tipe data apapun
4. Penggunaan
- Array digunakan untuk menyimpan data yang berurutan
- Map digunakan untuk menyimpan data yang tidak berurutan dan perlu diakses berdasarkan key
*/

// Contoh Program Fungsi Map
#include <iostream>
#include <map> // Library untuk menggunakan fungsi map

using namespace std;

int main() {
    
    // Deklarasi map dengan int (key) dan string (value)
    map<int, string> game_154;
  
    // Tambahkan elemen ke dalam map
    game_154[1] = "Persona 3 Reload  $69.99";
    game_154[2] = "Baldurs Gate 3    $59.99";
    game_154[3] = "Helldivers 2      $49.99";
    game_154[4] = "Hi-Fi Rush        $29.99";
    game_154[5] = "Lethal Company    $9.99";

    cout << "== Steam Store Page ==" << endl;
    for (int i = 1; i <= game_154.size(); ++i) { // Looping untuk menampilkan semua elemen map
        cout << i << ". " << game_154[i] << endl; // Menampilkan elemen map
    }

    return 0;
}