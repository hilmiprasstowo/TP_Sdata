#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

//deklarasi, inisilaisasi, mengelola dan mengambil data dari file txt
class Database {
private:
    // Data untuk Canon
    string canon[5];
    long long int hargaCanon[5];
    int umurCanon[5];

    // Data untuk Sony
    string sony[5];
    long long int hargaSony[5];
    int umurSony[5];

    // Data untuk Nikon
    string nikon[5];
    long long int hargaNikon[5];
    int umurNikon[5];

    // Data untuk Fujifilm
    string fujifilm[5];
    long long int hargaFujifilm[5];
    int umurFujifilm[5];

    string olympus[5];
    long long int hargaOlympus[5];
    int umurOlympus[5];

    // Data untuk AudioRecorder
    string audioRecorder[5];
    long long int hargaAudioRecorder[5];
    int umurAudioRecorder[5];

    // Data untuk Clip-On
    string clipOn[5];
    long long int hargaClipOn[5];
    int umurClipOn[5];

    // Data untuk Headset
    string headset[5];
    long long int hargaHeadset[5];
    int umurHeadset[5];

    // Data untuk Mic
    string mic[5];
    long long int hargaMic[5];
    int umurMic[5];

    // Data untuk SoundDevices
    string soundDevices[5];
    long long int hargaSoundDevices[5];
    int umurSoundDevices[5];

    // Data untuk Mount
    string mount[5];
    long long int hargaMount[5];
    int umurMount[5];

    // Data untuk Sigma
    string sigma[5];
    long long int hargaSigma[5];
    int umurSigma[5];

    // Data untuk Zeiss
    string zeiss[5];
    long long int hargaZeiss[5];
    int umurZeiss[5];

    // Data untuk LensaSony
    string lensasony[5];
    long long int hargaLensaSony[5];
    int umurLensaSony[5];

    // Data untuk Aputere
    string aputere[5];
    long long int hargaAputere[5];
    int umurAputere[5];

    // Data untuk Beam
    string beam[5];
    long long int hargaBeam[5];
    int umurBeam[5];

    // Data untuk Dedolight
    string dedolight[5];
    long long int hargaDedolight[5];
    int umurDedolight[5];

    // Data untuk Godox
    string godox[5];
    long long int hargaGodox[5];
    int umurGodox[5];

    // Data untuk Nanlite
    string nanlite[5];
    long long int hargaNanlite[5];
    int umurNanlite[5];
    
    string Cinema[5];
    long long int hargaCinema[5];
    int umurCinema[5];
    
    




	public:
    // Load data dari file
    void daftarKatalog() {
        loadDataFromFile("data/kamera/canon.txt", "Canon");
        loadDataFromFile("data/kamera/sony.txt", "Sony");
        loadDataFromFile("data/kamera/nikon.txt", "Nikon");
        loadDataFromFile("data/kamera/fujifilm.txt", "Fujifilm");
        loadDataFromFile("data/kamera/olympus.txt", "Olympus");
        
        // Kategori Audio
        loadDataFromFile("data/audio/audioRecorder.txt", "AudioRecorder");
        loadDataFromFile("data/audio/clipOn.txt", "ClipOn");
        loadDataFromFile("data/audio/headset.txt", "Headset");
        loadDataFromFile("data/audio/mic.txt", "Mic");
        loadDataFromFile("data/audio/soundDevices.txt", "SoundDevices");

        // Kategori Lensa
        loadDataFromFile("data/lensa/cinema.txt", "Cinema");
        loadDataFromFile("data/lensa/mount.txt", "Mount");
        loadDataFromFile("data/lensa/sigma.txt", "Sigma");
        loadDataFromFile("data/lensa/zeiss.txt", "Zeiss");
        loadDataFromFile("data/lensa/lensasony.txt", "LensaSony");

        // Kategori Lightning
        loadDataFromFile("data/lightning/aputere.txt", "Aputere");
        loadDataFromFile("data/lightning/beam.txt", "Beam");
        loadDataFromFile("data/lightning/dedolight.txt", "Dedolight");
        loadDataFromFile("data/lightning/godox.txt", "Godox");
        loadDataFromFile("data/lightning/nanlite.txt", "Nanlite");
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
        int indexCanon = 0, indexSony = 0, indexNikon = 0, indexFujifilm = 0, indexOlympus = 0, indexLensaSony = 0;
        int indexAudioRecorder = 0, indexClipOn = 0, indexHeadset = 0, indexMic = 0, indexSoundDevices = 0;
        int indexMount = 0, indexSigma = 0, indexZeiss = 0, indexAputere = 0, indexBeam = 0, indexDedolight = 0, indexGodox = 0, indexNanlite = 0;
        
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
            } else if (jenis == "Sony" && indexSony < 5) {
                sony[indexSony] = name;
                hargaSony[indexSony] = price;
                umurSony[indexSony] = age;
                indexSony++;
            } else if (jenis == "Nikon" && indexNikon < 5) {
                nikon[indexNikon] = name;
                hargaNikon[indexNikon] = price;
                umurNikon[indexNikon] = age;
                indexNikon++;
            } else if (jenis == "Fujifilm" && indexFujifilm < 5) {
                fujifilm[indexFujifilm] = name;
                hargaFujifilm[indexFujifilm] = price;
                umurFujifilm[indexFujifilm] = age;
                indexFujifilm++;
            } else if (jenis == "Olympus" && indexOlympus < 5) {
                olympus[indexOlympus] = name;
                hargaOlympus[indexOlympus] = price;
                umurOlympus[indexOlympus] = age;
                indexOlympus++;
            } else if (jenis == "AudioRecorder" && indexAudioRecorder < 5) {
                audioRecorder[indexAudioRecorder] = name;
                hargaAudioRecorder[indexAudioRecorder] = price;
                umurAudioRecorder[indexAudioRecorder] = age;
                indexAudioRecorder++;
            } else if (jenis == "ClipOn" && indexClipOn < 5) {
                clipOn[indexClipOn] = name;
                hargaClipOn[indexClipOn] = price;
                umurClipOn[indexClipOn] = age;
                indexClipOn++;
            } else if (jenis == "Headset" && indexHeadset < 5) {
                headset[indexHeadset] = name;
                hargaHeadset[indexHeadset] = price;
                umurHeadset[indexHeadset] = age;
                indexHeadset++;
            } else if (jenis == "Mic" && indexMic < 5) {
                mic[indexMic] = name;
                hargaMic[indexMic] = price;
                umurMic[indexMic] = age;
                indexMic++;
            } else if (jenis == "SoundDevices" && indexSoundDevices < 5) {
                soundDevices[indexSoundDevices] = name;
                hargaSoundDevices[indexSoundDevices] = price;
                umurSoundDevices[indexSoundDevices] = age;
                indexSoundDevices++;
            } else if (jenis == "Mount" && indexMount < 5) {
                mount[indexMount] = name;
                hargaMount[indexMount] = price;
                umurMount[indexMount] = age;
                indexMount++;
            } else if (jenis == "Sigma" && indexSigma < 5) {
                sigma[indexSigma] = name;
                hargaSigma[indexSigma] = price;
                umurSigma[indexSigma] = age;
                indexSigma++;
            } else if (jenis == "Zeiss" && indexZeiss < 5) {
                zeiss[indexZeiss] = name;
                hargaZeiss[indexZeiss] = price;
                umurZeiss[indexZeiss] = age;
                indexZeiss++;
            } else if (jenis == "LensaSony" && indexLensaSony < 5) {
                lensasony[indexLensaSony] = name;
                hargaLensaSony[indexLensaSony] = price;
                umurLensaSony[indexLensaSony] = age;
                indexLensaSony++;
            } else if (jenis == "Aputere" && indexAputere < 5) {
                aputere[indexAputere] = name;
                hargaAputere[indexAputere] = price;
                umurAputere[indexAputere] = age;
                indexAputere++;
            } else if (jenis == "Beam" && indexBeam < 5) {
                beam[indexBeam] = name;
                hargaBeam[indexBeam] = price;
                umurBeam[indexBeam] = age;
                indexBeam++;
            } else if (jenis == "Dedolight" && indexDedolight < 5) {
                dedolight[indexDedolight] = name;
                hargaDedolight[indexDedolight] = price;
                umurDedolight[indexDedolight] = age;
                indexDedolight++;
            } else if (jenis == "Godox" && indexGodox < 5) {
    godox[indexGodox] = name;
    hargaGodox[indexGodox] = price;
    umurGodox[indexGodox] = age;
    indexGodox++;
} else if (jenis == "Nanlite" && indexNanlite < 5) {
    nanlite[indexNanlite] = name;
    hargaNanlite[indexNanlite] = price;
    umurNanlite[indexNanlite] = age;
    indexNanlite++;
}
}



        file.close();
    }

    // === Canon Functions ===
    string namaCanon(int n) {
        return canon[n];
    }

    long long int priceCanon(int n) {
        return hargaCanon[n];
    }

    int umurCanonBarang(int n) {
        return umurCanon[n];
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
            ages[i] = umurCanon[i];
        }
    }

    // === Sony Functions ===
    string namaSony(int n) {
        return sony[n];
    }

    long long int priceSony(int n) {
        return hargaSony[n];
    }

    int umurSonyBarang(int n) {
        return umurSony[n];
    }

    int jumlahVariantSony() {
        return sizeof(sony) / sizeof(sony[0]);
    }

    void searchSony(const string& query, int results[], int& count) {
        string lowerQuery = query;
        for (char& c : lowerQuery) c = tolower(c);

        count = 0;
        for (int i = 0; i < jumlahVariantSony(); i++) {
            string lowerName = sony[i];
            for (char& c : lowerName) c = tolower(c);

            if (lowerName.find(lowerQuery) != string::npos) {
                results[count] = i;
                count++;
            }
        }
    }

    void getAllSony(string names[], long long int prices[], int ages[]) {
        for (int i = 0; i < jumlahVariantSony(); i++) {
            names[i] = sony[i];
            prices[i] = hargaSony[i];
            ages[i] = umurSony[i];
        }
    }

    // === Nikon Functions ===
    string namaNikon(int n) {
        return nikon[n];
    }

    long long int priceNikon(int n) {
        return hargaNikon[n];
    }

    int umurNikonBarang(int n) {
        return umurNikon[n];
    }

    int jumlahVariantNikon() {
        return sizeof(nikon) / sizeof(nikon[0]);
    }

    void searchNikon(const string& query, int results[], int& count) {
        string lowerQuery = query;
        for (char& c : lowerQuery) c = tolower(c);

        count = 0;
        for (int i = 0; i < jumlahVariantNikon(); i++) {
            string lowerName = nikon[i];
            for (char& c : lowerName) c = tolower(c);

            if (lowerName.find(lowerQuery) != string::npos) {
                results[count] = i;
                count++;
            }
        }
    }

    void getAllNikon(string names[], long long int prices[], int ages[]) {
        for (int i = 0; i < jumlahVariantNikon(); i++) {
            names[i] = nikon[i];
            prices[i] = hargaNikon[i];
            ages[i] = umurNikon[i];
        }
    }

    // === Fujifilm Functions ===
    string namaFujifilm(int n) {
        return fujifilm[n];
    }

    long long int priceFujifilm(int n) {
        return hargaFujifilm[n];
    }

    int umurFujifilmBarang(int n) {
        return umurFujifilm[n];
    }

    int jumlahVariantFujifilm() {
        return sizeof(fujifilm) / sizeof(fujifilm[0]);
    }

    void searchFujifilm(const string& query, int results[], int& count) {
        string lowerQuery = query;
        for (char& c : lowerQuery) c = tolower(c);

        count = 0;
        for (int i = 0; i < jumlahVariantFujifilm(); i++) {
            string lowerName = fujifilm[i];
            for (char& c : lowerName) c = tolower(c);

            if (lowerName.find(lowerQuery) != string::npos) {
                results[count] = i;
                count++;
            }
        }
    }

    void getAllFujifilm(string names[], long long int prices[], int ages[]) {
        for (int i = 0; i < jumlahVariantFujifilm(); i++) {
            names[i] = fujifilm[i];
            prices[i] = hargaFujifilm[i];
            ages[i] = umurFujifilm[i];
        }
    }

    // === Olympus Functions ===
    string namaOlympus(int n) {
        return olympus[n];
    }

    long long int priceOlympus(int n) {
        return hargaOlympus[n];
    }

    int umurOlympusBarang(int n) {
        return umurOlympus[n];
    }

    int jumlahVariantOlympus() {
        return sizeof(olympus) / sizeof(olympus[0]);
    }

    void searchOlympus(const string& query, int results[], int& count) {
        string lowerQuery = query;
        for (char& c : lowerQuery) c = tolower(c);

        count = 0;
        for (int i = 0; i < jumlahVariantOlympus(); i++) {
            string lowerName = olympus[i];
            for (char& c : lowerName) c = tolower(c);

            if (lowerName.find(lowerQuery) != string::npos) {
                results[count] = i;
                count++;
            }
        }
    }

    void getAllOlympus(string names[], long long int prices[], int ages[]) {
        for (int i = 0; i < jumlahVariantOlympus(); i++) {
            names[i] = olympus[i];
            prices[i] = hargaOlympus[i];
            ages[i] = umurOlympus[i];
        }
    }
    // === AudioRecorder Functions ===
string namaAudioRecorder(int n) {
    return audioRecorder[n];
}

long long int priceAudioRecorder(int n) {
    return hargaAudioRecorder[n];
}

int umurAudioRecorderBarang(int n) {
    return umurAudioRecorder[n];
}

int jumlahVariantAudioRecorder() {
    return sizeof(audioRecorder) / sizeof(audioRecorder[0]);
}

void searchAudioRecorder(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantAudioRecorder(); i++) {
        string lowerName = audioRecorder[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}

void getAllAudioRecorder(string names[], long long int prices[], int ages[]) {
    for (int i = 0; i < jumlahVariantAudioRecorder(); i++) {
        names[i] = audioRecorder[i];
        prices[i] = hargaAudioRecorder[i];
        ages[i] = umurAudioRecorder[i];
    }
}

// === Clip-On Functions ===
string namaClipOn(int n) {
    return clipOn[n];
}

long long int priceClipOn(int n) {
    return hargaClipOn[n];
}

int umurClipOnBarang(int n) {
    return umurClipOn[n];
}

int jumlahVariantClipOn() {
    return sizeof(clipOn) / sizeof(clipOn[0]);
}

void searchClipOn(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantClipOn(); i++) {
        string lowerName = clipOn[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}

void getAllClipOn(string names[], long long int prices[], int ages[]) {
    for (int i = 0; i < jumlahVariantClipOn(); i++) {
        names[i] = clipOn[i];
        prices[i] = hargaClipOn[i];
        ages[i] = umurClipOn[i];
    }
}

// === Headset Functions ===
string namaHeadset(int n) {
    return headset[n];
}

long long int priceHeadset(int n) {
    return hargaHeadset[n];
}

int umurHeadsetBarang(int n) {
    return umurHeadset[n];
}

int jumlahVariantHeadset() {
    return sizeof(headset) / sizeof(headset[0]);
}

void searchHeadset(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantHeadset(); i++) {
        string lowerName = headset[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}

void getAllHeadset(string names[], long long int prices[], int ages[]) {
    for (int i = 0; i < jumlahVariantHeadset(); i++) {
        names[i] = headset[i];
        prices[i] = hargaHeadset[i];
        ages[i] = umurHeadset[i];
    }
}

// === Mic Functions ===
string namaMic(int n) {
    return mic[n];
}

long long int priceMic(int n) {
    return hargaMic[n];
}

int umurMicBarang(int n) {
    return umurMic[n];
}

int jumlahVariantMic() {
    return sizeof(mic) / sizeof(mic[0]);
}

void searchMic(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantMic(); i++) {
        string lowerName = mic[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}

void getAllMic(string names[], long long int prices[], int ages[]) {
    for (int i = 0; i < jumlahVariantMic(); i++) {
        names[i] = mic[i];
        prices[i] = hargaMic[i];
        ages[i] = umurMic[i];
    }
}

// === SoundDevices Functions ===
string namaSoundDevices(int n) {
    return soundDevices[n];
}

long long int priceSoundDevices(int n) {
    return hargaSoundDevices[n];
}

int umurSoundDevicesBarang(int n) {
    return umurSoundDevices[n];
}

int jumlahVariantSoundDevices() {
    return sizeof(soundDevices) / sizeof(soundDevices[0]);
}

void searchSoundDevices(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantSoundDevices(); i++) {
        string lowerName = soundDevices[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}

// Cinema
string namaCinema(int n) {
    return Cinema[n];
}

long long int priceCinema(int n) {
    return hargaCinema[n];
}

int umurCinemaBarang(int n) {
    return umurCinema[n];
}

int jumlahVariantCinema() {
    return sizeof(Cinema) / sizeof(Cinema[0]);
}

void searchCinema(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantCinema(); i++) {
        string lowerName = Cinema[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}

// Mount
string namaMount(int n) {
    return mount[n];
}

long long int priceMount(int n) {
    return hargaMount[n];
}

int umurMountBarang(int n) {
    return umurMount[n];
}

int jumlahVariantMount() {
    return sizeof(mount) / sizeof(mount[0]);
}

void searchMount(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantMount(); i++) {
        string lowerName = mount[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}

// Sigma
string namaSigma(int n) {
    return sigma[n];
}

long long int priceSigma(int n) {
    return hargaSigma[n];
}

int umurSigmaBarang(int n) {
    return umurSigma[n];
}

int jumlahVariantSigma() {
    return sizeof(sigma) / sizeof(sigma[0]);
}

void searchSigma(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantSigma(); i++) {
        string lowerName = sigma[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}

// Zeiss
string namaZeiss(int n) {
    return zeiss[n];
}

long long int priceZeiss(int n) {
    return hargaZeiss[n];
}

int umurZeissBarang(int n) {
    return umurZeiss[n];
}

int jumlahVariantZeiss() {
    return sizeof(zeiss) / sizeof(zeiss[0]);
}

void searchZeiss(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantZeiss(); i++) {
        string lowerName = zeiss[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}

// LensaSony
string namaLensaSony(int n) {
    return lensasony[n];
}

long long int priceLensaSony(int n) {
    return hargaLensaSony[n];
}

int umurLensaSonyBarang(int n) {
    return umurLensaSony[n];
}

int jumlahVariantLensaSony() {
    return sizeof(lensasony) / sizeof(lensasony[0]);
}

void searchLensaSony(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantLensaSony(); i++) {
        string lowerName = lensasony[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}

// Aputere
string namaAputere(int n) {
    return aputere[n];
}

long long int priceAputere(int n) {
    return hargaAputere[n];
}

int umurAputereBarang(int n) {
    return umurAputere[n];
}

int jumlahVariantAputere() {
    return sizeof(aputere) / sizeof(aputere[0]);
}

void searchAputere(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantAputere(); i++) {
        string lowerName = aputere[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}

// Beam
string namaBeam(int n) {
    return beam[n];
}

long long int priceBeam(int n) {
    return hargaBeam[n];
}

int umurBeamBarang(int n) {
    return umurBeam[n];
}

int jumlahVariantBeam() {
    return sizeof(beam) / sizeof(beam[0]);
}

void searchBeam(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantBeam(); i++) {
        string lowerName = beam[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}

// Dedolight
string namaDedolight(int n) {
    return dedolight[n];
}

long long int priceDedolight(int n) {
    return hargaDedolight[n];
}

int umurDedolightBarang(int n) {
    return umurDedolight[n];
}

int jumlahVariantDedolight() {
    return sizeof(dedolight) / sizeof(dedolight[0]);
}

void searchDedolight(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantDedolight(); i++) {
        string lowerName = dedolight[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}

// Godox
string namaGodox(int n) {
    return godox[n];
}

long long int priceGodox(int n) {
    return hargaGodox[n];
}

int umurGodoxBarang(int n) {
    return umurGodox[n];
}

int jumlahVariantGodox() {
    return sizeof(godox) / sizeof(godox[0]);
}

void searchGodox(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantGodox(); i++) {
        string lowerName = godox[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}

// Nanlite
string namaNanlite(int n) {
    return nanlite[n];
}

long long int priceNanlite(int n) {
    return hargaNanlite[n];
}

int umurNanliteBarang(int n) {
    return umurNanlite[n];
}

int jumlahVariantNanlite() {
    return sizeof(nanlite) / sizeof(nanlite[0]);
}

void searchNanlite(const string& query, int results[], int& count) {
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    count = 0;
    for (int i = 0; i < jumlahVariantNanlite(); i++) {
        string lowerName = nanlite[i];
        for (char& c : lowerName) c = tolower(c);

        if (lowerName.find(lowerQuery) != string::npos) {
            results[count] = i;
            count++;
        }
    }
}


void getAllSoundDevices(string names[], long long int prices[], int ages[]) {
    for (int i = 0; i < jumlahVariantSoundDevices(); i++) {
        names[i] = soundDevices[i];
        prices[i] = hargaSoundDevices[i];
        ages[i] = umurSoundDevices[i];
    }
}

};


#endif
