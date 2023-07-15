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
int main()
{
    RainfallData data;

    for (int i = 0; i < NUM_MONTHS; ++i)
    {
        cout << "Enter the average rainfall for " << MONTHS[i] << ": ";
        cin >> data.monthlyRainfall[i];
    }

    string currentMonth;
    cout << "Enter the current month: ";
    cin >> currentMonth;

    int startIndex = -1;
    for (int i = 0; i < NUM_MONTHS; ++i)
    {
        if (currentMonth == MONTHS[i])
        {
            startIndex = i;
            break;
        }
    }

    if (startIndex == -1)
    {
        cout << "Invalid month entered.\n";
        return 0;
    }

    for (int i = startIndex, count = 0; count < NUM_MONTHS; ++i, ++count)
    {
        if (i == NUM_MONTHS)
            i = 0;

        cout << "Enter the rainfall for " << MONTHS[i] << ": ";
        cin >> data.monthlyRainfall[i];
    }

    double sum = 0;
    for (int i = 0; i < NUM_MONTHS; ++i)
    {
        sum += data.monthlyRainfall[i];
    }
    data.averageRainfall = sum / NUM_MONTHS;
    char choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Display rainfall table\n";
        cout << "2. Display rainfall bar graph\n";
        cout << "3. Search for a specific month\n";
        cout << "4. Save rainfall data to a file\n";
        cout << "5. Load rainfall data from a file\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            displayRainfallTable(data);
            break;
        case '2':
            displayRainfallBarGraph(data);
            break;
        case '3':
            cout << "Enter the month to search: ";
            cin >> currentMonth;
            for (int i = 0; i < NUM_MONTHS; ++i)
            {
                if (currentMonth == MONTHS[i])
                {
                    cout << "Rainfall for " << currentMonth << ": " << data.monthlyRainfall[i] << " mm\n";
                    displayRainfallTable({ data.monthlyRainfall[i] });
                    displayRainfallBarGraph({ data.monthlyRainfall[i] });
                    break;
                }
            }
            break;
        case '4':
            saveRainfallData(data);
            break;
        case '5':
            data = loadRainfallData();
            break;
        case '6':
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != '6');

    return 0;
}
