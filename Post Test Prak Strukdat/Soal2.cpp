// Naufal Geraldo Putra Pramudianartono - 2311102154

#include <iostream>
#include <windows.h>
using namespace std;
const int maksimal_tumpukan = 10;
bool keluar = false;
char ya_tidak;
int pilihan;
string data_masuk;
struct tumpukan 
{
    int posisi;
    string data[maksimal_tumpukan]; // ganti dengan maksimal tumpukan karena itu merupakan integer konstan bernilai 10
};
tumpukan buku;

// menganalisi posisi awal adalah -1 atau masih belum ada data di stack
void inisialisasi()
{
    buku.posisi = -1;
}

// fungsi pengecekan apakah stack masih kosong
bool kosong()
{
    if (buku.posisi == -1) // diganti dengan "-1" karena pada inisialisasi() menentukan bahwa posisi awal adalah pada -1
    {
        return true;
    }
    else
    {
        return false;
    }
}

// fungsi pengecekan apakah stack sudah penuh
bool penuh()
{
    if (buku.posisi == maksimal_tumpukan - 1)
    {
        return true;
    }
    else 
    {
        return false; // ganti dengan false karena diatas berada true berarti ini adalah kebalikannya
    }
}

// fungsi untuk memasukan data stack baru
void push_tumpukan(string data_masukkan)
{
    if (kosong() == true)
    {
        buku.posisi++;
        buku.data[buku.posisi] = data_masukkan; // ganti dengan data_masukkan karena pada push_tumpukan() ada string data_masukkan
        cout << "Berhasil memasukkan : " << data_masukkan << endl;
        cout << "\n";
    }
    else if (penuh() == false)
    {
        buku.posisi++;
        buku.data[buku.posisi] = data_masukkan; // ganti dengan data_masukkan karena pada push_tumpukan() ada string data_masukkan
        cout << "Berhasil memasukkan : " << data_masukkan << endl;
        cout << "\n";
    }
    else
    {
        cout << "Tumpukan sudah penuh" << endl;
        cout << "\n";
    }
}

// fungsi untuk menghapus data stack
void pop_tumpukan()
{
    // perkondisian untuk mengecek apakah data kosong
    if (kosong() == true) // ganti dengan kosong() karena sedang cek apakah stack kosong atau tidak
    {
        cout << "Tumpukan kosong" << endl;
        cout << "\n";
    }
    else
    {
        buku.posisi--;
        cout << "Data berhasil dihapus" << endl;
        cout << "\n";
    }
}
void tampil_data()
{
    if (kosong() == true) // ganti dengan kosong() karena output dari kasus ini adalah "Tidak ada data" berarti stack kosong
    {
        cout << "Tidak ada data" << endl;
        cout << "\n";
    }
    else 
    {
        cout << "Berikut adalah stack:" << endl;
        for (int c = buku.posisi; c >= 0; c--) /* ganti dengan buku.posisi karena ini kasus dimana stack tidak kosong maka mulai array 
                                               dari posisi stack dari atas ke bawah (terindikasi dengan c--)*/
        {
            cout << buku.data[c] << endl;
        }
        cout << "\n";
    }
}
int main()
{
    inisialisasi();
    do
    {
        cout << "\t" << "Stack Apps" << endl;
        cout << "1. Masukkan data dari Stack" << endl;
        cout << "2. Hapus data dari Stack" << endl;
        cout << "3. Tampilkan data Stack" << endl;
        cout << "4. Keluar" << endl;
        cout << "Silahkan pilih (1-4) : ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "Silahkan masukkan data : ";
            cin >> data_masuk;
            push_tumpukan(data_masuk);
            break;
        case 2:
            pop_tumpukan();
            break;
        case 3:
            tampil_data();
            break;
        case 4:
            cout << "Yakin ingin keluar (y/t) ? ";
            cin >> ya_tidak;
            if (ya_tidak == 'y' || ya_tidak == 'Y')
            {
                cout << "Terima kasih" << endl;
                keluar = true;
            }
            else
            {
                system("cls");
            }
            break;  
        default:
            cout << "Pilihan tidak tersedia..." << endl;
            cout << "Keluar (y/t) ? ";
            cin >> ya_tidak;
            if (ya_tidak == 'y' || ya_tidak == 'Y')
            {
                cout << "Terima kasih" << endl;
                keluar = true;
            }
            else
            {
                system("cls");
            }
        }
    } while (keluar == false);
    return 0;
}