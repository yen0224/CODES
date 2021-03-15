//solution to 7-11
#include <iostream>
#include <cmath>
using namespace std;
double mean (const double x[], int size){
    double Me,sum=0;
    for (int i = 0; i < size; i++)
        sum+=x[i];
    Me=sum/size;
    return Me;
}
double deviation(const double x[],int size){
    double dev,squareDev=0;
    double Me=mean(x,size);
    for (int i = 0; i < size; i++)
        squareDev+=pow(x[i]-Me,2);
    dev=sqrt(squareDev/(size-1));
    return dev;
}
int main(int argc, char const *argv[]){ 
    //double userinput[10]={1.9,2.5,3.7,2,1,6,3,4,5,2};
    double userinput[10];
    cout<<"Enter ten numbers:";
    for(int i=0;i<10;i++)
        cin>>userinput[i];   
    cout << "The mean is " << mean(userinput,10) << endl;
    cout << "The standard deviation is " << deviation(userinput,10)<< endl;
    return 0;
}