#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to calculate GCD (Greatest Common Divisor)
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to find the modular inverse of e modulo phi
int modInverse(int e, int phi) {
    for (int d = 1; d < phi; d++) {
        if ((e * d) % phi == 1) {
            return d;
        }
    }
    return -1; // If no modular inverse is found
}

// Function to perform modular exponentiation (base^exp % mod)
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;  // Take base modulo mod
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;  // Divide exp by 2
        base = (base * base) % mod;  // Square the base
    }
    return result;
}

int main() {
    // Set two small prime numbers for p and q
    int p = 61, q = 53;
    int n = p * q;             // n = p * q, used for encryption and decryption
    int phi = (p - 1) * (q - 1); // Euler's totient function

    // Choose e such that e is coprime with phi
    int e = 17; 
    while (gcd(e, phi) != 1) e++; // Find e where gcd(e, phi) == 1

    // Find d using the modular inverse of e mod phi
    int d = modInverse(e, phi);

    // Output the public and private keys
    cout << "Public key: (" << e << ", " << n << ")\n";
    cout << "Private key: (" << d << ", " << n << ")\n";

    // Input plaintext as a string
    string plaintext;
    cout << "Enter plaintext: ";
    cin >> plaintext;

    // Encrypt each character of the plaintext
    vector<long long> ciphertext;
    for (char c : plaintext) {
        ciphertext.push_back(powerMod(c, e, n)); // Encrypt each character
    }

    // Display the encrypted ciphertext
    cout << "Encrypted ciphertext: ";
    for (long long c : ciphertext) {
        cout << c << " ";  // Display encrypted numbers
    }
    cout << endl;

    // Decrypt the ciphertext to get back the original text
    string decrypted = "";
    for (long long c : ciphertext) {
        decrypted += (char)powerMod(c, d, n); // Decrypt each number to character
    }

    // Output the decrypted plaintext
    cout << "Decrypted plaintext: " << decrypted << endl;

    return 0;
}
