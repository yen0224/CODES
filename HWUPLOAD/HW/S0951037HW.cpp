//written by Chiayen,HSU,S0951037
//DO NOT COPY
#include <iostream>
#include <iomanip>
//#include <time.h>
using namespace std;
int frameStart[4];
int firstday[4], jumpLine[4];
//在這邊輸出所有的月曆標頭，並用陣列特性直接呼叫月份名稱出來
//不需再更動
void canlenderTitle(int startMonth, int year, int amount)
{
    string mounthName[12] = {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = startMonth; i < startMonth + amount; i++)
    {
        cout << "                " << setw(9) << std::left
             << mounthName[i] << setw(4) << year
             << "                  ";
    }
    cout << endl;
}
//月跟月的分界、星期名稱與數字的分隔，可連續輸出多個
//不需再做更動
void seperator(int tms)
{
    for (int i = 0; i < tms; i++)
    {
        cout << "-----------------------------------------------";
    }
    cout << endl;
}
//輸出星期名稱，可連續輸出多個
//不需再做更動
void weekName(int tms)
{
    for (int i = 0; i < tms; i++)
    {
        cout << "     S     M     T     W     T     F     S     ";
    }
    cout << endl;
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
//輸出月曆，參數：月，跳行，模式
void MonthDayOutput(int month, int year, int mode)
{
    int isLeap;
    int monthInFunc;
    int monthdayLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int monthday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                isLeap = 1;
            else
                isLeap = 0;
        }
        else
        {
            isLeap = 1;
        }
    }
    else
    {
        isLeap = 0;
    }
    switch (mode)
    {
    case 0:
        firstday[0] = get_monthFirstDay(month, year);
        jumpLine[0] = 6 - firstday[0];
        cout << "|";
        for (int i = 0; i < 6 * firstday[0]; i++)
            cout << " ";
        for (int i = 0; i < (isLeap ? monthdayLeap[month] : monthday[month]); i++)
        {
            cout << setw(6) << right << i + 1;

            while (jumpLine[0] == 0)
            {
                cout << setw(4) << "|" << endl
                     << "|";
                jumpLine[0] = 7;
            }
            jumpLine[0]--;
        }
        break;
    //3*4
    case 1:
        //取得接下來輸出三個月的第一天分別是在禮拜幾，並存在陣列中
        monthInFunc = month;
        //取得各月之第一天，輸出至哪天需跳行
        for (int i = 0; i < 3; i++)
        {
            firstday[i] = get_monthFirstDay(monthInFunc, year);
            jumpLine[i] = 6 - firstday[i];
            monthInFunc++;
        }

        for (int i = 0; i < 3; i++)
        {
            //cout<<<<"|";
            for (int j = 0; j < 6 * firstday[i]; j++)
                cout << " ";
            for (int k = 0; k != jumpLine[i] + 1; k++)
            {
                cout << setw(6) << right << k + 1;
                if (jumpLine[i] == k)
                {
                    frameStart[i] = k + 2;
                }
            }
            cout << setw(5) << "|";
        }
        cout << endl;
        for (int t = 0; t < 5; t++)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 7; j++)
                {

                    if (frameStart[i] - 1 == (isLeap ? monthdayLeap[month + i] : monthday[month + i]))
                    {
                        cout << setw(6) << " ";
                    }
                    else
                    {
                        cout << setw(6) << frameStart[i];
                        frameStart[i]++;
                    }
                }
                cout << setw(5) << "|";
            }
            cout << endl;
        }
        break;

    //4*3
    case 2:
        //取得接下來輸出四個月的第一天分別是在禮拜幾，並存在陣列中
        monthInFunc = month;
        //取得各月之第一天，輸出至哪天需跳行
        for (int i = 0; i < 4; i++)
        {
            firstday[i] = get_monthFirstDay(monthInFunc, year);
            jumpLine[i] = 6 - firstday[i];
            monthInFunc++;
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 6 * firstday[i]; j++)
                cout << " ";
            for (int k = 0; k != jumpLine[i] + 1; k++)
            {
                cout << setw(6) << right << k + 1;
                if (jumpLine[i] == k)
                {
                    frameStart[i] = k + 2;
                    cout << setw(5) << "|";
                }
            }
        }
        cout << endl;
        for (int t = 0; t < 5; t++)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    if (frameStart[i] - 1 == (isLeap ? monthdayLeap[month + i] : monthday[month + i]))
                    {
                        cout << setw(6) << " ";
                    }
                    else
                    {
                        cout << setw(6) << frameStart[i];
                        frameStart[i]++;
                    }
                }
                cout << setw(5) << "|";
            }
            cout << endl;
        }
        break;
    default:
        break;
    }
}
int main(int argc, char const *argv[])
{
    int year;
    cout << "Enter the year of the canlender which you want to see:" << endl;
    cin >> year;
    //year=2021;
    //待新增功能：使使用者可選擇輸出格式
    cout << "[OPTION] please select the format :" << endl;
    cout << "[0]12x1" << endl
         << "[1] 3x4" << endl
         << "[2] 4x3" << endl;
    int format;
    cin >> format;
    //format=0;
    switch (format)
    {
    case 1:
        //3*4
        //i每跳一次會輸出三個月份
        for (int i = 0; i < 3; i++)
        {
            canlenderTitle(i * 3, year, 3);
            weekName(3);
            seperator(3);
            MonthDayOutput(i * 3, year, 1);
            seperator(3);
            cout << endl;
        }

        break;
    case 2:
        for (int i = 0; i < 3; i++)
        {
            canlenderTitle(i * 4, year, 4);
            weekName(4);
            seperator(4);
            MonthDayOutput(i * 3, year, 2);
            seperator(4);
            cout << endl;
        }
        break;
    default:
        cout << "unselected,or error command, the program would process by [default]: 12*1" << endl;
    case 0:
        for (int month = 0; month < 12; month++)
        {
            canlenderTitle(month, year, 1);
            weekName(1);
            seperator(1);
            MonthDayOutput(month, year, 0);
            cout << endl;
        }
        break;
    }
    cout << "THE PROGRAM IS WRITTEN BY CHIA-YEN, HSU" << endl
         << "DO NOT COPY" << endl;
    return 0;
}