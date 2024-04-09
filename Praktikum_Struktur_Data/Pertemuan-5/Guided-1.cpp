#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key) {
    return key & MAX_SIZE;
}

// Struktur data untuk setiap node
struct Mahasiswa {
    int key;
    int value;
    Mahasiswa* next;
    Mahasiswa(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table 
class HashTable_154 {
    private:
        Mahasiswa** table;
    public:
        HashTable_154() {
            table = new Mahasiswa*[MAX_SIZE] ();
        }
        ~HashTable_154() {
            for (int i = 0; i < MAX_SIZE; i++) {
                Mahasiswa* current = table[1];
                while (current != nullptr) {
                    Mahasiswa* temp = current;
                    current = current -> next;
                    delete temp;
                }
            }
            delete[] table;
            }

            // insertion
            void insert(int key, int value) {
                int index = hash_func(key);
                Mahasiswa* current = table[index];
                while (current != nullptr) {
                    if (current -> key == key) {
                        current -> value = value;
                        return;
                    }
                    current = current -> next;
                }
                Mahasiswa* node = new Mahasiswa(key, value);
                node -> next = table[index];
                table[index] = node;
            }

            // Searching
            int get_nim (int key) {
                int index = hash_func(key);
                Mahasiswa* current = table[index];
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
                Mahasiswa* current = table[index];
                Mahasiswa* prev = nullptr;
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
                    Mahasiswa* current = table[i];
                    while (current != nullptr) {
                        cout << current -> key << ": " << current -> value << endl;
                        current = current -> next;
                    }
                }
            }
};

int main() {
    HashTable_154 ht;
    // Insertion
    ht.insert(1,10);
    ht.insert(2,20);
    ht.insert(3,30);

    //Searching
    cout << "Get key 1: " << ht.get_nim(1) << endl;
    cout << "Get key 4: " << ht.get_nim(4) << endl;
    cout << "Get key 5: " << ht.get_nim(2) << endl;


    //Deletion
    ht.remove(4);

    //Traversal
    ht.traverse();
}