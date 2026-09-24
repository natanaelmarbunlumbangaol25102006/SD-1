#include <iostream>
#include <string>
using namespace std;

#define MAX 100

// Struktur Stack
struct Stack {
    char data[MAX];
    int top;
};

// Mengecek apakah stack kosong
bool isEmpty(Stack &s) {
    return s.top == -1;
}

// Mengecek apakah stack penuh
bool isFull(Stack &s) {
    return s.top == MAX - 1;
}

// Menambahkan data ke stack
void push(Stack &s, char huruf) {
    if (isFull(s)) {
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = huruf;
    }
}

// Mengambil data dari stack
char pop(Stack &s) {
    if (isEmpty(s)) {
        return '\0';
    } else {
        char huruf = s.data[s.top];
        s.top--;
        return huruf;
    }
}

int main() {
    Stack s;
    s.top = -1;

    string kata;

    // Input kata
    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    // Memasukkan setiap huruf ke stack
    for (int i = 0; i < kata.length(); i++) {
        push(s, kata[i]);
    }

    // Menampilkan kata yang sudah dibalik
    cout << "Kata setelah dibalik: ";

    while (!isEmpty(s)) {
        cout << pop(s);
    }

    cout << endl;

    return 0;
}