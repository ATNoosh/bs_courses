#include <iostream.h>
#include <conio.h>
#include <stdio.h>

#define F1 59
#define F2 60
#define CTRLDEL 83
#define END 79
#define HOME 71
#define UPARROW 72
#define DOWNARROW 80
#define LEFTARROW 75
#define RIGHTARROW 77

int backGround = 0,foreGround = 15;

void Brush()
{
	for(long counter = 0;counter < 4000;counter ++)
   {
   	textbackground(backGround);
      textcolor(foreGround);
   	cprintf("%c",' ');
   }
     /*	textbackground(backGround);
      textcolor(foreGround);
   window(1,1,80,50);*/
}
//..............................................................................
//******************************************************************************
class cFile
{
	public :
   	cFile(){}
   private:
   	FILE *filePointer;
};
//..............................................................................
//******************************************************************************
//..............................................................................
class cCharNode
{
   friend ostream &operator << (ostream & , const cCharNode &);
   friend class cString;

	public :
      cCharNode(char = 0,int = 0,int = 0,bool = 0);
      void SetLocAndSel(int,int,bool);

   private:
   	char character;
      int row;
      int col;
      bool select;

      cCharNode *next;
      cCharNode *pre ;
};
//..............................................................................
cCharNode :: cCharNode(char ch,int r,int c,bool isSel)
{
	next = pre = NULL;

	character = ch;
   row = r;
   col = c;
   select = isSel;
}
//..............................................................................
void cCharNode :: SetLocAndSel(int r,int c,bool isSel)
{
   row = r;
   col = c;
   select = isSel;
}
//..............................................................................
//******************************************************************************
ostream &operator << (ostream &output , const cCharNode &ch)
{
	gotoxy(ch.col,ch.row);
   if(ch.select == false)
   {
   	textbackground(backGround);
      textcolor(foreGround);
   	cprintf("%c",ch.character);
   }
   else
	{
   	textbackground(foreGround);
      textcolor(backGround);
   	cprintf("%c",ch.character);
   }
   return output;
}
//******************************************************************************
//..............................................................................
//******************************************************************************
class cString
{
	public :
      cString();
      void Manager();
      void ExtendedCodeFunc(int,int);
      void SetLocations(cCharNode*);

      cCharNode* Search(int , int);
      int SearchWord(char*);
      void SearchWindow();
      void SearchSelect();

      void Copy();
      void CopyPaste(int);
      void CutPaste();

      void PrintAll();
      void PrintPart(cCharNode* , cCharNode*);
      void PrintLine(cCharNode*);
      void DelPrint(cCharNode*);

      void AddLast(cCharNode *);
      void AddFirst(cCharNode*);
      void AddAfter(cCharNode*,cCharNode*);
      void AddTab(int,int);

      void Delete(cCharNode*);
      void Select(cCharNode*,int);
      void Select(cCharNode*,cCharNode*);
      void SetSelects();
      void ShowHelp();
   private:
   	cCharNode *first;
   	cCharNode *last ;
      cCharNode *currentPos;
      cCharNode *startCopy;

      void EnterKey(int,int);
      void BackSpaceKey();
      void DelKey();
      void TabKey(int,int);
      void UsualKey(int,int,int);
      void EndKey();
      void HomeKey();

      void GoRight(int,int);
      void GoLeft(int,int);
      void GoUp(int,int);
      void GoDown(int,int);
};
//..............................................................................
cString :: cString()
{
	first = last = currentPos = startCopy = NULL;
}
//..............................................................................
void cString :: Select(cCharNode *start,cCharNode *end)
{
	if(!first)
   	return;

   cCharNode *temp = start;
   if(temp -> next)
   {
   	while(temp != end -> next)
      {
      	temp -> select = !(temp -> select);
      	temp = temp -> next;
      }
   }
}
//..............................................................................
void cString :: SetSelects()
{
	if(!first)
   	return;
   cCharNode *temp = first;

   while(temp != last -> next)
   {
   	temp -> select = false;
   	temp = temp -> next;
   }
}
//..............................................................................
void cString :: SearchSelect()
{
	if(!first)
   	return;

   cCharNode *temp = first;

   if(temp -> next)
   {
   	while(temp != last -> next)
      {
      	if(temp -> select == true)
         	break;
      	temp = temp -> next;
      }

      startCopy = temp;
   }
}
//..............................................................................
void cString :: Copy()
{
	SearchSelect();
   //SetSelects();
}
//..............................................................................
void cString :: CopyPaste(int cutCopy)
{
	if(cutCopy == 0)
   {
   	CutPaste();
      return;
   }
	if(!first || !startCopy)
   	return;

   cCharNode *temp = startCopy;

   while(temp != last -> next && temp -> select != false)
   {
   	cCharNode *newNode;
      newNode = new cCharNode(temp -> character);

      AddAfter(currentPos , newNode);
      currentPos = newNode;
   	temp = temp -> next;
   }

   SetLocations(first);
   //SetSelects();
   clrscr();

  	textbackground(0);
   textcolor(15);
   PrintAll();

}
//..............................................................................
void cString :: CutPaste()
{

	if(!first || !startCopy)
   	return;

   cCharNode *temp = startCopy;

   while(temp -> select != false && temp != last -> next)
   {
   	cCharNode *newNode;
      newNode = new cCharNode(temp -> character);

      AddAfter(currentPos , newNode);
      currentPos = newNode;
   	temp = temp -> next;
      Delete(temp -> pre);
   }

   SetLocations(first);
   //SetSelects();
   clrscr();
   	textbackground(0);
      textcolor(15);
   PrintAll();

}
//..............................................................................
cCharNode* cString :: Search(int r,int c)
{
	if(!first)
   	return NULL;

   if(((first -> row) == r) && ((first -> col) == c))
   	return first;

   if(((last -> row) == r) && ((last -> col) == c))
   	return last;

   if(((currentPos -> row) == r) && ((currentPos -> col) == c))
   	return currentPos;

   cCharNode *temp = first -> next;

   while(temp != last)
   {
   	if(temp)
      {
   		if(temp -> row == r && temp -> col == c)
      		return temp;
   		temp = temp -> next;
      }
      else
      	return NULL;
   }

   return NULL;
}
//..............................................................................
void cString :: Select(cCharNode *start,int size)
{
	cCharNode *temp = start;

   if(temp -> next)
   {
   	for(int counter = 0;counter < size;counter ++)
      {
      	temp -> select = true;
         if(temp == last)
         {
         	textcolor(0);
            textbackground(15);
         }
      	temp = temp -> next;
      }
   }
}
//..............................................................................
void cString :: SearchWindow()
{
	clrscr();
   textcolor(3);
   textbackground(5);
   window(15,5,64,5);
   cprintf("\n\r                 Search Window                  ",179);
   textcolor(5);
   textbackground(3);
   window(15,6,64,6);
   cprintf("\n\r                                                ",179);
   textcolor(5);
   textbackground(3);
   window(15,6,64,6);
   cprintf("\n\r           Word :                               ",179);
   textcolor(5);
   textbackground(3);
   window(15,7,64,7);
   cprintf("\n\r                                                ",179);
   textcolor(5);
   textbackground(3);
   window(15,8,64,8);
   cprintf("\n\r           Casensive :                          ",179);
   textcolor(5);
   textbackground(3);
   window(15,9,64,9);
   cprintf("\n\r                                                ",179);
}
//..............................................................................
int cString :: SearchWord(char *word)
{

	//SearchWindow();
	clrscr();
   cout << "Enter a word:";
   //gotoxy(33,6);
   //cgets(word);
   cin >> word;
   //window(1,1,80,25);
   //textcolor(foreGround);
   //textbackground(backGround);

	clrscr();

	cCharNode *temp1 , *temp2;
   temp1 = first;

   while(temp1 != last -> next)
   {
   	temp2 = temp1 ;
   	for(unsigned counter = 0;counter < strlen(word);counter ++)
      {
      	if(temp2 -> character != word[counter])
         	break;
         if(counter == strlen(word) - 1)
         {
   			Select(temp1,strlen(word));
            currentPos = temp1;
   			clrscr();
   			PrintAll();
            cout << *currentPos;
            SetSelects();
            return 1;
         }
         temp2 = temp2 -> next;
      }

   	temp1 = temp1 -> next;
   }

   return 0;
}
//..............................................................................
void cString :: Manager()
{
	int r , c , ch , cutCopy = 1;

   for(;;)
   {
   	r = wherey();
   	c = wherex();
      ch = getch();

      switch(ch)
      {
      	case 0 :
         	ExtendedCodeFunc(r , c);
         	break;

         case 24:
         	Copy();
            cutCopy = 0;
            break;

         case 3 :
         	Copy();
            break;

         case 22:
         	CopyPaste(cutCopy);
            break;

         case 6: //ctrl + f
           SearchWord("ali");
           break;

         case 13:
         	EnterKey(r,c);
            break;

         case 8:
         	BackSpaceKey();
         	break;

         case 9:
         	TabKey(r,c);
            break;

         default:
         	UsualKey(ch , r , c);
         	break;
      }
   }
}
//..............................................................................
void cString :: EnterKey(int r,int c)
{
   cCharNode *newNode;
	newNode = new cCharNode('\n' , r , c , false);

   AddAfter(currentPos , newNode);
   SetLocations(currentPos);
   currentPos = newNode;

  	if(currentPos -> pre)
  		DelPrint(currentPos -> pre);
   else
   {
   	clrscr();
      PrintAll();
      gotoxy(1 , 1);
   }

   if(currentPos -> next)
   	gotoxy(currentPos -> next -> col,currentPos -> next -> row);
   else
   	gotoxy(1 , r + 1);
}
//..............................................................................
void cString :: TabKey(int r,int c)
{
	AddTab(r , c);
   SetLocations(currentPos);
   PrintLine(currentPos);
   cout << *currentPos;
}
//..............................................................................
void cString :: BackSpaceKey()
{
	if(!currentPos)
   {
   	delline();
      PrintLine(currentPos);
   	gotoxy(1,1);
      return;
   }
   int mid = 0;
   currentPos = currentPos -> pre;

   if(currentPos)
   {
   	Delete(currentPos -> next);
      int c = wherex();

      //if(c != 1)
      //{

      if( Search(currentPos -> row + 1, 1) == NULL)	//last line
      	delline();
      else
      {
	      if( currentPos -> col != 1)
   	   {
      		clreol();
         	mid = 0;
      	}
         else{
      	mid = 1;
      	//delline();	//clear characters to end of current line
          }
      }
      //}
   }
   else
   	Delete(first);

   SetLocations(currentPos);
   if(mid == 0)
   PrintLine(currentPos);
   else
   //PrintPart(currentPos -> pre->pre,last);
   PrintAll();

   if(currentPos)
   	if(currentPos -> next)
      	gotoxy(currentPos -> next -> col,currentPos -> next -> row);
}
//..............................................................................
void cString :: DelKey()
{
	if(!currentPos)
   {
   	gotoxy(1,1);
      return;
   }

   if(currentPos -> next)
   	currentPos = currentPos -> next;
   else
   {
   	cout << *currentPos;
   	return;
   }

   if(currentPos)
   {
   	Delete(currentPos -> pre);
      delline();
   }

   SetLocations(currentPos);
   PrintLine(currentPos);

   if(currentPos)
     	gotoxy(currentPos -> col,currentPos -> row);
}
//..............................................................................
void cString :: UsualKey(int ch,int r,int c)
{
	cCharNode *newNode;
	newNode = new cCharNode(ch , r , c , false);	//new character

   if(r == 1 && c == 1)		//first point of page
   {
      AddFirst(newNode);   //Add before first and update first
	   SetLocations(currentPos);
      currentPos = newNode;

   	if(currentPos != last)
   		PrintLine(currentPos);
   	else
   		cout << *currentPos;

      gotoxy(2,1);
      return;
   }

   AddAfter(currentPos , newNode);
   SetLocations(currentPos);
   currentPos = newNode;
   if(currentPos != last)
   	PrintLine(currentPos);
   else
   	cout << *currentPos;

   if(currentPos -> next)
   	gotoxy(currentPos -> next -> col,currentPos -> next -> row);
   if(c == 79)
   {
   	cCharNode *newLineNode = new cCharNode('\n' , r , c , false);
      AddAfter(currentPos,newLineNode);
      SetLocations(currentPos);
      currentPos = newLineNode;
      PrintPart(currentPos,currentPos -> next);
   }

}
//..............................................................................
void cString :: EndKey()
{
	cCharNode *temp = currentPos;

   if(!currentPos || !(currentPos -> next))	//any character or currentPos == first
   	return;

   if(temp -> character == '\n' && temp -> next)	//first of line
   	temp = temp -> next;

   while(temp -> next)	//search for next new line character.
   {
   	if(temp -> character == '\n')
      	break;
   	temp = temp -> next;
   }
   if(temp != last)
   	currentPos = temp -> pre;
   else
   	currentPos = temp;
   cout << *currentPos;
}
//..............................................................................
void cString :: HomeKey()
{
	cCharNode *temp = currentPos;

   if(!currentPos || !(currentPos -> pre))	//any character or currentPos == first
   	return;

   while(temp -> pre)	//search for previous new line character
   {
   	if(temp -> character == '\n')
      	break;
   	temp = temp -> pre;
   }

   if(temp == first)
   {
   	currentPos = first;
   	gotoxy(1 , 1);
      return;
   }

   currentPos = temp;
   gotoxy(currentPos -> next -> col, currentPos -> next -> row);
}
//..............................................................................
void cString :: PrintAll()
{
	if(!first)
   	return;

   cCharNode *temp = first ;

   while(temp != last -> next)
   {
		cout << *temp;
   	temp = temp -> next;
   }

}
//..............................................................................
void cString :: PrintPart(cCharNode *start, cCharNode *end)
{
	if(start == first && end == last)
   {
   	PrintAll();
      return;
   }

   cCharNode *temp = start;

   while(temp != end )
   {
   	cout << *temp;
   	temp = temp -> next;
   }
   if(end)
   	cout << *end;
}
//..............................................................................
void cString :: PrintLine(cCharNode *currentNode)
{
	cCharNode *toBack = currentNode;
	cCharNode *toForward = currentNode;

   if(toBack)
   	while(toBack -> pre)
   	{
   		if(toBack -> character == '\n')
      		break;
   		toBack = toBack -> pre;
   	}

   if(toForward)
   	while(toForward -> next)
   	{
   		if(toForward -> character == '\n')
      		break;
      	toForward = toForward -> next;
   	}

   PrintPart(toBack , toForward);
}
//..............................................................................
void cString :: DelPrint(cCharNode *currentNode)
{
	int count = last -> row - currentNode -> row + 1;

   for(int counter = 0;counter < count;counter ++)
   	delline();

   cCharNode *temp = currentNode;

   while(temp -> pre)
   {
   	if(temp -> character == '\n')
      	break;
   	temp = temp -> pre;
   }

   PrintPart(temp , last);
}
//..............................................................................
void cString :: SetLocations(cCharNode *currentNode)
{
   if(!first)
   	return;

	cCharNode *temp = currentNode;

   if(!temp)
   	return;

   if(temp == first)
   {
   	first -> SetLocAndSel(1,1,false);
      temp = temp -> next;
   }

   while(temp != last -> next)
   {
   	int r = temp -> pre -> row;
   	int c = temp -> pre -> col;
      char preCh = temp -> pre -> character;

      if(c > 80 || preCh == '\n')
      	temp -> SetLocAndSel(r + 1, 1, 0);
      else
      {
         temp -> SetLocAndSel(r , c + 1,0);
      }

   	temp = temp -> next;
   }
}
//..............................................................................
void cString :: AddLast(cCharNode  *newNode)
{
   if(first)
   {
		last -> next = newNode;
   	newNode -> next = NULL;
   	newNode -> pre = last ;
   	last = newNode;
   }

   else
   {
		first = last = currentPos = newNode;
   	newNode -> pre =  NULL ;
   	newNode -> next = NULL ;
   }
}
//..............................................................................
void cString :: ShowHelp()
{
      clrscr();
      textcolor(5);
      textbackground(10);
      window(15,5,64,5);
      cprintf("\n\r                   Help Window                 " );
      textcolor(3);
      textbackground(5);
      window(15,6,64,6);
      cprintf("\n\r        Key            %c          Action         ",179);
      textcolor(4);
      textbackground(7);
      window(15,6,65,20);
		cprintf("\n\rF1                     %cHelp                      ",179);
      cprintf("\n\rF2                     %cChange Color              ",179);
      cprintf("\n\rCtrl + ArrowKey        %cSelect                    ",179);
      cprintf("\n\rCtrl + c               %cCopy Selected             ",179);
      cprintf("\n\rCtrl + x               %cCut Selected              ",179);
      cprintf("\n\rCtrl + v               %cPaste                     ",179);
      cprintf("\n\rEnd Key                %cMove cursor to end of line",179);
      cprintf("\n\rHome Key               %cM~ to first of line       ",179);
      cprintf("\n\rCtrl + Del             %cDelete                    ",179);
      cprintf("\n\rCtrl + F               %cFind Word                 ",179);

      getch();   
   	window(1,1,80,25);
      clrscr();
      Brush();
      PrintAll();
}
//..............................................................................
void cString :: AddFirst(cCharNode *newNode)
{
	if(first)
   {
   	first -> pre = newNode;
   	newNode -> pre = NULL ;
      newNode -> next = first;
      first = newNode;
   }

   else
   {
   	first = last = currentPos = newNode;
   	first -> pre =  NULL ;
   	first -> next = NULL ;
   }
}
//..............................................................................
void cString :: AddAfter(cCharNode *preNode,cCharNode *newNode)
{
   if(preNode == NULL)
   {
   	AddFirst(newNode);
      return;
   }

	if(preNode == last)
   	AddLast(newNode);

   else
   {
		newNode -> next = preNode -> next;
		newNode -> pre = preNode ;
		( preNode -> next ) -> pre = newNode;
   	preNode -> next = newNode;
	}
}
//..............................................................................
void cString :: AddTab(int r,int c)
{
	cCharNode *newNode;
	for(int counter = c ; counter < (c + 8) ; counter ++)
   {
   	newNode = new cCharNode(' ' , r , counter , false);
      AddAfter(currentPos,newNode);
      currentPos = newNode;
      PrintPart(currentPos,currentPos -> next);
   }
}
//..............................................................................
void cString :: Delete(cCharNode *delNode)
{

	if(first == delNode)
   {
      first = first -> next;
      if(first)
      	first -> pre = NULL;
      delete delNode;
      return;
   }

   if(last == delNode)
   {
		last = last -> pre;
      last -> next = NULL;
      delete delNode;
      return;
   }

   else
   {
   	( delNode -> next ) -> pre = delNode -> pre ;
   	( delNode -> pre ) -> next = delNode -> next;
      delete delNode;
   }
}
//..............................................................................
void cString :: ExtendedCodeFunc(int r,int c)
{
	int counter = 0;
	int ch = getch();

	switch(ch)
   {
      case F2:
         clrscr();
         backGround --;
			foreGround ++;
         Brush();
         PrintAll();
         break;
      case F1:
         ShowHelp();
         break;
   	case CTRLDEL:
      	DelKey();
         break;

   	case END:
      	EndKey();
      	break;

   	case HOME:
      	HomeKey();
      	break;

   	case UPARROW:
      	GoUp(r , c);
      	break;

      case DOWNARROW:
      	GoDown(r , c);
      	break;

   	case LEFTARROW:
      	GoLeft(r , c);
      	break;

      case RIGHTARROW:
         GoRight(r , c);
        	break;

      case 116:	//ctrl + rightarrow
      	if(currentPos)			//if not currentPos : no string
         {
      		if(currentPos -> next)
            {
         		currentPos -> next -> select = !(currentPos -> next -> select);
         		cout << *currentPos;
         		currentPos = currentPos -> next;
            }
            else		//currentPos = last
            {
            	if(currentPos -> select == false)
               	currentPos -> select = true;
         		cout << *currentPos;
            }
         }
      	break;

      case 115:   //ctrl + leftarrow
      	if(currentPos)
         	currentPos -> select = !(currentPos -> select);
         cout << *currentPos;
         currentPos = currentPos -> pre;
         break;

      case 145:	//ctrl + downarrow
      	cCharNode *temp = currentPos;
         GoDown(r , c);
         Select(temp , currentPos -> pre);
         PrintPart(temp , last);
         cout << *currentPos;
         //gotoxy(currentPos -> col,currentPos -> row);
         break;

   }
	if(ch == 141) //ctrl + uparrow
   {
   	cCharNode *temp = currentPos;
      GoUp(r,c);
      Select(currentPos ,temp -> pre);
      PrintPart(currentPos,last);
      cout << *currentPos;
   }
}
//..............................................................................
void cString :: GoRight(int r,int c)
{
	if(!currentPos)
   	return;
	if(currentPos -> next)
   {
   	if(currentPos -> next -> character != '\n')
      {
      	if(c < 80)
         {
         	gotoxy(c + 1,r);
         }
      }
      else
      	return;
   }

   if(currentPos && currentPos -> next)
   	currentPos = currentPos -> next;
}
//..............................................................................
void cString :: GoLeft(int r,int c)
{            
	if(!currentPos)
   	return;
	if(currentPos -> pre)
   {
   	if(currentPos -> character != '\n')
      {
         	gotoxy(c - 1,r);
      }
      else
      	return;
   }
   else
   {
   	currentPos = first;
      gotoxy(1,1);
   }

   if(currentPos && currentPos -> pre)
   	currentPos = currentPos -> pre;
}
//..............................................................................
void cString :: GoUp(int r,int c)
{
   if( r == 1) //first row
   	return;

   cCharNode *temp;

   if(c != 1) 	//usual point
		temp = Search(r - 1 , c - 1);

   else   		//first column
   {
   	temp = Search(r - 1, c);
      if(temp == first)
      {
      	currentPos = first;
         gotoxy(1,1);
      }
    	if(temp)
      {
      	if(temp -> pre)
      		currentPos = temp -> pre;
         gotoxy(temp -> col,temp -> row);
         return;
      }
   }

   if(temp)		//if above of this char was char
   {
   	currentPos = temp;
      cout << *currentPos;
   }

   else			//if above of this char was not char this statements move curser to end of pre line
   {
   	temp = currentPos;

      if(temp -> pre)
      while(temp != first)               //search for find previous new line character '\n'
      {
      	if(temp -> character == '\n')
         	break;
      	temp = temp -> pre;
      }
      temp = temp -> pre;
      cout << *temp;
      currentPos = temp;
   }

}
//..............................................................................
void cString :: GoDown(int r,int c)
{
	bool lastSwitch = false;	//next place is last or no
	cCharNode *temp ;

   if(c == 1)		//if the curser was first of line
   {
   	temp = Search(r + 1, c);

      if(!temp)	//this mean that currentPos is last line
      	return;

      currentPos = temp -> pre;
      gotoxy(temp -> col,temp -> row);
      return;
   }

   temp = Search(r + 1 , c - 1);

   if(temp)		//usual point and char
   {
   	currentPos = temp;
      cout << *currentPos;		//this statement realy move the curser to down point
   }

   else		//if down of this char wasent other char
   {
   	temp = currentPos;

      while(temp -> character != '\n')	//search for first new line character
      {
      	if(!temp -> next)
         	return;
      	temp = temp -> next;
      }

      if(temp -> next)
      {
      	temp = temp -> next;

         while(temp -> character != '\n')	//search for second new line character
         {
      		if(temp == last)
            {
            	lastSwitch = true;	//down of this char was last pointer
            	break;
            }
            if(temp -> next)
            	temp = temp -> next;
         }
      }

      currentPos = temp -> pre;		//search ended and we locate curser and currentPos

      if(!lastSwitch)
      	gotoxy(temp -> col,temp -> row);
      else
      	cout << *temp;
   }
}
//..............................................................................
//******************************************************************************
int main()
{
	cString s;
//   Brush();
   gotoxy(1,1);
   s.Manager();
   getch();
	return 0;
}
//******************************************************************************