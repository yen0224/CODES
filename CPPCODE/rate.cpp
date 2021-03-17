#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    cout << "Enter yearly interest rate:";
    float rate;
    cin >> rate;
    double mounthRate = rate / 1200;

    return 0;
}