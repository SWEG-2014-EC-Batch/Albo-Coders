#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> numbers;

    // Inserting elements into the multiset
    numbers.insert(10);
    numbers.insert(30);
    numbers.insert(20);
    numbers.insert(10); // Allowing duplicate elements

    // Iterating over the multiset
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout <<endl;

    // Counting the occurrences of a specific element
    int count = numbers.count(10);
    cout << "Count of 10: " << count <<endl;

    // Removing elements from the multiset
    numbers.erase(30);

    // Checking if an element exists in the multiset
    bool exists = numbers.find(20) != numbers.end();
    cout << "Element 20 exists: " <<boolalpha << exists << endl;

    return 0;
}
