//solution to ex05-47
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    double userinput[10],sum = 0, devsum = 0,squareSum=0,avg;
    //double userinput[10] = {1, 2, 3, 4.5, 5.6, 6, 7, 8, 9, 10};
    for(int i=0;i<10;i++){
        cin>>userinput[i];
        sum+=userinput[i];   
    }
    avg=sum/10;
    for (int i = 0; i < 10; i++)
    {
        devsum+=pow(userinput[i]-avg,2);
    }
    cout << "The mean is " << avg << endl;
    cout << "The standard deviation is " << sqrt(devsum/9) << endl;

    return 0;
}
