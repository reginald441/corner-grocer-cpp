#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

GroceryTracker::GroceryTracker() {
    inputFileName = "CS210_Project_Three_Input_File.txt";
    backupFileName = "frequency.dat";
}

void GroceryTracker::LoadDataFromFile() {
    ifstream inputFile(inputFileName);
    string item;

    if (!inputFile.is_open()) {
        cout << "Error: Unable to open input file: " << inputFileName << endl;
        return;
    }

    itemFrequency.clear();

    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}

void GroceryTracker::CreateBackupFile() const {
    ofstream outputFile(backupFileName);

    if (!outputFile.is_open()) {
        cout << "Error: Unable to create backup file: " << backupFileName << endl;
        return;
    }

    for (const auto& pair : itemFrequency) {
        outputFile << pair.first << " " << pair.second << endl;
    }

    outputFile.close();
}

int GroceryTracker::GetItemFrequency(const string& item) const {
    auto it = itemFrequency.find(item);

    if (it != itemFrequency.end()) {
        return it->second;
    }

    return 0;
}

void GroceryTracker::PrintAllFrequencies() const {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void GroceryTracker::PrintHistogram() const {
    for (const auto& pair : itemFrequency) {
        cout << setw(12) << left << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

void GroceryTracker::DisplayMenu() const {
    cout << "\n========== Corner Grocer Menu ==========" << endl;
    cout << "1. Search for an item frequency" << endl;
    cout << "2. Print all item frequencies" << endl;
    cout << "3. Print histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

