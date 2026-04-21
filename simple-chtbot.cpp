#include <iostream>
#include <string>
using namespace std;

int main() {
    string userInput;

    cout << "Simple Chatbot (type 'exit' to quit)\n";

    while (true) {
        cout << "\nYou: ";
        getline(cin, userInput);

        if (userInput == "exit") {
            cout << "Bot: Goodbye!\n";
            break;
        }
        else if (userInput == "hello" || userInput == "hi") {
            cout << "Bot: Hello! How can I help you?\n";
        }
        else if (userInput == "how are you") {
            cout << "Bot: I'm just code, but I'm doing great!\n";
        }
        else if (userInput == "your name") {
            cout << "Bot: I'm a simple C++ chatbot.\n";
        }
        else if (userInput == "what can you do") {
            cout << "Bot: I can answer simple questions.\n";
        }
        else if (userInput == "bye") {
            cout << "Bot: Bye! Have a nice day!\n";
            break;
        }
        else {
            cout << "Bot: Sorry, I don't understand that.\n";
        }
    }

    return 0;
}