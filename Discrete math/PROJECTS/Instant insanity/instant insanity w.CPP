#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void get_color();
void analiz();
void find();
void reader();
void findlr(int);
void show();

int color[4][4];
int mokaab[4][4];
int front_back[4][4];
int left_right[4][4];

struct xy
{
  int x,y;
}xy1[4];

int main()
{
   reader();
   return 0;
}
//******************************************************************************
void reader()
{
   char ch;
   do{
     	 get_color();
       analiz();
       find();
       printf("\n Do you want to continue?(y/n)");
       ch=getche();
       //clrscr();
      }while(ch!='n');
}
//******************************************************************************
void get_color()
{
	char ch;
   clrscr();
   printf("\n\t\t\t***  THE POROGRAM IS JONONE ANI.  ****\n");
	for(int i=0;i<4;i++)
    {
      if(i!=0)
        printf("\n\n");
      for(int j=0;j<4;j++)
       {
         printf("\nInsert the color of side %d  of mokaab %d:",j+1,i+1);
         ch=getche();
         switch (ch)
         {
           case 'r': color[i][j]=0;
             break;
           case 'b': color[i][j]=1;
             break;
           case 'w': color[i][j]=2;
             break;
           case 'g': color[i][j]=3;
             break;
         }//switch
       }// for
     }//for

}
//******************************************************************************
void analiz()
{
     int x=0,y=0;
     for(int i=0;i<4;i++)
      {
        x=color[i][0];
        y=color[i][1];
        if(front_back[x][y]>0)
           front_back[y][x]=i+1;
         else
           front_back[x][y]=i+1;
      }
     for(int i=0;i<4;i++)
      {
        x=color[i][2];
        y=color[i][3];
        if(left_right[x][y]>0)
           left_right[y][x]=i+1;
         else
        left_right[x][y]=i+1;
      }


   /*  printf("\n\nmatrix front_back");

      for(int i=0;i<4;i++)
      {
        printf("\n");
        for(int j=0;j<4;j++)
          printf("%d ",front_back[i][j]);
       }
      printf("\n\n matrix let_right");
      for(int i=0;i<4;i++)
      {
        printf("\n");
        for(int j=0;j<4;j++)
          printf("%d ",left_right[i][j]);
       }  */

}
//******************************************************************************
void find()
{
	int count_color1[4]={0},pos=1,count_color2[4]={0};
   for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
        if(front_back[i][j]>0)
          if(i!=j)
           count_color1[i]++;
      for(int t=0;t<4;t++)
         if(front_back[t][i]>0)
          if(t!=i)
           count_color1[i]++;
     }

     for(int i=0;i<4;i++)
       if(count_color1[i]>2)
        {
          pos=0;
          printf("\n\n\nBA IN RANGA NEMITAVAN  MASALE RA HAL KARD!!!%c\n        press a key...",7);
          getch();
          clrscr();
          reader();
         }
   for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
        if(left_right[i][j]>0)
          if(i!=j)
           count_color2[i]++;
      for(int t=0;t<4;t++)
         if(left_right[t][i]>0)
           if(t!=i)
           count_color2[i]++;
     }
     for(int i=0;i<4;i++)
       if(count_color2[i]>2)
        {
          pos=0;
          printf("\n\n\nBA IN RANGA NEMITAVAN  MASALE RA HAL KARD!!!%c\n        press a key...",7);
          getch();
          clrscr();
          reader();
         }

      if(pos)
         {
           for(int i=0;i<4;i++)
             for(int j=0;j<4;j++)
               if(front_back[i][j]>0)
                {
                   xy1[front_back[i][j]-1].x=i;
                   xy1[front_back[i][j]-1].y=j;
                 }
            for(int i=0;i<4;i++)
             {
              if(xy1[i].x==xy1[i].y)
               {
                 mokaab[i][0]=xy1[i].x;
                 mokaab[i][1]=xy1[i].y;
                 findlr(i);
                }
             }

          /*   printf("\n\nmokaab ha:");
              for(int i=0;i<4;i++)
               {
                printf("\n");
                for(int j=0;j<4;j++)
                  printf("%d ",mokaab[i][j]);

               }           */
             show();
          }
}
//******************************************************************************
void findlr(int m)
{
	for(int i=0;i<4;i++)
     for(int j=0;j<4;j++)
       if(left_right[i][j]==m+1)
        {
          mokaab[m][2]=j;
          mokaab[m][3]=i;
        }
}
//******************************************************************************
void show()
{
    int col;
    printf("\n\n   THE RESULT:\n\n");
    printf("\n\n		   	FRONT	BACK	LEFT	RIGHT");
    printf("\n________________________________________________________________\n");
    for(int i=0;i<4;i++)
     {
        printf("\n	mokaab %d    |",i+1);
        for(int j=0;j<4;j++)
         {
           col=mokaab[i][j];
           switch(col)
            {
              case 0: printf("	RED");
                break;
              case 1: printf("	BLUE");
                break;
              case 2: printf("	WHITE");
                break;
              case 3: printf("	GREEN");
                break;
            }
          }
        }
     printf("\n________________________________________________________________\n");
}
