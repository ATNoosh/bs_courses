#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct sNode
{
	char ch;

   sNode *leftChild ;
   sNode *rightChild;
};
//******************************************************************************
class cTree
{
	public :
      cTree();
      void AddNode();
      void Insert(char);
      void PreOrder(sNode* );
      void InOrder( sNode *);
      void PostOrder(sNode*);
      sNode *GetRoot(){return root;}

   private:
   	sNode *root;
      sNode *newNode;
      sNode *currNode;
};
//..............................................................................
cTree :: cTree()
{
	root = newNode = currNode = NULL;
}
//..............................................................................
void cTree :: Insert(char newChar)
{
   newNode = new sNode;
   newNode -> ch = newChar;
   newNode -> leftChild  = 0;
   newNode -> rightChild = 0;
   if(!root)
   {root = newNode;
   return;}
   currNode = root;
   AddNode();
}
//..............................................................................
void cTree :: AddNode()
{
	if(!currNode)
   {
   	currNode = newNode;
      return;
   }

   if(newNode -> ch < currNode -> ch)
   {
   	currNode = currNode -> leftChild;
   	AddNode();
   }
   else
   {
   	currNode = currNode -> rightChild;
   	AddNode();
   }
}
//..............................................................................
void cTree :: PreOrder(sNode *rootNode)
{
	if(rootNode)
   {
   	cout << rootNode -> ch;
      PreOrder(rootNode -> leftChild);
      PreOrder(rootNode -> rightChild);
   }
}
//..............................................................................
void cTree :: InOrder(sNode *rootNode)
{
	if(rootNode)
   {
   	InOrder(rootNode -> leftChild);
      cout << rootNode -> ch;
      InOrder(rootNode -> rightChild);
   }
}
//..............................................................................
void cTree :: PostOrder(sNode *rootNode)
{
	if(rootNode)
   {
   	PostOrder(rootNode -> leftChild);
      PostOrder(rootNode -> rightChild);
   	cout << rootNode -> ch;
   }
}
//..............................................................................
//******************************************************************************
void main()
{
	cTree t1;
   char ch;

   for(int counter = 0;counter < 4;counter ++)
   {
      cout << counter << ")";
   	cin >> ch;
   	t1.Insert(ch);
   }

   	t1.PreOrder(t1.GetRoot());
   getch();
}
