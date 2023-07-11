#include <iostream>
using namespace std;

struct Point {
    double x;
    double y;
};

Point readPoint() {
    Point p;
    cout << "Enter x coordinate: ";
    cin >> p.x;
    cout << "Enter y coordinate: ";
    cin >> p.y;
    return p;
}

void printPoint(Point p) {
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}

int main() {
    Point p = readPoint();
    cout << "The point is: ";
    printPoint(p);
    return 0;
}
