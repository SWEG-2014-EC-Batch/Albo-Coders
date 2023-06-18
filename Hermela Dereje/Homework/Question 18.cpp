#include <iostream>
#include <cassert>
using namespace std;
void applyDiscount(double& price, double discount, bool isPercentage) {
    assert(discount >= 0.0);

    double discountAmount;
    if (isPercentage) {
        assert(discount <= 100.0);
        discountAmount = (discount / 100.0) * price;
    } else {
        discountAmount = discount;
    }

    assert(price - discountAmount >= 0.0);

    price -= discountAmount;
}

int main() {
    double price;
    double discount;
    bool isPercentage;

    cout << "Enter the price of the item: ";
    cin >> price;

    cout << "Enter the discount: ";
    cin >> discount;

    cout << "Is the discount a percentage? (1 for percentage, 0 for fixed amount): ";
    cin >> isPercentage;

    applyDiscount(price, discount, isPercentage);

    cout << "Price after discount: " << price << endl;

    return 0;
}
