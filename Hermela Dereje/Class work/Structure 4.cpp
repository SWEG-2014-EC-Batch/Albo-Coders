#include <iostream>
using namespace std;

struct Phone {
    int area_code;
    int exchange;
    int number;
};

int main() {

    Phone my_phone = {212, 767, 8900};


    Phone user_phone;
    cout << "Enter phone number (area code, exchange, number): ";
    cin >> user_phone.area_code >> user_phone.exchange >> user_phone.number;
3
    cout << "My phone number: (" << my_phone.area_code << ") " << my_phone.exchange << "-" << my_phone.number << endl;
    cout << "User phone number: (" << user_phone.area_code << ") " << user_phone.exchange << "-" << user_phone.number << endl;

    return 0;
}
