#include <stdio.h>
#include <conio.h>

//******************************************************************************
struct sNode
{
	int data;
   sNode *next;
}*first,*last,*temp;

//******************************************************************************
void Initialize();
void Add(sNode *);
void Delete(sNode *);
void ShowLinks();
//******************************************************************************
void main()
{
	Initialize();
   sNode *node;

   node = new sNode;

   node = new sNode;
   node -> data = 7;
   Add(node);
   ShowLinks();

   node = new sNode;
   node -> data = 11;
   Add(node);
   ShowLinks();

   node = new sNode;
   node -> data = 12;
   Add(node);
   ShowLinks();

   node = new sNode;
   node -> data = 13;
   Add(node);

   node = new sNode;
   node -> data = 8;
   Add(node);
   ShowLinks();

   node = new sNode;
   node -> data = 10;
   Add(node);
   ShowLinks();

   ShowLinks();
   getch();
}
//******************************************************************************
void Initialize()
{
	first = last = temp = 0;
}
//******************************************************************************
void ShowLinks()
{
	if(first == 0)
   {
   	printf("\nEmpty");
      return;
   }
   printf("\n\n");
	temp = first;
   printf("\n first : %d",first -> data);
   printf("\n last : %d",last -> data);

   do
   {
   	printf("\n %d",temp -> data);
   	temp = temp -> next;
   }while(temp != NULL);

}
//******************************************************************************
void Add(sNode *newNode)
{
	if(first == 0)
   {
   	first = last = newNode;
      newNode -> next = NULL;
      last -> next = NULL;
      return;
   }

   if((newNode -> data) < (first -> data))
   {
   	newNode -> next = first ;
      first = newNode;
      last -> next = NULL;
      return;
   }

   if((newNode -> data) > (last -> data))
   {
   	last -> next = newNode;
      last = newNode;
      last -> next = NULL;
      return;
   }

   temp = new sNode;
   temp = first;

   while(1)
   {
   	if(temp -> next == NULL)
	   	break;

      if((temp -> next -> data ) >= (newNode -> data))
      	break;
      temp = temp -> next ;
   }

   newNode -> next = temp -> next ;
   temp -> next = newNode;
   last -> next = NULL;

}
//******************************************************************************
void Delete(sNode *inited)
{
	if(first == inited)
   {
   	temp = first;
      first = first -> next;
      delete temp;
      return;
   }
}
//******************************************************************************