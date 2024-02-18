#include <stdio.h>
#include <conio.h>
void Merge(int *,int ,int ,int ,int *);
void MergeSort(int *,int,int,int *);
//******************************************************************************
void main()
{
	int size , *array,*ansarray;
	printf("\nEnter size : ");
   scanf("%d",&size);

   array = new int[size];
   ansarray = new int[size];

	for(int counter = 0;counter < size;counter ++)
   {
   	printf("\nEnter array [%d] :",counter);
   	scanf("%d",&array[counter]);
   }

   MergeSort(array,0,size,ansarray);

   for(int counter = 0;counter < size;counter ++)
   	printf("\nArray [%d] = %d",counter ,ansarray[counter]);

   getch();

}
//******************************************************************************
void Merge(int *array,int start,int mid,int end,int *ansArr)
{
   int firstHalfCounter = start ;
   int secondHalfCounter = mid ;
   int allCounter = start ;

   while(firstHalfCounter < mid && secondHalfCounter < end)
   {
   	if(array[firstHalfCounter] < array[secondHalfCounter])
      {
      	ansArr[allCounter] = array[firstHalfCounter];
         firstHalfCounter ++;
      }
      else
      {
      	ansArr[allCounter] = array[secondHalfCounter];
         secondHalfCounter ++;
      }

      allCounter ++;
   }

   while(firstHalfCounter < mid)
   {
   	ansArr[allCounter] = array[firstHalfCounter];
      firstHalfCounter ++;
      allCounter ++;
   }
   while(secondHalfCounter < end)
   {
   	ansArr[allCounter] = array[secondHalfCounter];
      secondHalfCounter ++;
      allCounter ++;
   }
}
//******************************************************************************
void MergeSort(int *array,int start,int end,int *ansarray)
{
	if(start == end - 1)
   	return;
   
   int mid = (start + end) / 2 ;
   MergeSort(array,start,mid,ansarray);
   MergeSort(array,mid,end,ansarray);
   Merge(array,start,mid,end,ansarray);

   for(int counter = start;counter < end;counter ++)
   	array[counter] = ansarray[counter];
}
//******************************************************************************
