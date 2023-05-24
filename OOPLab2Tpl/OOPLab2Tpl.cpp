#include <iostream>
#include <string>
#include <bitset>
using namespace std;

// Функція для доповнення тексту пробілами до 128 символів
string padText(const string& text) {
    string paddedText = text;
    if (paddedText.length() < 128) {
        paddedText.append(128 - paddedText.length(), ' ');
    }
    return paddedText;
}

// Функція для шифрування символу
bitset<16> encryptCharacter(char c, int position) {
    bitset<16> encrypted;
    unsigned char asciiCode = static_cast<unsigned char>(c);

    encrypted |= (asciiCode >> 4);        // Старша частина ASCII-коду
    encrypted |= (position << 4);         // Позиція символу
    encrypted |= ((asciiCode & 0x0F) << 11); // Молодша частина ASCII-коду
    encrypted |= encrypted.count() % 2;   // Біт парності

    return encrypted;
}

// Функція для шифрування тексту
bitset<16>* encryptText(const string& text) {
    bitset<16>* encryptedText = new bitset<16>[128];

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        encryptedText[i] = encryptCharacter(c, i);
    }

    return encryptedText;
}

int main() {
    string inputText;
    cout << "Введіть текст до 128 символів: ";
    getline(cin, inputText);

    string paddedText = padText(inputText);
    bitset<16>* encryptedText = encryptText(paddedText);

    cout << "Шифрований текст: " << endl;
    for (int i = 0; i < paddedText.length(); i++) {
        cout << "Символ '" << paddedText[i] << "': " << encryptedText[i] << endl;
    }

    delete[] encryptedText;

    return 0;
}