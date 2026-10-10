#include <iostream>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void preOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}

void deleteTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    int number;

    std::cout << "Selamat siang! Mari kita bangun Binary Search Tree Anda." << std::endl;
    std::cout << "Masukkan angka (ketik 0 untuk berhenti dan menampilkan hasil):" << std::endl;

    while (true) {
        std::cout << "Masukkan angka: ";
        std::cin >> number;

        if (number == 0) {
            break;
        }

        root = insert(root, number);
    }

    if (root == nullptr) {
        std::cout << "\nTree kosong, tidak ada data untuk ditampilkan." << std::endl;
    } else {
        std::cout << "\nTree telah berhasil dibangun. Berikut adalah hasil traversalnya:" << std::endl;

        std::cout << "Pre-order Traversal  : ";
        preOrderTraversal(root);
        std::cout << std::endl;

        std::cout << "In-order Traversal   : ";
        inOrderTraversal(root);
        std::cout << std::endl;

        std::cout << "Post-order Traversal : ";
        postOrderTraversal(root);
        std::cout << std::endl;
    }

    deleteTree(root);
    
    std::cout << "Terima kasih telah menggunakan program ini!" << std::endl;

    return 0;
}