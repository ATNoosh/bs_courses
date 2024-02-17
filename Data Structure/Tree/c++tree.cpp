#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

class cNode
{
	friend class cTree;
	public :
   	cNode(){leftChild = rightChild = NULL;}

	private:
		char ch;
		cNode *leftChild ;
   	cNode *rightChild;
};
//******************************************************************************
class cTree
{
	public :
      cTree();
      void AddNode(char);
      void Insert(char);
      void PreOrder(cNode* );
      void InOrder( cNode *);
      void PostOrder(cNode*);
      cNode *GetRoot(){return root;}

   private:
   	cNode *root;
      cNode *newNode;
      cNode *currNode;
};
//..............................................................................
cTree :: cTree()
{
	root = newNode = currNode = NULL;
}
//..............................................................................
void cTree :: Insert(char newChar)
{
   if(!root)
   {
   	newNode = new cNode;
   	newNode -> ch = newChar;
   	newNode -> leftChild  = 0;
   	newNode -> rightChild = 0;
   	root = newNode;
   	return;
   }
   currNode = root;
   AddNode(newChar);
}
//..............................................................................
void cTree :: AddNode(char newChar)
{
	if(!currNode)
   {  
   	newNode = new cNode;
   	newNode -> ch = newChar;
   	newNode -> leftChild  = 0;
   	newNode -> rightChild = 0;
   	currNode = newNode;
      return;
   }

   if(newNode -> ch < currNode -> ch)
   {
   	currNode = currNode -> leftChild;
   	AddNode(newChar);
   }
   else
   {
   	currNode = currNode -> rightChild;
   	AddNode(newChar);
   }
}
//..............................................................................
void cTree :: PreOrder(cNode *rootNode)
{
	if(rootNode)
   {
   	cout << rootNode -> ch;
      PreOrder(rootNode -> leftChild);
      PreOrder(rootNode -> rightChild);
   }
}
//..............................................................................
void cTree :: InOrder(cNode *rootNode)
{
	if(rootNode)
   {
   	InOrder(rootNode -> leftChild);
      cout << rootNode -> ch;
      InOrder(rootNode -> rightChild);
   }
}
//..............................................................................
void cTree :: PostOrder(cNode *rootNode)
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
