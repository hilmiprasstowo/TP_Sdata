#ifndef CART_H
#define CART_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "database.h"
#include "inputoutput.h"
using namespace std;

class Cart {
private:
    struct CartItem {
        string name;
        long long int price;
        int days;
    };

    struct Customer {
        string name; // Nama pelanggan
        long long int totalPayment; // Total pembayaran
    };

    CartItem items[100]; 
    Customer queue[100]; // Array untuk menyimpan antrian pelanggan
    int itemCount = 0;   
    int front = 0;       // Indeks depan dari antrian
    int rear = 0;        // Indeks belakang dari antrian
    int queueCount = 0;  // Jumlah pelanggan dalam antrian

public:
    void addItem(const string& item, long long int price, int days) {
        if (itemCount >= 100) {
            cout << "Keranjang penuh. Tidak dapat menambahkan item lagi." << endl;
            return;
        }
        items[itemCount] = {item, price, days};
        itemCount++;
        cout << "Item \"" << item << "\" berhasil ditambahkan ke keranjang." << endl;
    }

    void viewCart() {
        if (itemCount == 0) {
            cout << "Keranjang Anda kosong." << endl;
            return;
        }
        cout << "=================================" << endl;
        cout << "|\tKeranjang Belanja Anda\t|" << endl;
        cout << "=================================" << endl;
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << items[i].name << "\t\tRp" << items[i].price << " untuk " << items[i].days << " hari" << endl;
        }
    }

    void checkout() {
        if (itemCount == 0) {
            cout << "Keranjang Anda kosong. Tidak dapat melakukan checkout." << endl;
            return;
        }

        long long int total = 0;
        for (int i = 0; i < itemCount; i++) {
            total += items[i].price;
        }

        char siswa;
        double discount = 1.0;
        cout << "Apakah Anda seorang mahasiswa dengan surat rekomendasi? (y/n): ";
        cin >> siswa;
        if (siswa == 'y' || siswa == 'Y') {
            discount = 0.5;
            cout << "Anda mendapatkan diskon 50%." << endl;
        }

        long long int discountedTotal = total * discount;

        char isDelivery;
        long long int deliveryCharge = 0;
        if (discountedTotal >= 500000) {
            cout << "Anda memenuhi syarat untuk gratis antar jemput dalam radius 300km." << endl;
            cout << "Apakah Anda ingin menggunakan layanan antar jemput? (y/n): ";
            cin >> isDelivery;
            if (isDelivery == 'y' || isDelivery == 'Y') {
                int distance;
                cout << "Masukkan jarak antar (dalam km): ";
                cin >> distance;
                if (distance > 300) {
                    deliveryCharge = (distance - 300) * 4000;
                    cout << "Biaya tambahan untuk jarak lebih dari 300km: Rp" << deliveryCharge << endl;
                }
            }
        } else {
            cout << "Anda tidak memenuhi syarat untuk gratis antar jemput." << endl;
        }

        long long int finalTotal = discountedTotal + deliveryCharge;
        long long int dp = finalTotal / 2;

        char paymentMethod;
        cout << "Pilih metode pembayaran (c: cash, t: transfer bank): ";
        cin >> paymentMethod;
        string paymentMethodStr = (paymentMethod == 'c' || paymentMethod == 'C') ? "Cash" : "Transfer Bank";

        // Tambahkan ke antrian pelanggan
        if (queueCount < 100) {
            cout << "Masukkan nama pelanggan: ";
            cin.ignore(); // Menghindari masalah input
            getline(cin, queue[rear].name); // Simpan nama pelanggan
            queue[rear].totalPayment = finalTotal;
            rear = (rear + 1) % 100; // Tambahkan ke antrian
            queueCount++;
        }

        ofstream outFile("ringkasan_pembayaran.txt");
        outFile << "=================================" << endl;
        outFile << "|\tRingkasan Pembayaran\t|" << endl;
        outFile << "=================================" << endl;
        for (int i = 0; i < itemCount; i++) {
            outFile << items[i].name << "\t\tRp" << items[i].price << " untuk " << items[i].days << " hari" << endl;
        }
        outFile << "Total Harga: Rp" << total << endl;
        outFile << "Diskon: " << (1 - discount) * 100 << "%" << endl;
        outFile << "Total Setelah Diskon: Rp" << discountedTotal << endl;
        outFile << "Biaya Antar Jemput: Rp" << deliveryCharge << endl;
        outFile << "Total Pembayaran: Rp" << finalTotal << endl;
        outFile << "DP 50%: Rp" << dp << endl;
        outFile << "Metode Pembayaran: " << paymentMethodStr << endl;
        outFile << "Nama Pelanggan: " << queue[(rear - 1 + 100) % 100].name << endl;
        outFile.close();

        cout << "Total Pembayaran: Rp" << finalTotal << endl;
        cout << "DP 50%: Rp" << dp << endl;
        cout << "Ringkasan pembayaran telah disimpan dalam file 'ringkasan_pembayaran.txt'." << endl;

        itemCount = 0;
    }

    // Fungsi untuk admin melihat antrian pelanggan
    void viewQueue() {
        if (queueCount == 0) {
            cout << "Antrian kosong." << endl;
            return;
        }

        cout << "Antrian Pembayaran:" << endl;
        for (int i = 0; i < queueCount; i++) {
            int index = (front + i) % 100;
            cout << i + 1 << ". Nama: " << queue[index].name << ", Total Pembayaran: Rp" << queue[index].totalPayment << endl;
        }
    }

    // Fungsi untuk admin mengkonfirmasi pembayaran
    void confirmPayment() {
        if (queueCount == 0) {
            cout << "Antrian kosong." << endl;
            return;
        }

        cout << "Konfirmasi pembayaran untuk pelanggan: " << queue[front].name << endl;
        front = (front + 1) % 100;
        queueCount--;
        cout << "Pembayaran berhasil dikonfirmasi." << endl;
    }
};

#endif