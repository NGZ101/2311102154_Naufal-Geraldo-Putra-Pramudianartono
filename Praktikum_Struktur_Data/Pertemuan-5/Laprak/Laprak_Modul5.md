# <h1 align="center">Laporan Praktikum Modul Hashed Table</h1>

<p align="center">Arvinanto Bahtiar</p>

## Dasar Teori

Hashing adalah  teknik untuk melakukan penambahan, penghapusan dan pencarian dengan constant average time. Untuk menambahkan dat aatau pencarian, ditentukan key dari data tersebut dan digunakan sebuah fungsi hash untuk menetapkan lokasi untuk key tersebut. <br/>
Hash table adalah arrays dengan sel-sel yang ukurannya telah ditentukan dan dapat berisi data atau key yang berkesesuaian dengan data. Untuk setiap key, digunakan fungsi hash untuk memetakan key pada bilangan dalam rentang 0 hingga H-size-I. <br/>

### Fungsi Hash Table <br/>
    Hash Table menggunakan fungsi hash untuk memetakan nilai yang diberikan dengan kunci tertentu ke indeks dalam array. Fungsi hash ini harus menghasilkan nilai yang unik untuk setiap kunci yang berbeda, sehingga elemen-elemen dapat disimpan dengan benar.

### Operasi Hash Table <br/>
    - Insertion <br/>
      Digunakan untuk menambah data baru ke dalam hashed table. Elemen baru akan ditempatkan pada indeks yang dihasilkan oleh fungsi hash.
    - Deletion <br/>
      Digunakan untuk menghapus suatu data yang berada dalam hashed table. Elemen yang dihapus akan dihapus dari indeks yang dihasilkan oleh fungsi hash.
    - Searching <br/>
      Digunakan untuk mencari data yang spesifik yang ada dalam hashed table bedasarkan kunci atau indeksnya. Pencarian dilakukan dengan menggunakan fungsi hash untuk menghasilkan indeks elemen yang dicari.
    - Update <br/>
      Digunakan untuk mengubah data yang sudah ada dalam hashed table menjadi data baru. Nilai elemen dapat diubah berdasarkan kunci atau indeksnya.
    - Traversal <br/>
      Digunakan untuk menampilkan seluruh data pada hashed table
### Collision Resolution <br/>
    Collision terjadi ketika dua atau lebih elemen memiliki indeks yang sama setelah melalui fungsi hash. Operasi ini digunakan untuk menangani collision dan memastikan bahwa elemen-elemen dengan indeks yang sama dapat disimpan dan diakses dengan benar.
    - Open Hashing (Chaining) <br/>
      Permasalahan collision diselesaikan dengan menambahkan seluruh elemen yang memilih nilai hash sama pada sebuah set. Open Hashing menyediakan sebuah linked list untuk setiap elemen yang memiliki hash sama. Tiap sel pada hash tableberisi pointer ke sebuah linked list yang berisi data/elemen.
    - Closed Hashing <br/>
      1. Linear Probing <br/>
         Pada saat terjadi collision, maka akan mencari posisi yang kosong di bawah tempat terjadinya collision, jika masih penuh terus ke bawah, hingga ketemu tempat yang kosong. Jika tidak ada tempat yang kosong berarti HashTable sudah penuh.
      2. Quadratic Probing <br/>
         Penanganannya hampir sama dengan metode linear, hanya lompatannya tidak satu-satu, tetapi quadratic ( 12, 22, 32, 42, ... )
      3. Double Hashing <br/>
         Pada saat terjadi collision, terdapat fungsi hash yang kedua untuk menentukan posisinya kembali.

## Guided

### 1. Guided I

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key) {
    return key & MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
    private:
        Node** table;
    public:
        HashTable() {
            table = new Node*[MAX_SIZE] ();
        }
        ~HashTable() { 
            for (int i = 0; i < MAX_SIZE; i++) {
                Node* current = table[1];
                while (current != nullptr) {
                    Node* temp = current;
                    current = current -> next;
                    delete temp;
                }
            }
            delete[] table;
            }

            // insertion
            void insert(int key, int value) {
                int index = hash_func(key);
                Node* current = table[index];
                while (current != nullptr) {
                    if (current -> key == key) {
                        current -> value = value;
                        return;
                    }
                    current = current -> next;
                }
                Node* node = new Node(key, value);
                node -> next = table[index];
                table[index] = node;
            }

            // Searching
            int get (int key) {
                int index = hash_func(key);
                Node* current = table[index];
                while (current != nullptr) {
                    if (current -> key == key) {
                        return current -> value;
                    }
                    current = current -> next;
                }
                return -1;
            }

            // Deletion
            void remove(int key) {
                int index = hash_func(key);
                Node* current = table[index];
                Node* prev = nullptr;
                while (current != nullptr) {
                    if (current -> key == key) {
                        if (prev == nullptr) {
                            table[index] = current -> next;
                        } else {
                            prev -> next = current -> next;
                        }
                        delete current;
                        return;
                    }
                    prev = current;
                    current = current -> next;
                }
            }

            // Traversal
            void traverse() {
                for (int i = 0; i < MAX_SIZE; i++) {
                    Node* current = table[i];
                    while (current != nullptr) {
                        cout << current -> key << ": " << current -> value << endl;
                        current = current -> next;
                    }
                }
            }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1,10);
    ht.insert(2,20);
    ht.insert(3,30);

    //Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    //Deletion
    ht.remove(4);

    //Traversal
    ht.traverse();
}
```

Kode di atas menampilkan penggunaan hashed table dan operatornya seperti: insertion untuk memasukkan data baru, searching untuk mencari value dengan cara menginput key dari value tersebut, deletion untuk menghapus suatu data dalam hashed table, dan traverse untuk menampilkan seluruh hashed table. Pada int main(), Hashtable dideklarasikan sebagai ht. Insertion digunakan untuk menambahkan key 1,2, dan 3 yang mempunyai value 10, 20 dan 30. Lalu, deletion digunakan untuk menghapus key 4. Pada bagian akhir, traversal digunakan untuk menampilkan output yaitu:
1: 10 <br/>
2: 20 <br/>
3: 30 <br/>

### 2. Guided II

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this -> name = name;
        this -> phone_number = phone_number;
    }
};

class HashMap {
    private:
    vector <HashNode*> table[TABLE_SIZE];
    public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c: key) {
            hash_val += c;
        }
    return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for(auto node : table[hash_val]) {
            if (node -> name == name) {
                node -> phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it) -> name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name) {
    int hash_val = hashFunc(name);
    for (auto node : table[hash_val]) {
        if (node -> name == name) {
            return node -> phone_number;
        }
    }
    return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
                for (auto pair : table[i]) {
                if(pair != nullptr) {
                    cout << "[" << pair -> name << ", " << pair -> phone_number << "]";
                }
                }
                cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Nomer Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```

Kode di atas merupakan program contoh implementasi hashed table untuk penyimpanan data string nama karyawan dan int nomor telpon. void insert digunakan untuk menambahkan data string nama karyawan dan int nomor telpon. void remove digunakan untuk menghapus data, bedasarkan nama yang diinput user. void searchByName digunakan untuk mencari data bedasarkan nama yang diinput user. void print digunakan untuk menampilkan seluruh data nama dan nomor telpon. Pada int main(), Hashmap dideklarasikan sebagai employee_map. insert digunakan untuk menambah 3 data yaitu: Mistah dengan no telp 1234, Pastah dengan no telp 5678, dan Ghana dan 91011. searchByName digunakan untuk mencari data no telp Mistah dan Pastah. remove digunakan untuk menghapus data Mistah. Pada bagian akhir, print digunakan untuk menampilkan hash table dengan output:
Hash Table : <br/>
0: <br/>
1: <br/>
2: <br/>
3: <br/>
4: [Pastah, 5678] <br/>
5: <br/>
6: [Ghana, 91011] <br/>
7: <br/>
8: <br/>
9: <br/>
10: <br/>

## Unguided

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :a. Setiap mahasiswa memiliki NIM dan nilai. b. Program memiliki tampilan pilihan menu berisi poin C. c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
#include <iostream>
#include <iomanip>

using namespace std;
const int MAX_SIZE = 1000;

// Fungsi hash sederhana
int hash_func_154(int key) {
    return key & MAX_SIZE;
}

// Struktur data untuk setiap node
struct mahasiswa_154 {
    string nama_154;
    int nim_154;
    int nilai_154;
    mahasiswa_154* next;
    mahasiswa_154(string nama_154, int nim_154, int nilai_154) : nama_154(nama_154), nim_154(nim_154), nilai_154(nilai_154), next(nullptr) {}
};

// Class hash table 
class HashTable_154 {
    private:
        mahasiswa_154** table;
    public:
        HashTable_154() {
            table = new mahasiswa_154*[MAX_SIZE] ();
        }
        ~HashTable_154() {
            for (int i = 0; i < MAX_SIZE; i++) {
                mahasiswa_154* current = table[i];
                while (current != nullptr) {
                    mahasiswa_154* temp = current;
                    current = current -> next;
                    delete temp;
                }
            }
            delete[] table;
            }

            // insertion
            void insert_154(string nama_154, int nim_154, int nilai_154) {
                int index = hash_func_154(nim_154);
                mahasiswa_154* current = table[index];
                while (current != nullptr) {
                    if (current -> nim_154 == nim_154) {
                        current -> nama_154 = nama_154;
                        current -> nilai_154 = nilai_154;
                        return;
                    }
                    current = current -> next;
                }
                mahasiswa_154* node = new mahasiswa_154(nama_154, nim_154, nilai_154);
                node -> next = table[index];
                table[index] = node;
            }

            // Searching (NIM mahasiswa_154)
            mahasiswa_154* get_nim_154 (int nim_154) {
                int index = hash_func_154(nim_154);
                mahasiswa_154* current = table[index];
                while (current != nullptr) {
                    if (current -> nim_154 == nim_154) {
                        return current;
                    }
                    current = current -> next;
                }
                return nullptr;
            }

            // Searching (Nilai mahasiswa_154)
            void get_nilai (int min_nilai, int max_nilai) {
                for(int i = 0 ; i < MAX_SIZE ; i++) {
                    mahasiswa_154* current = table[i];
                    while(current != nullptr) {
                        if(current -> nilai_154 >= min_nilai && current -> nilai_154 <= max_nilai) {
                            cout << current -> nama_154 << " dengan NIM " << current -> nim_154 << " mendapat nilai " << current -> nilai_154 << endl;
                            cout << "=====================================================================================================" << endl;
                        }
                        current = current -> next;
                    }

                }
            }

            // Deletion
            void remove(int nim_154) {
                int index = hash_func_154(nim_154);
                mahasiswa_154* current = table[index];
                mahasiswa_154* prev = nullptr;
                while (current != nullptr) {
                    if (current -> nim_154 == nim_154) {
                        if (prev == nullptr) {
                            table[index] = current -> next;
                        } else {
                            prev -> next = current -> next;
                        }
                        delete current;
                        return;
                    }
                    prev = current;
                    current = current -> next;
                }
            }

            // Traversal
            void traverse() {
                cout << left << setw(15) << "=NAMA=" << setw(15) << "=NIM=" << setw(10) << "=NILAI=" << endl;
                for (int i = 0; i < MAX_SIZE; i++) {
                    mahasiswa_154* current = table[i];
                    while (current != nullptr) {
                        cout << left << setw(15) << current->nama_154 << setw(17) << current->nim_154 << setw(10) << current->nilai_154 << endl;
                        current = current -> next;
                    }
                }
            }
};

int main() {
    HashTable_154 ht;

    string nama_154;
    int pilihan;
    int nim_154, nilai_154;
    int min_nilai = 80, max_nilai = 90;
    mahasiswa_154* result = nullptr;

    do {
        cout << "\n= Menu Hash Table mahasiswa_154 =" << endl;
        cout << "1. Insert " << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Cari Data Dari NIM" << endl;
        cout << "4. Cari Data Dari Nilai" << endl;
        cout << "5. Menampilkan Hashed Table" << endl;
        cout << "6. Keluar dari program" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;
        cout << endl;
        switch(pilihan)
        {
        case 1:
            cout << "Masukkan nama mahasiswa: ";
            cin >> nama_154;
            cout << "Masukkan NIM mahasiswa: ";
            cin >> nim_154;
            cout << "Masukkan nilai mahasiswa: ";
            cin >> nilai_154;
            ht.insert_154(nama_154, nim_154, nilai_154);
            cout << "Data " << nama_154 << " dengan NIM " << nim_154 << " dan nilai " << nilai_154 << " telah ditambah" << endl;
            break;
        case 2:
            cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
            cin >> nim_154;
            ht.remove(nim_154);
            cout << "Data " << nama_154 << " dengan NIM " << nim_154 << " telah dihapus" << endl;
            break;
        case 3:
            cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
            cin >> nim_154;
            result = ht.get_nim_154(nim_154); // Jangan lupa memasukkan "result =" sebelum ht.get_nim_154 
            if (result != nullptr) {
                cout << "Data mahasiswa dengan NIM " << nim_154 << " telah ditemukan" << endl;
                cout << "Nama: " << result->nama_154 << ", Nilai: " << result->nilai_154 << endl;
            }
            else {
                cout << "Data mahasiswa dengan NIM " << nim_154 << " tidak dapat ditemukan" << endl;
            }
            break;
        case 4:
            cout << "Masukkan nilai minimum yang ingin dicari: ";
            cin >> min_nilai;
            cout << "Masukkan nilai maksimum yang ingin dicari: ";
            cin >> max_nilai;
            cout << "Nilai dari " << min_nilai << " sampai dengan " << max_nilai << endl;
            ht.get_nilai(min_nilai, max_nilai); 
            break;
        case 5:
            cout << "Penampilan Hash Table: " << endl;
            ht.traverse();
            break;
        case 6:
            cout << "Terima kasih telah menggunakan program ini" << endl;
            break;
        default:
            cout << "Pilihan anda tidak valid" << endl;
        }
        cout << endl;
    }
    while(pilihan != 6);
}
```

#### Output:
![Output Unguided 1-1](<(1) Unguided-1(Pertemuan-5)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output Unguided 1-2](<(2) Unguided-1(Pertemuan-5)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output Unguided 1-3](<(3) Unguided-1(Pertemuan-5)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output Unguided 1-4](<(4) Unguided-1(Pertemuan-5)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output Unguided 1-5](<(5) Unguided-1(Pertemuan-5)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output Unguided 1-6](<(6) Unguided-1(Pertemuan-5)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)

Kode di atas menampilkan penggunaan hashed table pada database mahasiswa yang berisi nama, nim, dan nilai. Hash table ini menggunakan operator sebagai berikut: insertion untuk memasukkan data baru, searching untuk mencari value dengan cara menginput key dari value tersebut, deletion untuk menghapus suatu data dalam hashed table, dan traverse untuk menampilkan seluruh hashed table. Pada int main(), Hashtable dideklarasikan sebagai ht. Lalu user diberi menu pilihan dari 1 sampai dengan 6. Jika memilih 1, user dapat menambahkan data baru pada hash table. Jika memilih 2, user dapat menghapus sebuah data dalah hash table bedasarkan nimnya. Jika memilih 3, user dapat menemukan data dengan pencarian NIM. Jika memilih 4, user dapat menemukan data dengan pencarian range nilai dari minimum dan maksimum yang ditentukan user. Jika memilih 5, hash table dan data di dalamnya akan ditampilkan. Jika memilih 6, progra, akan berhenti. 

## Kesimpulan

Hash table adalah arrays dengan sel-sel yang ukurannya telah ditentukan dan dapat berisi data atau key yang berkesesuaian dengan data. Hash table mempunyai beberapa operasi yaitu sebagai berikut: Insertion, Deletion, Searching, Update, dan Traversal.

## Referensi

[1] M. Josuttis, Nicolai. "C++17 The Complete Guide." (2019). <br/>
[2] Mailund, T. " The Joys of Hashing: Hash Table Programming with C. Apress." (2019) <br/>
[3] Tapia-Fernández, Santiago. , García-García, Daniel. , García-Hernandez, Pablo. "Key Concepts, Weakness and Benchmark on Hash Table
Data Structures." (2022). <br/>