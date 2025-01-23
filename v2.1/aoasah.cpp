#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Open an output file for spooling
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Failed to open output file." << endl;
        return 1;
    }

    outputFile << "Perkalian tabel 9:" << endl;
    for (int i = 1; i <= 10; ++i) {
        outputFile << "9 x " << i << " = " << 9 * i << endl;
    }

    outputFile << endl;
    outputFile << "perkalian tabel 10:" << endl;
    for (int i = 1; i <= 10; ++i) {
        outputFile << "10 x " << i << " = " << 10 * i << endl;
    }

    // Close the output file
    outputFile.close();

    // Open an input file for reading
    ifstream inputFile("output.txt");
    if (!inputFile) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    // Read and display data from the input file
    string line;
    while (getline(inputFile, line)) {
        cout << "Read from file: " << line << endl;
    }

    // Close the input file
    inputFile.close();

    return 0;
}
