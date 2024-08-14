#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

// Define Morse code mappings
map<char, string> morseCode = {
    {'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},  {'E', "."},
    {'F', "..-."}, {'G', "--."},  {'H', "...."}, {'I', ".."},   {'J', ".---"},
    {'K', "-.-"},  {'L', ".-.."}, {'M', "--"},   {'N', "-."},   {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},  {'S', "..."},  {'T', "-"},
    {'U', "..-"},  {'V', "...-"}, {'W', ".--"},  {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'1', ".----"},{'2', "..---"},{'3', "...--"},{'4', "....-"},
    {'5', "....."},{'6', "-...."},{'7', "--..."},{'8', "---.."},{'9', "----."},
    {'0', "-----"},{' ', " / "}
};

// Reverse mapping for decoding Morse code back to text
map<string, char> reverseMorseCode;

void initializeReverseMorseCode() {
    for (auto pair : morseCode) {
        reverseMorseCode[pair.second] = pair.first;
    }
}

// Function to encode text to Morse code
string encodeToMorse(const string& text) {
    stringstream morseResult;
    for (char c : text) {
        c = toupper(c); // Convert to uppercase for uniformity
        if (morseCode.find(c) != morseCode.end()) {
            morseResult << morseCode[c] << " ";
        }
    }
    return morseResult.str();
}

// Function to decode Morse code to text
string decodeFromMorse(const string& morse) {
    stringstream textResult;
    stringstream morseStream(morse);
    string morseLetter;
    while (morseStream >> morseLetter) {
        if (reverseMorseCode.find(morseLetter) != reverseMorseCode.end()) {
            textResult << reverseMorseCode[morseLetter];
        } else if (morseLetter == "/") { // Space between words
            textResult << " ";
        }
    }
    return textResult.str();
}

int main() {
    // Initialize reverse morse code dictionary
    initializeReverseMorseCode();

    int choice;
    char continueChoice;

    do {
        cout << "Morse Code Translator" << endl;
        cout << "1. Encode text to Morse code" << endl;
        cout << "2. Decode Morse code to text" << endl;
        cout << "Choose an option (1 or 2): ";
        cin >> choice;
        cin.ignore();  // Ignore trailing newline

        if (choice == 1) {
            string text;
            cout << "Enter text to encode: ";
            getline(cin, text);
            string encoded = encodeToMorse(text);
            cout << "Morse code: " << encoded << endl;
        } else if (choice == 2) {
            string morse;
            cout << "Enter Morse code to decode (use spaces between letters and '/' for spaces between words): ";
            getline(cin, morse);
            string decoded = decodeFromMorse(morse);
            cout << "Decoded text: " << decoded << endl;
        } else {
            cout << "Invalid option, please choose either 1 or 2." << endl;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> continueChoice;
        cin.ignore();  // Ignore trailing newline

    } while (tolower(continueChoice) == 'y');

    cout << "Thank you for using the Morse Code Translator. Goodbye!" << endl;

    return 0;
}
