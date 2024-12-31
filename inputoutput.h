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
    
    void printKatalogSony(bool ascending) {
        string names[5];
        long long int prices[5];
        int ages[5];
        db.getAllSony(names, prices, ages); // Ambil data termasuk umur

        for (int i = 0; i < db.jumlahVariantSony() - 1; i++) {
            for (int j = i + 1; j < db.jumlahVariantSony(); j++) {
                if ((ascending && prices[i] > prices[j]) || (!ascending && prices[i] < prices[j])) {
                    swap(names[i], names[j]);
                    swap(prices[i], prices[j]);
                    swap(ages[i], ages[j]); // Tukar data umur sesuai harga
                }
            }
        }

        cout << "=========================================" << endl;
        cout << "|\tKatalog Kamera Sony\t\t|" << endl;
        cout << "=========================================" << endl;
        for (int i = 0; i < db.jumlahVariantSony(); i++) {
            cout << i + 1 << ". " << names[i] << endl
                 << "\tHarga: Rp" << prices[i] << "/hari" << endl
                 << "\tUmur: " << ages[i] << " tahun" << endl << endl;
        }
    }

    void printSearchResultsSony(int results[], int count) {
        if (count == 0) {
            cout << "Tidak ada hasil yang ditemukan." << endl;
        } else {
            cout << "Hasil pencarian:" << endl;
            for (int i = 0; i < count; i++) {
                int idx = results[i];
                cout << idx + 1 << ". " << db.namaSony(idx) << endl
                     << "\tHarga: Rp" << db.priceSony(idx) << "/hari" << endl
                     << "\tUmur: " << db.umurSonyBarang(idx) << " tahun" << endl << endl;
            }
        }
    }
    
    void printKatalogNikon(bool ascending) {
    string nikon[5];
    long long int hargaNikon[5];
    int umurNikon[5];
    db.getAllNikon(nikon, hargaNikon, umurNikon); // Ambil data termasuk umur

    for (int i = 0; i < db.jumlahVariantNikon() - 1; i++) {
        for (int j = i + 1; j < db.jumlahVariantNikon(); j++) {
            if ((ascending && hargaNikon[i] > hargaNikon[j]) || (!ascending && hargaNikon[i] < hargaNikon[j])) {
                swap(nikon[i], nikon[j]);
                swap(hargaNikon[i], hargaNikon[j]);
                swap(umurNikon[i], umurNikon[j]); // Tukar data umur sesuai harga
            }
        }
    }

    cout << "=========================================" << endl;
    cout << "|\tKatalog Kamera Nikon\t\t|" << endl;
    cout << "=========================================" << endl;
    for (int i = 0; i < db.jumlahVariantNikon(); i++) {
        cout << i + 1 << ". " << nikon[i] << endl
             << "\tHarga: Rp" << hargaNikon[i] << "/hari" << endl
             << "\tUmur: " << umurNikon[i] << " tahun" << endl << endl;
    }
}

void printSearchResultsNikon(int results[], int count) {
    if (count == 0) {
        cout << "Tidak ada hasil yang ditemukan." << endl;
    } else {
        cout << "Hasil pencarian:" << endl;
        for (int i = 0; i < count; i++) {
            int idx = results[i];
            cout << idx + 1 << ". " << db.namaNikon(idx) << endl
                 << "\tHarga: Rp" << db.priceNikon(idx) << "/hari" << endl
                 << "\tUmur: " << db.umurNikonBarang(idx) << " tahun" << endl << endl;
        }
    }
}

void printKatalogFujifilm(bool ascending) {
    string fujifilm[5];
    long long int hargaFujifilm[5];
    int umurFujifilm[5];
    db.getAllFujifilm(fujifilm, hargaFujifilm, umurFujifilm); // Ambil data termasuk umur

    for (int i = 0; i < db.jumlahVariantFujifilm() - 1; i++) {
        for (int j = i + 1; j < db.jumlahVariantFujifilm(); j++) {
            if ((ascending && hargaFujifilm[i] > hargaFujifilm[j]) || (!ascending && hargaFujifilm[i] < hargaFujifilm[j])) {
                swap(fujifilm[i], fujifilm[j]);
                swap(hargaFujifilm[i], hargaFujifilm[j]);
                swap(umurFujifilm[i], umurFujifilm[j]); // Tukar data umur sesuai harga
            }
        }
    }

    cout << "=========================================" << endl;
    cout << "|\tKatalog Kamera Fujifilm\t\t|" << endl;
    cout << "=========================================" << endl;
    for (int i = 0; i < db.jumlahVariantFujifilm(); i++) {
        cout << i + 1 << ". " << fujifilm[i] << endl
             << "\tHarga: Rp" << hargaFujifilm[i] << "/hari" << endl
             << "\tUmur: " << umurFujifilm[i] << " tahun" << endl << endl;
    }
}

void printSearchResultsFujifilm(int results[], int count) {
    if (count == 0) {
        cout << "Tidak ada hasil yang ditemukan." << endl;
    } else {
        cout << "Hasil pencarian:" << endl;
        for (int i = 0; i < count; i++) {
            int idx = results[i];
            cout << idx + 1 << ". " << db.namaFujifilm(idx) << endl
                 << "\tHarga: Rp" << db.priceFujifilm(idx) << "/hari" << endl
                 << "\tUmur: " << db.umurFujifilmBarang(idx) << " tahun" << endl << endl;
        }
    }
}

void printKatalogOlympus(bool ascending) {
    string olympus[5];
    long long int hargaOlympus[5];
    int umurOlympus[5];
    db.getAllOlympus(olympus, hargaOlympus, umurOlympus); // Ambil data termasuk umur

    for (int i = 0; i < db.jumlahVariantOlympus() - 1; i++) {
        for (int j = i + 1; j < db.jumlahVariantOlympus(); j++) {
            if ((ascending && hargaOlympus[i] > hargaOlympus[j]) || (!ascending && hargaOlympus[i] < hargaOlympus[j])) {
                swap(olympus[i], olympus[j]);
                swap(hargaOlympus[i], hargaOlympus[j]);
                swap(umurOlympus[i], umurOlympus[j]); // Tukar data umur sesuai harga
            }
        }
    }

    cout << "=========================================" << endl;
    cout << "|\tKatalog Kamera Olympus\t\t|" << endl;
    cout << "=========================================" << endl;
    for (int i = 0; i < db.jumlahVariantOlympus(); i++) {
        cout << i + 1 << ". " << olympus[i] << endl
             << "\tHarga: Rp" << hargaOlympus[i] << "/hari" << endl
             << "\tUmur: " << umurOlympus[i] << " tahun" << endl << endl;
    }
}

void printSearchResultsOlympus(int results[], int count) {
    if (count == 0) {
        cout << "Tidak ada hasil yang ditemukan." << endl;
    } else {
        cout << "Hasil pencarian:" << endl;
        for (int i = 0; i < count; i++) {
            int idx = results[i];
            cout << idx + 1 << ". " << db.namaOlympus(idx) << endl
                 << "\tHarga: Rp" << db.priceOlympus(idx) << "/hari" << endl
                 << "\tUmur: " << db.umurOlympusBarang(idx) << " tahun" << endl << endl;
        }
    }
}



void printKatalogAudioRecorder(bool ascending) {
    string names[5];
    long long int prices[5];
    int ages[5];
    db.getAllAudioRecorder(names, prices, ages); // Ambil data termasuk umur

    for (int i = 0; i < db.jumlahVariantAudioRecorder() - 1; i++) {
        for (int j = i + 1; j < db.jumlahVariantAudioRecorder(); j++) {
            if ((ascending && prices[i] > prices[j]) || (!ascending && prices[i] < prices[j])) {
                swap(names[i], names[j]);
                swap(prices[i], prices[j]);
                swap(ages[i], ages[j]); // Tukar data umur sesuai harga
            }
        }
    }

    cout << "=========================================" << endl;
    cout << "|\tKatalog Audio Recorder\t\t|" << endl;
    cout << "=========================================" << endl;
    for (int i = 0; i < db.jumlahVariantAudioRecorder(); i++) {
        cout << i + 1 << ". " << names[i] << endl
             << "\tHarga: Rp" << prices[i] << "/hari" << endl
             << "\tUmur: " << ages[i] << " tahun" << endl << endl;
    }
}

void printSearchResultsAudioRecorder(int results[], int count) {
    if (count == 0) {
        cout << "Tidak ada hasil yang ditemukan." << endl;
    } else {
        cout << "Hasil pencarian:" << endl;
        for (int i = 0; i < count; i++) {
            int idx = results[i];
            cout << idx + 1 << ". " << db.namaAudioRecorder(idx) << endl
                 << "\tHarga: Rp" << db.priceAudioRecorder(idx) << "/hari" << endl
                 << "\tUmur: " << db.umurAudioRecorderBarang(idx) << " tahun" << endl << endl;
        }
    }
}

void printKatalogClipOn(bool ascending) {
    string names[5];
    long long int prices[5];
    int ages[5];
    db.getAllClipOn(names, prices, ages); // Ambil data termasuk umur

    for (int i = 0; i < db.jumlahVariantClipOn() - 1; i++) {
        for (int j = i + 1; j < db.jumlahVariantClipOn(); j++) {
            if ((ascending && prices[i] > prices[j]) || (!ascending && prices[i] < prices[j])) {
                swap(names[i], names[j]);
                swap(prices[i], prices[j]);
                swap(ages[i], ages[j]); // Tukar data umur sesuai harga
            }
        }
    }

    cout << "=========================================" << endl;
    cout << "|\tKatalog Clip-On\t\t|" << endl;
    cout << "=========================================" << endl;
    for (int i = 0; i < db.jumlahVariantClipOn(); i++) {
        cout << i + 1 << ". " << names[i] << endl
             << "\tHarga: Rp" << prices[i] << "/hari" << endl
             << "\tUmur: " << ages[i] << " tahun" << endl << endl;
    }
}

void printSearchResultsClipOn(int results[], int count) {
    if (count == 0) {
        cout << "Tidak ada hasil yang ditemukan." << endl;
    } else {
        cout << "Hasil pencarian:" << endl;
        for (int i = 0; i < count; i++) {
            int idx = results[i];
            cout << idx + 1 << ". " << db.namaClipOn(idx) << endl
                 << "\tHarga: Rp" << db.priceClipOn(idx) << "/hari" << endl
                 << "\tUmur: " << db.umurClipOnBarang(idx) << " tahun" << endl << endl;
        }
    }
}

void printKatalogHeadset(bool ascending) {
    string names[5];
    long long int prices[5];
    int ages[5];
    db.getAllHeadset(names, prices, ages); // Ambil data termasuk umur

    for (int i = 0; i < db.jumlahVariantHeadset() - 1; i++) {
        for (int j = i + 1; j < db.jumlahVariantHeadset(); j++) {
            if ((ascending && prices[i] > prices[j]) || (!ascending && prices[i] < prices[j])) {
                swap(names[i], names[j]);
                swap(prices[i], prices[j]);
                swap(ages[i], ages[j]); // Tukar data umur sesuai harga
            }
        }
    }

    cout << "=========================================" << endl;
    cout << "|\tKatalog Headset\t\t|" << endl;
    cout << "=========================================" << endl;
    for (int i = 0; i < db.jumlahVariantHeadset(); i++) {
        cout << i + 1 << ". " << names[i] << endl
             << "\tHarga: Rp" << prices[i] << "/hari" << endl
             << "\tUmur: " << ages[i] << " tahun" << endl << endl;
    }
}

void printSearchResultsHeadset(int results[], int count) {
    if (count == 0) {
        cout << "Tidak ada hasil yang ditemukan." << endl;
    } else {
        cout << "Hasil pencarian:" << endl;
        for (int i = 0; i < count; i++) {
            int idx = results[i];
            cout << idx + 1 << ". " << db.namaHeadset(idx) << endl
                 << "\tHarga: Rp" << db.priceHeadset(idx) << "/hari" << endl
                 << "\tUmur: " << db.umurHeadsetBarang(idx) << " tahun" << endl << endl;
        }
    }
}

void printKatalogMic(bool ascending) {
    string names[5];
    long long int prices[5];
    int ages[5];
    db.getAllMic(names, prices, ages); // Ambil data termasuk umur

    for (int i = 0; i < db.jumlahVariantMic() - 1; i++) {
        for (int j = i + 1; j < db.jumlahVariantMic(); j++) {
            if ((ascending && prices[i] > prices[j]) || (!ascending && prices[i] < prices[j])) {
                swap(names[i], names[j]);
                swap(prices[i], prices[j]);
                swap(ages[i], ages[j]); // Tukar data umur sesuai harga
            }
        }
    }

    cout << "=========================================" << endl;
    cout << "|\tKatalog Mic\t\t|" << endl;
    cout << "=========================================" << endl;
    for (int i = 0; i < db.jumlahVariantMic(); i++) {
        cout << i + 1 << ". " << names[i] << endl
             << "\tHarga: Rp" << prices[i] << "/hari" << endl
             << "\tUmur: " << ages[i] << " tahun" << endl << endl;
    }
}

void printSearchResultsMic(int results[], int count) {
    if (count == 0) {
        cout << "Tidak ada hasil yang ditemukan." << endl;
    } else {
        cout << "Hasil pencarian:" << endl;
        for (int i = 0; i < count; i++) {
            int idx = results[i];
            cout << idx + 1 << ". " << db.namaMic(idx) << endl
                 << "\tHarga: Rp" << db.priceMic(idx) << "/hari" << endl
                 << "\tUmur: " << db.umurMicBarang(idx) << " tahun" << endl << endl;
        }
    }
}

void printKatalogSoundDevices(bool ascending) {
    string names[5];
    long long int prices[5];
    int ages[5];
    db.getAllSoundDevices(names, prices, ages); // Ambil data termasuk umur

    for (int i = 0; i < db.jumlahVariantSoundDevices() - 1; i++) {
        for (int j = i + 1; j < db.jumlahVariantSoundDevices(); j++) {
            if ((ascending && prices[i] > prices[j]) || (!ascending && prices[i] < prices[j])) {
                swap(names[i], names[j]);
                swap(prices[i], prices[j]);
                swap(ages[i], ages[j]); // Tukar data umur sesuai harga
            }
        }
    }

    cout << "=========================================" << endl;
    cout << "|\tKatalog Sound Devices\t\t|" << endl;
    cout << "=========================================" << endl;
    for (int i = 0; i < db.jumlahVariantSoundDevices(); i++) {
        cout << i + 1 << ". " << names[i] << endl
             << "\tHarga: Rp" << prices[i] << "/hari" << endl
             << "\tUmur: " << ages[i] << " tahun" << endl << endl;
    }
}

void printSearchResultsSoundDevices(int results[], int count) {
    if (count == 0) {
        cout << "Tidak ada hasil yang ditemukan." << endl;
    } else {
        cout << "Hasil pencarian:" << endl;
        for (int i = 0; i < count; i++) {
            int idx = results[i];
            cout << idx + 1 << ". " << db.namaSoundDevices(idx) << endl
                 << "\tHarga: Rp" << db.priceSoundDevices(idx) << "/hari" << endl
                 << "\tUmur: " << db.umurSoundDevicesBarang(idx) << " tahun" << endl << endl;
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