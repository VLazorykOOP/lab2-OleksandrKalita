#include <iostream>
#include <string>
#include <bitset>

// Функція для доповнення тексту пробілами до 128 символів
std::string padText(const std::string& text) {
    std::string paddedText = text;
    if (paddedText.length() < 128) {
        paddedText.append(128 - paddedText.length(), ' ');
    }
    return paddedText;
}

// Функція для шифрування символу
std::bitset<16> encryptCharacter(char c, int position) {
    std::bitset<16> encrypted;
    unsigned char asciiCode = static_cast<unsigned char>(c);

    encrypted |= (asciiCode >> 4);        // Старша частина ASCII-коду
    encrypted |= (position << 4);         // Позиція символу
    encrypted |= ((asciiCode & 0x0F) << 11); // Молодша частина ASCII-коду
    encrypted |= encrypted.count() % 2;   // Біт парності

    return encrypted;
}

// Функція для шифрування тексту
std::bitset<16>* encryptText(const std::string& text) {
    std::bitset<16>* encryptedText = new std::bitset<16>[128];

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        encryptedText[i] = encryptCharacter(c, i);
    }

    return encryptedText;
}