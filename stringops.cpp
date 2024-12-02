/* Name: Bria Weisblat
Date: 11/18/2022
Section: 4
Assignment: Homework 6 Problem 1- String Operations
Due Date: 11/18/2022
About this project: This program takes in a user entered string and outputs statistics including
the number of vowels, the number of characters that appear in both cases, and whether or not
the string contains a hexadecimal value.
Assumptions: Assume that the user will only enter the proper type of data. Assume that the string
may contain multiple upper and lowercase pairs, but each matched pair of upper and lower case letters
would appear in the string only once. Assume that strings are terminated with '#". Assume that the
user inputs "Done" when they do not want to enter anymore strings.

All work below was performed by Bria Weisblat */


#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// Function Declarations
bool hasHexValue (string userString);
double vowelCount (string userString);
double caseMatchCount (string userString);

// Main function
int main() {

    string userString;

    cout << "Enter the string: ";
    getline(cin, userString, '#');

    // Continue to ask the user to enter a string until they input "Done"
    // \n is included since the user hits the enter key after they input their string
    while ( userString.compare("\nDone") != 0) {

        cout << "Number of vowels: " << vowelCount(userString) << endl;

        cout << "Number of matches upper and lowercase characters: " << caseMatchCount(userString) << endl;

        if (hasHexValue(userString))
            cout << "This string contains a hexadecimal value" << endl;
        else
            cout << "This string does not contain a hexadecimal value" << endl;

        cout << endl << "Enter the string: ";
        getline(cin, userString, '#');

    }
    return 0;
}


// Function Definitions
double vowelCount (string userString) {
    int numVowels = 0;
    int stringLength =  userString.size();

    // For each letter in the string
    for (int i =0; i < stringLength; i++){
       //Increase num vowels by 1 if the letter is an uppercase or lowercase vowel
        if ( (userString[i] == 'a') || (userString[i] == 'A') || (userString[i] == 'e') || (userString[i] == 'E') || (userString[i] == 'i') || (userString[i] == 'I') || (userString[i] == 'o') || (userString[i] == 'O') || (userString[i] == 'u') || (userString[i] == 'U')) {
            numVowels++;
        }
    }

    return numVowels;
}

double caseMatchCount (string userString) {
    int numMatches = 0;
    int stringLength = userString.size();

    // For each letter in the string
    for (int i = 0; i < stringLength; i++) {
        // If the letter is uppercase
        if (isupper(userString[i])) {
            // For each letter in the string after i
            for (int j = 1; j < stringLength; j++) {
                // If the letter is the first letter in lowercase
                if (userString[i + j] == tolower(userString[i]))
                    numMatches++;
            }
        }
        // If the letter is lowercase
        if (islower(userString[i])) {
            // For each letter in the string after i
            for (int j = 1; j < stringLength; j++) {
                // If the letter is the first letter in uppercase
                if (userString[i + j] == toupper(userString[i]))
                    numMatches++;
            }
        }
    }
    return numMatches;
}


bool hasHexValue (string userString) {
    bool hexVal;
    int stringLength = userString.size();

    // Find the first instance of 0x
    int hex0x = userString.find("0x");

    // While within the string
    while (hex0x != -1) {

        // If the character after 0x indicates a hexadecimal
        if (((userString[hex0x + 2] >= 'A') && (userString[hex0x + 2] <= 'F')) || ((userString[hex0x + 2] >= '0') && (userString[hex0x + 2] <= '9')) || ((userString[hex0x + 2] >= 'a') && (userString[hex0x + 2] <= 'f')))
            hexVal = true;

        // If the character after 0x does not indicate a hexadecimal
        else
            hexVal = false;

        // Search for any other instances of 0x
        hex0x = userString.find("0x", hex0x +1);
    }
    return hexVal;
}

