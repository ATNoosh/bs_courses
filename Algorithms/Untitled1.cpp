#include <iostream.h>
#include <conio.h>

int fact(int );

int main()
{
    cout << fact(5);
    getch();
    return 0;
}

int fact(int n)
{
    static int x = 0;
    
    if(n < 2)return 1;
    return n*fact(n-1);
}
