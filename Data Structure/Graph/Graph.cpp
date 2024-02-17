#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000
//**************************************************************************************************
class cFile
{
	friend class cGraph;

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
      	gotoxy(i*4 + 3, j*4 + 3);
      	cout << matrix[i][j] ;
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
   ShowMatrix();
   cout << endl;
}
//..............................................................................
void cFile :: InsertEdge(char *initedEdge)
{
	char strNumber[10];
   int strCounter = 0 , subStrCounter = 0;
   int ver1 , ver2;

  	while(initedEdge[strCounter] != ':')
   		strNumber[subStrCounter ++] = initedEdge[strCounter ++];

  	strNumber[subStrCounter] = NULL;
  	ver1 = atoi(strNumber);

   while(1)
   {
		strCounter ++;
      if(initedEdge[strCounter] == '\n')
      	break;
		subStrCounter = 0;
		while(initedEdge[strCounter] != ',')
			strNumber[subStrCounter ++] = initedEdge[strCounter ++];

		strNumber[subStrCounter] = NULL;
 		ver2 = atoi(strNumber);

  		strCounter ++;
  		subStrCounter = 0;
		while(initedEdge[strCounter] != ';')
  			strNumber[subStrCounter ++] = initedEdge[strCounter ++];

  		strNumber[subStrCounter] = NULL;
  		matrix[ver1][ver2] = atoi(strNumber);
  		matrix[ver2][ver1] = atoi(strNumber);
   }

}
//..............................................................................
//**************************************************************************************************


//..............................................................................
class cEdge
{
	friend class cStack;
   friend class cGraph;

	public :
   	cEdge(int = 0,int = 0);
   	bool operator == (cEdge);
      bool operator != (cEdge);

	private:
		int ver1;
   	int ver2;
};
//..............................................................................
cEdge :: cEdge(int v1,int v2)
{
	ver1 = v1;
   ver2 = v2;
}
//..............................................................................
bool cEdge :: operator == (cEdge rightVal)
{
	return !(*this != rightVal);
}
//..............................................................................
bool cEdge :: operator != (cEdge rightVal)
{
	if(this -> ver1 != rightVal.ver1 && this -> ver1 != rightVal.ver2 )
   	return true;

	if(this -> ver2 != rightVal.ver1 && this -> ver2 != rightVal.ver2 )
   	return true;

   if(this -> ver1 == rightVal.ver1 && this -> ver2 == rightVal.ver2)
   	return false;

   if(this -> ver1 == rightVal.ver2 && this -> ver2 == rightVal.ver1)
   	return false;
}
//..............................................................................
//******************************************************************************
class cStack
{
	public :
   	cStack();
      bool Push(int,int);
      cEdge Pop();
      bool IsEmpty();
      bool IsFull();
      void EmptyStack();
      void ShowStack();

   private:
   	int top;
      cEdge array[MAX_SIZE];
};
//..............................................................................
cStack :: cStack()
{
	cEdge zero(0,0);
	top = 0;

   for(int counter = 0;counter < MAX_SIZE;counter ++)
   {
   	array[counter] = zero;
   }
}
//..............................................................................
bool cStack :: Push(int v1,int v2)
{
	cEdge newEdge(v1,v2);

  	if(top != MAX_SIZE)
   {
   	array[top] = newEdge;
      top ++;
      return true;
   }

   cout << "\nThe stack is full.";
   getch();
   return false;

}
//..............................................................................
cEdge cStack :: Pop()
{
	cEdge falseEdge(-1,-1);
  	if(top != 0)
   {
   	top --;
      return array[top];
   }

   cout << "The stack is empty.";
   getch();

   return falseEdge;
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
   	cout << "(" << array[counter].ver1
      	  << "," << array[counter].ver2
           << ")\t" ;
      cout << endl;
   }
}
//..............................................................................
class cGraph
{
	public :
      cGraph();
      void GetMemory();
      void DfnLow(int);
      void DfnLow(int,int);
      void ShowDfnLow();
      void BiConnected();
      void BiConnected(int,int);
      void CopyFromFile();
      void ReadMatrix();
      void DFS();
      void DFS(int);
      void ShowVisited();
      void PrimMST();

   private:
   	int Min(int,int);
   	int **graphArray;
      bool **visitedEdge;
      int *low;
      int *dfn;
      int  num;
      int vertexNum;
      bool *visited;
      cStack stack;
      cFile file;
};
//.............................................................................
cGraph :: cGraph()
{
	graphArray = NULL;
   low = dfn = NULL;
   vertexNum = 0;
}
//.............................................................................
void cGraph :: PrimMST()
{
	visited = new bool [vertexNum];

   for(int counter = 0;counter < vertexNum ;counter ++)
   	visited[counter] = false;
      
	visited[0] = true;
   int j = 0 , temp;
   int add_vertex = 0;
   int counter;

   for(counter = 0;counter < vertexNum - 1;counter ++/*,visitedEdge[u][v] = true,visitedEdge[v][u] = true*/)
   {
   	int min = MAX_SIZE;

      for(j = 0;j < vertexNum;j ++)
      {
      	if(visited[j] == true)
         {
         	for(int k = 0;k < vertexNum;k ++)
            {
            	if(visited[k] == false && graphArray[j][k] < min && graphArray[j][k] != -1)
               {
                  add_vertex = k;
                  visitedEdge[j][k] = true;
                  visitedEdge[k][j] = true;
                  temp = j;
                  min = graphArray[j][k];
               }
            }
         }
      }

      visited[add_vertex] = true;
      cout << endl << add_vertex << temp;
   }

   if(counter < vertexNum - 1)
   	cout << endl <<"No spanning tree." << endl ;

}
//.............................................................................
void cGraph :: ShowVisited()
{
	for(int counter = 0;counter < vertexNum;counter ++)
   	if(visited[counter] == true)
      		cout << counter << ",";
}
//.............................................................................
void cGraph :: DFS()
{
	visited = new bool[vertexNum];

   for(int counter = 0;counter < vertexNum;counter ++)
   	visited[counter] = false;

   DFS(3);
}
//.............................................................................
void cGraph :: DFS(int initedVer)
{
	visited[initedVer] = true;
   cout << initedVer;

   for(int verCounter = 0;verCounter < vertexNum;verCounter ++)
   {
   	if(graphArray[initedVer][verCounter] >= 0)
      {
      	if(!visited[verCounter])
         {
         	cout << endl << initedVer;
         	DFS(verCounter);
         }
      }
   }
}
//.............................................................................
void cGraph :: ReadMatrix()
{
	file.ReadFile();
   CopyFromFile();
}
//.............................................................................
void cGraph :: CopyFromFile()
{
	vertexNum = file.verNumber;

   GetMemory();

	for(int i = 0;i < vertexNum;i ++)
   {
   	for(int j = 0;j < vertexNum; j ++)
      {
      	graphArray[i][j] = file.matrix[i][j];
         visitedEdge[i][j] = false;
      }
   }
}
//.............................................................................
void cGraph :: ShowDfnLow()
{
	for(int counter = 0;counter < vertexNum;counter ++)
   {
   	cout << endl << counter << " : " << dfn[counter] << "\t" << low[counter];
   }
}
//.............................................................................
void cGraph :: GetMemory()
{
	graphArray = new int *[vertexNum];
   visitedEdge = new bool *[vertexNum];

   for(int counter = 0;counter < vertexNum;counter ++)
   {
    	graphArray[counter] = new int[vertexNum];
      visitedEdge[counter] = new bool[vertexNum];
   }

}
//.............................................................................
void cGraph :: DfnLow(int root)
{
	num = 1;
   dfn = new int[vertexNum];
   low = new int[vertexNum];

   for(int counter = 0;counter < vertexNum;counter ++)
   	dfn[counter] = low[counter] = 0;

   DfnLow(root , -1);
}
//.............................................................................
void cGraph :: DfnLow(int curVer,int curPar)
{
	dfn[curVer] = low[curVer] = num ++;

   for(int verCounter = 0;verCounter < vertexNum;verCounter ++)
   {
   	if(graphArray[curVer][verCounter] >= 0)
      {
      	if(dfn[verCounter] == 0)
         {
         	DfnLow(verCounter , curVer);
            low[curVer] = Min(low[curVer] , low[verCounter]);
         }
         else
         	if(verCounter != curPar)
            	low[curVer] = Min(low[curVer] , dfn[verCounter]);
      }
   }
}
//.............................................................................
int cGraph :: Min(int x,int y)
{
	if(x > y)
   	return y;
   return x;
}
//.............................................................................
void cGraph :: BiConnected()
{
	num = 1;
   dfn = new int [vertexNum];
   low = new int [vertexNum];
   visited = new bool [vertexNum];

   for(int counter = 0;counter < vertexNum;counter ++)
   	dfn [counter] = low[counter] = visited[counter] = 0;

   BiConnected(0,-1);
}
//.............................................................................
void cGraph :: BiConnected(int curVer,int parVer)
{
	dfn[curVer] = low[curVer] = num ++;

   for(int verCounter = 0;verCounter < vertexNum;verCounter ++)
   {
   	if(graphArray[curVer][verCounter] >= 0)
      {
      	if((parVer != verCounter) && (dfn[verCounter] < dfn[curVer]))
         	stack.Push(curVer , verCounter);

         if(dfn[verCounter] == 0)
         {
         	BiConnected(verCounter , curVer);
            low[curVer] = Min(low[curVer] , low[verCounter]);

            if(low[verCounter] >= dfn[curVer])
            {
            	cout << "New BiConnected Component : " << curVer << endl;

               visited[curVer] = true;

               cEdge curEdge(curVer , verCounter);
               cEdge popedEdge;
               do
               {
                  popedEdge = stack.Pop();
                  cout << popedEdge.ver1 << "," << popedEdge.ver2 << endl;

               }while(popedEdge != curEdge);
            }
         }
         else
         	if(verCounter != parVer)
            	low[curVer] = Min(low[curVer] , dfn[verCounter]);
      }
   }
}
//.............................................................................
//.............................................................................
void main()
{
	cGraph graph;
   //graph.GetArray();
   //graph.CopyFromFile();
   graph.ReadMatrix();
   graph.DfnLow(0);   
   cout << endl;       
   cout << endl;
   graph.ShowDfnLow();
   cout << endl;
   cout << endl;
   graph.BiConnected();

   cout << "\n\nAxial Nodes : ";
   graph.ShowVisited();

   cout << endl << endl << "DFS : " ;
   graph.DFS();

   cout << endl << endl << "MST : " ;
   graph.PrimMST();
   getch();
}
