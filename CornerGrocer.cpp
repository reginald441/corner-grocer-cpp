#include <iostream>
#include <limits>
#include <string>
#include "GroceryTracker.h"
using namespace std;

int main() {
    GroceryTracker tracker;
    tracker.LoadDataFromFile();
    tracker.CreateBackupFile();

    int choice = 0;

    do {
        tracker.DisplayMenu();

        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number from 1 to 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            string itemName;
            cout << "Enter the item name: ";
            getline(cin, itemName);

            int frequency = tracker.GetItemFrequency(itemName);
            cout << itemName << " was purchased " << frequency << " time(s)." << endl;
            break;
        }
        case 2:
            cout << "\nItem Frequencies:" << endl;
            tracker.PrintAllFrequencies();
            break;

        case 3:
            cout << "\nHistogram:" << endl;
            tracker.PrintHistogram();
            break;

        case 4:
            cout << "Exiting program. Goodbye." << endl;
            break;

        default:
            cout << "Invalid choice. Please select a number from 1 to 4." << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}
