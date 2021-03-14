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