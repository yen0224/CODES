//this is the solution to EX
//student's ID: S0951037, Chia-Yen Hsu
//complier platform MacOS 11.2.3 Clang++(apple clang 12.0.0)
//encode: UTF-8
//DO NOT COPY
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    double velocity_ORI, velocity_AFT, duringTime;
    cout << "Enter v0, v1, and t:";
    cin >> velocity_ORI >> velocity_AFT >> duringTime;
    cout << "The average acceleration is " << (velocity_AFT - velocity_ORI) / duringTime << endl;
    return 0;
}