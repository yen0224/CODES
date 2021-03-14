//solution to EX03-19
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    cout << "Enter a point with two coordinates: ";
    double x, y;
    cin >> x >> y;
    cout << "Point (" << x << "," << y << ") " << (pow(x, 2) + pow(y, 2) <= 100 ? "is" : "is not") << " in the circle.";
    return 0;
}