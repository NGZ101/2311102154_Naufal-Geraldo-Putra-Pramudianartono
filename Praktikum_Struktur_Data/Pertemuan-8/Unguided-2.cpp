#include <iostream>
#include <cctype>

 using namespace std;

string kalimat_154;
int banyak_vokal_154;

// Fungsi untuk mencari dan menghitung huruf vokal dalam kalimat
void cari_vokal_154(string kalimat_154) {
  for(int i = 0; i < kalimat_154.length(); i++ ) { // Loop untuk memeriksa setiap karakter dalam kalimat
    char vokal_154 = tolower(kalimat_154[i]);
    if(vokal_154 == 'a'|| vokal_154 == 'i'|| vokal_154 == 'u'|| vokal_154 == 'e'|| vokal_154 == 'o' ) { // Memeriksa apakah karakter adalah huruf vokal
        banyak_vokal_154++; // Menambah jumlah huruf vokal jika ditemukan
    }
  }

  // Menampilkan jumlah huruf vokal jika ditemukan atau tidak ditemukan
  if(banyak_vokal_154 > 0) {
    cout << "Kalimat: " << kalimat_154 << " memiliki " << banyak_vokal_154 << " huruf vokal" << endl;
  }
  else {
    cout << "Kalimat " << kalimat_154 << " tidak memiliki huruf vokal" << endl;
  }
}

int main() {
    cout << "==== Program Pencari Huruf Vokal Naufal Geraldo ====" << endl;
    cout << "Masukkan Kalimat: ";
    getline(cin, kalimat_154);
    
    cari_vokal_154(kalimat_154);

    return 0;
}