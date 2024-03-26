# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Arvinanto Bahtiar</p>

## Dasar Teori

Linked List adalah struktur data yang digunakan untuk menyimpan kumpulan data. Linked List adalah salah satu struktur data paling sederhana dan paling umum. Struktur data ini dapat digunakan untuk mengimplementasikan beberapa tipe data abstrak umum lainnya. Minimalnya, setiap simpul berisi data dan referensi ke simpul berikutnya dalam urutan. Struktur ini memungkinkan penyisipan atau penghapusan elemen secara efisien dari posisi manapun. Manfaat utama dari linked list dibandingkan array biasa adalah bahwa elemen
linked list dapat dengan mudah dimasukkan atau dihapus tanpa realokasi atau reorganisasi seluruh struktur karena item data tidak perlu disimpan secara berurutan di memori atau di disk.Linked List hampir sama dengan array, kelainannya dapat terlihat pada cara penyimpanan dan pengaksesan elemen-elemennya. Sementara array menggunakan alokasi memori statis dan menyimpan elemen-elemennya secara kontigu, Linked List menggunakan alokasi memori dinamis dan menyimpan elemen-elemennya sebagai simpul-simpul yang terhubung satu sama lain melalui pointer. Ini memungkinkan Linked List untuk lebih fleksibel dalam hal ukuran dan memori, namun seringkali memiliki kompleksitas akses yang lebih tinggi daripada array. 

1. Single Linked List <br/>
   Single linked list atau biasa disebut linked list terdiri dari elemen-elemen individu, dimana masing-masing dihubungkan dengan pointer tunggal. Masing-masing elemen terdiri dari dua bagian, yaitu sebuah data dan sebuah pointer yang disebut dengan pointer next. Dengan menggunakan struktur two-member seperti ini, linked list dibentuk dengan cara menunjuk pointer next suatu elemen ke elemen yang mengikutinya.  Pointer next pada elemen terakhir merupakan NULL, yang menunjukkan akhir dari suatu list. Elemen pada awal suatu list disebut head, dan elemen terakhir dari suatu list disebut tail.

2. Double Linked List <br/>
   Elemen-elemen dihubungkan dengan dua pointer dalam satu elemen. Struktur ini menyebabkan list melintas baik ke depan maupun ke belakang. Masing-masing elemen pada double linked list terdiri dari tiga bagian, disamping data dan pointer next, masing-masing
   elemen dilengkapi dengan pointer prev yang menunjuk ke elemen sebelumnya. Double linked list dibentuk dengan menyusun sejumlah elemen sehingga pointer next menunjuk ke elemen yang mengikutinya dan pointer prev menunjuk ke elemen yang mendahuluinya. Untuk menunjukkan head dari double linked list, maka pointer prev dari elemen pertama menunjuk NULL. Untuk menunjukkan tail dari double linked list tersebut, maka pointer next dari elemen terakhir menunjuk NULL. Pada dasarnya, penggunaan Double Linked List hampir sama dengan penggunaan Single Linked List yang telah kita pelajari pada materi sebelumnya.
 
Hanya saja Double Linked List menerapkan sebuah pointer baru, yaitu prev, yang
digunakan untuk menggeser mundur selain tetap mempertahankan pointer next. 

## Guided 

### 1. Program Single Linked List

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
    
};
    Node *head;
    Node *tail;

//Instalasi Node 
void init() {
    head = NULL;
    tail = NULL;
}
// Pengecekan 
bool isEmpty() {
    if (head == NULL)
    return true;
    else
    return false;
}

// Tambah Depan
void insertDepan(int nilai) {
    // Buat Node baru
    Node *baru = new Node;
    baru -> data = nilai;
    baru -> next = NULL;
    if (isEmpty() == true) {
        head = tail = baru;
        tail -> next = NULL;
    }
    else {
        baru -> next = head;
        head = baru;

    }
    
}

// Tambah Belakang
void insertBelakang(int nilai) {
    // Buat Node baru
    Node *baru = new Node;
    baru -> data = nilai;
    baru -> next = NULL;
    if(isEmpty() == true) {
        head = tail = baru;
        tail -> next = NULL;
    }
    else {
        tail -> next = baru;
        tail = baru;
    }
}

//Hitung Jumlah List 
int hitungList() {
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while(hitung != NULL) {
        jumlah++;
        hitung = hitung -> next;
    }
    return jumlah;
}

//Tambah Tengah
void insertTengah(int data, int posisi) {
    if(posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkaun" << endl;
    }
    else if(posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else {
        Node *baru, *bantu;
        baru = new Node();
        baru -> data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi-1) {
            bantu = bantu -> next;
            nomor++;
        }
        baru -> next = bantu -> next;
        bantu -> next = baru;
    }
}

// Hapus Depan
void hapusDepan() {
    Node *hapus;
    if(isEmpty() == false) {
        if(head -> next != NULL) {
            hapus = head;
            head = head -> next;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "List kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if(isEmpty() == false) {
        if(head != tail) {
            hapus = tail;
            bantu = head;
            while(bantu -> next != tail) {
                bantu = bantu -> next;
            }
            tail = bantu;
            tail -> next = NULL;
        delete hapus;
        }
        else {
            head = tail = NULL;
        }

    }
    else {
        cout << "List Kosong!" << endl;
    }
} 

// Hapus Tengah
void hapusTengah(int posisi) {
    Node *hapus, *bantu, *bantu2;
    if(posisi < 1 || posisi > hitungList()) {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else {
        int nomor = 1;
        bantu = head;
        while(nomor <= posisi) {
            if(nomor == posisi - 1) {
                bantu2 = bantu;
            }
            if(nomor == posisi) {
                hapus = bantu;
            }
            bantu = bantu -> next;
            nomor++;
        }
        bantu2 -> next = bantu;
    delete hapus;
    }
}

//Ubah Depan
void ubahDepan(int data) {
    if(isEmpty() == false) {
        head -> data = data;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahTengah(int data, int posisi) {
    Node *bantu;
    if(isEmpty() == false) {
        if(posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if(posisi == 1) {
            cout << "psosisi bukan posisi tengah" << endl;
        }
        else {
            bantu = head;
            int nomor = 1;
            while(nomor < posisi) {
                bantu = bantu -> next;
                nomor++;
            }
            bantu -> data = data;
        }
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Belakang
void ubahBelakang(int data) {
    if (isEmpty() == false) {
        tail -> data = data;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList() {
    Node *bantu, *hapus;
    bantu = head;
    while(bantu != NULL) {
        hapus = bantu;
        bantu = bantu -> next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu;
    bantu = head;
    if(isEmpty() == false) {
        while(bantu != NULL) {
            cout << bantu -> data << ends;
            bantu = bantu -> next;
        }
        cout << endl;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3);tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```

Kode di atas merupakan program untuk menampilkan single linked list berupa integer data. 
Berikut adalah penjelasan program:
- Mulai dengan struct node <br/>
  Digunakan untuk mendeklarasikan int data dan Node* next.
- void init() <br/>
  Inisialisasikan node dengan mendeklarasikan bahawa head dan tail sebagai NULL, menandakan bahwa linked list awalnya kosong.
- bool isEmpty() <br/>
  Digunakan untuk memeriksa apakah linked list kosong sebelum melakukan operasi tertentu seperti menambah atau menghapus elemen dari linked list.
- void insertDepan(int nilai) <br/>
  Digunakan untuk menambahkan sebuah node baru dengan int nilai ke bagian depan dari linked list.
- void insertBelakang(int nilai) <br/>
  Digunakan untuk menambahkan sebuah node baru dengan int nilai ke bagian belakang dari linked list.
- int hitungList() <br/>
  Digunakan untuk menghitung jumlah elemen (node) yang terdapat dalam linked list. Fungsi ini akan melakukan traversing (penelusuran) dari awal linked list hingga akhirnya dan menghitung setiap node yang ditemui.
- void insertTengah(int data, int posisi) <br/>
  Digunakan untuk menambahkan sebuah node baru dengan int nilai ke bagian sesuai posisi yang diinginkan user dari linked list.
- void hapusDepan() <br/>
  Digunakan untuk menghapus sebuah node int nilai pada bagian depan dari linked list.
- void hapusBelakang() <br/>
  Digunakan untuk menghapus sebuah node int nilai pada bagian belakang dari linked list.
- void hapusTengah(int posisi) <br/>
  Digunakan untuk menghapus sebuah node int nilai pada bagian sesuai posisi yang diinginkan user dari linked list.
- void ubahDepan(int data) <br/>
  Digunakan mengubah nilai data pada elemen pertama dalam linked list tanpa mengubah struktur linked list itu sendiri.
- void ubahBelakang(int data) <br/>
  Digunakan mengubah nilai data pada elemen terakhir dalam linked list tanpa mengubah struktur linked list itu sendiri.
- void ubahTengah(int data, int posisi) <br/>
  Digunakan mengubah nilai data pada elemen sesuai posisi yang diinginkan user dalam linked list tanpa mengubah struktur linked list itu sendiri.
- void ubahBelakang(int data) <br/>
  Digunakan mengubah nilai data pada elemen terakhir dalam linked list tanpa mengubah struktur linked list itu sendiri.
- void clearList() <br/>
  Digunakan untuk menghapus semua elemen yang ada dalam linked list. 
- void tampil() <br/>
  Digunakan untuk menampilkan elemen pada (nilai data) yang terdapat dalam linked list secara berurutan dari awal hingga akhir.
- int main() <br/>
  Digunakan untuk mendeklarasikan fungsi-fungsi diatas.
  

### 2. Program Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode -> data = data;
        newNode -> prev = nullptr;
        newNode -> next = head;
        if(head != nullptr) {
            head -> prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if(head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head -> next;
        if (head != nullptr) {
            head -> prev = nullptr;
        }
        else {
            tail = nullptr;
        }
    }
    bool update(int oldData, int newData) {
        Node* current = head;
        while(current != nullptr) {
            if(current -> data == oldData) {
                current -> data = newData;
                return true;
            }
            current = current -> next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while(current != nullptr) {
            Node* temp = current;
            current = current -> next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while(current != nullptr) {
            cout << current -> data << " ";
            current = current -> next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while(true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: " ;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add:  ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if(!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```

Kode di atas merupakan program untuk mencetak double linked list. Data yang ada di dalam linked list tersebut dapat diinput, dihapus, diperbarui, dihapus secara keseluruhan, dan ditampilkan oleh user. Berikut adalah penjelasan program:
- class Node()
  Terdapat int data, Node* prev, dan Node* next. Class ditambahkan "public" sebelum mendeklarasikan apapun, agar program dapat membaca variabel yang dideklarasikan pada class. 
- class DoublyLinkedList()
  Terdapat Node* head dan Node* tail dan class ini digunakan untuk mendeklarasikannya sebagai nullptr dan sebagai tempat kumpulan fungsi yang akan digunakan pada program ini yaitu sebagai berikut:
  1. void push (int data) <br/>
     Digunakan untuk menambahkan data di depan
  2. void pop() <br/>
     Digunakan untuk menghapuskan data di depan
  3. void update(int oldData, int newData) <br/>
     Digunakan untuk mengubah data dengan data baru
  4. void deleteAll() <br/>
     Digunakan untuk menghapus seluruh data 
  5. void display() <br/>
     Digunakan untuk menampilkan data
- int main()
  Tempat dimana user dapat memilih dari menu switch case. User dapat memilih dari angka 1 sampai 6

## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan Usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut: a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda. b. Hapus data Akechi c. Tambahkan data berikut diantara John dan Jane: "Futaba 18" d. Tambahkan data berikut di awal: "Igor 20" e. Ubah data Michael menjadi: "Reyn 18" f. Tampilkan seluruh data

```C++
#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama_154;
    int usia_154;
    Node *next;
};
Node *head;
Node *tail;

// Inisialisasi Node
void init_154() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah linked list kosong
bool itsEmpty_154() {
    return head == NULL;
}

// Menghitung jumlah Node dalam linked list
int hitung_list_154() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Menambahkan node di depan
void input_depan_154(string nama,int usia) {
    // membuat Node baru
    Node *baru = new Node;
    baru->nama_154 = nama;
    baru->usia_154 = usia;
    baru->next = NULL;
    if (itsEmpty_154()){
        head = tail = baru;
    } 
    else {
        baru->next = head;
        head = baru;
    }
}

// Menambahkan node di tengah
void input_tengah_154(string nama, int usia, int posisi) {
    if (posisi < 1 || posisi > hitung_list_154() + 1) {
        cout << "Posisi diluar jangkauan" << endl;
    } 
    else if (posisi == 1) {
        input_depan_154(nama, usia);
    } 
    else {
        Node* baru = new Node();
        baru->nama_154 = nama;
        baru->usia_154 = usia;
        Node* bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Menambahkan node di belakang
void input_belakang_154(string nama, int usia) {
    // membuat Node baru
    Node* baru = new Node;
    baru->nama_154 = nama;
    baru->usia_154 = usia;
    baru->next = NULL;

    if (itsEmpty_154()) {
        head = tail = baru;
    } 
    else {
        tail->next = baru;
        tail = baru;
    }
}

// Hapus Node di depan
void hapus_depan_154() {
    if (!itsEmpty_154()) {
        Node *hapus = head;
        if (head == tail) {
            head = tail = NULL;
        } 
        else {
            head = head->next;
        }
        delete hapus;
    } 
    else {
        cout << "Tidak ada list yang tersedia" << endl;
    }
}

// Hapus Node di tengah
void hapus_tengah_154(int posisi) {
    if (posisi < 1 || posisi > hitung_list_154()) {
        cout << "Posisi diluar jangkauan" << endl;
    } 
    else if (posisi == 1) {
        hapus_depan_154();
    } 
    else {
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        Node *hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Hapus Node di belakang
void hapus_belakang_154(){
    if (!itsEmpty_154()) {
        if (head == tail) {
            delete head;
            head = tail = NULL;
        } 
        else {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            delete tail;
            tail = bantu;
            tail->next = NULL;
        }
    } 
    else {
        cout << "List kosong!" << endl;
    }
}

// Update Node di tengah
void ubah_tengah_154(string nama, int usia, int posisi){
    if (posisi < 1 || posisi > hitung_list_154()) {
        cout << "Posisi di luar jangkauan" << endl;
    } 
    else {
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi) {
            bantu = bantu->next;
            nomor++;
        }
        bantu->nama_154 = nama;
        bantu->usia_154 = usia;
    }
}

// Update Node di belakang
void ubah_belakang_154(string nama,int usia){
    if (!itsEmpty_154()) {
        tail->nama_154 = nama;
        tail->usia_154 = usia;
    } 
    else {
        cout << "Tidak ada list yang tersedia" << endl;
    }
}

// Hapus semua Node dalam linked list
void hapus_list_154(){
    Node *bantu = head;
    while (bantu != NULL){
        Node *hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan semua Node dalam linked list
void tampilan_154() {
    Node *bantu = head;
    cout << left << setw(10) << "Nama" << right << setw(2) << "Usia" << endl;
    if (!itsEmpty_154()) {
        while (bantu != NULL) {
            cout << left << setw(10) << bantu->nama_154 << right << setw(2) << bantu->usia_154 << endl;
            bantu = bantu->next;
        }
        cout << endl;
    } 
    else {
        cout << "Tidak ada data yang tersedia!" << endl;
    }
}

int main()
{
    init_154();
    cout << "Selamat datang di program single linked list" << endl;

    // Menambahkan data awal
    input_depan_154("Karin", 18);
    input_depan_154("Hoshino", 18);
    input_depan_154("Akechi", 20);
    input_depan_154("Yusuke", 19);
    input_depan_154("Michael", 18);
    input_depan_154("Jane", 20);
    input_depan_154("John", 19);

    int choice;
    do {
        // Menu utama program
        cout << "\n1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Masukkan pilihanmu: ";
        cin >> choice;

        switch (choice) {
            // Digunakan untuk menambah data
            case 1: {
                string nama_154;
                int usia_154;
                cout << "Masukkan nama: ";
                cin >> nama_154;
                cout << "Masukkan usia: ";
                cin >> usia_154;
                input_depan_154(nama_154, usia_154);
                break;
            }
            // Digunakan untuk menghapus data
            case 2: {
                string namaHapus;
                cout << "Masukkan nama data yang ingin dihapus: ";
                cin >> namaHapus;
                Node* temp = head;
                int posisi = 1;
                while (temp != NULL && temp->nama_154 != namaHapus) {
                    temp = temp->next;
                    posisi++;
                }
                if (temp != NULL) {
                    hapus_tengah_154(posisi);
                    cout << "Data dengan nama " << namaHapus << " berhasil dihapus." << endl;
                } 
                else {
                    cout << "Data dengan nama " << namaHapus << " tidak ditemukan." << endl;
                }
                break;
            }
            // Digunakan untuk mengganti data
            case 3: {
                string namaLama, namaBaru;
                int usiaBaru;
                cout << "Masukkan nama yang ingin diupdate: ";
                cin >> namaLama;
                cout << "Masukkan nama baru: ";
                cin >> namaBaru;
                cout << "Masukkan usia baru: ";
                cin >> usiaBaru;
                Node* temp = head;
                int posisi = 1;
                while (temp != NULL && temp->nama_154 != namaLama) {
                    temp = temp->next;
                    posisi++;
                }
                if (temp != NULL) {
                    ubah_tengah_154(namaBaru, usiaBaru, posisi);
                } 
                else {
                    cout << "Data tidak ditemukan" << endl;
                }
                break;
            }
            // Digunakan untuk menambah data pada posisi tertentu
            case 4: {
                string nama, namabaru;
                int usia;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan usia: ";
                cin >> usia;
                cout << "Masukkan nama setelah data baru: ";
                cin >> namabaru;
                Node* temp = head;
                int posisi = 1;
                while (temp != NULL && temp->nama_154 != namabaru) {
                    temp = temp->next;
                    posisi++;
                }
                if (temp != NULL) {
                    input_tengah_154(nama, usia, posisi + 1);
                } 
                else {
                    cout << "Data tidak ditemukan" << endl;
                }
                break;
            }
            // Digunakan untuk menghapus data pada posisi tertentu
            case 5: {
                int posisi;
                cout << "Masukkan posisi data yang ingin dihapus: ";
                cin >> posisi;
                hapus_tengah_154(posisi);
                break;
            }
            // Digunakan untuk menghapus seluruh linked list
            case 6: {
                hapus_list_154();
                break;
            }
            // Digunakan untuk menampilkan linked list
            case 7: {
                tampilan_154();
                break;
            }
            // Digunakan untuk keluar dari program
            case 8: {
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                break;
            }
            // Saat user menginput pilihan invalid
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}
```

#### Output:
![Tugas A](<(1) Unguided-1(Pertemuan-3)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Tugas B](<(2) Unguided-1(Pertemuan-3)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Tugas C](<(3) Unguided-1(Pertemuan-3)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Tugas D](<(4) Unguided-1(Pertemuan-3)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Tugas E](<(5) Unguided-1(Pertemuan-3)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Tugas F](<(6) Unguided-1(Pertemuan-3)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)


Kode di atas digunakan untuk menampilkan struktur data single linked list. Pengguna dapat menambah, menghapus, mengubah, dan menampilkan data di dalam daftar terkait, yang dapat diakses oleh pengguna di menu yang ditampilkan oleh program saat program berjalan. Beberapa data, seperti nama dan usia, telah disimpan di dalam daftar terkait. Pengguna dapat menampilkan data terlebih dahulu atau langsung mengubahnya dengan menggunakan menu yang ditampilkan oleh program.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>
#include <iomanip>
using namespace std;

/* Digunakan untuk mendeklarasikan 
   - string name_154
   - double harga_154
   - node prev dan next
*/
class Node {
public:
    string nama_154;
    double harga_154;
    Node* prev;
    Node* next;
};

// Digunakan untuk mendeklarasikan class double linked list
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    // inisialisasi linked list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Digunakan untuk menambahkan node baru di awal linked list
    void push_154(string nama_154, double harga_154) {
        Node* newNode = new Node;
        newNode->nama_154 = nama_154;
        newNode->harga_154 = harga_154;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    // Digunakan untuk menghapus node yang berada di awal linked list
    void pop_154() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    // Digunakan untuk memperbarui data produk berdasarkan nama produk yang lama
    bool update_154(string nama_tua, string nama_baru , double harga_baru) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama_154 == nama_tua) {
                current->nama_154 = nama_baru;
                current->harga_154 = harga_baru;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Digunakan untuk menghapus seluruh node
    void delete_all_154() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Digunakan untuk menampilkan semua data dalam linked list
    void display_154() {
    Node* current = head;
    cout << left << setw(20) << "Nama Produk" << setw(10) << "Harga (Rp)" << endl;
    while (current != nullptr) {
        cout << left << setw(20) << current->nama_154 << setw(10) << current->harga_154 << endl;
        current = current->next;
    }
    cout << endl;
}

    // Digunakan untuk menambahkan node baru setelah node tertentu
    void insert_after_154(string nama, double harga, string nama_baru) {
        Node* newNode = new Node;
        newNode->nama_154 = nama;
        newNode->harga_154 = harga;

        Node* current = head;
        while (current != nullptr && current->nama_154 != nama_baru ){
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Produk " << nama_baru << " tidak tersedia" << endl;
            return;
        }
        newNode->prev = current;
        newNode->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
    }

    // Digunakan untuk menghapus node dengan nama produk tertentu
    void delete_node_154(string nama) {
        Node* current = head;
        while (current != nullptr && current->nama_154 != nama) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Produk " << nama << " tidak tersedia" << endl;
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
    }
};

int main() {
    DoublyLinkedList list;
    // Menambahkan data saat program dimulai
    list.push_154("hanasui", 30000);
    list.push_154("wardah", 50000);
    list.push_154("skintific", 100000);
    list.push_154("somethinc", 150000);
    list.push_154("originote", 60000);
    cout << "==== Selamat Datang Ke Toko Skincare PWT ====" << endl;
    while (true) {
        //Menu utama program ini
        cout << "\nToko Skincare PWT"<<endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        //Memiihih menu sesuai dengan yang diinginkan user
        int choice;
        cout << "masukkan pilihanmu: ";
        cin >> choice;
        switch (choice) {
            //Menambahkan data didalam double linked list
            case 1: {
                string nama_154;
                double harga_154;
                cout << "Masukkan nama produk: ";
                cin >> nama_154;
                cout << "Masukkan harga produk: ";
                cin >> harga_154;
                list.push_154(nama_154, harga_154);
                break;
            }
            //Menghapus data didalam double linked list
            case 2: {
                string nama_154;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> nama_154;
                list.delete_node_154(nama_154);
                break;
            }
            //Mengupdate data didalam linked list
            case 3: {
                string nama_tua, nama_baru;
                double nama_baru;
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> nama_tua;
                cout << "Masukkan nama produk baru: ";
                cin >> nama_baru;
                cout << "Masukkan harga produk baru: ";
                cin >> harga_baruF;
                bool updated = list.update_154(nama_tua, nama_baru, harga_baru);
                if (!updated) {
                    cout << "Data tidak tersedia" << endl;
                }
                break;
            }
            //Menambahkan data dengan urutan yang diinginkan user
            case 4: {
                string nama, nama_baru;
                double harga;
                cout << "Masukkan nama produk baru: ";
                cin >> nama;
                cout << "Masukkan harga produk baru: ";
                cin >> harga;
                cout << "Masukkan nama produk setelah produk yang ingin ditambahkan: ";
                cin >> nama_baru;
                list.insert_after_154(nama, harga, nama_baru);
                break;
            }
            //Menghapus data dengan urutan yang diinginkan user
            case 5: {
                string nama;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> nama;
                list.delete_node_154(nama);
                break;
            }
            //Menghapus semua data yang ada didalam double linked list
            case 6: {
                list.delete_all_154();
                break;
            }
            //Menampilkan seluruh data yang ada didalam double linked list
            case 7: {
                list.display_154();
                break;
            }
            //Keluar dari program double linked list
            case 8: {
                return 0;
            }
            // Saat terjadi input user yang invalid
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    }
    return 0;
}
```

#### Output:
![Tugas 1](<(1) Unguided-2(Pertemuan-3)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Tugas 2](<(2) Unguided-2(Pertemuan-3)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Tugas 3](<(3) Unguided-2(Pertemuan-3)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Tugas 4](<(4) Unguided-2(Pertemuan-3)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)

Kode di atas  menampilkan struktur data program double linked list digunakan. Di dalam program ini, penggunya memiliki menu yang dapat digunakan untuk melakukan berbagai tugas, seperti menambahkan, menghapus, mengupdate, menyisipkan, menghapus semua data, hingga menampilkan seluruh data. Pada awal program, data barang, termasuk harganya, telah tersimpan, dan data dapat ditampilkan secara instan tanpa mengubah data apa pun.


## Kesimpulan
Linked List adalah struktur data dinamis yang digunakan untuk menyimpan kumpulan yang hampir sama dengan array, kelainannya dapat terlihat pada cara penyimpanan dan pengaksesan elemen-elemennya. Sementara array menggunakan alokasi memori statis dan menyimpan elemen-elemennya secara kontigu, Linked List menggunakan alokasi memori dinamis dan menyimpan elemen-elemennya sebagai simpul-simpul yang terhubung satu sama lain melalui pointer.

## Referensi
[1] Triase, T. "Struktur Data: Diktat Edisi Revisi" (2020) <br/>
[2] Nugraha, Muhammad. "Dasar Pemrograman Dengan C++, Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform" (2021)<br/>
[3] Rafsanjani, Malik Akbar Hashemi. "Implementasi Algoritma Pengurutan General Purpose
dan Berbasis Komparasi untuk Data Berkategori dalam Waktu Linier Tanpa Paralelisasi" (2021) <br/>