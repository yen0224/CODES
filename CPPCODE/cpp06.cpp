//solution to 6.9
#include <iostream>
using namespace std;
double poundsToOunces(double pounds){
    double ounces=16*pounds;
    return ounces;
}
double ouncesToPounds(double ounces){
    double pounds=0.0625*ounces;
    return pounds;
}
int main(int argc, char const *argv[]){ 
    cout<<"Pounds\tOunces\t|\tOunces\tPounds\t\n";
    for (int i = 1; i < 11; i++)
    {
        cout<<i+10<<"\t"<<poundsToOunces(i+10)<<"\t|\t"<<i<<"\t"<<ouncesToPounds(i)<<endl;
    }
    
    return 0;
}