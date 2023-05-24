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