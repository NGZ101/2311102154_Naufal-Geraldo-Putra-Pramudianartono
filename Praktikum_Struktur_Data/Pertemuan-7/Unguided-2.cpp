#include<iostream>

using namespace std;

// Deklarasi struct node
struct node { // Node berisi variabel nama, nim, dan pointer next
    string nama_154;
    string nim_154;
    node *next;
};
    node *front; // Deklarasi node front
    node *back; // Deklarasi node back

// Prosedur untuk menginisialisasi node front dan back sebagai NULL
void init_154(){ 
    front = NULL;
    back = NULL;
}

// Fungsi untuk memeriksa apakah antrian kosong atau tidak
bool isEmpty_154(){
    if (front == 0){
        return true; // Jika tidak ada node pertama, maka antrian kosong (kembalikan true)
    } else {
        return false; // Jika ada node pertama, maka antrian tidak kosong (kembalikan false)
    }
}

// Prosedur untuk menambahkan data ke dalam antrian
void tambah_data_154(string nama_154, string nim_154){
    node *baru = new node; // Buat node baru
    baru->nama_154 = nama_154; // Isi node baru dengan nama mahasiswa dan NIM
    baru->nim_154 = nim_154; 
    baru->next = NULL; // Node baru tidak menunjuk ke node lain
    if(isEmpty_154() == true){ // Jika antrian kosong
        front = back = baru; // Node baru menjadi front dan back
        back->next = NULL; // Node berikutnya dari back adalah NULL
    } else if(isEmpty_154() == false){ // Jika antrian tidak kosong
        back->next = baru; // Tambahkan node baru di belakang antrian
        back = baru; // Node baru menjadi back
    }
}

// Prosedur untuk mengurangi antrian (menghapus node pertama)
void kurangi_antrian_154(){
    node *hapus; // Deklarasi node hapus
    if(isEmpty_154() == false){ // Jika antrian tidak kosong
        if(front->next != NULL){ // Jika ada node setelah front
            hapus = front; // Node hapus adalah front
            front = front->next; // Pindahkan front ke node berikutnya
            delete hapus; // Hapus node pertama
        } else { // Jika tidak ada node setelah front
            front = back = NULL; // Front dan back menjadi NULL
        }
    }
}

// Fungsi untuk menghitung jumlah node dalam antrian
int Hitung_Antrian_154(){
    node *hitung; // Deklarasi node hitung
    hitung = front; // Node hitung adalah front
    int jumlah_154 = 0; // Inisialisasi variabel jumlah_154
    while(hitung != NULL){ // Selama node hitung tidak NULL
        hitung = hitung->next; // Pindahkan hitung ke node berikutnya
        jumlah_154++; // Tambah nilai jumlah_154
    }
    return jumlah_154; // Kembalikan nilai jumlah_154
}

// Prosedur untuk menghapus seluruh antrian
void Hapus_Antrian_154(){
    node *hapus, *bantu; // Deklarasi node hapus dan bantu
    bantu = front; // Node bantu adalah front
    while(bantu != NULL){ // Selama node bantu tidak NULL
        hapus = bantu; // Node hapus sama dengan node bantu
        bantu = bantu->next; // Pindahkan bantu ke node berikutnya
        delete hapus; // Hapus node yang dihapus
    }
    front = back = NULL; // Front dan back menjadi NULL
}

// Prosedur untuk menampilkan antrian
void Melihat_Antrian_154(){
    node *bantu; // Deklarasi node bantu
    bantu = front; // Node bantu adalah front
    if(isEmpty_154() == true){ // Jika antrian kosong
        cout << "Antrian kosong!" << endl; 
    } else if(isEmpty_154() == false){ // Jika antrian tidak kosong
        cout << "--- Antrian Saat Ini ---" << endl; 
        int nomor_antrian_154 = 1; // Inisialisasi variabel nomor_antrian_154 dengan nilai 1
        while(bantu != NULL){ // Selama node bantu tidak NULL
            cout << nomor_antrian_154 << ". " << bantu->nama_154 << " - " << bantu->nim_154 << endl; // Tampilkan nomor antrian, nama, dan NIM
            bantu = bantu->next; // Pindahkan bantu ke node berikutnya
            nomor_antrian_154++; // Tambah nomor antrian
        }
    }
    cout << endl;
}

int main(){
    string nama_154, nim_154; 
    int pilih_154; 
    char yakin_154;
    MenuUtama:
    cout << "==== Program Queue Naufal Geraldo ====" << endl;
    cout << "==== Menu Program ====" << endl; // Tampilan menu antrian mahasiswa
    cout << "1. Tambah antrian" << endl;
    cout << "2. Kurangi antrian" << endl;
    cout << "3. Hitung jumlah antrian" << endl;
    cout << "4. Hapus antrian" << endl;
    cout << "5. Lihat antrian" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilihan Anda [1-6] = ";
    cin >> pilih_154;
    cout << endl;
    switch(pilih_154){ // Switch case berdasarkan pilihan user
        case 1: // Jika user memilih 1, tampilkan menu tambah antrian
            cout << "==== Tambah Antrian ====" << endl;
            cout << "Masukkan nama mahasiswa = ";
            cin >> nama_154;
            cout << "Masukkan NIM mahasiswa = ";
            cin >> nim_154;
            tambah_data_154(nama_154, nim_154); // Panggil prosedur tambah_data_154 dengan parameter nama dan NIM
            cout << "Data mahasiswa telah tersimpan!" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2: // Jika user memilih 2, tampilkan menu kurangi antrian
            cout << "==== Kurangi Antrian ====" << endl;
            if(isEmpty_154() == true){ // Jika antrian kosong, tampilkan "Antrian masih kosong!"
                cout << "Antrian masih kosong!" << endl;
            } else { // Jika antrian tidak kosong
                cout << "Apakah anda ingin mengurangi antrian (menghapus antrian pertama)? [y/n] = "; // Validasi keyakinan user untuk mengurangi antrian
                cin >> yakin_154;
                if(yakin_154 == 'y' || yakin_154 == 'Y'){ // Jika user memilih y atau Y
                    kurangi_antrian_154(); // Panggil prosedur kurangi_antrian_154()
                    cout << "Antrian telah dikurangi" << endl;
                } else if(yakin_154 == 'n' || yakin_154 == 'N'){ // Jika user memilih n atau N
                    cout << "Aksi dibatalkan" << endl;
                }
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 3: // Jika user memilih 3, tampilkan menu Hitung Jumlah Antrian
            cout << "==== Hitung Jumlah Antrian ====" << endl;
            cout << "Antrian yang tersimpan saat ini sebanyak " << Hitung_Antrian_154() << endl; // Panggil fungsi Hitung_Antrian_154()
            cout << endl;
            goto MenuUtama;
            break;
        case 4: // Jika user memilih 4, tampilkan menu hapus antrian
            cout << "==== Hapus Antrian ====" << endl;
            cout << "Apakah Anda yakin untuk menghapus seluruh antrian? [y/n] = "; // Validasi keyakinan user untuk menghapus seluruh antrian
            cin >> yakin_154;
            if(yakin_154 == 'y' || yakin_154 == 'Y'){ // Jika user memilih y atau Y
                Hapus_Antrian_154(); // Panggil prosedur Hapus_Antrian_154()
                cout << "Antrian telah dihapus" << endl;
            } else if(yakin_154 == 'n' || yakin_154 == 'N'){ // Jika user memilih n atau N
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 5: // Jika user memilih 5, tampilkan antrian
            Melihat_Antrian_154(); // Panggil prosedur Melihat_Antrian_154()
            cout << endl;
            goto MenuUtama;
            break;
        case 6:
            cout << "Anda keluar dari program" << endl;
            cout << endl;
            return 0;
            break;
        default: // Jika user memilih selain 1-5, tampilkan "Pilihan yang anda masukkan salah!"
            cout << "Pilihan yang anda masukkan salah!" << endl;
            cout << endl;
            goto MenuUtama;
            break;
    }
}