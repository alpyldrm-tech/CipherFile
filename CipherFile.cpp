#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include <cctype>

using namespace std;
using namespace chrono;


// 1. SEZAR ŞİFRELEME DOSYA İŞLEMİ

// isEncrypt parametresi true ise şifreleme, false ise çözme işlemi
void caesarCipher(const string& inputFile, const string& outputFile, int key, bool isEncrypt) {
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    if (!inFile) {
        cout << "HATA: Girdi dosyasi acilamadi!\n";
        return;
    }

    // Dosyayı belleğe (vektöre) al
    vector<char> buffer((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());

    // Şifre çözme işlemiyse, Sezar mantığını tersine çevir (26 - key)
    int actualKey = isEncrypt ? key : (26 - (key % 26));

    auto start = high_resolution_clock::now();

    for (size_t i = 0; i < buffer.size(); i++) {
        char c = buffer[i];
        if (c >= 'a' && c <= 'z') {
            buffer[i] = (c - 'a' + actualKey) % 26 + 'a';
        }
        else if (c >= 'A' && c <= 'Z') {
            buffer[i] = (c - 'A' + actualKey) % 26 + 'A';
        }
    }

    outFile.write(buffer.data(), buffer.size());

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nSezar islemi basarili!\n";
    cout << "Islem suresi: " << duration.count() << " ms\n";
}


// 2. VİGENÈRE ŞİFRELEME DOSYA İŞLEMİ

// isEncrypt parametresi true ise şifreleme, false ise çözme işlemi
void vigenereCipher(const string& inputFile, const string& outputFile, const string& key, bool isEncrypt) {
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    if (!inFile) {
        cout << "HATA: Girdi dosyasi acilamadi!\n";
        return;
    }


    vector<char> buffer((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    auto start = high_resolution_clock::now();

    int j = 0;
    int keyLen = key.length();

    for (size_t i = 0; i < buffer.size(); i++) {
        char c = buffer[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            char keyChar = tolower(key[j % keyLen]);
            int shift = keyChar - 'a';

            // Şifre çözme işlemiyse kaydırma miktarını tersine çevir
            if (!isEncrypt) {
                shift = (26 - shift) % 26;
            }

            if (c >= 'a' && c <= 'z') {
                buffer[i] = (c - 'a' + shift) % 26 + 'a';
            }
            else if (c >= 'A' && c <= 'Z') {
                buffer[i] = (c - 'A' + shift) % 26 + 'A';
            }
            j++; // Sadece harf şifrelendiğinde anahtar ilerler
        }
    }

    outFile.write(buffer.data(), buffer.size());

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nVigenere islemi basarili!\n";
    cout << "Islem suresi: " << duration.count() << " ms\n";
}


// 3. XOR ŞİFRELEME DOSYA İŞLEMİ 

void xorCipher(const string& inputFile, const string& outputFile, const string& key) {
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    if (!inFile) {
        cout << "HATA: Girdi dosyasi acilamadi!\n";
        return;
    }

    vector<char> buffer((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    auto start = high_resolution_clock::now();

    for (size_t i = 0; i < buffer.size(); i++) {
        buffer[i] ^= key[i % key.length()];
    }

    outFile.write(buffer.data(), buffer.size());

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nXOR islemi basarili!\n";
    cout << "Islem suresi: " << duration.count() << " ms\n";
}


// YARDIMCI FONKSİYONLAR VE MENÜ

void fileInfo(const string& filename) {
    ifstream file(filename, ios::binary | ios::ate);
    if (!file) {
        cout << "HATA: Dosya bulunamadi!\n";
        return;
    }
    cout << "Dosya Boyutu: " << file.tellg() << " byte\n";
    system("pause");
}

void showMenu() {
    cout << "\n===========================================\n";
    cout << "      CIPHERFILE - DOSYA SIFRELEME\n";
    cout << "===========================================\n";
    cout << "1 - Dosya Sifrele\n";
    cout << "2 - Dosya Coz\n";
    cout << "3 - Dosya Bilgisi Goruntule\n";
    cout << "4 - Cikis\n";
    cout << "Seciminiz: ";
}


void processFile(bool isEncrypt) {
    int algoChoice;
    string inputFile, outputFile, strKey;
    int intKey;

    system("cls");
    cout << "\n--- Algoritma Secimi ---\n";
    cout << "1 - Sezar\n";
    cout << "2 - Vigenere\n";
    cout << "3 - XOR\n";
    cout << "Seciminiz: ";
    cin >> algoChoice;

    if (!(cin >> algoChoice) || algoChoice < 1 || algoChoice > 3) {
        cin.clear();
        cin.ignore(10000, '\n');

        cout << "Gecersiz algoritma secimi!\n";
        system("pause");
        return;
    }

    cout << (isEncrypt ? "Sifrelenecek" : "Cozulecek") << " dosya adi (ornek.txt): ";
    cin >> inputFile;
    cout << "Cikti dosya adi: ";
    cin >> outputFile;

    if (algoChoice == 1) {
        cout << "Anahtar (Sayi giriniz): ";
        cin >> intKey;
        caesarCipher(inputFile, outputFile, intKey, isEncrypt);
    }
    else if (algoChoice == 2) {
        cout << "Anahtar (Kelime giriniz): ";
        cin >> strKey;
        vigenereCipher(inputFile, outputFile, strKey, isEncrypt);
    }
    else if (algoChoice == 3) {
        cout << "Anahtar (Kelime giriniz): ";
        cin >> strKey;
        // XOR'da şifreleme ve çözme aynı işlemdir, isEncrypt parametresine gerek yok
        xorCipher(inputFile, outputFile, strKey);
    }

    cout << "\n";
    system("pause");
}

// MAIN FONKSİYONU

int main() {
    int choice;

    do {
        system("cls");
        showMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (choice) {
        case 1:
            processFile(true); // Şifrele
            break;
        case 2:
            processFile(false); // Çöz
            break;
        case 3:
        {
            string inputFile;
            cout << "Bilgisi goruntulenecek dosya adi: ";
            cin >> inputFile;
            fileInfo(inputFile);
        }
        break;
        case 4:
            break;
        default:
            cout << "Gecersiz secim!\n";
            system("pause");
        }
    } while (choice != 4);

    return 0;
}