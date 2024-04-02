# <h1 align="center">Laporan Praktikum Modul Linked List Circular dan Non Circular </h1>
<p align="center">Arvinanto Bahtiar</p>

## Dasar Teori
Linked List adalah struktur data yang digunakan untuk menyimpan kumpulan data. Linked List adalah salah satu struktur data paling sederhana dan paling umum. Struktur data ini dapat digunakan untuk mengimplementasikan beberapa tipe data abstrak umum lainnya. 

1. Linked List Non circular <br/>
   Linked list non circular adalah linked list dimana node head tidak terhubung dengan node terakhir maka tidak membentuk lingkaran (Non Circular). Node tail selalu bersifat NULL berarti node terakhir dalam linked list.
   
2. Linked List Circular <br/>
   Linked list Circular adalah linked list dimana node head terhubung dengan node tail yang tidak bersifat NULL berarti linked list circular tidak mempunyai akhiran. Bentuk linked list ini sama dengan lingkaran (Circular) karena tidak mempunyai akhiran.

## Guided 

### 1. Linked List Non Circular

```C++
#include <iostream>
using namespace std;

//PORGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node

struct node {
    int data;
    node *next;
};
node *head;
node *tail;

//inisialisasi node
void init(){
    head = NULL;
    tail = NULL;
}
//pengecekan
bool isempty(){
    if (head == NULL)
    return true;
    else
    return false;
}
// Tambah depan
void insertdepan(int nilai){
    //buat node baru
    node *baru = new node;
    baru->data = nilai;
    baru->next = NULL;
    if (isempty() ==true){
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        baru->next = head;
        head = baru;
        }
}
// tambah belakang
void insertbelakang(int nilai){
    //buat node baru
    node *baru = new node;
    baru->data= nilai;
    baru->next = NULL;
    if (isempty()==true){
        head = tail = baru;
        tail-> next = NULL;
    }
    else{
        tail->next = baru;
        tail = baru;
    }
}
//hitung jumlah list
int hitunglist(){
    node *hitung;
    hitung=head;
    int jumlah=0;
    while (hitung!=NULL){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//tambah tengah
void inserttengah(int data, int posisi){
    if (posisi <1 || posisi > hitunglist()){
        cout << "posisi diluar jangkauan"<<endl;
    }
    else if (posisi == 1){
        cout << " posisi bukan posisi tengah"<<endl;
    }
    else{
        node *baru, *bantu;
        baru = new node();
        baru->data= data;

        //transvering
        bantu = head;
        int nomor = 1;
        while ( nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        baru ->next = bantu->next;
        bantu->next = baru;
    }
}

//hapus depan
void hapusdepan(){
    node * hapus;
    if (isempty()==false){
        if ( head->next!=NULL){
            hapus = head;
            head = head-> next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "list kosong!"<<endl;
    }
}
//hapus belakang
void hapusbelakang(){
    node *hapus;
    node *bantu;
    if (isempty()==false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next !=tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next= NULL;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << " list kosong!"<<endl;
    }
}
//hapus tengah
void hapustengah(int posisi){
    node * bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitunglist()){
        cout << "posisi diluar jangkauan"<<endl;
    }
    else if ( posisi == 1){
        cout << " posisi bukan posisi tengah"<<endl;
    }
    else {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi){
            if (nomor==posisi -1){
                sebelum = bantu;
            }
            if (nomor == posisi){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}
// ubah depan
void ubahdepan(int data){
    if (isempty()==0){
        head->data = data;
    }
    else{
        cout << "list masih kosong!"<<endl;
    }
}
// ubah tengah
void ubahtengah(int data, int posisi){
    node *bantu;
    if (isempty()==0){
        if (posisi < 1 || posisi > hitunglist()){
            cout << " posisi di luar jangkauan"<<endl;
        }
        else if (posisi==1){
            cout << " posisi bukan posisi tengah"<<endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while ( nomor < posisi){
                bantu = bantu->next;
                nomor++;
            }
            bantu->data=data;
        }
    }
    else{
        cout << " list masih kosong!"<<endl;
    }
}
//ubah belakang
void ubahbelakang(int data){
    if (isempty ()==0){
        tail->data = data;
    }
    else {
        cout << "list masih kosong!"<<endl;
    }
}
//hapus list
void clearlist(){
    node *bantu, *hapus;
    bantu = head;
    while ( bantu !=NULL){
        hapus = bantu;
        bantu= bantu-> next;
        delete hapus;
    }
    head = tail = NULL;
    cout << " list berhasil terhapus"<<endl;
}
//tampilan list
void tampil (){
    node *bantu;
    bantu = head;
    if (isempty()== false){
        while ( bantu != NULL){
            cout << bantu->data <<ends;
            bantu = bantu-> next;
        }
        cout << endl;
    }
    else {
        cout << " list masih kosong!"<<endl;
    }
}
int main (){
    init();
    insertdepan(3);
    tampil();
    insertbelakang(5);
    tampil();
    insertdepan(2);
    tampil();
    insertdepan(1);
    tampil();
    hapusdepan();
    tampil();
    hapusbelakang();
    tampil();
    inserttengah(7, 2);
    tampil();
    hapustengah(2);
    tampil();
    ubahdepan(1);
    tampil();
    ubahbelakang(8);
    tampil();
    ubahtengah(11, 2);
    tampil();
    return 0;
}
```

Program diatas adalah contoh program linked list bentuk non circular. Program ini berfungsi untuk menyimpan data nama angka, User harus modifikasi code pada bagian int main() jika ingin menambahkan angka lain karena tidak diberi cin untuk menginput angka baru.

### 2. inked List Circular

```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string data;
    Node* next;
};

Node* head, * tail, * baru, * bantu, * hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam ");
    tampil();
    insertDepan("Bebek ");
    tampil();
    insertBelakang("Cicak ");
    tampil();
    insertBelakang("Domba ");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi ", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
Program diatas adalah contoh program linked list bentuk circular. Program ini berfungsi untuk menyimpan data nama binatang, seperti ayam, bebek, cicak, domba, dan sapi. User harus modifikasi code pada bagian int main() jika ingin menambahkan binatang lain karena tidak diberi cin untuk menginput binatang baru.

## Unguided 

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1:
```C++
#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct node {
    string nama_154;
    string nim_154;
    node *next;
};

// Deklarasi variabel head dan tail
node *head;
node *tail;

// Inisialisasi linked list
void init_154() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah linked list kosong
bool isEmpty_154() {
    return head == NULL;
}
// Menghitung jumlah node dalam linked list
int hitung_list_154() {
    int jumlah = 0;
    node *bantu = head;
    while(bantu != NULL) {
        jumlah++;
        bantu = bantu -> next;
    }
    return jumlah;
}

// Menambah data mahasiswa di depan linked list
void insert_depan_154(string nama_154, string nim_154) {
    // Membuat node baru
    node *baru = new node;
    baru->nama_154 = nama_154;
    baru->nim_154 = nim_154;
    baru->next = NULL;

    // Jika linked list kosong
    if(isEmpty_154()) {
        head = tail = baru;
    } 
    else {
        baru->next = head;
        head = baru;
    }
}

// Menambah data mahasiswa di belakang linked list
void insert_belakang_154(string nama_154, string nim_154) {
    // Membuat node baru
    node *baru = new node;
    baru->nama_154 = nama_154;
    baru->nim_154 = nim_154;
    baru->next = NULL;

    // Jika linked list kosong
    if(isEmpty_154()) {
        head = tail = baru;
    } 
    else {
        tail->next = baru;
        tail = baru;
    }
}

// Menambah data mahasiswa di tengah linked list
void insert_tengah_154(string nama_154, string nim_154, int posisi_154) {
    if(posisi_154 < 1 || posisi_154 > hitung_list_154() + 1) {
        cout << "Posisi diluar jangkauan" << endl;
    } 
    else {
        if(posisi_154 == 1) {
            insert_depan_154(nama_154, nim_154);
        } 
        else if(posisi_154 == hitung_list_154() + 1) {
            insert_belakang_154(nama_154, nim_154);
        } 
        else {
            node *baru = new node;
            baru->nama_154 = nama_154;
            baru->nim_154 = nim_154;

            node *bantu = head;
            for (int i = 1; i < posisi_154 - 1; ++i) {
                bantu = bantu->next;
            }

            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
}

// Mengubah data mahasiswa di depan linked list
void ubah_depan_154(string nama_154, string nim_154) {
    if(!isEmpty_154()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = head->nama_154;
        string nim_sebelum = head->nim_154;

        // Mengubah data
        head->nama_154 = nama_154;
        head->nim_154 = nim_154;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama_154 << endl;
    } 
    else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di belakang linked list
void ubah_belakang_154(string nama_154, string nim_154) {
    if(!isEmpty_154()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = tail -> nama_154;
        string nim_sebelum = tail -> nim_154;

        // Mengubah data
        tail->nama_154 = nama_154;
        tail->nim_154 = nim_154;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama_154 << endl;
    } 
    else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di tengah linked list
void ubah_tengah_154(string nama_154, string nim_154, int posisi_154) {
    if(posisi_154 < 1 || posisi_154 > hitung_list_154()) {
        cout << "Posisi diluar jangkauan" << endl;
    } 
    else {
        node *bantu = head;
        for (int i = 1; i < posisi_154; ++i) {
            bantu = bantu->next;
        }

        // Menyimpan data sebelum diubah
        string nama_sebelum = bantu -> nama_154;
        string nim_sebelum = bantu -> nim_154;

        // Mengubah data
        bantu->nama_154 = nama_154;
        bantu->nim_154 = nim_154;

        // Menampilkan informasi
        cout << "Data pada posisi_154 " << posisi_154 << " telah diubah dari " << nama_sebelum << " menjadi " << nama_154 << endl;
    }
}

// Menghapus data mahasiswa di depan linked list
void hapus_depan_154() {
    if(!isEmpty_154()) {
        node *hapus = head;
        if (head == tail) {
            head = tail = NULL;
        } 
        else {
            head = head->next;
        }
        delete hapus;
    } 
    else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di belakang linked list
void hapus_belakang_154() {
    if(!isEmpty_154()) {
        node *hapus = tail;
        if(head == tail) {
            head = tail = NULL;
        } else {
            node *bantu = head;
            while(bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        }
        delete hapus;
    } 
    else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di tengah linked list
void hapus_tengah_154(int posisi_154) {
    if(posisi_154 < 1 || posisi_154 > hitung_list_154()) {
        cout << "Posisi diluar jangkauan" << endl;
    } 
    else {
        if(posisi_154 == 1) {
            hapus_depan_154();
        } 
        else if(posisi_154 == hitung_list_154()) {
            hapus_belakang_154();
        } 
        else {
            node *hapus = head;
            for(int i = 1; i < posisi_154 - 1; ++i) {
                hapus = hapus->next;
            }
            node *hapus_node = hapus->next;
            hapus->next = hapus_node->next;
            delete hapus_node;
        }
    }
}

// Menghapus seluruh data di dalam linked list
void hapus_list_154() {
    while(!isEmpty_154()) {
        hapus_depan_154();
    }
    cout << "Linked list berhasil dihapus semua!" << endl;
}

// Menampilkan seluruh data dalam linked list
void tampilan_154() {
    if(!isEmpty_154()) {
        node *bantu = head;
        int nomor = 1; // Variabel untuk nomor indeks atau nomor urut
        cout << setw(5) << left << "No" << setw(15) << left << "NAMA" << "NIM" << endl;
        while(bantu != NULL) {
            cout << setw(5) << left << nomor << setw(15) << left << bantu->nama_154 << bantu->nim_154 << endl;
            bantu = bantu->next;
            nomor++; // Menginkremen nomor indeks atau nomor urut
        }
    } 
    else {
        cout << "Linked list kosong!" << endl;
    }
}

int main() {
    init_154();
    int pilihan_154;
    string nama_154;
    string nim_154;
    int posisi_154;
    do {
        // Menampilkan menu
        cout << "\n= Menu Linked List Non Circular Mahasiswa =" << endl;
        cout <<endl;
        cout << "1.Tambah Depan" << endl;
        cout << "2.Tambah Belakang" << endl;
        cout << "3.Tambah Tengah" << endl;
        cout << "4.Ubah Depan" << endl;
        cout << "5.Ubah Belakang" << endl;
        cout << "6.Ubah Tengah" << endl;
        cout << "7.Hapus Depan" << endl;
        cout << "8.Hapus Belakang" << endl;
        cout << "9.Hapus Tengah" << endl;
        cout << "10.Hapus List" << endl;
        cout << "11.Tampilkan" << endl;
        cout << "0.Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilihan_154;
        cout <<endl;
        switch(pilihan_154) {
            case 1:
                cout <<"-TAMBAH DEPAN-"<<endl;
                cout << endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insert_depan_154(nama_154, nim_154);
                break;
            case 2:
                cout << "-Tambah Belakang-"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insert_belakang_154(nama_154, nim_154);
                break;
            case 3:
                cout << "-Tambah Tengah-"<<endl;
                cout<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout << "Masukkan Posisi :";
                cin >> posisi_154;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insert_tengah_154(nama_154, nim_154, posisi_154);
                break;
            case 4:
                cout << "-Ubah Depan-"<<endl;
                cout<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout << endl;
                ubah_depan_154(nama_154, nim_154);
                break;
            case 5:
                cout << "-Ubah Belakang-"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout << endl;
                ubah_belakang_154(nama_154, nim_154);
                break;
            case 6:
                cout << "-Ubah Tengah-"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout << "Masukkan Posisi :";
                cin >> posisi_154;
                cout << endl;
                ubah_tengah_154(nama_154, nim_154, posisi_154);
                break;
            case 7:
                cout << "-Hapus Depan-"<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama_154;
                cout << "data "<<nama_154<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapus_depan_154();
                break;
            case 8:
                cout << "-Hapus Belakang-"<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama_154;
                cout << "data "<<nama_154<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapus_belakang_154();
                break;
            case 9:
                cout << "-Hapus Tengah-"<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama_154;
                cout <<"Posisi"<<endl;
                cin >>posisi_154;
                cout << "data "<<nama_154<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapus_tengah_154(posisi_154);
                break;
            case 10:
                cout << "-Hapus List-"<<endl;
                cout <<endl;
                hapus_list_154();
                break;
            case 11:
                cout << "-Menampilkan Semua data mahasiswa-"<<endl;
                cout <<endl;
                cout <<"DATA MAHASISWA"<<endl;
                cout << endl;
                tampilan_154();
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan_154 != 0);
    return 0;
}
```

#### Output:
![Output Unguided 1-1](<(1) Unguided-1(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output Unguided 1-2](<(2) Unguided-1(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output Unguided 1-3](<(3) Unguided-1(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output Unguided 1-4](<(4) Unguided-1(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output Unguided 1-5](<(5) Unguided-1(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output Unguided 1-6](<(6) Unguided-1(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output Unguided 1-7](<(7) Unguided-1(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output Unguided 1-8](<(8) Unguided-1(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)

Pada program diatas, terdapat 11 menu yang dapat digunakan untuk memodifikasi suatu linked list non-circular yang terdiri dari:
1. tambah depan <br/>
2. tambah belakang <br/>
3. tambah tengah <br/>
4. Ubah depan <br/>
5. ubah belakang <br/>
6. ubah tengah <br/>
7. Hapus depan <br/>
8. hapus belakang <br/>
9. hapus tengah <br/>
10. hapus list <br/>
11. Tampilkan <br/>
dan <br/>
0. Berfungsi untuk menghentikan program. <br/>

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah) 

```C++
#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct node {
    string nama_154;
    string nim_154;
    node *next;
};

// Deklarasi variabel head dan tail
node *head;
node *tail;

// Inisialisasi linked list
void init_154() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah linked list kosong
bool isEmpty_154() {
    return head == NULL;
}
// Menghitung jumlah node dalam linked list
int hitung_list_154() {
    int jumlah = 0;
    node *bantu = head;
    while(bantu != NULL) {
        jumlah++;
        bantu = bantu -> next;
    }
    return jumlah;
}

// Menambah data mahasiswa di depan linked list
void insert_depan_154(string nama_154, string nim_154) {
    // Membuat node baru
    node *baru = new node;
    baru->nama_154 = nama_154;
    baru->nim_154 = nim_154;
    baru->next = NULL;

    // Jika linked list kosong
    if(isEmpty_154()) {
        head = tail = baru;
    } 
    else {
        baru->next = head;
        head = baru;
    }
}

// Menambah data mahasiswa di belakang linked list
void insert_belakang_154(string nama_154, string nim_154) {
    // Membuat node baru
    node *baru = new node;
    baru->nama_154 = nama_154;
    baru->nim_154 = nim_154;
    baru->next = NULL;

    // Jika linked list kosong
    if(isEmpty_154()) {
        head = tail = baru;
    } 
    else {
        tail->next = baru;
        tail = baru;
    }
}

// Menambah data mahasiswa di tengah linked list
void insert_tengah_154(string nama_154, string nim_154, int posisi_154) {
    if(posisi_154 < 1 || posisi_154 > hitung_list_154() + 1) {
        cout << "Posisi diluar jangkauan" << endl;
    } 
    else {
        if(posisi_154 == 1) {
            insert_depan_154(nama_154, nim_154);
        } 
        else if(posisi_154 == hitung_list_154() + 1) {
            insert_belakang_154(nama_154, nim_154);
        } 
        else {
            node *baru = new node;
            baru->nama_154 = nama_154;
            baru->nim_154 = nim_154;

            node *bantu = head;
            for (int i = 1; i < posisi_154 - 1; ++i) {
                bantu = bantu->next;
            }

            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
}

// Mengubah data mahasiswa di depan linked list
void ubah_depan_154(string nama_154, string nim_154) {
    if(!isEmpty_154()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = head->nama_154;
        string nim_sebelum = head->nim_154;

        // Mengubah data
        head->nama_154 = nama_154;
        head->nim_154 = nim_154;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama_154 << endl;
    } 
    else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di belakang linked list
void ubah_belakang_154(string nama_154, string nim_154) {
    if(!isEmpty_154()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = tail -> nama_154;
        string nim_sebelum = tail -> nim_154;

        // Mengubah data
        tail->nama_154 = nama_154;
        tail->nim_154 = nim_154;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama_154 << endl;
    } 
    else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di tengah linked list
void ubah_tengah_154(string nama_154, string nim_154, int posisi_154) {
    if(posisi_154 < 1 || posisi_154 > hitung_list_154()) {
        cout << "Posisi diluar jangkauan" << endl;
    } 
    else {
        node *bantu = head;
        for (int i = 1; i < posisi_154; ++i) {
            bantu = bantu->next;
        }

        // Menyimpan data sebelum diubah
        string nama_sebelum = bantu -> nama_154;
        string nim_sebelum = bantu -> nim_154;

        // Mengubah data
        bantu->nama_154 = nama_154;
        bantu->nim_154 = nim_154;

        // Menampilkan informasi
        cout << "Data pada posisi_154 " << posisi_154 << " telah diubah dari " << nama_sebelum << " menjadi " << nama_154 << endl;
    }
}

// Menghapus data mahasiswa di depan linked list
void hapus_depan_154() {
    if(!isEmpty_154()) {
        node *hapus = head;
        if (head == tail) {
            head = tail = NULL;
        } 
        else {
            head = head->next;
        }
        delete hapus;
    } 
    else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di belakang linked list
void hapus_belakang_154() {
    if(!isEmpty_154()) {
        node *hapus = tail;
        if(head == tail) {
            head = tail = NULL;
        } else {
            node *bantu = head;
            while(bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        }
        delete hapus;
    } 
    else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di tengah linked list
void hapus_tengah_154(int posisi_154) {
    if(posisi_154 < 1 || posisi_154 > hitung_list_154()) {
        cout << "Posisi diluar jangkauan" << endl;
    } 
    else {
        if(posisi_154 == 1) {
            hapus_depan_154();
        } 
        else if(posisi_154 == hitung_list_154()) {
            hapus_belakang_154();
        } 
        else {
            node *hapus = head;
            for(int i = 1; i < posisi_154 - 1; ++i) {
                hapus = hapus->next;
            }
            node *hapus_node = hapus->next;
            hapus->next = hapus_node->next;
            delete hapus_node;
        }
    }
}

// Menghapus seluruh data di dalam linked list
void hapus_list_154() {
    while(!isEmpty_154()) {
        hapus_depan_154();
    }
    cout << "Linked list berhasil dihapus semua!" << endl;
}

// Menampilkan seluruh data dalam linked list
void tampilan_154() {
    if(!isEmpty_154()) {
        node *bantu = head;
        int nomor = 1; // Variabel untuk nomor indeks atau nomor urut
        cout << setw(5) << left << "No" << setw(15) << left << "NAMA" << "NIM" << endl;
        while(bantu != NULL) {
            cout << setw(5) << left << nomor << setw(15) << left << bantu->nama_154 << bantu->nim_154 << endl;
            bantu = bantu->next;
            nomor++; // Menginkremen nomor indeks atau nomor urut
        }
    } 
    else {
        cout << "Linked list kosong!" << endl;
    }
}

int main() {
    init_154();
    int pilihan_154;
    string nama_154;
    string nim_154;
    int posisi_154;
    do {
        // Menampilkan menu
        cout << "\n= Menu Linked List Non Circular Mahasiswa =" << endl;
        cout <<endl;
        cout << "1.Tambah Depan" << endl;
        cout << "2.Tambah Belakang" << endl;
        cout << "3.Tambah Tengah" << endl;
        cout << "4.Ubah Depan" << endl;
        cout << "5.Ubah Belakang" << endl;
        cout << "6.Ubah Tengah" << endl;
        cout << "7.Hapus Depan" << endl;
        cout << "8.Hapus Belakang" << endl;
        cout << "9.Hapus Tengah" << endl;
        cout << "10.Hapus List" << endl;
        cout << "11.Tampilkan" << endl;
        cout << "0.Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilihan_154;
        cout <<endl;
        switch(pilihan_154) {
            case 1:
                cout <<"-TAMBAH DEPAN-"<<endl;
                cout << endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insert_depan_154(nama_154, nim_154);
                break;
            case 2:
                cout << "-Tambah Belakang-"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insert_belakang_154(nama_154, nim_154);
                break;
            case 3:
                cout << "-Tambah Tengah-"<<endl;
                cout<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout << "Masukkan Posisi :";
                cin >> posisi_154;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insert_tengah_154(nama_154, nim_154, posisi_154);
                break;
            case 4:
                cout << "-Ubah Depan-"<<endl;
                cout<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout << endl;
                ubah_depan_154(nama_154, nim_154);
                break;
            case 5:
                cout << "-Ubah Belakang-"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout << endl;
                ubah_belakang_154(nama_154, nim_154);
                break;
            case 6:
                cout << "-Ubah Tengah-"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout << "Masukkan Posisi :";
                cin >> posisi_154;
                cout << endl;
                ubah_tengah_154(nama_154, nim_154, posisi_154);
                break;
            case 7:
                cout << "-Hapus Depan-"<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama_154;
                cout << "data "<<nama_154<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapus_depan_154();
                break;
            case 8:
                cout << "-Hapus Belakang-"<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama_154;
                cout << "data "<<nama_154<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapus_belakang_154();
                break;
            case 9:
                cout << "-Hapus Tengah-"<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama_154;
                cout <<"Posisi"<<endl;
                cin >>posisi_154;
                cout << "data "<<nama_154<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapus_tengah_154(posisi_154);
                break;
            case 10:
                cout << "-Hapus List-"<<endl;
                cout <<endl;
                hapus_list_154();
                break;
            case 11:
                cout << "-Menampilkan Semua data mahasiswa-"<<endl;
                cout <<endl;
                cout <<"DATA MAHASISWA"<<endl;
                cout << endl;
                tampilan_154();
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan_154 != 0);
    return 0;
}
```
#### Output:
![Output Unguided 2](<Unguided-2(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)

Tugas ini suruh menggunakan program single linked list non-circular dan mengisinya dengan data Jawad, nama user, Farrel, Denis, Anis, Bowo, Gahar, Udin, dan Ucok menggunakan operator insert depan, insert belakang dan insert tengah.

### 3. Lakukan perintah berikut: a) Tambahkan data berikut diantara Farrel dan Denis:Wati 2330004, b) Hapus data Denis, c) Tambahkan data berikut di awal: Owi 2330000, d) Tambahkan data berikut di akhir: David 23300100, e) Ubah data Udin menjadi data berikut: Idin 23300045, f) Ubah data terkahir menjadi berikut: Lucy 23300101, g) Hapus data awal h) Ubah data awal menjadi berikut: Bagas 2330002 i) Hapus data akhir j) Tampilkan seluruh data 

```C++
#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct node {
    string nama_154;
    string nim_154;
    node *next;
};

// Deklarasi variabel head dan tail
node *head;
node *tail;

// Inisialisasi linked list
void init_154() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah linked list kosong
bool isEmpty_154() {
    return head == NULL;
}
// Menghitung jumlah node dalam linked list
int hitung_list_154() {
    int jumlah = 0;
    node *bantu = head;
    while(bantu != NULL) {
        jumlah++;
        bantu = bantu -> next;
    }
    return jumlah;
}

// Menambah data mahasiswa di depan linked list
void insert_depan_154(string nama_154, string nim_154) {
    // Membuat node baru
    node *baru = new node;
    baru->nama_154 = nama_154;
    baru->nim_154 = nim_154;
    baru->next = NULL;

    // Jika linked list kosong
    if(isEmpty_154()) {
        head = tail = baru;
    } 
    else {
        baru->next = head;
        head = baru;
    }
}

// Menambah data mahasiswa di belakang linked list
void insert_belakang_154(string nama_154, string nim_154) {
    // Membuat node baru
    node *baru = new node;
    baru->nama_154 = nama_154;
    baru->nim_154 = nim_154;
    baru->next = NULL;

    // Jika linked list kosong
    if(isEmpty_154()) {
        head = tail = baru;
    } 
    else {
        tail->next = baru;
        tail = baru;
    }
}

// Menambah data mahasiswa di tengah linked list
void insert_tengah_154(string nama_154, string nim_154, int posisi_154) {
    if(posisi_154 < 1 || posisi_154 > hitung_list_154() + 1) {
        cout << "Posisi diluar jangkauan" << endl;
    } 
    else {
        if(posisi_154 == 1) {
            insert_depan_154(nama_154, nim_154);
        } 
        else if(posisi_154 == hitung_list_154() + 1) {
            insert_belakang_154(nama_154, nim_154);
        } 
        else {
            node *baru = new node;
            baru->nama_154 = nama_154;
            baru->nim_154 = nim_154;

            node *bantu = head;
            for (int i = 1; i < posisi_154 - 1; ++i) {
                bantu = bantu->next;
            }

            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
}

// Mengubah data mahasiswa di depan linked list
void ubah_depan_154(string nama_154, string nim_154) {
    if(!isEmpty_154()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = head->nama_154;
        string nim_sebelum = head->nim_154;

        // Mengubah data
        head->nama_154 = nama_154;
        head->nim_154 = nim_154;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama_154 << endl;
    } 
    else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di belakang linked list
void ubah_belakang_154(string nama_154, string nim_154) {
    if(!isEmpty_154()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = tail -> nama_154;
        string nim_sebelum = tail -> nim_154;

        // Mengubah data
        tail->nama_154 = nama_154;
        tail->nim_154 = nim_154;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama_154 << endl;
    } 
    else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di tengah linked list
void ubah_tengah_154(string nama_154, string nim_154, int posisi_154) {
    if(posisi_154 < 1 || posisi_154 > hitung_list_154()) {
        cout << "Posisi diluar jangkauan" << endl;
    } 
    else {
        node *bantu = head;
        for (int i = 1; i < posisi_154; ++i) {
            bantu = bantu->next;
        }

        // Menyimpan data sebelum diubah
        string nama_sebelum = bantu -> nama_154;
        string nim_sebelum = bantu -> nim_154;

        // Mengubah data
        bantu->nama_154 = nama_154;
        bantu->nim_154 = nim_154;

        // Menampilkan informasi
        cout << "Data pada posisi_154 " << posisi_154 << " telah diubah dari " << nama_sebelum << " menjadi " << nama_154 << endl;
    }
}

// Menghapus data mahasiswa di depan linked list
void hapus_depan_154() {
    if(!isEmpty_154()) {
        node *hapus = head;
        if (head == tail) {
            head = tail = NULL;
        } 
        else {
            head = head->next;
        }
        delete hapus;
    } 
    else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di belakang linked list
void hapus_belakang_154() {
    if(!isEmpty_154()) {
        node *hapus = tail;
        if(head == tail) {
            head = tail = NULL;
        } else {
            node *bantu = head;
            while(bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        }
        delete hapus;
    } 
    else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di tengah linked list
void hapus_tengah_154(int posisi_154) {
    if(posisi_154 < 1 || posisi_154 > hitung_list_154()) {
        cout << "Posisi diluar jangkauan" << endl;
    } 
    else {
        if(posisi_154 == 1) {
            hapus_depan_154();
        } 
        else if(posisi_154 == hitung_list_154()) {
            hapus_belakang_154();
        } 
        else {
            node *hapus = head;
            for(int i = 1; i < posisi_154 - 1; ++i) {
                hapus = hapus->next;
            }
            node *hapus_node = hapus->next;
            hapus->next = hapus_node->next;
            delete hapus_node;
        }
    }
}

// Menghapus seluruh data di dalam linked list
void hapus_list_154() {
    while(!isEmpty_154()) {
        hapus_depan_154();
    }
    cout << "Linked list berhasil dihapus semua!" << endl;
}

// Menampilkan seluruh data dalam linked list
void tampilan_154() {
    if(!isEmpty_154()) {
        node *bantu = head;
        int nomor = 1; // Variabel untuk nomor indeks atau nomor urut
        cout << setw(5) << left << "No" << setw(15) << left << "NAMA" << "NIM" << endl;
        while(bantu != NULL) {
            cout << setw(5) << left << nomor << setw(15) << left << bantu->nama_154 << bantu->nim_154 << endl;
            bantu = bantu->next;
            nomor++; // Menginkremen nomor indeks atau nomor urut
        }
    } 
    else {
        cout << "Linked list kosong!" << endl;
    }
}

int main() {
    init_154();
    int pilihan_154;
    string nama_154;
    string nim_154;
    int posisi_154;
    do {
        // Menampilkan menu
        cout << "\n= Menu Linked List Non Circular Mahasiswa =" << endl;
        cout <<endl;
        cout << "1.Tambah Depan" << endl;
        cout << "2.Tambah Belakang" << endl;
        cout << "3.Tambah Tengah" << endl;
        cout << "4.Ubah Depan" << endl;
        cout << "5.Ubah Belakang" << endl;
        cout << "6.Ubah Tengah" << endl;
        cout << "7.Hapus Depan" << endl;
        cout << "8.Hapus Belakang" << endl;
        cout << "9.Hapus Tengah" << endl;
        cout << "10.Hapus List" << endl;
        cout << "11.Tampilkan" << endl;
        cout << "0.Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilihan_154;
        cout <<endl;
        switch(pilihan_154) {
            case 1:
                cout <<"-TAMBAH DEPAN-"<<endl;
                cout << endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insert_depan_154(nama_154, nim_154);
                break;
            case 2:
                cout << "-Tambah Belakang-"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insert_belakang_154(nama_154, nim_154);
                break;
            case 3:
                cout << "-Tambah Tengah-"<<endl;
                cout<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout << "Masukkan Posisi :";
                cin >> posisi_154;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insert_tengah_154(nama_154, nim_154, posisi_154);
                break;
            case 4:
                cout << "-Ubah Depan-"<<endl;
                cout<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout << endl;
                ubah_depan_154(nama_154, nim_154);
                break;
            case 5:
                cout << "-Ubah Belakang-"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout << endl;
                ubah_belakang_154(nama_154, nim_154);
                break;
            case 6:
                cout << "-Ubah Tengah-"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama_154;
                cout << "Masukkan NIM :";
                cin >> nim_154;
                cout << "Masukkan Posisi :";
                cin >> posisi_154;
                cout << endl;
                ubah_tengah_154(nama_154, nim_154, posisi_154);
                break;
            case 7:
                cout << "-Hapus Depan-"<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama_154;
                cout << "data "<<nama_154<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapus_depan_154();
                break;
            case 8:
                cout << "-Hapus Belakang-"<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama_154;
                cout << "data "<<nama_154<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapus_belakang_154();
                break;
            case 9:
                cout << "-Hapus Tengah-"<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama_154;
                cout <<"Posisi"<<endl;
                cin >>posisi_154;
                cout << "data "<<nama_154<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapus_tengah_154(posisi_154);
                break;
            case 10:
                cout << "-Hapus List-"<<endl;
                cout <<endl;
                hapus_list_154();
                break;
            case 11:
                cout << "-Menampilkan Semua data mahasiswa-"<<endl;
                cout <<endl;
                cout <<"DATA MAHASISWA"<<endl;
                cout << endl;
                tampilan_154();
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan_154 != 0);
    return 0;
}
```

#### Output:
![Output 3-1](<(1) Unguided-3(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output 3-2](<(2) Unguided-3(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output 3-3](<(3) Unguided-3(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output 3-4](<(4) Unguided-3(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output 3-5](<(5) Unguided-3(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output 3-6](<(6) Unguided-3(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output 3-7](<(7) Unguided-3(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output 3-8](<(8) Unguided-3(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output 3-9](<(9) Unguided-3(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)
![Output 3-10](<(10) Unguided-3(Pertemuan-4)_2311102154_Naufal Geraldo Putra Pramudianartono.png>)

Pada tugas ini disuruh memodifikasi hasil akhir dari tugas kedua. Pertama menambah Wati antara Farrel dan Denis dengan operasi tambah tengah, lalu Hapus data denis dengan operator hapus tengah, menambah Owi pada awal linked list dengan operator tambah depan, menambahkan David pada akhir linked list dengan operator tambah belakang, ubah Udin dengan Idin menggunakan operator ubah tengah, ubah data akhir dengan Lucy menggunakan operator ubah belakang, hapus data awal dengan operator hapus depan, ubah data awal dengan Bagas menggunakan ubah depan, hapus data akhir dengan operator hapus belakang, pada akhirnya menampilkan seluruh linked list. 

## Kesimpulan
Linked list non circular adalah linked list dimana node head tidak terhubung dengan node tail. Sedangkan, linked list circural adalah linked list dimana node headnya mengarah terhubung dengan node tail dan akan mengarah kembali ke node head.

## Referensi
[1] kurniman Putra, Agung. "Single linked list".(2019) <br/>
[2] Nugraha, A. S. "Artikel Double Linked List Circulate". (2019) <br/>
[3] Santoso, Joseph Teguh. "Struktur Data dan Algoritma : Bagian 1". (2021) <br/>