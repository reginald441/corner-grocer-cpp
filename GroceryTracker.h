#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>
using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency;
    string inputFileName;
    string backupFileName;

public:
    GroceryTracker();
    void LoadDataFromFile();
    void CreateBackupFile() const;
    int GetItemFrequency(const string& item) const;
    void PrintAllFrequencies() const;
    void PrintHistogram() const;
    void DisplayMenu() const;
};

#endif
