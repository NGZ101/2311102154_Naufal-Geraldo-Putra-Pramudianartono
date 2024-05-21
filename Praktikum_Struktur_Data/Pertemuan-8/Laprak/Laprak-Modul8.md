# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Naufal Geraldo Putra Pramudianartono - 2311102154</p>

## Dasar Teori
Searching atau pencarian adalah menemukan nilai (data) tertentu di dalam sekumpulan data yang bertipe sama, baik bertipe dasar atau bertipe bentukan. Searching juga dapat dianggap sebagai proses pencarian suatu data di dalam sebuah array dengan cara mengecek satu persatu pada setiap index baris atau setiap index kolomnya dengan menggunakan teknik perulangan untuk melakukan pencarian data 
Terdapat 2 metode pada algoritma Searching, yaitu: <br/>

### Sequential Search
Sequential searching merupakan suatu teknik pencarian data dimana data dicari secara urut dari depan ke belakang atau dari awal sampai akhir berdasarkan key yang dicari. <br/>
- Tahapan algoritma sequential searching: 
1) i <- 0 
2) Ketemu <- false 
3) Selama (tidak ketemu) dan (i < N) kerjakan baris 4 
4) Jika (Data[i] = key) maka ketemu <- true  Jika tidak i <- i + 1 
5) Jika (Ketemu) maka i adalah indeks dari data yang dicari
Bentuk Sequential 
- Sequential Search dalam bentuk kode:
```C++
int sequential_search(int data [], int n, int k) {
    int posisi, i, ketemu;

    // Jika jumlah elemen dalam array kurang atau sama dengan 0, kembalikan -1.
    if (n <= 0)
        posisi = -1;
    else {
        ketemu = 0; // Inisialisasi variabel untuk menyimpan status ketemunya elemen.
        i = 1; // Mulai pencarian dari indeks 1 (ini mungkin bug, biasanya dari 0).
        
        // Loop untuk mencari elemen k dalam array data sampai ketemu atau mencapai akhir array.
        while ((i < n -1) && !ketemu) {
            if (data[i] == k) { // Jika elemen pada indeks i sama dengan k,
                posisi = i;     // simpan indeks posisi,
                ketemu = 1;     // dan set ketemu menjadi 1.
            } else {
                i++; // Jika tidak sama, lanjutkan ke indeks berikutnya.
            }
        }

        // Jika elemen tidak ketemu, set posisi menjadi -1.
        if (!ketemu) {
            posisi = -1;
        }
    }

    return posisi; // Kembalikan posisi elemen yang dicari, atau -1 jika tidak ketemu.
}
```

### Binary Search
Algoritma binary search merupakan sebuah teknik pencarian data dengan cara berulang kali membagi separuh dari jumlah data yang dicari sehingga memperkecil lokasi pencarian sampai menjadi satu data. <br/>
- Tahapan algoritma binary searching: 
1. l <- 1
2. r <- N
3. ketemu <- false
4. selama (l<=r) dan (not ketemu) kerjakan baris 5 sampai 8.
5. m <- (l+r) div 2
6. jika (data[m] = x) maka ketemu <- true
7. jika (x < data[m]) maka r <- m-1
8. jika (x > data[m]) maka l <- m+1.
9. if (ketemu) maka m adalah indeks dari data yang dicari, jika tidak data tidak ditemukan.

- Sequential Search dalam bentuk kode:
```C++
int binary_search(int data[], int n, int k) {
    int left, right, mid, posisi;

    left = 0;          // Batas kiri dari array
    right = n - 1;     // Batas kanan dari array
    posisi = -1;       // Inisialisasi posisi dengan -1 (jika elemen tidak ditemukan)

    // Loop untuk mencari elemen k dalam array data
    while (left <= right) {
        mid = (left + right) / 2; // Hitung indeks tengah

        if (data[mid] == k) { // Jika elemen pada indeks tengah sama dengan k,
            posisi = mid;     // simpan indeks posisi,
            break;            // dan keluar dari loop
        } else if (data[mid] < k) {
            left = mid + 1;   // Jika elemen di tengah kurang dari k, cari di sebelah kanan
        } else {
            right = mid - 1;  // Jika elemen di tengah lebih dari k, cari di sebelah kiri
        }
    }

    return posisi; // Kembalikan posisi elemen yang dicari, atau -1 jika tidak ketemu
}
```

## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.

```C++
#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // Algoritma Sequential Search
    for(i = 0; i < n; i++) {
        if(data[i] == cari) {
            ketemu = true;
            break;
        }
    }
    cout << "\t Program Sequential Search Sederhana \n" << endl;
    cout << "data: (9, 4, 1, 7, 5, 12, 4, 13, 4, 10)" << endl;
    if(ketemu) {
        cout << "\n Angka " << cari << " ditemukan pada indeks ke-" << i << endl;
    }
    else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```

#### Output:
![Output Guided 1](<Guided-1(Pertemuan-8)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)

- Deklarasi dan Inisialisasi Variabel:
1. int n = 10 Mendefinisikan panjang array data.
2. int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10} untuk inisialisasi array data dengan 10 elemen.
3. int cari = 10 adalah elemen yang akan dicari dalam array.
4. bool ketemu = false adalah variabel boolean untuk menandai apakah elemen ditemukan dalam array.
5. int i sebagai variabel untuk iterasi dalam loop.

- Algoritma Sequential Search:
1. for(i = 0; i < n; i++): Loop untuk iterasi dari indeks 0 hingga indeks terakhir array (n-1).
2. if(data[i] == cari): Memeriksa apakah elemen pada indeks i sama dengan elemen yang dicari (cari).
3. ketemu = true berarti jika elemen ditemukan, set variabel ketemu menjadi true.
4. break digunakan keluar dari loop karena elemen sudah ditemukan.

- Menampilkan Hasil:
1. if(ketemu): memeriksa apakah elemen ditemukan.
2. cout << "\n Angka " << cari << " ditemukan pada indeks ke-" << i << endl berarti jika elemen ditemukan, menampilkan pesan beserta indeks elemen tersebut.
3. cout << cari << " tidak dapat ditemukan pada data." << endl berarti jika elemen tidak ditemukan, menampilkan pesan bahwa elemen tidak ditemukan.

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int dataArray[7] = {1,8,2,5,4,9,7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for(i = 0; i < 7; i++) {
        min = i;
        for(j = i + 1; j < 7; j++) {
            if(dataArray[j] < dataArray[min]) {
                min = j;
            }
        }
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}

void binarysearch() {
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = 6; // Corrected 6 to match array bounds
    while(!b_flag && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(dataArray[tengah] == cari) {
            b_flag = true;
        }
        else if (dataArray[tengah] < cari) {
            awal = tengah + 1;
        }
        else {
            akhir = tengah - 1;
        }
    }
    if(b_flag) {
        cout << "\n Data ditemukan pada indeks ke- " << tengah << endl;
    }
    else {
        cout << "\n Data tidak ditemukan \n";
    }
}

int main() {
    cout << "\t BINARY SEARCH" << endl;
    cout << "\n Data: ";

    //Tampilkan data awal
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    cout << "\n Masukkan data yang ingin Anda cari: ";
    cin >> cari;

    cout << "\n Data diurutkan: ";

    //Urutkan data dengan selection sort
    selection_sort();

    //Tampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    binarysearch();
    
    _getche();
    return 0;
}
```

#### Output:
![Output Guided 2](<Guided-2(Pertemuan-8)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)

- selection_sort()
Fungsi ini melakukan pengurutan array menggunakan algoritma Selection Sort untuk mengurutkan array dari nilai terkecil ke terbesar.

- binarysearch()
1. Fungsi ini melakukan pencarian elemen dalam array yang sudah diurutkan menggunakan algoritma Binary Search.
2. Algoritma ini bekerja dengan membagi array menjadi dua bagian dan memeriksa apakah elemen yang dicari berada di bagian kiri atau kanan array.
3. Jika ditemukan, maka variabel b_flag akan diubah menjadi true dan indeks elemen tersebut akan disimpan di variabel tengah. Jika tidak, pencarian akan terus dilakukan sampai seluruh bagian dari array diperiksa.

- Fungsi main()
1. Menampilkan judul program dan data awal array.
2. Meminta pengguna memasukkan elemen yang ingin dicari.
3. Mengurutkan array menggunakan selection_sort().
4. Menampilkan data setelah diurutkan.
5. Melakukan pencarian menggunakan binarysearch() dan menampilkan hasilnya.
6. Fungsi i_getche() digunakan untuk menahan tampilan layar agar hasil pencarian tidak langsung hilang.
7. Setelah menampilkan hasil pencarian, program akan menunggu hingga pengguna menekan tombol apapun sebelum keluar.

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <cctype> 

using namespace std;

string kalimat_154;
char cari_huruf_154;

// Fungsi untuk melakukan binary search pada sebuah string
int binarySearch_154(string kalimat, char cari) {
    int awal = 0;
    int akhir = kalimat.length() - 1;

    // Konversi huruf yang dicari ke huruf kapital
    cari = toupper(cari);

    while (awal <= akhir) {
        int tengah = (awal + akhir) / 2;

        // Konversi huruf pada posisi tengah ke huruf kapital
        char hurufTengah = toupper(kalimat[tengah]);

        if (hurufTengah == cari) {
            return tengah; // Huruf ditemukan pada indeks tengah
        } else if (hurufTengah < cari) {
            awal = tengah + 1; // Cari di bagian kanan
        } else {
            akhir = tengah - 1; // Cari di bagian kiri
        }
    }

    return -1; // Huruf tidak ditemukan
}

int main() {
    cout << "==== Program Pencari Char Naufal Geraldo ====" << endl;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat_154);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> cari_huruf_154;

    int posisi_154 = binarySearch_154(kalimat_154, cari_huruf_154);

    if (posisi_154 != -1) {
        cout << "Huruf '" << cari_huruf_154 << "' ditemukan pada posisi " << posisi_154 << " dalam kalimat." << endl;
    } else {
        cout << "Huruf '" << cari_huruf_154 << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}
```

#### Output:
![Output 1](<Unguided-1(Pertemuan-8)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)

- binarySearch_154(string kalimat, char cari)
1. Menginisialisasi awal dengan 0 dan akhir dengan panjang string dikurangi 1.
2. Mengonversi cari menjadi huruf kapital menggunakan toupper.
3. Memulai loop pencarian biner (while (awal <= akhir)) dengan: 
4. Menghitung indeks tengah (tengah = (awal + akhir) / 2)
5. Mengonversi huruf pada indeks tengah ke huruf kapital (hurufTengah = toupper(kalimat[tengah]))
6. Jika hurufTengah sama dengan cari, mengembalikan tengah atau huruf ditemukan pada indeks tengah
7. Lalu jika hurufTengah kurang dari cari, mengoutput awal = tengah + 1 atau cari di bagian kanan
8. Lalu jika hurufTengah lebih dari cari, mengoutput akhir = tengah - 1 atau cari di bagian kiri

- int main()
1. int main digunakan untuk menampilkan judul program
2. Memasukkan input user dengan getline(cin, kalimat_154); dan cin >> cari_huruf_154;
3. Lalu kedua input dimasukkan kedalam algoritma searching 
4. Jika posisi_154 != -1 maka akan mengoutputkan: cout << "Huruf '" << cari_huruf_154 << "' ditemukan pada posisi " << posisi_154 << " dalam kalimat." << endl;
5. Jika tidak maka akan mengoutputkan: cout << "Huruf '" << cari_huruf_154 << "' tidak ditemukan dalam kalimat." << endl;


### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
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
```

#### Output:
- Jika kalimat ada huruf vokal:
![Output 2 Ada vokal](<Unguided-2(Pertemuan-8)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
- Jika kalimat tidak ada huruf vokal
![Output 2 Tidak ada vokal](<Unguided-2(Pertemuan-8)_2311102154_Naufal Geraldo Putra Pramudianartono(2).png>)

- cari_vokal_154(kalimat_154)
1. For loop digunakan untuk memeriksa setiap karakter dalam kalimat
2. char vokal_154 = tolower(kalimat_154[i]) digunakan untuk mengubah input uppercase menjadi lowercase karena program hanya mendeteksi huruf vokal lowercase
3. if(vokal_154 == 'a'|| vokal_154 == 'i'|| vokal_154 == 'u'|| vokal_154 == 'e'|| vokal_154 == 'o' ) untuk memeriksa apakah karakter adalah huruf vokal
4. Jika iya maka banyak_vokal_154 akan ++ atau bertambah
5. Lalu jika banyak huruf vokal lebih dari 0 maka mengoutputkan: cout << "Kalimat: " << kalimat_154 << " memiliki " << banyak_vokal_154 << " huruf vokal" << endl;
6. Dan jika banyak hurud vokal tidak lebih dari 0 maka mengoutputkan: cout << "Kalimat " << kalimat_154 << " tidak memiliki huruf vokal" << endl;

- int main()
1. int main digunakan untuk menampilkan judul 
2. tempat user dapat menginput kalimat dengan getline(cin, kalimat_154); 
3. Lalu input user akan dimasukan ke dalam algoritma searching dengan memanggil fungsi cari_vokal_154(kalimat_154)

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

// Inisialisasi array dengan data yang diberikan
int data_154[10] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};

int banyak_empat_154;
int elemen_target_154 = 4;

// Fungsi untuk mencari elemen target dan menghitung jumlah kemunculannya
void cari_empat_154() {
    for(int i = 0; i < 10; i++) {
        if(elemen_target_154 == data_154[i]) { // Periksa apakah elemen saat ini sama dengan elemen target
            banyak_empat_154++; // Tambahkan jumlah jika ditemukan kecocokan
        } 
    }
    if(banyak_empat_154 > 0) {
        cout << "Banyak elemen 4 dalam data array adalah: " << banyak_empat_154;
    }
    else {
        cout << "Data array tidak memiliki elemen 4";
    }

}

int main() {
    cout << "==== Program Pencari Elemen 4 Naufal Geraldo ====" << endl;
    cout << "data: (9, 4, 1, 4, 7, 10, 5, 4, 12, 4)" << endl;
    cari_empat_154();

    return 0;
}
```

#### Output:
![Output 3](<Unguided-3(Pertemuan-8)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)

- Dekalarasi
int data_154[10] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4} dideklarasikan sebagai array data yang akan digunakan untuk soal ini

- cari_empat_154
1. for(int i = 0; i < 10; i++) adalah loop untuk mencari elemen 4 dalam array data sampai ketemu atau mencapai akhir array.
2. if(elemen_target_154 == data_154[i]) cek apabila saat ini sama dengan elemen yang dicari yaitu 4
3. Jika iya maka banyak_empat_154 akan ++ atau bertambah
4. Lalu jika total elemen 4 pada array lebih dari 0 maka akan mengoutputkan: cout << "Banyak elemen 4 dalam data array adalah: " << banyak_empat_154;
5. Dan jika total elemen 4 pada array tidak lebih dari 0 makan akan mengoutputkan: cout << "Data array tidak memiliki elemen 4";

- int main
1. int main() digunakan untuk menampilkan judul program, data array, 
2. Lalu memanggil fungsi  cari_empat_154()

## Kesimpulan
Searching merupakan proses pencarian data dalam sekumpulan data seperti array yang memiliki dua bentuk algoritma yaitu sequential search, dimana data dicari secara urut dari depan ke belakang atau dari awal sampai akhir berdasarkan key yang dicari dan binary search, dimana data dicaru dengan cara berulang kali membagi separuh dari jumlah data yang dicari sehingga memperkecil lokasi pencarian sampai menjadi satu data. 

## Referensi
[1] Siswanto, Bhakti"Implementasi Algoritma Sequential Searching padaPencarian Transaksi Bilyet Giro Wisma BCA Pondok Indah Berbasis Website." (2022)<br/>
[2] Fendyanto. "IMPLEMENTASI ALGORITMA BINARY SEARCH PADA PENCARIAN DATA JEMAAT GEREJA HKBP MANADO ." (2022)<br/>