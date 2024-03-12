# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Arvinanto Bahtiar</p>

## Dasar Teori

"Tipe data adalah adalah sebuah pengklasifikasian data berdasarkan jenis data. Tipe data digunakan untuk menampung data sementara.

A. Tipe data Primitif
   Tipe data primitif adalah tipe data yang sudah ditentukan oleh sistem, tipe data
   primitif ini disediakan oleh banyak bahasa pemrograman. Contoh tipe data primitif:
   -Int (Bilangan bulat)
   -Float (Bilangan desimal)
   -Char (Huruf)
   -Boolean (True/False)"
B. Tipe data Abstrak
   Tipe data abstrak  merupakan tipe data yang dibentuk oleh 
   programer itu sendiri. Pada tipe data abstrak bisa berisi
   banyak tipe data, jadi nilainya bisa lebih dari satu dan beragam tipe data. 
   -Class
    Suatu konsep dari Object Oriented Programming (OOP) yang
    berfungsi sebagai tempat untuk mengumpulkan tipe data ke dalam
    suatu kelas data dan menjadi deskripsi suatu objek 
    yang bersifat private (tertutup) secara default.
   -Struct 
    Berfungsi sebagai tempat untuk mengumpulkan tipe data ke dalam 
    sebuah struktur data dan menjadi bagian dari data yang baru
    yang bersifat public (terbuka) secara default.
C. Tipe Data Koleksi
   -Array 
    struktur data statis yang menyimpan elemen-elemen dengan tipe data yang sama
   -Vector 
    vector mirip seperti array yang memiliki kemampuan untuk menyimpan data dalam bentuk elemen-elemen yang alokasi memorinya dilakukan otomatis dan bersebelahan
   -Map 
    Map terasa mirip dengan array namun dengan index yang memungkinkan untuk berupa tipe data selain integer"

## Guided 

### 1. [Tipe Data Primitif]

```C++
#include <iostream>
#include <iomanip>

using namespace std;

// Tipe Data Primitif

int main(){
    char op;
    float num1, num2;

    // it allows user to enter operator i.e. +,-,*,/
    cout << "Enter operator (+,-,*,/)";
    cin >> op;

    // it allows user to enter the operands
    cout << "Enter 2 operands: ";
    cin >> num1 >> num2;

    // switch statements begins
    switch (op)
    {
    case '+' :
        cout << "Result: " << num1+num2;
        break;
    case '-' :
        cout << "Result: " << num1-num2;
        break;
    case '*' :
        cout << "Result: " << num1*num2;
        break;
    case '/' :
        if(num2 !=0){
            cout << "Result: " << num1/num2;
        }
        else{
            cout << "ERROR! DEVISION BY 0 IS NOT ALLOWED";
        }
        break; 
    // if the operator is other than +, -, * or /,
    // error message will display
    default:
       cout << "ERROR! OPERATOR NOT CORRECT";
        break;
    } // switch statement ends
    return 0;
}

"Kode di atas mempnyai 4 operasi, yaitu: penjumlahan (+), pengurangan (-), perkalian (*), dan pembagian (/). User dapat menginput salah satu simbol operator lalu menginput 2 bilangan yang ingin dihitung. Program ini menggunkan data primitif char untuk membolehkan user memilih simbol operator dan data primitif float untuk perhitungan kedua bilangan yang diinput user."

### 2. [Tipe Data Abstrak]

```C++
#include <stdio.h>
#include <string.h>

// Struct
struct Mahasiswa{
    char name[50];
    char address[100];
    int age;
};

// Tipe Data Abstrak

int main(){
    struct Mahasiswa mhs1, mhs2;

    // Menggunakan Struct
    strcpy(mhs1.name, "Dian");
    strcpy(mhs1.address, "Mataram");
    mhs1.age =22;
    
    // Mengisi nilai ke struct
    strcpy(mhs2.name, "Bambang");
    strcpy(mhs2.address, "Surabaya");
    mhs2.age =23;
    
    // Mencetak isi dari struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}

"Kode di atas merupakan program untuk mencetak struct, yaitu salah satu tipe data abstrak. Dalam struct mahasiswa berisi tipe data char name dengan ukuran 50, char address dengan ukuran 50, dan int age. Dalam int main struct mahasiswa dideklarasikan dengan 2 objek yaitu mh1 dan mh2 lalu bagian name, address, dan age diisi."

### 3. Tipe Data Koleksi

```C++
#include <iostream>
#include <array>
using namespace std;

// Tipe Data Koleksi

int main (){
    // Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;
    
    // Deklarasi dan inisialisasi array
    cout << "Isi array pertama : "<< nilai[0]<<endl;
    cout << "Isi array kedua : "<< nilai[1]<<endl;
    cout << "Isi array ketiga : "<< nilai[2]<<endl;
    cout << "Isi array keempat : "<< nilai[3]<<endl;
    cout << "Isi array kelima : "<< nilai[4]<<endl;
    
    return 0;
}

"Kode di atas merupakan program untuk mengoutputkan array, yaitu salah satu tipe data koleksi. #include <array> diperlukan untuk menggunakan fungsi array.Array diatas nilai menampung lima nilai: 23, 50, 34, 78, dan 90, lalu dideklarasikan"

## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
#include <iostream>
#include <cctype> // Untuk input tolower() (dan toupper()) agar input user dapat dibaca walaupun user memakai huruf besar

using namespace std;

char pilih_154; // Data primitif 1 huruf untuk menu
float bil1_154, bil2_154; // Data primitif float untuk menginput 2 bilangan

void mulaiprogram_154() { // Fungsi untuk menampilkan menu pilihan
    cout << "PROGRAM KALKULATOR 2 BILANGAN \n";
    cout << "a. Penjumlahan (+) \n";
    cout << "b. Pengurangan (-) \n";
    cout << "c. Perkalian (*) \n";
    cout << "d. Pembagian (/) \n";
    cout << "Masukkan Pilihan : ";
    cin >> pilih_154;
    pilih_154 = tolower(pilih_154);
}

float tambah_154() { // Fungsi Penjumlahan
    cout << "\n--- PENJUMLAHAN ---" << endl;
    cout << "Bilangan pertama : ";
    cin >> bil1_154;
    cout << "Bilangan kedua : ";
    cin >> bil2_154;
    cout << bil1_154 << " + " << bil2_154  << " = ";
    return bil1_154 + bil2_154; // Mengoutput hasil penjumlahan
}

float kurang_154() { // Fungsi Pengurangan
    cout << "\n--- PENGURANGAN ---" << endl;
    cout << "Bilangan pertama : ";
    cin >> bil1_154;
    cout << "Bilangan kedua : ";
    cin >> bil2_154;
    cout << bil1_154 << " - " << bil2_154  << " = ";
    return bil1_154 - bil2_154; // Mengoutput hasil pengurangan
}

float kali_154() { // Fungsi Perkalian
    cout << "\n--- PERKALIAN ---" << endl;
    cout << "Bilangan pertama : ";
    cin >> bil1_154;
    cout << "Bilangan kedua : ";
    cin >> bil2_154;
    cout << bil1_154 << " * " << bil2_154  << " = ";
    return bil1_154 * bil2_154; // Mengoutput hasil perkalian
}

float bagi_154() { // Fungsi Pembagian
    cout << "\n--- PEMBAGIAN ---" << endl;
    cout << "Bilangan pertama : ";
    cin >> bil1_154;
    cout << "Bilangan kedua : ";
    cin >> bil2_154;
    cout << bil1_154 << " / " << bil2_154  << " = ";
    return bil1_154 / bil2_154; // Mengoutput hasil pembagian  
}

int main() {
    do { // Looping menu pilihan
        mulaiprogram_154();
        switch (pilih_154) { // Switch case untuk memilih menu
            case 'a':
                cout << tambah_154() << "\n" << endl; // Menjalankan fungsi penjumlahan jika a dipilih 
                break;
            case 'b':
                cout << kurang_154() << "\n" << endl; // Menjalankan fungsi pengurangan jika b dipilih 
                break;
            case 'c':
                cout << kali_154() << "\n" << endl; // Menjalankan fungsi perkalian jika c dipilih 
                break;         
            case 'd':
                cout << bagi_154() << "\n" << endl; // Menjalankan fungsi pembagian jika d dipilih
                break;
            default:
                cout << "ERROR PILIHAN INVALID \n" << endl;
                return 0;
        }
    } while (pilih_154 != 0); // Looping akan terus berjalan selama user tidak memilih 0

    return 0;
}

#### Output:
![Output Unguided-1](<Unguided-1_2311102154_Naufal Geraldo Putra Pramudianartono-1.png>)

"Kode di atas mempnyai 4 pilihan, yaitu: penjumlahan (+), pengurangan (-), perkalian (*), dan pembagian (/). User dapat memilih dari menu dan menginput a sampai d lalu menginput 2 bilangan yang ingin dihitung. Program ini menggunkan 4 fungsi dan 1 prosedur, 4 fungsi tersebut untuk logika rumus dan 1 prosedur untuk memulai program dan menampilkan menu awal. Program ini akan berulang selama user tidak menginput 0 karena adanya perulangan do while. Program ini juga menggunakan #include <cctype> dan tolower() untuk mengubah input huruf besar menjadi huruf kecil supaya program dapat membaca input walaupun user secara tidak sengaja memencet caps lock.

Kesimpulan Tipe Data Primitif:
Tipe data primitif merupakan tipe data yang berada pada default yang disediakan bahasa pemograman dan sangat penting untuk penampungan data sederhana." 

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!]

```C++
#include <iostream>

using namespace std;

// Struct User_154 yang berisi data nama string, tempatlahir string, umur int, dan agama string dalam akses public
class user_154{
    public:
    string nama_154;
    string tempatlahir_154;
    int usia_154;
    string agama_154;
};

// Class usercontact_154 yang berisi data email string, instagram string, dan twitter string
struct usercontact_154 {
    string email_154;   
    string instagram_154;
    string twitter_154;
};

int main() {
    cout << "== Contoh Struct and Class ==" << endl;

    // Deklarasi Struct user_154
    user_154 pengguna{"Naufal Geraldo Putra Pramudianartono", "Jakarta", 18, "Islam",};
    cout << "\n - Biografi Pengguna - " << endl;
    cout << "Nama: " << pengguna.nama_154 << endl;
    cout << "Tempat Lahir: " << pengguna.tempatlahir_154 << endl;
    cout << "Usia: " << pengguna.usia_154 << endl;
    cout << "Agama: " << pengguna.agama_154 << endl;

    // Deklarasi Class usercontact_154
    usercontact_154 kontak ;
    kontak.email_154 = "naufal.geraldo30@gmail.com";
    kontak.instagram_154 = "@NGZ30";
    kontak.twitter_154 = "@NGonX";
    cout << "\n - Info Kontak Pengguna -" << endl;
    cout << "Email: " << kontak.email_154 << endl;
    cout << "Instagram: " << kontak.instagram_154 << endl;
    cout << "Twitter: " << kontak.twitter_154 << endl;
    return 0;
}

#### Output:
![Output Unguided-2](<Unguided-2_2311102154_Naufal Geraldo Putra Pramudianartono.png>)

"Kode di atas digunakan merupakan program yang mengoutputkan class dan struct. Dalam class user_154 menampung 3 variabel string dan 1 int. 3 variabel string: nama_154, tempatlahir_154, dan agama_154. 1 variabel int: usia_154. Dalam struct sercontact_154 menampung 3 variabel string yaitu: email_154, instagram_154, twitter_154. Class dan struct kemudian diisi dengan nilai pengguna untuk class dan kontak untuk struct.

Fungsi Class:
Suatu konsep dari Object Oriented Programming (OOP) yang
Berfungsi sebagai tempat untuk mengumpulkan tipe data ke dalam
suatu kelas data dan menjadi deskripsi suatu objek 
yang bersifat private (tertutup) secara default.

Fungsi Struct:
Berfungsi sebagai tempat untuk mengumpulkan tipe data ke dalam 
sebuah struktur data dan menjadi bagian dari data yang baru
yang bersifat public (terbuka) secara default."

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!]

```C++
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

#### Output:
![Output Unguided-3](<Unguided-3_2311102154_Naufal Geraldo Putra Pramudianartono.png>)

"Kode di atas merupakan program untuk mengoutputkan sebuah map. Pada kode di atas, terdapat sebuah map game_154 dengan key yang bersifat int dan value bersifat string. Ada 5 lima elemen yang berisi game yang dijual di Steam. Lalu perulangan for digunakan untuk menampilkan semua elemen.

= Array
  - Hanya dapat menggunakan tipe data primitif
  - Harus menggunakan bilangan bulat non-negatif dan mulai berurutan dari 0
  - Harus dideklarasikan dengan ukuran yang tetap

= Map
  - Dapat menggunakan tipe data apapun
  - Dapat menggunakan nilai berapa pun 
  - Map dapat dideklarasikan dengan ukuran yang dinamis"

## Kesimpulan
"Tipe data adalah bagian pemograman yang sangat penting karena dapat menentukan jenis nilai yang disimpan sangat berguna agar sistem tidak bingung. Sebagai programmer, memahami tipe data membantu kita koding lebih efisien, akurat, dan mudah."

## Referensi
[1] Musiafa, Zayid. "STRUKTUR DATA DAN IMPLEMENTASI ALGORITMA (SDIA): Pemrograman Python C C++ Java" (2022)
[2] Putra, Muhammad Taufik Dwi, Munawir Munawir, and Ana Rahma Yuniarti. "BELAJAR PEMROGRAMAN LANJUT DENGAN C++." (2023).
