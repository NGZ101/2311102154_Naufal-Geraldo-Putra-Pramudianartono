#include <iostream>
using namespace std;

//PORGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node

struct node {
    int data;
    node *next;
};
node *head;
node *tail;

//inisialisasi node
void init_154(){
    head = NULL;
    tail = NULL;
}
//pengecekan
bool isEmpty_154(){
    if (head == NULL)
    return true;
    else
    return false;
}
// Tambah depan
void insert_depan_154(int nilai){
    //buat node baru
    node *baru = new node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty_154() ==true){
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        baru->next = head;
        head = baru;
        }
}
// tambah belakang
void insert_belakang_154(int nilai){
    //buat node baru
    node *baru = new node;
    baru->data= nilai;
    baru->next = NULL;
    if (isEmpty_154()==true){
        head = tail = baru;
        tail-> next = NULL;
    }
    else{
        tail->next = baru;
        tail = baru;
    }
}
//hitung jumlah list
int hitung_list_154(){
    node *hitung;
    hitung=head;
    int jumlah=0;
    while (hitung!=NULL){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//tambah tengah
void insert_tengah_154(int data, int posisi){
    if (posisi <1 || posisi > hitung_list_154()){
        cout << "posisi diluar jangkauan"<<endl;
    }
    else if (posisi == 1){
        cout << " posisi bukan posisi tengah"<<endl;
    }
    else{
        node *baru, *bantu;
        baru = new node();
        baru->data= data;

        //transvering
        bantu = head;
        int nomor = 1;
        while ( nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        baru ->next = bantu->next;
        bantu->next = baru;
    }
}

//hapus depan
void hapus_depan_154(){
    node * hapus;
    if (isEmpty_154()==false){
        if ( head->next!=NULL){
            hapus = head;
            head = head-> next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "list kosong!"<<endl;
    }
}
//hapus belakang
void hapus_belakang_154(){
    node *hapus;
    node *bantu;
    if (isEmpty_154()==false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next !=tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next= NULL;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << " list kosong!"<<endl;
    }
}
//hapus tengah
void hapus_tengah_154(int posisi){
    node * bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitung_list_154()){
        cout << "posisi diluar jangkauan"<<endl;
    }
    else if ( posisi == 1){
        cout << " posisi bukan posisi tengah"<<endl;
    }
    else {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi){
            if (nomor==posisi -1){
                sebelum = bantu;
            }
            if (nomor == posisi){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}
// ubah depan
void ubah_depan_154(int data){
    if (isEmpty_154()==0){
        head->data = data;
    }
    else{
        cout << "list masih kosong!"<<endl;
    }
}
// ubah tengah
void ubah_tengah_154(int data, int posisi){
    node *bantu;
    if (isEmpty_154()==0){
        if (posisi < 1 || posisi > hitung_list_154()){
            cout << " posisi di luar jangkauan"<<endl;
        }
        else if (posisi==1){
            cout << " posisi bukan posisi tengah"<<endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while ( nomor < posisi){
                bantu = bantu->next;
                nomor++;
            }
            bantu->data=data;
        }
    }
    else{
        cout << " list masih kosong!"<<endl;
    }
}
//ubah belakang
void ubah_belakang_154(int data){
    if (isEmpty_154 ()==0){
        tail->data = data;
    }
    else {
        cout << "list masih kosong!"<<endl;
    }
}
//hapus list
void clear_list_154(){
    node *bantu, *hapus;
    bantu = head;
    while ( bantu !=NULL){
        hapus = bantu;
        bantu= bantu-> next;
        delete hapus;
    }
    head = tail = NULL;
    cout << " list berhasil terhapus"<<endl;
}
//tampilan list
void tampil_154 (){
    node *bantu;
    bantu = head;
    if (isEmpty_154()== false){
        while ( bantu != NULL){
            cout << bantu->data <<ends;
            bantu = bantu-> next;
        }
        cout << endl;
    }
    else {
        cout << " list masih kosong!"<<endl;
    }
}
int main (){
    init_154();
    insert_depan_154(3);
    tampil_154();
    insert_belakang_154(5);
    tampil_154();
    insert_depan_154(2);
    tampil_154();
    insert_depan_154(1);
    tampil_154();
    hapus_depan_154();
    tampil_154();
    hapus_belakang_154();
    tampil_154();
    insert_tengah_154(7, 2);
    tampil_154();
    hapus_tengah_154(2);
    tampil_154();
    ubah_depan_154(1);
    tampil_154();
    ubah_belakang_154(8);
    tampil_154();
    ubah_tengah_154(11, 2);
    tampil_154();
    return 0;
}