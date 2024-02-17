#include <iostream.h>
#include <conio.h>

class Test
{
	public :
      Test(){}
      static int Add(int x,int y){return x + y;}

};

void main()
{
	cout << Test::Add(3 , 7);
   getch();
}