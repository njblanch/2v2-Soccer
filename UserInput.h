//
// Created by Nathan Blanchard on 10/4/23.
//

#ifndef M2OEP_NJBLANCH_VALIDATEINPUT_H
#define M2OEP_NJBLANCH_VALIDATEINPUT_H

#include <string>
#include <iostream>

using std::string, std::ostream;

// Function gets and validates user input for an integer from 1 to selectionMax
int getUserInput(int selectionMax) {
    string input;
    int num;
    std::stringstream ss;
    getline(std::cin, input);
    // Check if input is empty
    if (input.length() == 0) {
        cout << "No input" << endl;
        cout << "Enter a number from 1 to " << selectionMax << "..." << endl;
        ss.clear();
        return getUserInput(selectionMax);
    }
    // Make sure all characters are numeric
    for (char c : input) {
        if (!isnumber(c)) {
            cout << "Invalid input" << endl;
            cout << "Enter a number from 1 to " << selectionMax << "..." << endl;
            return getUserInput(selectionMax);
        }
    }
    // Try to store input in num as int, check to make sure that it is within the desired range
    ss << input;
    if (!(ss >> num) || num > selectionMax || num <= 0) {
        cout << "Invalid input" << endl;
        cout << "Enter a number from 1 to " << selectionMax << "..." << endl;
        ss.clear();
        return getUserInput(selectionMax);
    }
    return num;
}

#endif //M2OEP_NJBLANCH_VALIDATEINPUT_H
