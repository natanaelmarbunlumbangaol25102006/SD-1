#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* next;
};

Node* head = NULL;

void tampilkanList() {
    if (head == NULL) {
        cout << "Isi Linked List: NULL\n";
        return;
    }
    
    cout << "Isi Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nilai << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void tambahAwal(int nilai) {
    Node* newNode = new Node();
    newNode->nilai = nilai;
    newNode->next = head;
    head = newNode;
}

void tambahAkhir(int nilai) {
    Node* newNode = new Node();
    newNode->nilai = nilai;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void tambahSetelah(int nilaiBaru, int nilaiCari) {
    if (head == NULL) {
        cout << "Linked List masih kosong!\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->nilai != nilaiCari) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Nilai " << nilaiCari << " tidak ditemukan dalam list.\n";
    } else {
        Node* newNode = new Node();
        newNode->nilai = nilaiBaru;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void hapusNilai(int nilaiHapus) {
    if (head == NULL) {
        cout << "Linked List masih kosong!\n";
        return;
    }

    if (head->nilai == nilaiHapus) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL && current->nilai != nilaiHapus) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Nilai " << nilaiHapus << " tidak ditemukan dalam list.\n";
    } else {
        prev->next = current->next;
        delete current;
    }
}

int main() {
    int pilihan, nilai, nilaiCari;

    do {
        cout << "\n===== MENU SINGLE LINKED LIST =====\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahAwal(nilai);
                tampilkanList();
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahAkhir(nilai);
                tampilkanList();
                break;
            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> nilaiCari;
                tambahSetelah(nilai, nilaiCari);
                tampilkanList();
                break;
            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                hapusNilai(nilai);
                tampilkanList();
                break;
            case 5:
                tampilkanList();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}