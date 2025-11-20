#include <iostream>
#include <string>
using namespace std;

string caesarCipher(string text, int shift) {
    string result = "";

    // Fix shift so it always stays within 0–25
    shift = shift % 26;
    if (shift < 0) {
        shift += 26;
    }

    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        // Uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (char)(((ch - 'A' + shift) % 26) + 'A');
        }
        // Lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (char)(((ch - 'a' + shift) % 26) + 'a');
        }
        // Non-letters remain unchanged

        result += ch;
    }

    return result;
}

int main() {
    string text;
    int shift;

    cout << "Enter text to encrypt: ";
    getline(cin, text);

    cout << "Enter shift value: ";
    cin >> shift;

    string encrypted = caesarCipher(text, shift);

    cout << "Encrypted text: " << encrypted << endl;

    return 0;
}

