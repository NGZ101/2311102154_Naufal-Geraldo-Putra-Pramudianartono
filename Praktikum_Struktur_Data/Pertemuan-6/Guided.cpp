#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return(top == maksimal);
}

bool isEmpty() {
    return(top == 0);
}

void pushArrayBuku(string data) {
    if(isFull()) {
        cout << "Data telah penuh" << endl;
    } 
    else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if(isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } 
    else {
        arrayBuku[top-1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if(isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;  
    } 
    else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if(posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else {
        int index = top;
        for(int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for(int i = top; i >= 0; i--) {
        arrayBuku[i] = " ";
    }
    top = 0;
}

void cetakArrayBuku() {
    if(isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else {
        for(int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    // Push untuk memasukkan input ke dalam stack (Input pertama berada di paling bawah dan input terbaru di paling atas stack)
    pushArrayBuku("Kalkulus"); 
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    // Cetak untuk menampilkan seluruh stack yang telah diinput user
    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    
    // Peek untuk cek isi stack dengan 
    peekArrayBuku(2);
    // Pop untuk menghapus data pada posisi pertama
    popArrayBuku();

    cout << "Banyaknya data = " << countStack << endl;

    // Change untuk mengganti data pada suatu posisi dengan data baru
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}