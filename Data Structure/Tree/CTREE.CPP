#include <stdio.h>
#include <conio.h>

struct sTreeNode
{
   sTreeNode *lChild;
	char ch;
   sTreeNode *rChild;
}*root,*curNode,*newNode;

void PostOrder(sTreeNode *);
void PreOrder(sTreeNode *);
void InOrder(sTreeNode *);
void Add();

void main()
{
   PreOrder(root);
   getch();
}
//******************************************************************************
void PostOrder(sTreeNode *node)
{
	if(node)
   {
   	PostOrder(node -> lChild);
   	PostOrder(node -> rChild);
      printf("%c" ,node -> ch );
   }
}
//******************************************************************************
void PreOrder(sTreeNode *node)
{
	if(node)
   {
      printf("%c",node -> ch);
   	PreOrder(node -> lChild);
   	PreOrder(node -> rChild);
   }
}
//******************************************************************************
void InOrder(sTreeNode *node)
{
	if(node)
   {
   	InOrder(node -> lChild);
      printf("%c",node -> ch);
   	InOrder(node -> rChild);
   }
}
//******************************************************************************
void Add()
{
	if(curNode)
   {
   	if(newNode -> ch < curNode -> ch)
      {
      	curNode = curNode -> lChild;
         Add();
      }
   	else
      {
      	curNode = curNode -> rChild;
         Add();
   	}
   }
   else
   {
   	curNode = newNode;
   }
}
//******************************************************************************
