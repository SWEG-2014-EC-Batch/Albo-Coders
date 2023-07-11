#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX_RECORDS = 100;

struct Tool {
    string toolName;
    int quantity;
    double cost;
};

void initializeFile() {
    fstream file("hardware.dat", ios::out | ios::binary);
    if (!file) {
        cerr << "Error creating file!" << endl;
        return;
    }

    Tool emptyTool;

    for (int i = 0; i < MAX_RECORDS; i++) {
        file.write(reinterpret_cast<char*>(&emptyTool), sizeof(Tool));
    }

    file.close();
}

void addTool() {
    fstream file("hardware.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    int recordNumber;
    cout << "Enter the record number: ";
    cin >> recordNumber;

    // Check if record number is valid
    if (recordNumber < 0 || recordNumber >= MAX_RECORDS) {
        cout << "Invalid record number!" << endl;
        file.close();
        return;
    }

    Tool tool;
    file.seekg(recordNumber * sizeof(Tool));
    file.read(reinterpret_cast<char*>(&tool), sizeof(Tool));

    // Check if record already exists
    if (tool.toolName != "") {
        cout << "Record already exists!" << endl;
        file.close();
        return;
    }

    cout << "Enter the tool name: ";
    cin.ignore();
    getline(cin, tool.toolName);

    cout << "Enter the quantity: ";
    cin >> tool.quantity;

    cout << "Enter the cost: ";
    cin >> tool.cost;

    file.seekp(recordNumber * sizeof(Tool));
    file.write(reinterpret_cast<char*>(&tool), sizeof(Tool));

    file.close();
}

void listTools() {
    fstream file("hardware.dat", ios::in | ios::binary);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    Tool tool;
    int recordNumber = 0;

    cout << "Record #\tTool Name\tQuantity\tCost" << endl;
    while (file.read(reinterpret_cast<char*>(&tool), sizeof(Tool))) {
        if (tool.toolName != "") {
            cout << recordNumber << "\t\t" << tool.toolName << "\t\t" << tool.quantity << "\t\t" << tool.cost << endl;
        }
        recordNumber++;
    }

    file.close();
}

void deleteTool() {
    fstream file("hardware.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    int recordNumber;
    cout << "Enter the record number to delete: ";
    cin >> recordNumber;

    // Check if record number is valid
    if (recordNumber < 0 || recordNumber >= MAX_RECORDS) {
        cout << "Invalid record number!" << endl;
        file.close();
        return;
    }

    Tool emptyTool;
    file.seekp(recordNumber * sizeof(Tool));
    file.write(reinterpret_cast<char*>(&emptyTool), sizeof(Tool));

    file.close();
}

void updateTool() {
    fstream file("hardware.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    int recordNumber;
    cout << "Enter the record number to update: ";
    cin >> recordNumber;

    // Check if record number is valid
    if (recordNumber < 0 || recordNumber >= MAX_RECORDS) {
        cout << "Invalid record number!" << endl;
        file.close();
        return;
    }

    Tool tool;
    file.seekg(recordNumber * sizeof(Tool));
    file.read(reinterpret_cast<char*>(&tool), sizeof(Tool));

    // Check if record exists
    if (tool.toolName == "") {
        cout << "Record does not exist!" << endl;
        file.close();
        return;
    }

    cout << "Enter the new tool name: ";
    cin.ignore();
    getline(cin, tool.toolName);

    cout << "Enter the new quantity: ";
    cin >> tool.quantity;

    cout << "Enter the new cost: ";
    cin >> tool.cost;

    file.seekp(recordNumber * sizeof(Tool));
    file.write(reinterpret_cast<char*>(&tool), sizeof(Tool));

    file.close();
}

int main() {
    initializeFile();

    int choice;
    do {
        cout << "1. Add a tool\n";
        cout << "2. List all tools\n";
        cout << "3. Delete a tool\n";
        cout << "4. Update a tool\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTool();
                break;
            case 2:
                listTools();
                break;
            case 3:
                deleteTool();
                break;
            case 4:
                updateTool();
                break;
            case 0:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}

