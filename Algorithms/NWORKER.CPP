#include <iostream.h>
#include <conio.h>

const int SIZE = 4;

void main()
{
	for(;;)
   {
   cout << "\t\t\tNEXT MATRIX : \n" ;
   int C[SIZE][SIZE];
   int x = wherex();
   int y = wherey();
   for(int i = 0;i < SIZE ;i ++)
   {
   	for(int j = 0;j < SIZE ;j ++)
      {
      	gotoxy(x + 3 * i , 3 * j + y);
         cin >> C[j][i];
      }
   }

   for(int i = 0;i < SIZE;i ++)
   {
   	int sum = 0;
   	for(int j = 0;j < SIZE;j ++)
      {
   		sum += C[i][j];
      }
      cout << endl << "C[" << i << "][j] = " << sum;
   }
   cout << endl << endl;
   int j ;
   for(int i = 0;i < SIZE;i ++)
   {
   	int sum = 0;
   	for(j = 0;j < SIZE;j ++)
      {
   		sum += C[j][i];
      }
      cout << endl << "C[i][" << j << "] = " << sum;
   }                    
   cout << endl << endl;
   cout << endl << endl;

   for(int i = 0;i < SIZE ;i ++)
   {
   	for(int j = 0;j < SIZE ;j ++)
      {
   		for(int k = 0;k < SIZE ;k ++)
   		{
         	for(int l = 0;l < SIZE ; l ++)
            {
            	if(i == j || i == k || j == k
               || l == j || l == k || l == i)
                  continue;
               cout << '\t' << 1 <<' ' << i+1 << '\t' << 2 <<' ' << j+1 << '\t' << 3 <<' ' << k+1  << '\t' << 4 << ' ' << l + 1;
               cout << " : " << C[0][i] + C[1][j] + C[2][k] + C[3][l] << endl;
            }
      	}
      }
   }
   getch();
   }
}