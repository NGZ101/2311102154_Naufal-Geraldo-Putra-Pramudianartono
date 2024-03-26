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
    input_depan_154("Karin", 18);
    input_depan_154("Hoshino", 18);
    input_depan_154("Akechi", 20);
    input_depan_154("Yusuke", 19);
    input_depan_154("Michael", 18);
    input_depan_154("Jane", 20);
    input_depan_154("John", 19);
    int choice;
    do {
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
            case 5: {
                int posisi;
                cout << "Masukkan posisi data yang ingin dihapus: ";
                cin >> posisi;
                hapus_tengah_154(posisi);
                break;
            }
            case 6: {
                hapus_list_154();
                break;
            }
            case 7: {
                tampilan_154();
                break;
            }
            case 8: {
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}