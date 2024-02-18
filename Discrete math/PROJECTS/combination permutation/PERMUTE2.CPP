#include <iostream.h>
#include <conio.h>

char mainArray[4];

void Permute(char[4],int);

void main()
{
	Permute(mainArray,0);
   getch();
}
void Permute(char array[4],int currentIndex)
{
	if(currentIndex == 4)
   {
   	cout << "\t";
   	for(int i = 0;i < 4;i++)
      {
      	cout << array[i];
      }
   	return;
   }
   array[currentIndex] = 'A';
   Permute(array,currentIndex + 1);
   array[currentIndex] = 'B';
   Permute(array,currentIndex + 1);
   array[currentIndex] = 'C';
   Permute(array,currentIndex + 1);
   array[currentIndex] = 'D';
   Permute(array,currentIndex + 1);
   array[currentIndex] = 'E';
   Permute(array,currentIndex + 1);
   array[currentIndex] = 'F';
   Permute(array,currentIndex + 1);
}