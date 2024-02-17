//Ali Tahmasebi
//this program read input.txt in current path.
//this program read graph by this method :
//first line of file : number of vertex
//in other line edges
//each edge : ver1,ver2,cost 
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>

//**************************************************************************************************
class cFile
{
	public :
   	cFile();
      void OpenFile();
      void CloseFile();
      void SetMatrix();
      void GetMemory();
      void InsertEdge(char *);
      void ReadFile();
      void ShowMatrix();
      int **GetMatrix(){return matrix;}

   private:
   	FILE *filePointer;
      int verNumber;
      int **matrix;
};
//..............................................................................
cFile :: cFile()
{
   OpenFile();
}
//..............................................................................
void cFile :: SetMatrix()
{
	for(int i = 0;i < verNumber;i ++)
		for(int j = 0;j < verNumber;j ++)
      	matrix[i][j] = -1;
}
//..............................................................................
void cFile :: ShowMatrix()
{
	for(int i = 0;i < verNumber;i ++)
   {
   	cout << endl;

   	for(int j = 0;j < verNumber;j ++)
      {
      	cout << matrix[i][j]<< '\t';
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
	matrix = new int *[verNumber];

   for(int counter = 0;counter < verNumber;counter ++)
   {
    	matrix[counter] = new int[verNumber];
   }
}
//..............................................................................
void cFile :: ReadFile()
{
   char buffer[1000];
	fgets(buffer,1000,filePointer);    //true
   verNumber = atoi(buffer);

   GetMemory();
   SetMatrix();

   while(1)
   {
		fgets(buffer,1000,filePointer);    //true
      if(buffer[0] == '#')
      	break;
      InsertEdge(buffer);
   }
}
//..............................................................................
void cFile :: InsertEdge(char *initedEdge)
{
	char strNumber[10];
   int strCounter = 0 , subStrCounter = 0;
   int ver1 , ver2;

   while(initedEdge[strCounter] != ',')
   	strNumber[subStrCounter ++] = initedEdge[strCounter ++];

   strNumber[subStrCounter] = NULL;
   ver1 = atoi(strNumber);

   strCounter ++;
   subStrCounter = 0;
	while(initedEdge[strCounter] != ':')
   	strNumber[subStrCounter ++] = initedEdge[strCounter ++];

   strNumber[subStrCounter] = NULL;
   ver2 = atoi(strNumber);

   strCounter ++;
   subStrCounter = 0;
	while(initedEdge[strCounter] != '\n')
   	strNumber[subStrCounter ++] = initedEdge[strCounter ++];

   strNumber[subStrCounter] = NULL;
   matrix[ver1][ver2] = atoi(strNumber);
   matrix[ver2][ver1] = atoi(strNumber);

}
//..............................................................................
//**************************************************************************************************
void main()
{
	cFile file;
   file.ReadFile();
   file.ShowMatrix();
   getch();
}
