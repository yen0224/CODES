//credit: Yen Hsu, github: https://github.com/yen2451/CLang/introToC_if-switch.c
#include <stdio.h>
int main(int argc, char const *argv[])
{
    /*if函式，為Ｃ語言中的條件判斷式，語法為：
    if (condition){  -->condition判斷式回傳值為非零才執行大括號內的程式碼，
    }
    else if(){      -->若有第二個條件判斷式才使用，可不寫，亦可重複使用
    }
    else{           -->上述所有條件不符合時，欲進行的程序，可不寫
    }
    */
    //示範：輸入二值，比對大小
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b)
    {
        printf("%s", "a is bigger\n");
    }
    else if (a < b)
    {
        printf("%s", "b is bigger\n");
    }
    else
    {
        printf("%s", "a is equal to b\n");
    }
    /*為另一種條件判斷式，若有要對一個變數的內容進行特定值比對時，會比if更方便
   switch (變數)
   {
   case 1 :
       變數值為1的時候要衝啥
       break;----->注意要加break，才能跳出比對程序
   case 2 :
   case 3 :
       變數值為2或3的時候要衝啥
       break;
   default:
       若上述直接不成立時要幹嘛
       break;
   }*/
    //（while回圈待介紹）依據使用者輸入的值做出回應
    char s;
    scanf("%s", &s);
    while (s != 'e')
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
        scanf("%s", &s);
    }
    return 0;
}
