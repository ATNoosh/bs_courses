#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

enum eDirection {N,NE,E,SE,S,SW,W,NW};
struct sPointDir
{
	int row;
   int col;
   int dir;
};
struct Delta
{
	int dRow;
   int dCol;
};
//******************************************************************************
class cFile
{
	public :
   	cFile();
      void OpenFile();
      void CloseFile();
      void GetMemory();
      void ReadFile(int);
      void ShowMatrix();
      int GetRow(){return rowNum;}
      int GetCol(){return colNum;}
      int GetExaNum(){return exampleNumber;}
      int **GetMatrix(){return matrix;}

   private:
   	FILE *filePointer;
      int exampleNumber;
      int rowNum;
      int colNum;
      int **matrix;
};
//..............................................................................
cFile :: cFile()
{
   char buffer[10];

   OpenFile();
   fgets(buffer,11,filePointer);		//true
   exampleNumber = atoi(buffer);
}
//..............................................................................
void cFile :: ShowMatrix()
{
	for(int i = 0;i < rowNum;i ++)
   {
   	cout << endl;

   	for(int j = 0;j < colNum;j ++)
      {
      	cout << matrix[i][j]<< ' ';
      }
   }
}
//..............................................................................
void cFile :: OpenFile()
{
	if((filePointer = fopen("Input.txt","r")) == NULL)
   {
   	cout << endl << "can not open file ." ;
      getch();
      exit(0);
   }
}
//..............................................................................
void cFile :: CloseFile()
{
	fclose(filePointer);
}
//..............................................................................
void cFile :: GetMemory()
{
	matrix = new int *[rowNum];

   for(int counter = 0;counter < rowNum;counter ++)
   {
    	matrix[counter] = new int[colNum];
   }

	matrix = new int *[rowNum];

   for(int counter = 0;counter < rowNum;counter ++)
   {
    	matrix[counter] = new int[colNum];
   }
}
//..............................................................................
void cFile :: ReadFile(int counter)
{
   char buffer[1000];
   char digit[2];

   if(counter != 0)
	   fgets(buffer,2,filePointer);

   fgets(buffer,1000,filePointer);    //true
   rowNum = atoi(buffer);

   fgets(buffer,1000,filePointer);    //true
   colNum = atoi(buffer);

   GetMemory();

   for(int iCounter = 0;iCounter < rowNum;iCounter ++)
   {

   	if(iCounter != 0)	//if iCounter != 0 \n is in file seek
      	fgets(buffer,2,filePointer);

   	fgets(buffer,colNum + 1,filePointer);

      if(strlen(buffer) != (unsigned) colNum)
      {
      	cout << "In row "<<iCounter<<" from example number "<<counter<<" is not "<<colNum<<" number.";
         getch();
         exit(0);
      }

      for(int jCounter = 0;jCounter < colNum;jCounter ++)
      {
      	digit[0] = buffer[jCounter];
         matrix[iCounter][jCounter] = atoi(digit);
      }
   }

}
//..............................................................................
//******************************************************************************
class cStack
{
	public :
   	cStack();
      bool Push(int,int,int);
      sPointDir Pop();
      bool IsEmpty();
      bool IsFull();
      void EmptyStack();
      void ShowStack();
	  void ShowIcon(int);

   private:
   	int top;
      sPointDir array[MAX_SIZE];
};
//..............................................................................
cStack :: cStack()
{
	sPointDir zero = {0,0,0};
	top = 0;

   for(int counter = 0;counter < MAX_SIZE;counter ++)
   {
   	array[counter] = zero;
   }
}
//..............................................................................
bool cStack :: Push(int x,int y,int direction)
{
	sPointDir newPoint = {x,y,direction};

  	if(top != MAX_SIZE)
   {
   	array[top] = newPoint;
      top ++;
      return true;
   }

   cout << "\nThe stack is full.";
   getch();
   return false;

}
//..............................................................................
sPointDir cStack :: Pop()
{
	sPointDir falsePoint = {-1,-1,10};
  	if(top != 0)
   {
   	top --;
      return array[top];
   }

   cout << "The stack is empty.";
   getch();

   return falsePoint;
}
//..............................................................................
bool cStack :: IsEmpty()
{
	if( top == 0)
   	return true;
   return false;
}
//..............................................................................
bool cStack :: IsFull()
{
	if( top == MAX_SIZE)
   	return true;
   return false;
}
//..............................................................................
void cStack :: EmptyStack()
{
	top = 0;
}
//..............................................................................
void cStack :: ShowStack()
{
	for(int counter = 0;counter < top;counter ++)
   {
   	cout << "(" << array[counter].row
      	  << "," << array[counter].col
           << ")\t" ;
           if((array[counter].row != 1)||(array[counter].col != 1))
               ShowIcon(array[counter].dir);
      cout << endl;
   }
}
//..............................................................................
void cStack :: ShowIcon(int direction)
{
	switch((direction-1)%8)
	{
		case N:
         printf("%c",24);
         break;
		case S:
         printf("%c",25);
         break;
		case NW:
         printf("%c",218);
         break;
		case SE:
         printf("%c",217);
         break;
		case E:
         printf("%c",26);
         break;
		case W:
         printf("%c",27);
         break;
		case NE:
         printf("%c",191);
         break;
		case SW:
         printf("%c",192);
         break;
	}
}
//..............................................................................
//******************************************************************************
class cMaze
{
	public :
   	cMaze();
      void GetMemory(int,int);
      void ShowMatrix();
      void CopyFileMatrix();
      void ReadMatrix(int);
      void Solve();
      int GetExaNumb(){return exampleNum;}
      void CloseMazeFile();

   private:
   	cStack mazeStack;
   	cFile mazeFile;
      Delta moveDelta[8];
   	int **mainMatrix;
      int rowNumber;
      int colNumber;
      int exampleNum;
      int **markMatrix;
};
//..............................................................................
cMaze :: cMaze()
{
	exampleNum = mazeFile.GetExaNum();

   moveDelta[0].dRow = -1;
   moveDelta[0].dCol = 0 ;
   moveDelta[1].dRow = -1;
   moveDelta[1].dCol = +1;
   moveDelta[2].dRow = 0 ;
   moveDelta[2].dCol = +1;
   moveDelta[3].dRow = +1;
   moveDelta[3].dCol = +1;
   moveDelta[4].dRow = +1;
   moveDelta[4].dCol = 0 ;
   moveDelta[5].dRow = +1;
   moveDelta[5].dCol = -1;
   moveDelta[6].dRow = 0 ;
   moveDelta[6].dCol = -1;
   moveDelta[7].dRow = -1;
   moveDelta[7].dCol = -1;
}
//..............................................................................
void cMaze :: ReadMatrix(int counter)
{
	mazeFile.ReadFile(counter);
   CopyFileMatrix();
}
//..............................................................................
void cMaze :: GetMemory(int rows,int cols)
{
	mainMatrix = new int *[rows + 2];

   for(int counter = 0;counter < rows + 2;counter ++)
   {
    	mainMatrix[counter] = new int[cols + 2];
   }

	markMatrix = new int *[rows + 2];

   for(int counter = 0;counter < rows + 2;counter ++)
   {
    	markMatrix[counter] = new int[cols + 2];
   }

   for(int i = 0;i <= rows;i ++)
   	for(int j = 0;j <= cols;j ++)
      	markMatrix[i][j] = 0;

	for(int counter = 0 ;counter <= cols + 1;counter ++)
   {
   	markMatrix[0][counter] = 1;
   	markMatrix[rows + 1][counter] = 1;
		mainMatrix[0][counter] = 1;
   	mainMatrix[rows + 1][counter] = 1;
   }

   for(int counter = 0 ;counter <= rows + 1;counter ++)
   {
   	markMatrix[counter][0] = 1;
   	markMatrix[counter][cols + 1] = 1;
   	mainMatrix[counter][0] = 1;
   	mainMatrix[counter][cols + 1] = 1;
   }
}
//..............................................................................
void cMaze :: ShowMatrix()
{

	cout << "\nMaze Matrix :\n";

	for(int rowCounter = 0;rowCounter <= rowNumber + 1;rowCounter ++)
   {
		for(int colCounter = 0;colCounter <= colNumber + 1;colCounter ++)
      {
      	cout << mainMatrix[rowCounter][colCounter] << ' ' ;
      }
      cout << endl;
   }
}
//..............................................................................
void cMaze :: CopyFileMatrix()
{
	rowNumber = mazeFile.GetRow();
   colNumber = mazeFile.GetCol();
   exampleNum = mazeFile.GetExaNum();

   GetMemory(rowNumber,colNumber);

	for(int i = 1;i <= rowNumber;i++)
   {
   	for(int j = 1;j <= colNumber;j++)
      {
      	mainMatrix[i][j] = mazeFile.GetMatrix()[i - 1][j - 1];
      }
   }
}
//..............................................................................
void cMaze :: CloseMazeFile()
{
	mazeFile.CloseFile();
}
//..............................................................................
void cMaze :: Solve()
{

	markMatrix[1][1] = 1;
   mazeStack.Push(1,1,N);
   sPointDir temp;

   if(mainMatrix[1][1] == 0)
   {
	while(!mazeStack.IsEmpty())
	{
		temp = mazeStack.Pop();
		int xPoped = temp.row;
		int yPoped = temp.col;
		int dirPoped = temp.dir;

		while(dirPoped < 8)
		{
			int xNextLoc = xPoped + moveDelta[dirPoped].dRow;
			int yNextLoc = yPoped + moveDelta[dirPoped].dCol;

			if((xNextLoc == rowNumber) && (yNextLoc == colNumber))
			{
				mazeStack.ShowStack();
				cout << "(" << xPoped << ',' << yPoped << ")" << endl;
				cout << "(" <<rowNumber << ',' << colNumber << ")" << endl;
				mazeStack.EmptyStack(); // empty for next example
				return;
			}

			if(!(mainMatrix[xNextLoc][yNextLoc]) && (!markMatrix[xNextLoc][yNextLoc]))
			{
				markMatrix[xNextLoc][yNextLoc] = 1;
				mazeStack.Push(xPoped , yPoped , dirPoped + 1);
				xPoped = xNextLoc;
				yPoped = yNextLoc;
				dirPoped = N;
			}

			else dirPoped ++;
		}
	}
   }
   cout << "I can not find any way to exit from this matrix !!!" ;
}
//..............................................................................
//******************************************************************************
int main()
{
	cMaze m1;
   for(int counter = 0;counter < m1.GetExaNumb();counter ++)
   {
      cout << "\t\t\t\t" <<counter + 1<<"th Example : \n\n";
   	m1.ReadMatrix(counter);
      m1.Solve();
      if(counter == m1.GetExaNumb() - 1)
      	cout << "\n\nPress any key to exit ...";
      else
         cout << "\n\nPress any key to view next example ... ";
		getch();
      system("cls");
   }

   m1.CloseMazeFile();
   return 0;
}
//******************************************************************************
