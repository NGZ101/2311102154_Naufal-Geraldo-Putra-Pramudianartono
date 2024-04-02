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
void init_154() {
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
void tampil_154() {
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
    init_154();
    insertDepan(3);tampil_154();
    insertBelakang(5);
    tampil_154();
    insertDepan(2);
    tampil_154();
    insertDepan(1);
    tampil_154();
    hapusDepan();
    tampil_154();
    hapusBelakang();
    tampil_154();
    insertTengah(7,2);
    tampil_154();
    hapusTengah(2);
    tampil_154();
    ubahDepan(1);
    tampil_154();
    ubahBelakang(8);
    tampil_154();
    ubahTengah(11, 2);
    tampil_154();
    return 0;
}