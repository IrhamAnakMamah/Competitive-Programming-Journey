#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Node(int val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

// Variabel global untuk menyimpan root dan daftar node
Node* root = nullptr;
vector<Node*> nodes;

// Fungsi untuk melakukan heapify ke atas
void heapifyUp(Node* node) {
    if (!node->parent) return;
    if (node->value > node->parent->value) {
        swap(node->value, node->parent->value);
        heapifyUp(node->parent);
    }
}

// Fungsi untuk melakukan heapify ke bawah
void heapifyDown(Node* node) {
    if (!node) return;
    Node* largest = node;
    if (node->left && node->left->value > largest->value) {
        largest = node->left;
    }
    if (node->right && node->right->value > largest->value) {
        largest = node->right;
    }
    if (largest != node) {
        swap(node->value, largest->value);
        heapifyDown(largest);
    }
}

// Fungsi untuk menyisipkan elemen baru ke dalam heap
void insert(int value) {
    Node* newNode = new Node(value);
    if (!root) {
        root = newNode;
        nodes.push_back(newNode);
        return;
    }

    // Menentukan lokasi untuk node baru
    Node* parent = nodes[(nodes.size() - 1) / 2];
    if (!parent->left) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    newNode->parent = parent;
    nodes.push_back(newNode);

    // Lakukan heapify ke atas untuk menjaga properti max-heap
    heapifyUp(newNode);
}

// Fungsi untuk menemukan node dengan nilai tertentu
Node* findNode(int value) {
    for (Node* node : nodes) {
        if (node->value == value) {
            return node;
        }
    }
    return nullptr;
}

// Fungsi untuk menghapus node tertentu
void deleteNode(int value) {
    Node* targetNode = findNode(value);
    if (!targetNode) {
        cout << "Node dengan nilai " << value << " tidak ditemukan!" << endl;
        return;
    }

    if (nodes.size() == 1) {
        delete root;
        root = nullptr;
        nodes.clear();
        return;
    }

    // Pindahkan nilai dari node terakhir ke target node
    Node* lastNode = nodes.back();
    targetNode->value = lastNode->value;

    // Hapus node terakhir
    if (lastNode->parent->left == lastNode) {
        lastNode->parent->left = nullptr;
    } else {
        lastNode->parent->right = nullptr;
    }
    nodes.pop_back();
    delete lastNode;

    // Heapify up atau down sesuai kebutuhan
    if (targetNode->parent && targetNode->value > targetNode->parent->value) {
        heapifyUp(targetNode);
    } else {
        heapifyDown(targetNode);
    }
}

// Fungsi untuk mencetak heap secara level-order
void printHeap() {
    for (Node* node : nodes) {
        cout << node->value << " ";
    }
    cout << endl;
}

int main() {
    insert(10);
    insert(20);
    insert(15);
    insert(30);
    insert(40);

    cout << "Heap setelah beberapa kali insert: ";
    printHeap();

    cout << "Menghapus node dengan nilai 15..." << endl;
    deleteNode(15);
    cout << "Heap setelah menghapus 15: ";
    printHeap();

    cout << "Menghapus node dengan nilai 40..." << endl;
    deleteNode(40);
    cout << "Heap setelah menghapus 40: ";
    printHeap();

    return 0;
}
