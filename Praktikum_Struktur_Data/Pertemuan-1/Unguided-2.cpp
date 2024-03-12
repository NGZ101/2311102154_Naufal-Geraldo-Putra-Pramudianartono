// Naufal Geraldo Putra Pramudianartono - 2311102154

// 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

/*
Fungsi Class:
Suatu konsep dari Object Oriented Programming (OOP) yang
Berfungsi sebagai tempat untuk mengumpulkan tipe data ke dalam
suatu kelas data dan menjadi deskripsi suatu objek 
yang bersifat private (tertutup) secara default

Fungsi Struct:
Berfungsi sebagai tempat untuk mengumpulkan tipe data ke dalam 
sebuah struktur data dan menjadi bagian dari data yang baru
yang bersifat public (terbuka) secara default.
*/

// Contoh Struct dan Class pada program
#include <iostream>

using namespace std;

// Struct User_154 yang berisi data nama string, tempatlahir string, umur int, dan agama string dalam akses public
class user_154{
    public:
    string nama_154;
    string tempatlahir_154;
    int usia_154;
    string agama_154;
};

// Class usercontact_154 yang berisi data email string, instagram string, dan twitter string
struct usercontact_154 {
    string email_154;   
    string instagram_154;
    string twitter_154;
};

int main() {
    cout << "== Contoh Struct and Class ==" << endl;

    // Deklarasi Struct user_154
    user_154 pengguna{"Naufal Geraldo Putra Pramudianartono", "Jakarta", 18, "Islam",};
    cout << "\n - Biografi Pengguna - " << endl;
    cout << "Nama: " << pengguna.nama_154 << endl;
    cout << "Tempat Lahir: " << pengguna.tempatlahir_154 << endl;
    cout << "Usia: " << pengguna.usia_154 << endl;
    cout << "Agama: " << pengguna.agama_154 << endl;

    // Deklarasi Class usercontact_154
    usercontact_154 kontak ;
    kontak.email_154 = "naufal.geraldo30@gmail.com";
    kontak.instagram_154 = "@NGZ30";
    kontak.twitter_154 = "@NGonX";
    cout << "\n - Info Kontak Pengguna -" << endl;
    cout << "Email: " << kontak.email_154 << endl;
    cout << "Instagram: " << kontak.instagram_154 << endl;
    cout << "Twitter: " << kontak.twitter_154 << endl;
    return 0;
}