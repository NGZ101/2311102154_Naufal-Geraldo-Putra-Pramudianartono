# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Arvinanto Bahtiar</p>

## Dasar Teori

Array adalah salah satu tipe data terstruktur yang digunakan dalam bahasa pemrograman untuk mempermudah penyimpan data karena array berisi
komponen-komponen yang memiliki tipe data yang sama. Setiap anggota array dapat diakses melalui suatu indeks. Array mempunyai beberapa
jenis seperti array 1 dimensi, array 2 dimensi dan array multidimensi, dimana masing-masing array tersebut memiliki fungsi yang berbeda dalam penggunaannya. Array 1 dimensi disebut dengan vektor, array 2 dimensi sering disebut sebagai matriks sedangkan array yang memiliki dimensi lebih dari 2(dua) yang disebut tensor.

1. Array Satu Dimensi <br/>
   Array satu dimensi tidak lain adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris, tetapi isi dari elemen tersebut boleh berbeda. Dapat disebut juga dengan istilah vektor yang menggambarkan data dalam suatu urutan.
   Deklarasi : Type_Data Nama_Variabel [index] 
   Misalnya : int A[5]; 
2. Array Dua Dimensi <br/>
   Array dua dimensi yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama. Pendeklarasian array dua dimensi hampir sama dengan pendeklarasian array satu dimensi, kecuali bahwa array dua dimensi terdapat dua jumlah elemen array yang terdapat di dalam kurung siku dan keduanya boleh tidak sama.
   Deklarasi : Type_Data Nama_Variabel [Index1] [index2]; 
   Misal : int A[3][2]
3. Array Multidimensi <br/>
   Array multi dimensi ini pada dasarnya sama dengan array sebelimnya kecuali pada jumlah dimensinya. Multidimensi mencakup array yang mempunyai lebih dari 2 indeks seperti berikut:
   - Array Tiga Dimensi <br/>
     Deklarasi : Type_Data Nama_Variabel [index1] [index2] [index3];
     Misal : int A [3][4][2];
   - Array Empat Dimensi <br/>
     Deklarasi : Type_Data Nama_Variabel [index1] i[ndex2] [index3] [index4];
     Misal : int A [3][4][2][5];
   - Array Lima Dimensi <br/>
     Deklarasi : Type_Data Nama_Variabel [index1] [index2] [index3] [index4];
     Misal : int A [3][4][2][5][8]; 

## Guided 

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>

using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI

int main() {
    // Deklarasi array
    int arr[2][2][3];
    // Input elemen
    for(int x = 0; x < 2; x++) {
        for(int y = 0; y < 3; y++) {
            for(int z = 0; z < 3; z++){
                cout << "Input Array ["<< x <<"] ["<< y <<"] ["<< z <<"] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for(int x = 0; x < 2; x++) {
        for(int y = 0; y < 3; y++) {
            for(int z = 0; z < 3; z++) {
                cout << "Data Array ["<< x <<"] ["<< y <<"] ["<< z <<"] =" << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for(int x = 0; x < 2; x++) {
        for(int y = 0; y < 3; y++) {
            for(int z = 0; z < 3; z++) {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```

Kode di atas merupakan program untuk menampilkan array tiga dimensi dengan 2 baris, 3 kolom dan 3 irisan. User dapat menentukan elemen ketiga dimensi array di atas lalu program akan mengoutputkan input user dan menampilkan array tiga dimensi.

### 2. Program Mencari Nilai Maksimal pada Array

```C++
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
```

Kode di atas merupakan program untuk mencetak elemen terbesar dan lokasinya pada suatu array. User bermulai dengan menginput panjang array lalu menginput elemen array, perulangan input elemen bedasarkan berapa banyak panjang yang user input. Lalu, menentukan nilai terbesar dan lokasinya dengan cara mengecek semua elemen array mulai dari elemen pertama atau array[0]. Jika array[i] lebih besar dari maks, maka nilai maks diperbarui dengan nilai array[i], dan lokasi diperbarui dengan indeks i.

## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

```C++
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
    int i_genap_154 = 0; // kedua index tersebut harus diinisialisasi bernilai 0 jika tidak akan terjadi segmentation fault (error)
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
```

#### Output:
![Output Unguided-1 ](<Unguided-1(Pertemuan-2)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)

Kode di atas digunakan untuk melainkan antara nilai genap dan ganjil pada suatu array. Program dimulai dengan penentuan ukuran dan elemen array oleh user lalu akan terjadi for loop array. setelah itu, setiap elemen array akan terjadi pengecekan nilai dengan cara membagi setiap elemen dengan 2 dan jika bersisa 0 maka elemen tersebut genap dan jika tidak elemen tersebut ganjil. Lalu elemen array, genap, dan ganjil akan ditampilkan.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
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
```

#### Output:
![Output Unguided-2](<Unguided-2(Pertemuan-2)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)

Kode di atas membuat array dengan tiga dimensi dimana user dapat menentukan ukuran dan elemen pada baris, kolom, dan irisan pada array. Program dimulai dengan penentuan baris, kolom, irisan oleh user lalu penentuan elemen dalam ketiga dimensi tersebut dan output program adalah tampilan array tiga dimensi.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!

```C++
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

char pilih_154, pilih2_154;
int i_154, ukuran_154, maks_154, min_154, rata_154;
double total_154;

// Fungsi menampilkan input ukuran 
void awal_154() {
    cout << "Masukkan ukuran array: ";
    cin >> ukuran_154;
}

// Fungsi menampilkan menu pilihan awal 
void menu_154() {
    cout << "A. Cari nilai maksimum \n";
    cout << "B. Cari nilai minimum \n";
    cout << "C. Cari nilai rata-rata \n";
    cout << "Pilihan anda: ";
    cin >> pilih_154;
    pilih_154 = toupper(pilih_154);
}

// Fungsi menampilkan menu pilihan pengurangan program
void akhir_154() {
    cout << "Apakah anda ingin mulai dari ulang ? (Y/N)";
    cin >> pilih2_154;
    pilih2_154 = toupper(pilih2_154);
}


int main() {
    start: // Destinasi untuk goto pada fungsi akhir jika memilih 'Y'
    awal_154();
    int array_154[ukuran_154];
    for (i_154 = 0; i_154 < ukuran_154; i_154++) {
        cout << "Input bilangan ke-" << i_154 + 1 <<" : ";
        cin >> array_154[i_154];
    }
    menu_154();
    switch (pilih_154) { // Switch case untuk pemilihan menu awal
    case 'A': // Menentukan nilai terbesar 
        maks_154 = array_154[0];
        for (i_154 = 0; i_154 < ukuran_154; i_154++) {
            if (array_154[i_154] > maks_154) {
                maks_154= array_154[i_154]; // Untuk bagian ini maks_154 harus didepan array jika tidak akan error
            }
        }
        cout << "Nilai maksimum adalah " << maks_154 << endl;
        break;
    case 'B': // Menentukan nilai terkecil
        min_154 = array_154[0];
        for (i_154 = 0; i_154 < ukuran_154; i_154++) {
            if (array_154[i_154] < min_154) {
                min_154= array_154[i_154]; // Untuk bagian ini min_154 harus didepan array jika tidak akan error
            }
        }
        cout << "Nilai minimum adalah " << min_154 << endl;
        break;
    case 'C': // Menentukan nilai rata-rata
        for (i_154 = 0; i_154 < ukuran_154; i_154++) {
            total_154 += array_154[i_154];
            rata_154 = total_154 / ukuran_154;
        }
        cout << "Nilai rata-rata adalah " << setprecision(2) << rata_154 << endl;
        break;
    default:
        cout << "ERROR MASUKKAN PILIHAN YANG VALID \n";
        break;
    }

    start2: // Destinasi goto pada bagian default
    akhir_154();
    switch (pilih2_154) {
    case 'Y':
        goto start;
        break;
    case 'N':
        cout << "Selamat Tinggal \n";
        break;
    default:
        cout << "ERROR PILIHAN INVALID \n";
        goto start2;
        break;
    }
}
```

#### Output:
![Output Unguided-3](<Unguided-3(Pertemuan-2)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)

Kode di atas merupakan program yang dapat menentukan nilai terbesar, terkecil, dan rata rata pada elemen array. Program dimulai dengan penentuan ukuran array lalu masuk ke dalam for loop array dimana user dapat menginput elemen dalam array. Kemudian user akan masuk ke dalam menu dimana mereka dapat memilih dari A sampai C, jika A terpilih maka program akan menggunakan logika pencari maks, jika B terpilih program akan menggunakan pencari min, jika C terpilih maka program akan menggunakan logika pencari rata-rata. Pada bagian akhir, user diberi pilihan untuk mengulangi program atau tidak. Jika user memilih 'Y' maka program akan berulang dan jika user memilih 'N' maka program mengoutpukan "Selamat Tinggal".


## Kesimpulan
Array adalah tipe data pemograman penting yang digunakan untuk mempermudah penyimpan data karena array berisi
komponen-komponen yang memiliki tipe data yang sama. Setiap data dalam array memiliki indeks, sehingga mudah untuk diproses.
Array secara umum dapat berbentuk:
 - Satu dimensi (Type_Data Nama_Variabel [Index1];)
 - Dua dimensi (Type_Data Nama_Variabel [Index1][Index2];)
 - Multidimensi (Type_Data Nama_Variabel [Index1][Index2][Index3][Index4][Index5]......;)

## Referensi
[1] Pratama,Muhammad Aldi. "STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++" (2020).<br/>
[2] Putri, Meidyan Permata, et al., "Algoritma dan Struktur Data" (2022).<br/>
