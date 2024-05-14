#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct node {
    string data_154;
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
    baru->data_154 = nama_154;
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
    baru->data_154 = nama_154;
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
            baru->data_154 = nama_154;
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
        string nama_sebelum = head->data_154;
        string nim_sebelum = head->nim_154;

        // Mengubah data
        head->data_154 = nama_154;
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
        string nama_sebelum = tail -> data_154;
        string nim_sebelum = tail -> nim_154;

        // Mengubah data
        tail->data_154 = nama_154;
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
        string nama_sebelum = bantu -> data_154;
        string nim_sebelum = bantu -> nim_154;

        // Mengubah data
        bantu->data_154 = nama_154;
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
            cout << setw(5) << left << nomor << setw(15) << left << bantu->data_154 << bantu->nim_154 << endl;
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