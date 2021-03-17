#include <iostream>
#include <iomanip>
//#include <time.h>

using namespace std;
//在這邊輸出所有的月曆標頭，並用陣列特性直接呼叫月份名稱出來
void canlenderTitle(int month, int year)
{
    string mounthName[12] = {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    cout << "                " << setw(9)<<std::left<<mounthName[month] <<setw(4)<< year<< "                  "<< endl;
    cout << "-----------------------------------------------" << endl;
    cout << "     S     M     T     W     T     F     S" << endl;
}
//輸出閏年之月曆
void isLeapYear(int month, int jumpLine)
{
    int monthdayLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < monthdayLeap[month]; i++)
    {
        
        cout<<setw(6)<<right<<i+1;

        while (jumpLine == 0)
        {
            cout <<"    "<< endl;
            jumpLine = 7;
        }
        jumpLine--;
    }
}
//輸出平年之月曆
void notLeapYear(int month, int jumpLine)
{
    int monthday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < monthday[month]; i++)
    {
        cout<<setw(6)<<right<<i+1;
        while (jumpLine == 0)
        {
            cout <<"    "<< endl;
            jumpLine = 7;
        }
        jumpLine--;
    }
}
//判斷該年該月之第一天是星期幾
//有二參數傳入：月份和年份
//由高斯公式得出該年該月之一日在星期幾
int get_monthFirstDay(int month, int year)
{
    month += 1;
    int d = 1, a, b, m, w;
    m = month + 12 - 2;
    (m > 12 ? m %= 12 : m);
    if (month == 1 || month == 2)
    {
        a = (year - 1) / 100;
        b = (year - 1) % 100;
    }
    else
    {
        a = year / 100;
        b = year % 100;
    }
    w = d + int(2.6 * m - 0.2) - 2 * a + b + int(a / 4) + int(b / 4);
    //cout<<a<<" "<<b<<" "<<m<<" "<<d<<" "<<w<<endl;
    while (w < 7)
        w += 7;
    w %= 7;
    return w;
}
void canlenderBody(int month, int year)
{
    int firstday = get_monthFirstDay(month, year);
    int jumpLine = 6 - firstday;
    for (int i = 0; i < 6 * firstday; i++)
        cout << " ";
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                isLeapYear(month, jumpLine);
            }
            else
            {
                notLeapYear(month, jumpLine);
            }
        }
        else
        {
            isLeapYear(month, jumpLine);
        }
    }
    else
    {
        notLeapYear(month, jumpLine);
    }
    //cout<<"^start at here"<<endl;
}

int main(int argc, char const *argv[])
{
    int year;

    cout << "Enter the year of the canlender which you want to see:" << endl;
    cin >> year;
    
    //待新增功能：使使用者可選擇輸出格式

    /*cout << "[OPTION] please select the format you want :" << endl;
    cout << "[0]12x1" << endl
         << "[1] 3x4" << endl
         << "[2] 4x3" << endl;
    int format;
    */
    //cin >> format;
        for (int month = 0; month < 12; month++)
        {
            canlenderTitle(month, year);
            canlenderBody(month, year);
            cout << endl;
        }
       
        return 0;
    }
