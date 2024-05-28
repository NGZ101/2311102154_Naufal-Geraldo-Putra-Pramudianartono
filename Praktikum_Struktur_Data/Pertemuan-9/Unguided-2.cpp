#include <iostream>
#include <iomanip>
#include <cctype>
    using namespace std;
struct Pohon{
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;
void init(){
    root = NULL;
}
bool isEmpty(){
    return root == NULL;
}
void buatNode(char data){
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "Node " << data << " berhasil dibuat sebagai root."
             << endl;
    }
    else
    {
        cout << "Tree sudah ada!" << endl;
    }
}
Pohon *findNode(Pohon *node, char data) // mencari node
{
    if (node == NULL) return NULL;
    if (node->data == data) return node;

    Pohon *foundNode = findNode(node->left, data);
    if (foundNode == NULL)
        foundNode = findNode(node->right, data);

    return foundNode;
}
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kiri !" << endl;
                return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
                return baru;
        }
    }
}
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kanan !" << endl;
                return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
                return baru;
        }
    }
}
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi "
                 << data << endl;
        }
    }
}
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// postOrder
void postOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}
// Hapus Tree
void clear()
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void characteristic()
{
    cout << "\n size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}
void printChild(Pohon *node) 
{
    if(isEmpty()) {
        cout << "Buat tree terlebih dahulu" << endl;
    }
    else if (!node) {
        cout << "Node yang ditunjuk tidak ada" << endl;
    }
    else {
        if(node->left) {
            cout << "Child Kiri: " << node->left->data << endl;
        }
        else {
            cout << "Child Kiri: tidak ada" << endl;
        }

        if(node->right) {
            cout << "Child Kanan: " << node->right->data << endl;
        }
        else {
            cout << "Child Kanan: tidak ada" << endl;
        }
    }
}
void printDescendants(Pohon* node){
    if(!node) return;
    if(node->left) {
        cout << " " << node->left->data;
        printDescendants(node->left);
    }
    if(node->right) {
        cout << " " << node->right->data;
        printDescendants(node->right);
    }
}
int main(){
    init();
    char pilih_154, data_154, posisi_154, data_parent_154;
    Pohon *node;

    do {
        cout << "==== Program Tree Naufal Geraldo ====" << endl;
        cout << "==== Menu Program ====" << endl;
        cout << "1. Buat Node Root" << endl;
        cout << "2. Tambah child kiri atau kanan" << endl;
        cout << "3. Update Node" << endl;
        cout << "4. Characteristic" << endl;
        cout << "5. Find Node" << endl;
        cout << "6. Pre Order" << endl;
        cout << "7. In Order" << endl;
        cout << "8. Post Order" << endl;
        cout << "9. Tampilkan Child" << endl;
        cout << "0. Tampilkan Descendants" << endl;
        cout << "Pilihan Anda = ";
        cin >> pilih_154;

        switch (pilih_154)
        {
        case '1': 
            cout << "Masukkan data untuk root: ";
            cin >> data_154;
            buatNode(data_154);
            break;

        case '2': 
            cout << "Masukkan data untuk child: ";
            cin >> data_154;
            cout << "Child yang diinput berada di posisi (kiri/left (L/l) / kanan/right (R/r)): ";
            cin >> posisi_154;
            posisi_154 = toupper(posisi_154);
            cout << "Masukkan data dari parent node: ";
            cin >> data_parent_154;
            node = findNode(root, data_parent_154);
            if (node == NULL){
                cout << "Node dengan data " << data_parent_154 << " tidak ditemukan" << endl;
            }
            else{
                if (posisi_154 == 'L') {
                    insertLeft(data_154, node);
                }
                else if (posisi_154 == 'R') {
                    insertRight(data_154, node);
                }
                else{
                    cout << "Pilihan tidak valid!" << endl;
                }
            }
            break;

        case '3': 
            cout << "Masukkan data baru untuk update: ";
            cin >> data_154;
            cout << "Masukkan data dari node yang ingin update: ";
            cin >> data_parent_154;
            node = findNode(root, data_parent_154);
            if (node == NULL){
                cout << "Node dengan data " << data_parent_154 << " tidak ditemukan!" << endl;
            }
            else{
                update(data_154, node);
            }
            break;

        case '4': 
            cout << "Karakteristik dari tree ini:";
            characteristic();
            break;

        case '5': 
            cout << "Masukkan data dari node yang ingin dicari: ";
            cin >> data_parent_154;
            node = findNode(root, data_parent_154);
            if (node == NULL){
                cout << "Node dengan data " << data_parent_154 << " tidak ditemukan!" << endl;
            }
            else{
                find(node);
            }
            break;

        case '6': 
            cout << "PreOrder Traversal: ";
            preOrder(root);
            cout << endl;
            break;

        case '7': 
            cout << "InOrder Traversal: ";
            inOrder(root);
            cout << endl;
            break;

        case '8': 
            cout << "PostOrder Traversal: ";
            postOrder(root);
            cout << endl;
            break;

        case '9': 
            cout << "Masukkan data dari node yang ingin melihat child: ";
            cin >> data_parent_154;
            node = findNode(root, data_parent_154);
            if (node == NULL){
                cout << "Node dengan data " << data_parent_154 << " tidak ditemukan!" << endl;
            }
            else{
                cout << "Child of node " << data_parent_154 << " :";
                printChild(node);
                cout << endl;
            }
            break;

        case '0': 
            cout << "Masukkan data dari node yang ingin melihat descendants: ";
            cin >> data_parent_154;
            node = findNode(root, data_parent_154);
            if (node == NULL){
                cout << "Node dengan data " << data_parent_154 << " tidak ditemukan!" << endl;
            }
            else{
                cout << "Descendants of node " << data_parent_154 << " :";
                printDescendants(node);
                cout << endl;
            }
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    } while (pilih_154 != '0');
}