#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

#define MAXSIZE 10

//..............................................................................
class cStack
{
	public :

   	cStack();
      bool Push(int);
      int Pop();
      bool IsEmpty();
      bool IsFull();
      void Menu();
      void Show();

   private:

   	int array[MAXSIZE];
   	int top;
};
//..............................................................................
cStack :: cStack()
{
	top = 0;

	for(int counter = 0;counter < MAXSIZE;counter ++)
   	array[counter] = 0;
}
//..............................................................................
void cStack :: Menu()
{
   clrscr();

	cout << "\n\n\n\n\n\t\t\t\t";
   cout << "1 ) Push .";
   cout << "\n\t\t\t\t2 ) Pop  .";
   cout << "\n\t\t\t\t3 ) Show .";
   cout << "\n\t\t\t\t4 ) Exit .";

   int select;

   cin >> select;
   switch(select)
   {
   	case 1:
      	int ele;
         cout << "Enter element : ";
         cin >> ele;
         this -> Push(ele);
      	break;
      case 2:
      	cout << this -> Pop();
      	break;
      case 3:
      	this -> Show();
         getch();
      	break;
      case 4:
      	exit(0);
      	break;
   }
}
//..............................................................................
void cStack :: Show()
{
	for(int counter = 0;counter < MAXSIZE;counter ++)
   	cout << endl << counter <<'\t'<< array[counter];

   cout << endl << endl <<"top : " << top ;
	for(int counter = 0;counter < top;counter ++)
   	cout << endl <<counter <<'\t'<< array[counter];
}
//..............................................................................
bool cStack :: Push(int newElement)
{
	if(top != MAXSIZE)
   {
   	array[top] = newElement;
      top ++;
      return true;
   }
   return false;
}
//..............................................................................
int cStack :: Pop()
{
	if(top != 0)
   {
   	top --;
      return array[top];
   }
}
//..............................................................................
bool cStack :: IsEmpty()
{
	if(top == 0)
   	return true;

   return false;
}
//..............................................................................
bool cStack :: IsFull()
{
	if(top == MAXSIZE)
   	return true;

   return false;
}
//..............................................................................
//******************************************************************************

void Reverse(cStack *, cStack *);

//******************************************************************************
void main()
{

  cStack mainStack , tempStack;

	for(;;)
  	{
  		for(;;)
  		{
  			int done = 0;
      	clrscr();

   		cout << "\n\n\n\n\n\t\t\t\t";
   		cout << "1 ) Push .";
   		cout << "\n\t\t\t\t2 ) Pop  .";
   		cout << "\n\t\t\t\t3 ) Show .";
   		cout << "\n\t\t\t\t4 ) Reverse .";

   		int select;

   		cin >> select;
   		switch(select)
   		{
   			case 1:
      			int ele;
         		cout << "Enter element : ";
         		cin >> ele;
         		mainStack.Push(ele);
      			break;
      		case 2:
      			cout << mainStack.Pop();
      			break;
      		case 3:
      			mainStack.Show();
         		getch();
      			break;
     			case 4:
     				done = 1;
      			break;
   		}

   	if(done == 1)
   		break;
   	}

   	Reverse(&mainStack , &tempStack);
	}

   getch();

}
//******************************************************************************
void Reverse(cStack *mainStack ,cStack *tempStack)
{

   if((mainStack -> IsEmpty()))
   	return ;

	int x = mainStack -> Pop();

  	Reverse(mainStack , tempStack);

   while(!(mainStack -> IsEmpty()))
   {
   	int y = mainStack -> Pop();
      tempStack -> Push(y);
   }

   mainStack -> Push(x);

   while(!(tempStack -> IsEmpty()))
   {
   	int y = tempStack -> Pop();
      mainStack -> Push(y);
   }

}
//******************************************************************************
