#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    
    cout << 312032486 + 365 * 86400 / 7 - 365 * 86400 / 13 + 365 * 86400 / 45 << endl;
    cout << 312032486 + 5 * 365 * 86400 / 7. - 5 * 365 * 86400 / 13. + 5 * 365 * 86400 / 45. << endl;
    cout << int(312032486 + 5 * 365 * 86400 / 7. - 5 * 365 * 86400 / 13. + 5 * 365 * 86400 / 45.) << endl;
    return 0;
}