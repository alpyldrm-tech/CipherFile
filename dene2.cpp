#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

// XOR Şifreleme Fonksiyonu
void xorCipher(const string& inputFile, const string& outputFile, const string& key) {
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    if (!inFile) {
        cout << "HATA: Dosya açılamadı!\n";
        return;
    }

    vector<char> buffer((istreambuf_iterator<char>(inFile)),
                         istreambuf_iterator<char>());

    auto start = high_resolution_clock::now();

    for (size_t i = 0; i < buffer.size(); i++) {
        buffer[i] ^= key[i % key.length()];
    }

    outFile.write(buffer.data(), buffer.size());

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nIslem basarili!\n";
    cout << "Islem suresi: " << duration.count() << " ms\n";
    cout << "Toplam byte: " << buffer.size() << "\n";
}

// Dosya Boyutu Gösterme
void fileInfo(const string& filename) {
    ifstream file(filename, ios::binary | ios::ate);
    if (!file) {
        cout << "Dosya bulunamadi!\n";
        return;
    }

    cout << "Dosya Boyutu: " << file.tellg() << " byte\n";
}

void showMenu() {
    cout << "\n===========================================\n";
    cout << "        CIPHERFILE - DOSYA SIFRELEME\n";
    cout << "===========================================\n";
    cout << "1 - Dosya Sifrele\n";
    cout << "2 - Dosya Coz\n";
    cout << "3 - Dosya Bilgisi Goruntule\n";
    cout << "4 - Cikis\n";
    cout << "Seciminiz: ";
}

int main() {
    int choice;
    string inputFile, outputFile, key;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Sifrelenecek dosya adi: ";
                cin >> inputFile;
                cout << "Cikti dosya adi: ";
                cin >> outputFile;
                cout << "Anahtar: ";
                cin >> key;
                xorCipher(inputFile, outputFile, key);
                break;

            case 2:
                cout << "Cozulecek dosya adi: ";
                cin >> inputFile;
                cout << "Cikti dosya adi: ";
                cin >> outputFile;
                cout << "Anahtar: ";
                cin >> key;
                xorCipher(inputFile, outputFile, key);
                break;

            case 3:
                cout << "Dosya adi: ";
                cin >> inputFile;
                fileInfo(inputFile);
                break;

            case 4:
                cout << "Program kapatiliyor...\n";
                break;

            default:
                cout << "Gecersiz secim!\n";
        }

    } while (choice != 4);

    return 0;
}