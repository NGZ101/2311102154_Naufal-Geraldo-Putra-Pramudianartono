#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi kelas Node untuk memperlihatkan simpul dalam linked list
class Node {
public:
    string nama_154;
    double harga_154;
    Node* prev;
    Node* next;
};

// Deklarasi kelas DoublyLinkedList untuk menggunakan double linked list
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    // inisialisasi linked list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // fungsi untuk menambahkan simpul baru di awal linked list
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

    // fungsi untuk menghapus simpul dari awal linked list
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

    // fungsi untuk memperbarui data produk berdasarkan nama produk yang lama
    bool update_154(string oldNama_131, string newNama_131, double newHarga_131) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama_154 == oldNama_131) {
                current->nama_154 = newNama_131;
                current->harga_154 = newHarga_131;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // fungsi untuk menghapus semua simpul dalam linked list
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

    // fungsi untuk menampilkan semua data produk dalam linked list
    void display_154() {
    Node* current = head;
    cout << left << setw(20) << "Nama Produk" << setw(10) << "Harga (Rp)" << endl;
    while (current != nullptr) {
        cout << left << setw(20) << current->nama_154 << setw(10) << current->harga_154 << endl;
        current = current->next;
    }
    cout << endl;
}

    // fungsi untuk menyisipkan simpul baru setelah simpul tertentu
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

    // fungsi untuk menghapus simpul dengan nama produk tertentu
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
        //menu utama program ini
        cout << "\nToko Skincare PWT"<<endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        //memiihih menu sesuai dengan yang diinginkan user
        int choice;
        cout << "masukkan pilihanmu: ";
        cin >> choice;
        switch (choice) {
            //menambahkan data didalam double linked list
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
            //menghapus data didalam double linked list
            case 2: {
                string nama_154;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> nama_154;
                list.delete_node_154(nama_154);
                break;
            }
            //mengupdate data didalam linked list
            case 3: {
                string oldNama_131, newNama_131;
                double newHarga_131;
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> oldNama_131;
                cout << "Masukkan nama produk baru: ";
                cin >> newNama_131;
                cout << "Masukkan harga produk baru: ";
                cin >> newHarga_131;
                bool updated = list.update_154(oldNama_131, newNama_131, newHarga_131);
                if (!updated) {
                    cout << "Data tidak tersedia" << endl;
                }
                break;
            }
            //menambahkan data dengan urutan yang diinginkan user
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
            //menghapus data dengan urutan yang diinginkan user
            case 5: {
                string nama;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> nama;
                list.delete_node_154(nama);
                break;
            }
            //menghapus semua data yang ada didalam double linked list
            case 6: {
                list.delete_all_154();
                break;
            }
            //menampilkan seluruh data yang ada didalam double linked list
            case 7: {
                list.display_154();
                break;
            }
            //keluar dari program double linked list
            case 8: {
                return 0;
            }
            //jika user salah menginputkan pilihan maka akan menampilkan pesan berikut
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    }
    return 0;
}