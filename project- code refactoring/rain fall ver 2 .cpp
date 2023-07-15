#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_MONTHS = 12;
const string MONTHS[NUM_MONTHS] = {
    "Meskerem", "Tikimt", "Hidar", "Tahsas", "Tir", "Yekatit",
    "Megabit", "Miazia", "Genbot", "Sene", "Hamle", "Nehase"
};

struct RainfallData {
    double averageRainfall;
    double monthlyRainfall[NUM_MONTHS];
};

void displayRainfallTable(const RainfallData& data)
{
    cout << "Month\t\tRainfall\tDeviation from Average\n";
    cout << "--------------------------------------------\n";

    for (int i = 0; i < NUM_MONTHS; ++i)
    {
        double rainfall = data.monthlyRainfall[i];
        double deviation = rainfall - data.averageRainfall;

        cout << left << setw(10) << MONTHS[i];
        cout << right << setw(10) << rainfall;
        cout << right << setw(10) << deviation << endl;
    }
}

void displayRainfallBarGraph(const RainfallData& data)
{
    cout << "Month\t\tRainfall\tBar Graph\n";
    cout << "--------------------------------------------\n";

    for (int i = 0; i < NUM_MONTHS; ++i)
    {
        double rainfall = data.monthlyRainfall[i];

        cout << left << setw(10) << MONTHS[i];
        cout << right << setw(10) << rainfall;

        // Print bar graph
        for (int j = 0; j < static_cast<int>(rainfall); ++j)
        {
            cout << "*";
        }

        cout << endl;
    }
}

void saveRainfallData(const RainfallData& data)
{
    ofstream outputFile("rainfall_data.txt");
    if (outputFile.is_open())
    {
        outputFile << "Average Rainfall: " << data.averageRainfall << endl;
        for (int i = 0; i < NUM_MONTHS; ++i)
        {
            outputFile << MONTHS[i] << ": " << data.monthlyRainfall[i] << endl;
        }
        outputFile.close();
        cout << "Rainfall data saved to 'rainfall_data.txt'.\n";
    }
    else
    {
        cout << "Unable to open the file for saving the data.\n";
    }
}

RainfallData loadRainfallData()
{
    RainfallData data;

    ifstream inputFile("rainfall_data.txt");
    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            if (line.find("Average Rainfall:") != string::npos)
            {
                size_t pos = line.find(":");
                data.averageRainfall = stod(line.substr(pos + 1));
            }
            else
            {
                for (int i = 0; i < NUM_MONTHS; ++i)
                {
                    if (line.find(MONTHS[i] + ":") != string::npos)
                    {
                        size_t pos = line.find(":");
                        data.monthlyRainfall[i] = stod(line.substr(pos + 1));
                        break;
                    }
                }
            }
        }
        inputFile.close();
        cout << "Rainfall data loaded from 'rainfall_data.txt'.\n";
    }
    else
    {
        cout << "Unable to open the file for loading the data.\n";
    }

    return data;
}
