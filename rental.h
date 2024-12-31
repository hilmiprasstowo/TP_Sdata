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

void katalogSony() {
    char sortOption;
    cout << "Ingin mengurutkan berdasarkan harga? (a: termurah, d: termahal): ";
    cin >> sortOption;

    if (sortOption == 'a') {
        io.printKatalogSony(true);
    } else if (sortOption == 'd') {
        io.printKatalogSony(false);
    }
	
	
    char addMore;
    do {
        int temp;
        cout << "Masukkan nomor kamera yang ingin ditambahkan ke wishlist: ";
        cin >> temp;
        if (temp > 0 && temp <= io.getDatabase().jumlahVariantSony()) {
            int days;
            cout << "Berapa hari Anda ingin menyewa kamera ini? ";
            cin >> days;

            double itemPrice = io.getDatabase().priceSony(temp - 1);
            double totalPrice = itemPrice * days;

            cart.addItem(io.getDatabase().namaSony(temp - 1), totalPrice, days);

            cout << "Kamera telah ditambahkan ke wishlist dengan total harga untuk " << days << " hari: " << totalPrice << endl;
        } else {
            cout << "Nomor kamera tidak valid." << endl;
        }

        cout << "Apakah Anda ingin menambahkan item lagi? (y/n): ";
        cin >> addMore;
        cin.ignore();
    } while(addMore == 'y' || addMore == 'Y');
}

    void searchSony() {
    string query;
    cout << "Masukkan kata kunci untuk mencari kamera Sony: ";
    cin.ignore();
    getline(cin, query);

    int results[100]; 
    int count = 0;  

    io.getDatabase().searchSony(query, results, count);
    io.printSearchResultsSony(results, count);
}

void katalogNikon() {
    char sortOption;
    cout << "Ingin mengurutkan berdasarkan harga? (a: termurah, d: termahal): ";
    cin >> sortOption;

    if (sortOption == 'a') {
        io.printKatalogNikon(true);
    } else if (sortOption == 'd') {
        io.printKatalogNikon(false);
    }

    char addMore;
    do {
        int temp;
        cout << "Masukkan nomor kamera yang ingin ditambahkan ke wishlist: ";
        cin >> temp;
        if (temp > 0 && temp <= io.getDatabase().jumlahVariantNikon()) {
            int days;
            cout << "Berapa hari Anda ingin menyewa kamera ini? ";
            cin >> days;

            double itemPrice = io.getDatabase().priceNikon(temp - 1);
            double totalPrice = itemPrice * days;

            cart.addItem(io.getDatabase().namaNikon(temp - 1), totalPrice, days);

            cout << "Kamera telah ditambahkan ke wishlist dengan total harga untuk " << days << " hari: " << totalPrice << endl;
        } else {
            cout << "Nomor kamera tidak valid." << endl;
        }

        cout << "Apakah Anda ingin menambahkan item lagi? (y/n): ";
        cin >> addMore;
        cin.ignore();
    } while(addMore == 'y' || addMore == 'Y');
}

void searchNikon() {
    string query;
    cout << "Masukkan kata kunci untuk mencari kamera Nikon: ";
    cin.ignore();
    getline(cin, query);

    int results[100]; 
    int count = 0;  

    io.getDatabase().searchNikon(query, results, count);
    io.printSearchResultsNikon(results, count);
}

void katalogFujifilm() {
    char sortOption;
    cout << "Ingin mengurutkan berdasarkan harga? (a: termurah, d: termahal): ";
    cin >> sortOption;

    if (sortOption == 'a') {
        io.printKatalogFujifilm(true);
    } else if (sortOption == 'd') {
        io.printKatalogFujifilm(false);
    }

    char addMore;
    do {
        int temp;
        cout << "Masukkan nomor kamera yang ingin ditambahkan ke wishlist: ";
        cin >> temp;
        if (temp > 0 && temp <= io.getDatabase().jumlahVariantFujifilm()) {
            int days;
            cout << "Berapa hari Anda ingin menyewa kamera ini? ";
            cin >> days;

            double itemPrice = io.getDatabase().priceFujifilm(temp - 1);
            double totalPrice = itemPrice * days;

            cart.addItem(io.getDatabase().namaFujifilm(temp - 1), totalPrice, days);

            cout << "Kamera telah ditambahkan ke wishlist dengan total harga untuk " << days << " hari: " << totalPrice << endl;
        } else {
            cout << "Nomor kamera tidak valid." << endl;
        }

        cout << "Apakah Anda ingin menambahkan item lagi? (y/n): ";
        cin >> addMore;
        cin.ignore();
    } while(addMore == 'y' || addMore == 'Y');
}

void searchFujifilm() {
    string query;
    cout << "Masukkan kata kunci untuk mencari kamera Fujifilm: ";
    cin.ignore();
    getline(cin, query);

    int results[100]; 
    int count = 0;  

    io.getDatabase().searchFujifilm(query, results, count);
    io.printSearchResultsFujifilm(results, count);
}

void katalogOlympus() {
    char sortOption;
    cout << "Ingin mengurutkan berdasarkan harga? (a: termurah, d: termahal): ";
    cin >> sortOption;

    if (sortOption == 'a') {
        io.printKatalogOlympus(true);
    } else if (sortOption == 'd') {
        io.printKatalogOlympus(false);
    }

    char addMore;
    do {
        int temp;
        cout << "Masukkan nomor kamera yang ingin ditambahkan ke wishlist: ";
        cin >> temp;
        if (temp > 0 && temp <= io.getDatabase().jumlahVariantOlympus()) {
            int days;
            cout << "Berapa hari Anda ingin menyewa kamera ini? ";
            cin >> days;

            double itemPrice = io.getDatabase().priceOlympus(temp - 1);
            double totalPrice = itemPrice * days;

            cart.addItem(io.getDatabase().namaOlympus(temp - 1), totalPrice, days);

            cout << "Kamera telah ditambahkan ke wishlist dengan total harga untuk " << days << " hari: " << totalPrice << endl;
        } else {
            cout << "Nomor kamera tidak valid." << endl;
        }

        cout << "Apakah Anda ingin menambahkan item lagi? (y/n): ";
        cin >> addMore;
        cin.ignore();
    } while(addMore == 'y' || addMore == 'Y');
}

void searchOlympus() {
    string query;
    cout << "Masukkan kata kunci untuk mencari kamera Olympus: ";
    cin.ignore();
    getline(cin, query);

    int results[100]; 
    int count = 0;  

    io.getDatabase().searchOlympus(query, results, count);
    io.printSearchResultsOlympus(results, count);
}



void katalogAudioRecorder() {
    char sortOption;
    cout << "Ingin mengurutkan berdasarkan harga? (a: termurah, d: termahal): ";
    cin >> sortOption;

    if (sortOption == 'a') {
        io.printKatalogAudioRecorder(true);
    } else if (sortOption == 'd') {
        io.printKatalogAudioRecorder(false);
    }

    char addMore;
    do {
        int temp;
        cout << "Masukkan nomor audio recorder yang ingin ditambahkan ke wishlist: ";
        cin >> temp;
        if (temp > 0 && temp <= io.getDatabase().jumlahVariantAudioRecorder()) {
            int days;
            cout << "Berapa hari Anda ingin menyewa audio recorder ini? ";
            cin >> days;

            double itemPrice = io.getDatabase().priceAudioRecorder(temp - 1);
            double totalPrice = itemPrice * days;

            cart.addItem(io.getDatabase().namaAudioRecorder(temp - 1), totalPrice, days);

            cout << "Audio Recorder telah ditambahkan ke wishlist dengan total harga untuk " << days << " hari: " << totalPrice << endl;
        } else {
            cout << "Nomor audio recorder tidak valid." << endl;
        }

        cout << "Apakah Anda ingin menambahkan item lagi? (y/n): ";
        cin >> addMore;
        cin.ignore();
    } while(addMore == 'y' || addMore == 'Y');
}

void searchAudioRecorder() {
    string query;
    cout << "Masukkan kata kunci untuk mencari audio recorder: ";
    cin.ignore();
    getline(cin, query);

    int results[100]; 
    int count = 0;  

    io.getDatabase().searchAudioRecorder(query, results, count);
    io.printSearchResultsAudioRecorder(results, count);
}

void katalogClipOn() {
    char sortOption;
    cout << "Ingin mengurutkan berdasarkan harga? (a: termurah, d: termahal): ";
    cin >> sortOption;

    if (sortOption == 'a') {
        io.printKatalogClipOn(true);
    } else if (sortOption == 'd') {
        io.printKatalogClipOn(false);
    }

    char addMore;
    do {
        int temp;
        cout << "Masukkan nomor clip-on yang ingin ditambahkan ke wishlist: ";
        cin >> temp;
        if (temp > 0 && temp <= io.getDatabase().jumlahVariantClipOn()) {
            int days;
            cout << "Berapa hari Anda ingin menyewa clip-on ini? ";
            cin >> days;

            double itemPrice = io.getDatabase().priceClipOn(temp - 1);
            double totalPrice = itemPrice * days;

            cart.addItem(io.getDatabase().namaClipOn(temp - 1), totalPrice, days);

            cout << "Clip-On telah ditambahkan ke wishlist dengan total harga untuk " << days << " hari: " << totalPrice << endl;
        } else {
            cout << "Nomor clip-on tidak valid." << endl;
        }

        cout << "Apakah Anda ingin menambahkan item lagi? (y/n): ";
        cin >> addMore;
        cin.ignore();
    } while(addMore == 'y' || addMore == 'Y');
}

void searchClipOn() {
    string query;
    cout << "Masukkan kata kunci untuk mencari clip-on: ";
    cin.ignore();
    getline(cin, query);

    int results[100]; 
    int count = 0;  

    io.getDatabase().searchClipOn(query, results, count);
    io.printSearchResultsClipOn(results, count);
}

void katalogHeadset() {
    char sortOption;
    cout << "Ingin mengurutkan berdasarkan harga? (a: termurah, d: termahal): ";
    cin >> sortOption;

    if (sortOption == 'a') {
        io.printKatalogHeadset(true);
    } else if (sortOption == 'd') {
        io.printKatalogHeadset(false);
    }

    char addMore;
    do {
        int temp;
        cout << "Masukkan nomor headset yang ingin ditambahkan ke wishlist: ";
        cin >> temp;
        if (temp > 0 && temp <= io.getDatabase().jumlahVariantHeadset()) {
            int days;
            cout << "Berapa hari Anda ingin menyewa headset ini? ";
            cin >> days;

            double itemPrice = io.getDatabase().priceHeadset(temp - 1);
            double totalPrice = itemPrice * days;

            cart.addItem(io.getDatabase().namaHeadset(temp - 1), totalPrice, days);

            cout << "Headset telah ditambahkan ke wishlist dengan total harga untuk " << days << " hari: " << totalPrice << endl;
        } else {
            cout << "Nomor headset tidak valid." << endl;
        }

        cout << "Apakah Anda ingin menambahkan item lagi? (y/n): ";
        cin >> addMore;
        cin.ignore();
    } while(addMore == 'y' || addMore == 'Y');
}

void searchHeadset() {
    string query;
    cout << "Masukkan kata kunci untuk mencari headset: ";
    cin.ignore();
    getline(cin, query);

    int results[100]; 
    int count = 0;  

    io.getDatabase().searchHeadset(query, results, count);
    io.printSearchResultsHeadset(results, count);
}

void katalogSoundDevices() {
    char sortOption;
    cout << "Ingin mengurutkan berdasarkan harga? (a: termurah, d: termahal): ";
    cin >> sortOption;

    if (sortOption == 'a') {
        io.printKatalogSoundDevices(true);
    } else if (sortOption == 'd') {
        io.printKatalogSoundDevices(false);
    }

    char addMore;
    do {
        int temp;
        cout << "Masukkan nomor sound devices yang ingin ditambahkan ke wishlist: ";
        cin >> temp;
        if (temp > 0 && temp <= io.getDatabase().jumlahVariantSoundDevices()) {
            int days;
            cout << "Berapa hari Anda ingin menyewa sound devices ini? ";
            cin >> days;

            double itemPrice = io.getDatabase().priceSoundDevices(temp - 1);
            double totalPrice = itemPrice * days;

            cart.addItem(io.getDatabase().namaSoundDevices(temp - 1), totalPrice, days);

            cout << "Sound Devices telah ditambahkan ke wishlist dengan total harga untuk " << days << " hari: " << totalPrice << endl;
        } else {
            cout << "Nomor sound devices tidak valid." << endl;
        }

        cout << "Apakah Anda ingin menambahkan item lagi? (y/n): ";
        cin >> addMore;
        cin.ignore();
    } while(addMore == 'y' || addMore == 'Y');
}

void searchSoundDevices() {
    string query;
    cout << "Masukkan kata kunci untuk mencari sound devices: ";
    cin.ignore();
    getline(cin, query);

    int results[100]; 
    int count = 0;  

    io.getDatabase().searchSoundDevices(query, results, count);
    io.printSearchResultsSoundDevices(results, count);
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
            cout << "3. search Nikon" << endl;
            cout << "4. search FujiFilm" << endl;
            cout << "5. search Olympus" << endl;
            cout << "6. Kembali ke menu utama" << endl;
            cout << "=====================================" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> temp;
            switch (temp) {
                case 1:
                   searchCanon();
                    break;
                case 2:
                   searchSony();
                    break;
                case 3:
                   searchNikon();
                    break;
                case 4:
                   searchFujifilm();
                    break;
                case 5:
                   searchOlympus();
                    break;
                case 6:
                   ulang = false;
                    break;
                default:
                    cout << "Pilihan tidak tersedia, harap masukkan lagi." << endl;
                    break;
            }
        }
    }
    
    void searchaudio() {
        bool ulang = true;
        while (ulang) {
            cout << endl;
            cout << "=====================================" << endl;
            cout << "|           search audio            |" << endl;
            cout << "=====================================" << endl;
            cout << "1. search audio recorder " << endl;
            cout << "2. search Clip on" << endl;
            cout << "3. search headset" << endl;
            cout << "4. search Microphone" << endl;
            cout << "5. search Sound device" << endl;
            cout << "6. Kembali ke menu utama" << endl;
            cout << "=====================================" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> temp;
            switch (temp) {
                case 1:
                   searchAudioRecorder();
                    break;
                case 2:
                   searchClipOn();
                    break;
                case 3:
                   searchHeadset();
                    break;
                case 4:
                   
                    break;
                case 5:
                   searchSoundDevices();
                    break;
                case 6:
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
            cout << "3. Katalog Kamera Nikon" << endl;
            cout << "4. Katalog Kamera Fujifilm" << endl;
            cout << "5. Katalog Kamera olympus" << endl;
            cout << "6. Cari Kamera" << endl;
            cout << "7. Lihat Wishlist" << endl;
            cout << "8. Kembali ke menu utama" << endl;
            cout << "=====================================" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> temp;
            switch (temp) {
                case 1:
                    katalogCanon();
                    break;
                case 2:
                    katalogSony();
                    break;
                case 3:
                    katalogNikon();
                    break;
                case 4:
                    katalogFujifilm();
                    break;
                case 5:
                    katalogOlympus();
                    break;
                case 6:
                    searchkamera();
                    break;
                case 7:
                    cart.viewCart();
                    break;
                case 8:
                     ulang = false;
                    break;
                default:
                    cout << "Pilihan tidak tersedia, harap masukkan lagi." << endl;
                    break;
            }
        }
    }
    
    void sewaAudio() {
        bool ulang = true;
        while (ulang) {
            cout << endl;
            cout << "=====================================" << endl;
            cout << "|     Kategori Rental Audio     |" << endl;
            cout << "=====================================" << endl;
            cout << "1. Katalog Audio Recorder" << endl;
            cout << "2. Katalog Clip on" << endl;
            cout << "3. Katalog Headset" << endl;
            cout << "4. Katalog Microphone" << endl;
            cout << "5. Katalog Sound device" << endl;
            cout << "6. Cari Audio" << endl;
            cout << "7. Lihat Wishlist" << endl;
            cout << "8. Kembali ke menu utama" << endl;
            cout << "=====================================" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> temp;
            switch (temp) {
                case 1:
                    katalogAudioRecorder();
                    break;
                case 2:
                    katalogClipOn();
                    break;
                case 3:
                    katalogHeadset();
                    break;
                case 4:
                    
                    break;
                case 5:
                    katalogSoundDevices();
                    break;
                case 6:
                    searchaudio();
                    break;
                case 7:
                    cart.viewCart();
                    break;
                case 8:
                     ulang = false;
                    break;
                default:
                    cout << "Pilihan tidak tersedia, harap masukkan lagi." << endl;
                    break;
            }
        }
    }
    
    void semuaKatalog() {
        bool ulang = true;
        while (ulang) {
            cout << endl;
            cout << "=====================================" << endl;
            cout << "|          DAFTAR KATALOG           |" << endl;
            cout << "=====================================" << endl;
            cout << "1. Katalog kamera" << endl;
            cout << "2. Katalog Audio" << endl;
            cout << "3. Katalog Headset" << endl;
            cout << "4. Katalog Microphone" << endl;
            cout << "5. Katalog Sound device" << endl;
            cout << "6. Cari Audio" << endl;
            cout << "7. Lihat Wishlist" << endl;
            cout << "8. Kembali ke menu utama" << endl;
            cout << "=====================================" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> temp;
            switch (temp) {
                case 1:
                    sewaKamera();
                    break;
                case 2:
                    sewaAudio();
                    break;
                case 3:
                    
                    break;
                case 4:
                    
                    break;
                case 5:
                   
                    break;
                case 6:
                    
                    break;
                case 7:
                    cart.viewCart();
                    break;
                case 8:
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
                    semuaKatalog();
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