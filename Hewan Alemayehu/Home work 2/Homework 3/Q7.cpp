#include <iostream>
#include <fstream>
#include <string>

const int MAX_RECORDS = 100;

struct Tool {
    std::string toolName;
    int quantity;
    double cost;
};

void initializeFile() {
    std::fstream file("hardware.dat", std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Error creating file!" << std::endl;
        return;
    }

    Tool emptyTool;

    for (int i = 0; i < MAX_RECORDS; i++) {
        file.write(reinterpret_cast<char*>(&emptyTool), sizeof(Tool));
    }

    file.close();
}

void addTool() {
    std::fstream file("hardware.dat", std::ios::in | std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    int recordNumber;
    std::cout << "Enter the record number: ";
    std::cin >> recordNumber;

    // Check if record number is valid
    if (recordNumber < 0  recordNumber >= MAX_RECORDS) {
        std::cout << "Invalid record number!" << std::endl;
        file.close();
        return;
    }

    Tool tool;
    file.seekg(recordNumber * sizeof(Tool));
    file.read(reinterpret_cast<char*>(&tool), sizeof(Tool));

    // Check if record already exists
    if (tool.toolName != "") {
        std::cout << "Record already exists!" << std::endl;
        file.close();
        return;
    }

    std::cout << "Enter the tool name: ";
    std::cin.ignore();
    std::getline(std::cin, tool.toolName);

    std::cout << "Enter the quantity: ";
    std::cin >> tool.quantity;

    std::cout << "Enter the cost: ";
    std::cin >> tool.cost;

    file.seekp(recordNumber * sizeof(Tool));
    file.write(reinterpret_cast<char*>(&tool), sizeof(Tool));

    file.close();
}

void listTools() {
    std::fstream file("hardware.dat", std::ios::in | std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    Tool tool;
    int recordNumber = 0;

    std::cout << "Record #\tTool Name\tQuantity\tCost" << std::endl;
    while (file.read(reinterpret_cast<char*>(&tool), sizeof(Tool))) {
        if (tool.toolName != "") {
            std::cout << recordNumber << "\t\t" << tool.toolName << "\t\t" << tool.quantity << "\t\t" << tool.cost << std::endl;
        }
        recordNumber++;
    }

    file.close();
}

void deleteTool() {
    std::fstream file("hardware.dat", std::ios::in | std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    int recordNumber;
    std::cout << "Enter the record number to delete: ";
    std::cin >> recordNumber;

    // Check if record number is valid
    if (recordNumber < 0  recordNumber >= MAX_RECORDS) {
        std::cout << "Invalid record number!" << std::endl;
        file.close();
        return;
    }

    Tool emptyTool;
    file.seekp(recordNumber * sizeof(Tool));
    file.write(reinterpret_cast<char*>(&emptyTool), sizeof(Tool));

    file.close();
}

void updateTool() {
    std::fstream file("hardware.dat", std::ios::in | std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    int recordNumber;
    std::cout << "Enter the record number to update: ";
    std::cin >> recordNumber;

    // Check if record number is valid
    if (recordNumber < 0 || recordNumber >= MAX_RECORDS) {
        std::cout << "Invalid record number!" << std::endl;
        file.close();
        return;
    }

    Tool tool;
    file.seekg(recordNumber * sizeof(Tool));
    file.read(reinterpret_cast<char*>(&tool), sizeof(Tool));

    // Check if record exists
    if (tool.toolName == "") {
        std::cout << "Record does not exist!" << std::endl;
        file.close();
        return;
    }

    std::cout << "Enter the new tool name: ";
    std::cin.ignore();
    std::getline(std::cin, tool.toolName);

    std::cout << "Enter the new quantity: ";
    std::cin >> tool.quantity;

    std::cout << "Enter the new cost: ";
    std::cin >> tool.cost;
