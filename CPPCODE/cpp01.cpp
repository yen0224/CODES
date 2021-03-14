//this is the solution to EX01_11
//student's ID: S0951037, Chia-Yen Hsu
//complier platform MacOS 11.2.3 Clang++(apple clang 12.0.0)
//encode: UTF-8
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    //current population is 312032486
    long current_amount = 312032486;
    //every day has 86400 sec.
    //86400*365=31536000
    long yearSecound = 31536000;
    //birth rate per year
    double birthPerYear = yearSecound / 7;
    //death rate per year
    double deathPerYear = yearSecound / 13;
    //immigrant rate per year
    double immigrantPerYear = yearSecound / 45;
    //output the current population
    cout << "Current population is " << current_amount << endl;
    //use for loop to output the polulation for the next 5 years
    for (int i = 1; i < 6; i++)
    {
        cout << "After " << i << " Year, the population will be " << current_amount + int(i * birthPerYear) - int(i * deathPerYear) + int(i * immigrantPerYear) << endl;
    }
    return 0;
}