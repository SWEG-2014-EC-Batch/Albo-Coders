#include <iostream>
#include <cassert>

using namespace std;

double calculate_discount(double price, double discount, bool is_percentage) {
    assert(discount >= 0 && "Discount cannot be negative");

    double discount_amount;
    if (is_percentage) {
        discount_amount = price * (discount / 100);
    } else {
        discount_amount = discount;
    }

    double discounted_price = price - discount_amount;
    assert(discounted_price > 0 && "Discounted price cannot be zero or negative");

    return discounted_price;
}

int main() {
    double price;
    double discount = 20.0;
    bool is_percentage = true;
    cout << "enter the price" << endl;
    cin >> price;

    double discounted_price = calculate_discount(price, discount, is_percentage);
    cout << "Discounted price: " << discounted_price << endl;

    return 0;
}
