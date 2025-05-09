#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


string padText(string text, int keyLen) {
    int padLen = keyLen - (text.length() % keyLen);
    if (padLen != keyLen) {
        text.append(padLen, 'X');
    }
    return text;
}


string encrypt(string text, string key) {
    int keyLen = key.length();
    text = padText(text, keyLen);
    int rows = text.length() / keyLen;

    vector<string> matrix(rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = text.substr(i * keyLen, keyLen);
    }

    vector<pair<char, int>> keyOrder;
    for (int i = 0; i < keyLen; i++) {
        keyOrder.push_back({key[i], i});
    }
    sort(keyOrder.begin(), keyOrder.end());

    string cipher;
    for (int k = 0; k < keyLen; k++) {
        int col = keyOrder[k].second;
        for (int row = 0; row < rows; row++) {
            cipher += matrix[row][col];
        }
    }

    return cipher;
}


string decrypt(string cipher, string key) {
    int keyLen = key.length();
    int rows = cipher.length() / keyLen;

    vector<pair<char, int>> keyOrder;
    for (int i = 0; i < keyLen; i++) {
        keyOrder.push_back({key[i], i});
    }
    sort(keyOrder.begin(), keyOrder.end());

    vector<int> invOrder(keyLen);
    for (int i = 0; i < keyLen; i++) {
        invOrder[keyOrder[i].second] = i;
    }

    vector<string> matrix(rows, string(keyLen, ' '));
    int index = 0;
    for (int k = 0; k < keyLen; k++) {
        int col = keyOrder[k].second;
        for (int row = 0; row < rows; row++) {
            matrix[row][col] = cipher[index++];
        }
    }

    string plain;
    for (int row = 0; row < rows; row++) {
        plain += matrix[row];
    }

    return plain;
}

int main() {
    string text, key;

    cout << "Enter plain text (no spaces): ";
    cin >> text;
    cout << "Enter numeric key (e.g., 4312): ";
    cin >> key;

    string encrypted = encrypt(text, key);
    cout << "Encrypted: " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
