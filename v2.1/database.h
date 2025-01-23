#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Database {
private:
    string canon[5], sony[5];
    long long int hargaCanon[5], hargasony[5];
    int umurCanon[5], umursony[5]; // Tambahkan array untuk menyimpan umur barang

public:
    void daftarKatalog() {
        loadDataFromFile("data/kamera/canon.txt", "Canon");
    }

    void sinkronDefault() {
        daftarKatalog(); // Memasukkan data ke array
    }

    void loadDataFromFile(const string& filename, const string& jenis) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File " << filename << " tidak dapat dibuka." << endl;
        return;
    }

    string line;
    int indexCanon = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        long long int price;
        int age;

        getline(ss, name, '|'); 
        string priceStr, ageStr;
        
        getline(ss, priceStr, '|'); 
        getline(ss, ageStr); 

        price = stoll(priceStr);
        age = stoi(ageStr);

        if (jenis == "Canon" && indexCanon < 5) {
            canon[indexCanon] = name;
            hargaCanon[indexCanon] = price;
            umurCanon[indexCanon] = age;
            indexCanon++;
        }
    }

    file.close();
}


    string namaCanon(int n) {
        return canon[n];
    }

    long long int priceCanon(int n) {
        return hargaCanon[n];
    }

    int umurCanonBarang(int n) {
        return umurCanon[n]; // Kembalikan umur barang
    }

    int jumlahVariantCanon() {
        return sizeof(canon) / sizeof(canon[0]);
    }

    void searchCanon(const string& query, int results[], int& count) {
        string lowerQuery = query;
        for (char& c : lowerQuery) c = tolower(c);

        count = 0;
        for (int i = 0; i < jumlahVariantCanon(); i++) {
            string lowerName = canon[i];
            for (char& c : lowerName) c = tolower(c);

            if (lowerName.find(lowerQuery) != string::npos) {
                results[count] = i;
                count++;
            }
        }
    }

    void getAllCanon(string names[], long long int prices[], int ages[]) {
        for (int i = 0; i < jumlahVariantCanon(); i++) {
            names[i] = canon[i];
            prices[i] = hargaCanon[i];
            ages[i] = umurCanon[i]; // Tambahkan umur barang ke output
        }
    }
    
    string namaSony(int n) {
        return sony[n];
    }

    long long int pricesony(int n) {
        return hargasony[n];
    }

    int umursonyBarang(int n) {
        return umursony[n]; // Kembalikan umur barang
    }

    int jumlahVariantsony() {
        return sizeof(sony) / sizeof(sony[0]);
    }

    void searchsony(const string& query, int results[], int& count) {
        string lowerQuery = query;
        for (char& c : lowerQuery) c = tolower(c);

        count = 0;
        for (int i = 0; i < jumlahVariantsony(); i++) {
            string lowerName = sony[i];
            for (char& c : lowerName) c = tolower(c);

            if (lowerName.find(lowerQuery) != string::npos) {
                results[count] = i;
                count++;
            }
        }
    }

    void getAllsony(string names[], long long int prices[], int ages[]) {
        for (int i = 0; i < jumlahVariantsony(); i++) {
            names[i] = sony[i];
            prices[i] = hargasony[i];
            ages[i] = umursony[i]; // Tambahkan umur barang ke output
        }
    }
};

#endif