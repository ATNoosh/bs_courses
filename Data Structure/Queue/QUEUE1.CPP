#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

#define MAXSIZE 10

//******************************************************************************
class cArrayQ
{
	public :
   	cArrayQ();
      bool AddQ(int);
      bool DelQ();
      bool IsFull();
      bool IsEmpty();
      void Menu();
      void ShowQ();

   private:
   	int array[MAXSIZE];	//queue
      int rear;				//bottom of queue
};
//..............................................................................
cArrayQ :: cArrayQ()
{
	for(int counter = 0;counter < MAXSIZE;counter ++)
   	array[counter] = 0;

   rear = 0;
}
//..............................................................................
bool cArrayQ :: AddQ(int element)
{
	if(this -> IsFull() == true)
   	return false;

   array[rear] = element;
   rear ++;

   return true;
}
//..............................................................................
bool cArrayQ :: DelQ()
{
	if(rear == 0)
   	return false;

	for(int counter = 0;counter < rear;counter ++)
   	array[counter] = array[counter + 1];
   rear --;
   return true;
}
//..............................................................................
bool cArrayQ :: IsFull()
{
	return (rear == MAXSIZE) ? true : false;
}
//..............................................................................
bool cArrayQ :: IsEmpty()
{
	return (rear == 0) ? true : false;
}
//..............................................................................
void cArrayQ :: ShowQ()
{
	for(int counter = 0;counter < MAXSIZE;counter ++)
   	cout << endl << counter << '\t' << array[counter] ;

   cout << endl << "rear : " << rear << endl << endl;

   for(int counter = 0;counter < rear;counter ++)
   {
   	cout << endl << counter << '\t' << array[counter];
   }
}
//..............................................................................
void cArrayQ :: Menu()
{
	for(;;)
   {
		clrscr();
		cout << "\n\n\n\n\n\n\t\t\t\tA ) AddQ."
   	<< endl << "\t\t\t\tD ) DelQ."
   	<< endl << "\t\t\t\tS ) ShowQ."
   	<< endl << "\t\t\t\tF ) Is full."
   	<< endl << "\t\t\t\tE ) Is empty."
   	<< endl << "\t\t\t\tQ ) Quit.\n" ;

   	char select;

   	cin >> select ;

   	switch(select)
   	{
   		case 'a':
   		case 'A':
         	if(this -> IsFull() == false)
            {
      			int ele;
      			cout << "Enter element : ";
         		cin >> ele;
               this -> AddQ(ele);
            }
            else
            {
					cout << "\nThe queue is full.";
            	getch();
            }
      		break;
   		case 'd':
   		case 'D':
				if(this -> DelQ() == false)
            {
         		cout << "\nThe queue is empty.";
            	getch();
            }
      		break;
   		case 's':
   		case 'S':
      		this -> ShowQ();
            getch();
      		break;
   		case 'f':
   		case 'F':
      		if(IsFull() == true)
            	cout << "\nThe queue is full.";
            else
               cout << "\nThe queue is not full." ;
            getch();
      		break;
   		case 'e':
   		case 'E':
      		if(IsEmpty() == false)
            	cout << "\nThe queue is not empty.";
            else
               cout << "\nThe queue is empty." ;
      		getch();
      		break;
   		case 'q':
   		case 'Q':
         	exit(0);
      		break;
   	}
   }
}
//..............................................................................
//******************************************************************************
void main()
{
	cArrayQ q1;
   q1.Menu();
}
//******************************************************************************