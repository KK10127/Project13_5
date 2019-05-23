/*
 * CHAPTER 13, PROJECT 5
 * CS 151
 * Tu 5:30-9:20 with Porto
 * Programmer: Jay Montoya
 *
 * PROBLEM STATEMENT:
 *      Write a program that asks the user for the name of a file and a string to search for.
 *      The program will search the file for all occurrences of the specified string and display
 *      all lines that containt the string. After all occurrences have been located, the program
 *      should report the number of times the string appeared in the file.
 *
 *  ALGORITHM:
 *  1. Define variables for the line, fileName, target string, target occurrences.
 *  2. Prompt user for the filename
 *  3. Open the infilestream
 *  4. Check that the filestream was opened correctly.
 *  5. While !file.eof()
 *      a. call line.find()
 *      b. see if the found value == string::npos
 *          IF it is, set startHere to 0 and break.
 *          ELSE increment the targetOccurenses and set the "startHere" to the
 *              found index + 1.
 *
 *  6. Output the occurenses
 *  7. Close the fileStream
 *
 */
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    // variables
    string line, fileName, target;
    int targetOccurences = 0;
    size_t found, startHere;
    int numLines;

    startHere = 0;

    // greeting and get filename
    cout << "Welcome to the demo of project 5!" << endl;
    cout << "Enter a file name: ";
    cin >> fileName;
    cout << "Enter a string to search for: ";
    cin >> target;

    // open filestream
    ifstream file;
    file.open(fileName, ios::in);

    // search for the string
    if (!file) {
        cout << "Could not open file!\n";
        return 0;
    }


    while(!file.eof()) {
        // get the next line
        getline(file, line);
        numLines++;

        // while we haven't reached the end of the line
        while (true) {

            found = line.find(target, startHere);
            if (found == string::npos) { // if the target screen was not found.
                startHere = 0;
                break; // go to the next line
            } else { // if it was found
                cout << "\tfound at line " << numLines << "!" << endl;
                targetOccurences++; // increment the occurrenses
                startHere = (found+1); // loop again but search after the found position
            }

        }
    }

    // occurrences output
    cout << "\n\n\'" << target << "\' was found " << targetOccurences << " times!" << endl;


    // housekeeping
    file.close();
    return 0;
}