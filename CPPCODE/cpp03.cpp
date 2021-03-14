//this is the solution to ex4-05
//written by Chiayen,Hsu S0951037
//last edited: 3/14
#include <iostream>
//#include <cstdlib>
#include <cmath>
#define PI atan(1) * 4
using namespace std;
int main(int argc, char const *argv[])
{
    int side_N;
    double side;
    cout << "Enter the number of sides: ";
    cin >> side_N;
    cout << "Enter the side: ";
    cin >> side;
    cout << fixed << "The area of the polygon is " << side_N * pow(side, 2) / (4 * tan(PI / side_N));
    return 0;
}