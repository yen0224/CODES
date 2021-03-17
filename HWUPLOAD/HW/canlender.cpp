#include <iostream>
//#include <time.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
//option: 可格式化
//在這邊輸出所有的月曆標頭，並用陣列特性直接呼叫月份名稱出來
void canlenderTitle(int month, int year)
{
    string mounthName[12] = {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    cout << "       " << mounthName[month] << " " << year << endl;
    cout << "---------------------------" << endl;
    cout << " S   M   T   W   T   F   S" << endl;
}
//判斷年是否為閏年後，輸出該月之月曆
double get_monthFirstDay(int month, int year)
{
    /*
    int monthday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int monthdayLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //判斷閏年:
    //馮四潤
    //逢百除四百才潤
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                //是閏年
            }
            else
            {
                //非潤
            }
        }
        else
        {
            //是潤
        }
    }
    else
    {
        //非潤
    }*/
    int d,m,y,c;
    d=1;
    if(month>2){
        m=month-2;
        y=year%100-1;
    }
    else if(month==1){
        m=11;
        y=year%100-1;
    }
    else m=12;
    y=year%100;
    if (year%100!=0)
        c=year%100+1;
    else c=year%100;
    int x=2.6*m-0.2;
    x%=7;
    int w=d%7+x+(5*(y%4))%7+(3*y)%7+(5*(c%4));
    return w;
}
void canlenderBody(int month, int year)
{
    
}

int main(int argc, char const *argv[])
{
    int year;
    
    cout << "Enter the year of the canlender which you want to see:";
    cin >> year;
    //待新增功能：使使用者可選擇輸出格式
    /*
    cout << "[OPTION]please select the format :" << endl;
    cout << "[0]12*1" << endl
         << "[1]3*4" << endl
         << "[2]2*6" << endl;
    int format;
    cin >> format;
    switch (format)
    {
    case 0:
         for (int month = 0; month < 12; month++){
        canlenderTitle(month, year);
        canlenderBody(month, year);
        cout << endl;
        }
        break;
    case 1:
    for (int month = 0; month < 12; month++){
        canlenderTitle(month, year);
        canlenderBody(month, year);
        cout << endl;
        }
        break;
    case 2:
    for (int month = 0; month < 12; month++)
    {
        canlenderTitle(month, year);
        canlenderBody(month, year);
        cout << endl;
        }
        break;
    default:
    cout<<"unselected,by [default]";
    for (int month = 0; month < 12; month++)
    {
        canlenderTitle(month, year);
        canlenderBody(month, year);
        cout << endl;
    
        break;
    }
    */

    //test year = 2021;
    //19000101 is Sunday
    
    for (int month = 0; month < 12; month++)
    {
        canlenderTitle(month, year);
        canlenderBody(month, year);
        cout << endl;
    }

    return 0;
}