#ifndef RENTAL_H
#define RENTAL_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "database.h"
#include "cart.h"


class Rental {
private:
    int temp;
    InputOutput io;
    Cart cart;

public:
	
    void katalogCanon() {
    char sortOption;
    cout << "Ingin mengurutkan berdasarkan harga? (a: termurah, d: termahal): ";
    cin >> sortOption;

    if (sortOption == 'a') {
        io.printKatalogCanon(true);
    } else if (sortOption == 'd') {
        io.printKatalogCanon(false);
    }
	
	
    char addMore;
    do {
        int temp;
        cout << "Masukkan nomor kamera yang ingin ditambahkan ke wishlist: ";
        cin >> temp;
        if (temp > 0 && temp <= io.getDatabase().jumlahVariantCanon()) {
            int days;
            cout << "Berapa hari Anda ingin menyewa kamera ini? ";
            cin >> days;

            double itemPrice = io.getDatabase().priceCanon(temp - 1);
            double totalPrice = itemPrice * days;

            cart.addItem(io.getDatabase().namaCanon(temp - 1), totalPrice, days);

            cout << "Kamera telah ditambahkan ke wishlist dengan total harga untuk " << days << " hari: " << totalPrice << endl;
        } else {
            cout << "Nomor kamera tidak valid." << endl;
        }

        cout << "Apakah Anda ingin menambahkan item lagi? (y/n): ";
        cin >> addMore;
        cin.ignore();
    } while(addMore == 'y' || addMore == 'Y');
}

    void searchCanon() {
    string query;
    cout << "Masukkan kata kunci untuk mencari kamera Canon: ";
    cin.ignore();
    getline(cin, query);

    int results[100]; 
    int count = 0;  

    io.getDatabase().searchCanon(query, results, count);
    io.printSearchResultsCanon(results, count);
}

    
      void addToCart(const string& item, long long int price, int days) {
        cart.addItem(item, price, days);
    }

    void viewCart() {
        cart.viewCart();
    }

    void checkout() {
        cart.checkout();
    }
    
    
    void searchkamera() {
        bool ulang = true;
        while (ulang) {
            cout << endl;
            cout << "=====================================" << endl;
            cout << "|           search kamera           |" << endl;
            cout << "=====================================" << endl;
            cout << "1. search canon" << endl;
            cout << "2. search sony" << endl;
            cout << "3. Kembali ke menu utama" << endl;
            cout << "=====================================" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> temp;
            switch (temp) {
                case 1:
                   searchCanon();
                    break;
                case 2:
                   
                    break;
                case 3:
                   ulang = false;
                    break;
                default:
                    cout << "Pilihan tidak tersedia, harap masukkan lagi." << endl;
                    break;
            }
        }
    }
    
    
        void sewaKamera() {
        bool ulang = true;
        while (ulang) {
            cout << endl;
            cout << "=====================================" << endl;
            cout << "|      Kategori Rental kamera       |" << endl;
            cout << "=====================================" << endl;
            cout << "1. Katalog Kamera Canon" << endl;
            cout << "2. Katalog Kamera Sony" << endl;
            cout << "3. Cari Kamera" << endl;
            cout << "4. Lihat Wishlist" << endl;
            cout << "5. Kembali ke menu utama" << endl;
            cout << "=====================================" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> temp;
            switch (temp) {
                case 1:
                    katalogCanon();
                    break;
                case 2:
                    
                    break;
                case 3:
                    searchkamera();
                    break;
                case 4:
                    cart.viewCart();
                    break;
                case 5:
                     ulang = false;
                    break;
                default:
                    cout << "Pilihan tidak tersedia, harap masukkan lagi." << endl;
                    break;
            }
        }
    }
    

    void home() {
        bool ulang = true;
        io.sinkronisasiData(); // Sinkronisasi data ke database
        while (ulang) {
            cout << endl;
            cout << "=========================" << endl;
            cout << "|\tMenu Utama\t|" << endl;
            cout << "=========================" << endl;
            cout << "1. Sewa" << endl;
            cout << "2. Informasi BSM" << endl;
            cout << "3. Lihat Wishlist" << endl;
            cout << "4. Checkout" << endl;
            cout << "5. lihat antrian" << endl;
            cout << "6. konfirmasi pembelian" << endl;
            cout << "7. Exit" << endl;
            cout << "=========================" << endl;
            cout << "Pilih menu: ";
            cin >> temp;
            switch (temp) {
                case 1:
                    sewaKamera();
                    break;
                case 2:
                    cout << "=====================================" << endl;
                    cout << "Kontak BSM RENTAL" << endl;
                    cout << "Nomor Telepon: 021-22792541" << endl;
                    cout << "Instagram: @bsmyogyakarta" << endl;
                    cout << "=====================================" << endl;
                   
                    break;
                case 3:
                    cart.viewCart();
                    break;
                case 4:
                    cart.checkout();
                    break;
                case 5:
                	cart.viewQueue();
                	break;
                case 6:
                	cart.confirmPayment();
                	break;
                case 7:
                    cout << "=====================================" << endl;
                    cout << "Terima kasih telah menggunakan layanan BSM RENTAL" << endl;
                    cout << "=====================================" << endl;
                    ulang = false;  // Mengakhiri perulangan menu home
                    break;
                default:
                    cout << "Menu tidak tersedia, harap masukkan lagi." << endl;
                    break;
            }
        }
    }
};

bool mulai() {
	Rental rental;
        rental.home();  
        return 0;
}

#endif