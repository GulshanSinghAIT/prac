#include <bits/stdc++.h>
using namespace std;

// Helper to convert string to lowercase for case-insensitive matching
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    map<string, string> chatbot;

    // Predefined questions and answers
    chatbot["hello"] = "Hi there! How can I help you today?";
    chatbot["who are you"] = "I'm a simple C++ chatbot.";
    chatbot["what is your name"] = "You can call me ChatBot!";
    chatbot["how are you"] = "I'm doing great. Thanks for asking!";
    chatbot["bye"] = "Goodbye! Have a nice day!";

    cout << "Welcome to ChatBot!\n";
    cout << "You can ask me basic questions. Type 'exit' to quit.\n\n";

    while (true) {
        cout << "👤 You: ";
        string user_input;
        getline(cin, user_input);

        string processed_input = toLower(user_input);

        if (processed_input == "exit") {
            cout << " ChatBot: It was nice talking to you. Bye!\n";
            break;
        }

        if (chatbot.find(processed_input) != chatbot.end()) {
            cout << " ChatBot: " << chatbot[processed_input] << "\n";
        } else {
            cout << " ChatBot: I don't know how to respond to that. What should I say?\n";
            cout << "  Teach me: ";
            string new_response;
            getline(cin, new_response);
            chatbot[processed_input] = new_response;
            cout << " ChatBot: Got it! I'll remember that.\n";
        }

        cout << "\n";
    }

    return 0;
}
