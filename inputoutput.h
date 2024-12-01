#ifndef INPUTOUTPUT_H
#define INPUTOUPUT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "database.h"
using namespace std;

class InputOutput {
private:
    Database db;

public:
    void printKatalogCanon(bool ascending) {
        string names[5];
        long long int prices[5];
        int ages[5];
        db.getAllCanon(names, prices, ages); // Ambil data termasuk umur

        for (int i = 0; i < db.jumlahVariantCanon() - 1; i++) {
            for (int j = i + 1; j < db.jumlahVariantCanon(); j++) {
                if ((ascending && prices[i] > prices[j]) || (!ascending && prices[i] < prices[j])) {
                    swap(names[i], names[j]);
                    swap(prices[i], prices[j]);
                    swap(ages[i], ages[j]); // Tukar data umur sesuai harga
                }
            }
        }

        cout << "=========================================" << endl;
        cout << "|\tKatalog Kamera Canon\t\t|" << endl;
        cout << "=========================================" << endl;
        for (int i = 0; i < db.jumlahVariantCanon(); i++) {
            cout << i + 1 << ". " << names[i] << endl
                 << "\tHarga: Rp" << prices[i] << "/hari" << endl
                 << "\tUmur: " << ages[i] << " tahun" << endl << endl;
        }
    }

    void printSearchResultsCanon(int results[], int count) {
        if (count == 0) {
            cout << "Tidak ada hasil yang ditemukan." << endl;
        } else {
            cout << "Hasil pencarian:" << endl;
            for (int i = 0; i < count; i++) {
                int idx = results[i];
                cout << idx + 1 << ". " << db.namaCanon(idx) << endl
                     << "\tHarga: Rp" << db.priceCanon(idx) << "/hari" << endl
                     << "\tUmur: " << db.umurCanonBarang(idx) << " tahun" << endl << endl;
            }
        }
    }

    void sinkronisasiData() {
        db.sinkronDefault();
    }

    Database getDatabase() {
        return db;
    }
};

#endif