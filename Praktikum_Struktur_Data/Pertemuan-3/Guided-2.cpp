#include <iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    void push_154(int data) {
        Node* newNode = new Node;
        newNode -> data = data;
        newNode -> prev = nullptr;
        newNode -> next = head;
        if(head != nullptr) {
            head -> prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop_154() {
        if(head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head -> next;
        if (head != nullptr) {
            head -> prev = nullptr;
        }
        else {
            tail = nullptr;
        }
    }
    bool update_154(int oldData, int newData) {
        Node* current = head;
        while(current != nullptr) {
            if(current -> data == oldData) {
                current -> data = newData;
                return true;
            }
            current = current -> next;
        }
        return false;
    }
    void delete_all_154() {
        Node* current = head;
        while(current != nullptr) {
            Node* temp = current;
            current = current -> next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display_154() {
        Node* current = head;
        while(current != nullptr) {
            cout << current -> data << " ";
            current = current -> next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while(true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: " ;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add:  ";
                cin >> data;
                list.push_154(data);
                break;
            }
            case 2: {
                list.pop_154();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update_154(oldData, newData);
                if(!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.delete_all_154();
                break;
            }
            case 5: {
                list.display_154();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}