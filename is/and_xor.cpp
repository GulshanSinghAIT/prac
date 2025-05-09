#include <iostream>
using namespace std;

int main() {
    string str = "Hello World";

    cout << "Char\tASCII\tAND(127)\tXOR(127)\n";
    for (char c : str) {
        int ascii = (int)c;
        int andResult = c & 127;
        int xorResult = c ^ 127;

        cout << c << "\t" << ascii << "\t" 
             << andResult << " (" << (char)andResult << ")\t" 
             << xorResult << " (" << (char)xorResult << ")\n";
    }

    return 0;
}
