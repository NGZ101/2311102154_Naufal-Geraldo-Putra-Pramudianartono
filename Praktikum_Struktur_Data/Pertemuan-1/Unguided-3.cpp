// 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map

// Naufal Geraldo Putra Pramudianartono - 2311102154


/*
Perbedaan Array dengan Map
= Array
  - Hanya dapat menggunakan tipe data primitif
  - Harus menggunakan bilangan bulat non-negatif dan mulai berurutan dari 0
  - Harus dideklarasikan dengan ukuran yang tetap


= Map
  - Dapat menggunakan tipe data apapun
  - Dapat menggunakan nilai berapa pun & tidak harus berurutan
  - Map dapat dideklarasikan dengan ukuran yang dinamis
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