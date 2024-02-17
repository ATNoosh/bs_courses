#include <iostream.h>
#include <conio.h>

void Magic(int );

void main()
{
	Magic(3);
   getch();
}
//******************************************************************************
void Magic(int rowCol)
{
	const int MAXSIZE = 5;
   int square[MAXSIZE][MAXSIZE];
	int k,l;

   if((rowCol > MAXSIZE) || (rowCol < 1))
   {
   	cout << "Error! out of range.";
      getch();
      return;
   }

   else if(!(rowCol % 2))
   {
   	cout << "Error! n is even.";
      getch();
      return;
   }

   for(int rowCounter = 0;rowCounter < rowCol;rowCounter ++)
   	for(int colCounter = 0;colCounter < rowCol;colCounter ++)
      	square[rowCounter][colCounter] = 0;

	square[0][(rowCol - 1) / 2] = 1;

   int key = 2;
   int i = 0;
   int j = (rowCol - 1) / 2;

   while(key <= rowCol * rowCol)
   {
   	if(i - 1 < 0)
      	k = rowCol - 1;
      else
      	k = i - 1;
      if(j - 1 < 0)
      	l = rowCol - 1;
      else
      	l = j - 1;
      if(square[k][l])
      	i = (i + 1) % rowCol;
      else
      {
      	i = k;
         j = l;
      }

      square[i][j] = key ;
      key ++;
   }

   cout << "Magic square of size " << rowCol << endl;

   for(int rowCounter = 0;rowCounter < rowCol;rowCounter ++)
   {
   	for(int colCounter = 0;colCounter < rowCol;colCounter ++)
      	cout << square[i][j] << " ";

      cout << endl;
   }
}
//******************************************************************************
