#include <iostream.h>
#include <stdio.h>
#include <conio.h>

int Combination(int,int);
int Min(int,int);

int main()
{
	int n , r;
    cout << "Enter n : ";
    cin >> n;
    cout << "Enter r : ";
    cin >> r;
    cout << Combination(n , r);
    getch();
    return 0;
}
//******************************************************************************
int Combination(int n,int r)
{
    int *array = new int[r];
    array[0] = 1;
    for(int i = 1;i < n;i ++)
        array[i] = 0;

	for(int i = 1;i <= n;i++)
   {
   	if(i % 2 == 0)
      {
      	array[i / 2] = 2 * (array[i / 2- 1] );
      	for(int j = Min(i/2 - 1,r); j > 0;j--)
         	array[j] += array[j - 1];
      }
      else
      {
      	for(int j = Min(i/2,r); j > 0;j--)
         	array[j] += array[j - 1];
      }
   }
   if(r > n/2)
   return array[n - r];
   return array[r];
}
//******************************************************************************
int Min(int x,int y)
{
    if(x > y)
        return y;
    return x;
}
//******************************************************************************
