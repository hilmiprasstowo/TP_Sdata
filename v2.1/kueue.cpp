#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;     // deklarasi variable Nama pasien
    int priority;    // deklarasi variable Prioritas pasien
    Node* next;      // deklarasi Pointer ke node berikutnya
    Node* prev;      // deklarasi Pointer ke node sebelumnya
};

// Priority Queue menggunakan elemen ke dalam antrian
class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue() {
        head = NULL;
    }

    // Fungsi untuk menambahkan pasien ke antrian
    void enqueue(string name, int priority) {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->priority = priority;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* current = head;

        // Cari posisi yang sesuai berdasarkan prioritas
        while (current != NULL && current->priority <= priority) {
            current = current->next;
        }

        if (current == NULL) {
            Node* tail = head;
            while (tail->next != NULL)
                tail = tail->next;

            tail->next = newNode;
            newNode->prev = tail;
        } else if (current->prev == NULL) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            Node* prevNode = current->prev;
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = current;
            current->prev = newNode;
        }
    }

    // Fungsi untuk melayani pasien (hapus node di head)
    void dequeue() {
        if (head == NULL) {
            cout << "Antrian Kosong" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
    }

    // Fungsi untuk menampilkan isi antrian
    void display() {
        if (head == NULL) {
            cout << "Antrian Kosong" << endl;
            return;
        }
        Node* current = head;
        while (current != NULL) {
            cout << "(" << current->name << ", Prioritas " << current->priority << ") -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    PriorityQueue pq;
    
    int pilihan;
    do {
        cout << "Menu Antrian Pasien Rumah Sakit" << endl;
        cout << "1. Tambahkan Pasien" << endl;
        cout << "2. Layanan Pasien" << endl;
        cout << "3. Tampilan Antrian" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            string nama;
            int prioritas;
            cout << "Masukkan nama pasien: ";
            cin >> nama;
            cout << "Masukkan prioritas(1 = urgent, 2 = Normal, 3 = Ringan): ";
            cin >> prioritas;
            pq.enqueue(nama, prioritas);
            
            cout << endl;
            break;
            
            
        }
        case 2:
            cout << "Layanan Pasien..." << endl;
            pq.dequeue();
            break;
        case 3:
            cout << "Antrian Pasien: ";
            pq.display();
            
            cout << endl;
            break;
        case 4:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Anda salah memasukkan opsi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}