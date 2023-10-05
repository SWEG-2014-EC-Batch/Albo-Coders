#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

// Define the customer struct
struct Customer {
    int customer_ID;
    string Fname;
    string Lname;
    int age;
    string gender;
    string phone_number;
    bool hasCriminalRecord;
    int loyaltyPoints;
    int ticketNumber;
};
struct Ticket {
    int ticketNumber;
    string eventName;
    string eventDate;
    double ticketPrice;
};
  Ticket ticket;

const int MAX_ROWS = 5;
const int MAX_COLS = 10;

// Initialize a 2D array to represent seat availability
bool seats[MAX_ROWS][MAX_COLS] = {false}; // false indicates available, true indicates occupied

// Function to record a reservation
void reserveSeat(int row, int col) {
    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS) {
        if (!seats[row][col]) {
            seats[row][col] = true; // Mark the seat as occupied
            cout << "Seat at Row " << row << ", Col " << col << " has been reserved.\n";
        } else {
            cout << "Sorry, the seat at Row " << row << ", Col " << col << " is already occupied.\n";
        }
    } else {
        cout << "Invalid seat selection.\n";
    }
}

// Function to check seat availability
bool isSeatAvailable(int row, int col) {
    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS) {
        return !seats[row][col]; // Return true if the seat is available (not occupied)
    }
    return false; // Invalid seat selection
}

// Function to display the seating chart
void displaySeatingChart() {
    cout << "Seating Chart:\n";
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            if (seats[row][col]) {
                cout << "X "; // Occupied
            } else {
                cout << "O "; // Available
            }
        }
        cout << endl;
    }
}

// Function to add a customer to the file
Customer add_customer()
{
    fstream File;
    cout << "PLEASE FILL IN THE DATA.\n";
    File.open("info.txt", ios::out | ios::app);
    if (!File) {
        cout << "File opening failed.\n";
        exit(1);
    }

    Customer info;
    // Input customer's details
    cout << "Customer ID: ";
    cin >> info.customer_ID;
    File << info.customer_ID << " ";

    cout << "First Name: ";
    cin >> info.Fname;
    File << info.Fname << " ";

    cout << "Last Name: ";
    cin >> info.Lname;
    File << info.Lname << " ";

    cout << "Age: ";
    cin >> info.age;
    File << info.age << " ";

    cout << "Gender: ";
    cin >> info.gender;
    File << info.gender << " ";

    cout << "Phone number: ";
    cin >> info.phone_number;
    File << info.phone_number << " ";

    cout<<" do you have crime record ( 1 for yes , 0 for no )";
    cin>>info.hasCriminalRecord;
    File <<info.hasCriminalRecord << " ";


    // Initialize other fields with default values
    info.loyaltyPoints = 0;
    File <<info.loyaltyPoints << endl;

    // Add the customer to the vector

    File.clear();
    File.close();
    return info;
}

double calculateDiscount(int loyaltyPoints)
{
    // Define the conversion rate of loyalty points to discount
    const int POINTS_TO_DISCOUNT = 100;
    const double DISCOUNT_RATE = 0.05; // 10% discount per 100 points

    // Calculate the discount based on the loyalty points
    int discountPoints = loyaltyPoints / POINTS_TO_DISCOUNT;
    double discountAmount = discountPoints * DISCOUNT_RATE;

    return discountAmount;
}

void generateTicketAndReceipt(Customer& customer) {
    // Generate and display the ticket
    double discount = calculateDiscount(customer.loyaltyPoints);
    int price = ticket.ticketPrice - discount;

    cout << "\n*** Ticket ***" << endl;
    cout << "Event: " << ticket.eventName << endl;
    cout << "Date: " << ticket.eventDate << endl;
    cout << "Ticket Number: " << ticket.ticketNumber << endl;
    cout << "Price: $" << fixed << setprecision(2) << ticket.ticketPrice << endl;

    // Generate and display the receipt
    cout << "\n*** Receipt ***" << endl;
    cout << "Customer: " << customer.Fname << " " << customer.Lname << endl;
    cout << "loyaltyPoints: " << customer.loyaltyPoints << endl;
    cout << "Event: " << ticket.eventName << endl;
    cout << "Ticket Price: $" << fixed << setprecision(2) << price << endl;


    // Provide a prepaid card
    cout << "\n*** Prepaid Card Provided ***" << endl;
    cout << "Congratulations, " << customer.Fname << "! You've received a prepaid card worth $50." << endl;
}
// Function to search for a customer by ID
Customer search_customer() {
    int ID, count = 0;
    cout << "Enter the customer ID you want to search: ";
    cin >> ID;

    Customer info;
    fstream File;
    File.open("info.txt", ios::in);

    while (File >> info.customer_ID >> info.Fname >> info.Lname >> info.age >> info.gender >> info.phone_number >> info.hasCriminalRecord >> info.loyaltyPoints) {
        if (info.customer_ID == ID) {
            cout << "Customer Found:\n";
            cout << "Customer ID: " << info.customer_ID << endl;
            cout << "Name: " << info.Fname << " " << info.Lname << endl;
            cout << "Age: " << info.age << endl;
            cout << "Gender: " << info.gender << endl;
            cout << "Phone number: " << info.phone_number << endl;
            cout << "loyaltyPoints: " << info.loyaltyPoints << endl;
            count++;
            break;
        }
    }

    File.close();

    if (count == 0) {
        Customer no_info;
        cout << "Customer with customer ID " << ID << " not found.\n";
        return no_info;
    }
    return info;
}

// Function to delete a customer by ID
void delete_customer(int ID)
{
    int count = 0;

    Customer info;
    vector<Customer>all_info;
    ifstream File;
    File.open("info.txt");

    while (File >> info.customer_ID >> info.Fname >> info.Lname >> info.age >> info.gender >> info.phone_number >> info.hasCriminalRecord >> info.loyaltyPoints)  {
        if (info.customer_ID != ID) {
            all_info.push_back(info);
        }
        else
        {
            count++;
        }
    }

    File.close();

    ofstream out_file;
    out_file.open("info.txt");
    for (size_t i = 0; i < all_info.size(); i++)
    {
        out_file << all_info[i].customer_ID << " ";
        out_file << all_info[i].Fname << " ";
        out_file << all_info[i].Lname << " ";
        out_file << all_info[i].age << " ";
        out_file << all_info[i].gender << " ";
        out_file << all_info[i].phone_number << " ";
        out_file << all_info[i].hasCriminalRecord << " ";
        out_file << all_info[i].loyaltyPoints << endl;
    }

    out_file.close();

    if (count == 0) {
        cout << "Customer record not found!" << endl;
    } else {
        cout << "Customer record deleted successfully!" << endl;
    }
}

// Function to calculate price (I added a placeholder function)
void calculate_price(fstream& File) {
    cout << "Calculate price function called (placeholder).\n";
}

bool compare_fun(const Customer& a, const Customer& b)
{
    if (a.loyaltyPoints == b.loyaltyPoints)
    {
        return a.customer_ID < b.customer_ID;
    }
    return a.loyaltyPoints > b.loyaltyPoints;
}
// Function to display all customer records
void display_all_customer() {
    Customer info;

    vector<Customer>all_info;
    ifstream File;
    File.open("info.txt");

    while (File >> info.customer_ID >> info.Fname >> info.Lname >> info.age >> info.gender >> info.phone_number >> info.hasCriminalRecord >> info.loyaltyPoints)
    {
        all_info.push_back(info);
    }

    File.close();

    sort(all_info.begin(), all_info.end(), compare_fun);

    cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    cout << "CUSTOMERID"<<"\t\tFIRST-NAME"<<"\t\tLAST-NAME"<<"\t\tAGE"<<"\t\tGENDER"<<"\t\tPHONE NUMBER"<<"\t loyaltyPoints\n";
    cout << "------------------------------------------------------------------------------------------------------------------------\n";

    for(auto &info : all_info)  {
        cout << info.customer_ID << setw(15) << "\t" << info.Fname << setw(15) << "\t" << info.Lname << setw(13) << "\t" << info.age << setw(13) << "\t" << info.gender << setw(13) << "\t" << info.phone_number << setw(13) << info.loyaltyPoints << endl;
    }
}

bool checkTravelerLegality (Customer customer) {

    if (customer.age < 18) {
        cout << "Sorry, " << customer.Fname << ", you must be at least 18 years old to travel.\n";
        return false;
    }
    else if (customer.hasCriminalRecord == 1) {
        cout << "Sorry, " << customer.Fname << ", you are not allowed to travel due to a criminal record.\n";
        return false;
    }
    else if(customer.Fname.length() > 0)  {
    cout<< "passed the legality checks"<<endl;
    return true;
    }
    return false;
}

void updateLoyaltyPoints() {
    Customer info= search_customer();
    int pointsToAdd;
    if(checkTravelerLegality(info))
    {
        cout << "Enter the points to add: ";
        cin >> pointsToAdd;
        info.loyaltyPoints+=pointsToAdd;
        delete_customer(info.customer_ID);

        fstream File;
        File.open("info.txt", ios::out | ios::app);
        if (!File) {
            cout << "File opening failed.\n";
            exit(1);
        }


        File << info.customer_ID << " ";
        File << info.Fname << " ";
        File << info.Lname << " ";
        File << info.age << " ";
        File << info.gender << " ";
        File << info.phone_number << " ";
        File <<info.hasCriminalRecord << " ";
        File <<info.loyaltyPoints << endl;

        // Add the customer to the vector

        File.clear();
        File.close();

    }
}



void Reserve()
{
    int choice, row, col;
    Customer user;
    cout << "1.New customer" << endl;
    cout << "2.Old customer" << endl;
    do
    {
        cin >> choice;
        if(choice==1)
        {
            user=add_customer();
            break;
        }
        else if(choice==2)
        {
            user=search_customer();
            break;
        }
        else
            cout << "Invalid input" << endl;
    } while (true);

    if(checkTravelerLegality(user))
    {
        cout << "Enter the row and column to reserve (e.g., 2 3): ";
        cin >> row >> col;
        if (isSeatAvailable(row, col))
        {
            cout << "The seat is available.\n";
            reserveSeat(row, col);

            cout << "Enter the event name: ";
            cin.ignore(); // Clear the newline character from the previous input
            getline(cin, ticket.eventName);

            cout << "Enter the event date: ";
            getline(cin, ticket.eventDate);
ticket.ticketPrice=250;
                // Generate and display the ticket and receipt
            user.ticketNumber = rand() % 1000 + 1; // Generate a random ticket number
        //info.ticketPrice = 250.0;
            generateTicketAndReceipt(user);

        }
        else {
            cout << "The seat is occupied.\n";
            cout<< " pleas chose other seats.\n";
        }
    }

}
void intro() {
    cout<<"----------------------------------------------------------------------------------------------------"<< endl;
    cout<<"                                      Welcome to Bus Management system                              "<< endl;
    cout<<"----------------------------------------------------------------------------------------------------"<< endl;
     cout<<"\t\t\t\t\t\ press any key to get started!";
     cin.get();
}


int main() {
    int choice, row, col, ID;
    intro();
    system("cls");
    do {
        cout << "----- Bus Management System -----\n";
        cout << "1. Reserve a Seat\n";
        cout << "2. Check Seat Availability\n";
        cout << "3. DELETE CUSTOMER\n";
        cout << "4. search_customer\n";
        cout << "5. displaySeatingChart\n";
        cout << "6. display_all_customer\n";
        cout << "7. Check Traveler Legality (for managers)\n";
        cout << "8. Update Loyalty Points\n";
        cout << "0. Exit\n";
        cout << "-------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                 system("cls");
                Reserve();
                break;
            case 2:
                 system("cls");
                cout << "Enter the row and column to check availability (e.g., 2 3): ";
                cin >> row >> col;
                isSeatAvailable(row,col);
                if (isSeatAvailable(row, col)) {
                    cout << "The seat is available.\n";
                } else {
                    cout << "The seat is occupied.\n";
                }
                break;

            case 3:
                 system("cls");
                cout << "DELETE CUSTOMER" << endl;
                cout << "Enter customer's ID you want to delete: ";
                cin >> ID;
                delete_customer(ID);
                break;
            case 4:
                 system("cls");
                search_customer();
                break;
            case 5:
                 system("cls");
                displaySeatingChart();
                break;

            case 6:
                 system("cls");
                display_all_customer();
                break;
            case 7:
                 system("cls");
                if (checkTravelerLegality(search_customer())) {
                        cout << "Traveler is legal and can proceed.\n";
                    }
                break;
            case 8:
                 system("cls");
                updateLoyaltyPoints();
                break;

            case 0:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        cout << "Enter any key to go back";
        cin.ignore();
        cin.get();
    } while (choice != 0);
    return 0;
}

                
