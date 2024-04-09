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