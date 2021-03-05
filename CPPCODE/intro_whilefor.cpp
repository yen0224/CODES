#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    /*回圈介紹：回圈的概念即為「重複執行」程式碼，常用的回圈有兩種：while和for
    while回圈：while回圈的概念為：條件成立便執行，而依「先判斷條件再執行」和「先執行再判斷條件」又分為
            while()和do-while()兩種，掛號內寫入條件即可
    for回圈：和while很像，可以說是自帶計數器的while回圈，括號內要填入：「定義計數器;計數器範圍;計數器運算方式」
    示範：
    */
    char s;
    scanf("%s", &s);
    while (s != 'e')//當s變數的內容不為“e”時，便執行程式碼
    {
        switch (s)
        {
        case 'w':
        case 'W':
            printf("%s", "up\n");
            break;
        case 'a':
        case 'A':
            printf("%s", "left\n");
            break;
        case 's':
        case 'S':
            printf("%s", "down\n");
            break;
        case 'd':
        case 'D':
            printf("%s", "right");
            break;
        default:
            printf("%s", "what??\n");
            break;
        }
        scanf("%s", &s);//上述程序已完成，而因為這段程式碼的目的是要使程式碼重複運作，故需再進行一次s的賦值
    }
    //for示範1
    
    for (int i = 1; i < 10; i++)
    {
        printf("%d\t%.0f\t%.0f\t%.0f\t\n", i, pow(i, 2), pow(i, 3), pow(i, 4));
        //
    }
    printf("%s","\n");
    //for示範2，三角形
    int level;//層數
    scanf("%d",&level);
    for (int i = 1; i <= level; i++)
    {
        int j;
        for (j=level-i; j >0; j--)
        {
            printf("%s"," ");
        }
        for (int k=1 ;k<=i; k++)
        {
            printf("%s","o");
        }
        printf("%s","\n");
        
        
        
    }
    
    return 0;
}
