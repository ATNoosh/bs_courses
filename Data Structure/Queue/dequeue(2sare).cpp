#include <iostream.h>
#include <conio.h>

#define MAXSIZE 5

//******************************************************************************
class cDeQueue
{
	public :
      cDeQueue();
      void ShowArr();
      void AddRight(int);
      void AddLeft(int);
      void DelRight();
      void DelLeft();

   private:
   	int array[MAXSIZE];
      int right , left;
};
//..............................................................................
cDeQueue :: cDeQueue()
{
	right = left = 0;
   for(int counter = 0;counter < MAXSIZE ;counter ++)
   	array[counter] = 0;
}
//..............................................................................
void cDeQueue :: ShowArr()
{
   for(int counter = left;counter <= right ;counter = (counter + 1) % MAXSIZE)
   	cout << endl <<array[counter];
}
//..............................................................................
void cDeQueue :: AddRight(int newItem)
{
	if((right + 1) % MAXSIZE == left)
		return;

	right = (right + 1) % MAXSIZE;
	array[right] = newItem;
}
//..............................................................................
void cDeQueue :: AddLeft(int newItem)
{
	if((right + 1) % MAXSIZE == left)
		return;

	if(left == 0)
		left = MAXSIZE - 1;
	else
		left --;

	array[left] = newItem;

}
//..............................................................................
void cDeQueue :: DelRight()
{
	if(left == right)
		return;

	if(right == 0)
		right = MAXSIZE - 1;
	else
		right --;
}
//..............................................................................
void cDeQueue :: DelLeft()
{
  	if(left == right)
		return;

	left = (left + 1) % MAXSIZE;

}
//..............................................................................
//******************************************************************************
void main()
{
	cDeQueue dq1;
	int num , sel;

	while(num != -1)
   {
   	cout << endl;
   	cin >> num;
      cin >> sel;
      switch(sel)
      {
      	case 1:
         	dq1.AddRight(num);
            break;
      	case 2:
         	dq1.AddLeft(num);
            break;
      	case 3:
         	dq1.DelRight();
            break;
      	case 4:
         	dq1.DelLeft();
            break;
      }
      clrscr();
      dq1.ShowArr();
   }
}
