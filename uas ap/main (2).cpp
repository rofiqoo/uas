#include <iostream>
#include <cctype>
#include <unordered_set>

std::string encryptPassword(const std::string &inputPassword) {
    const int PASSWORD_LENGTH = 8;
    const int ALPHABET_SIZE = 26;
    const char MIN_DIGIT = '1';
    const char MAX_DIGIT = '4';

    if (inputPassword.length() != PASSWORD_LENGTH) {
        return "Password tidak valid.";
    }

    std::unordered_set<char> uniqueChars;
    std::string encryptedPassword;

    for (char currentChar : inputPassword) {
        if (!isalnum(currentChar) || uniqueChars.count(currentChar) > 0) {
            return "Password tidak valid.";
        }

        uniqueChars.insert(currentChar);

        if (isalpha(currentChar)) {
            char encryptedChar = ((tolower(currentChar) - 'a' + 2) % ALPHABET_SIZE) + 'a';
            encryptedPassword += isupper(currentChar) ? toupper(encryptedChar) : encryptedChar;
        } else if (isdigit(currentChar) && currentChar >= MIN_DIGIT && currentChar <= MAX_DIGIT) {
            encryptedPassword += std::to_string((currentChar - '0') * 2);
        } else {
            return "Password tidak valid.";
        }
    }

    return "Password asli: " + inputPassword + "\nPassword terenkripsi: " + encryptedPassword;
}

int main() {
    std::string userPassword;
    std::cout << "Masukkan password (8 karakter): ";
    std::cin >> userPassword;

    std::string encryptionResult = encryptPassword(userPassword);
    std::cout << encryptionResult << std::endl;

  return 0;
}