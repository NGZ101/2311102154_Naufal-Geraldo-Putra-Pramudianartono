// Naufal Geraldo Putra - 2311102154
#include <iostream>
using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;
string queueTeller[maksimalQueue]; // TODO: Lengkapi bagian ini

bool isFull() {
    return back == maksimalQueue;// TODO: Lengkapi bagian ini
}

bool isEmpty() {
    return front == back;// TODO: Lengkapi bagian ini
}

void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        queueTeller[back] = data;
        back++;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        queueTeller[back-1] = "";
        back--;// TODO: Lengkapi bagian ini
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    int i;
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for(i=0; i<maksimalQueue; i++) {
            queueTeller[i] = "";
        }
        front = back = 0;// TODO: Lengkapi bagian ini
    }
}

void viewQueue() {
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
} 

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    enqueueAntrian("Putri");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
} 