#include <stdio.h>
#include <conio.h>

void Permutations(int);
void Print(int *,int );
void Swap(int &,int &);
int Fact(int );

int main()
{
    int n;
    printf("Enter n : ");        
    scanf("%d",&n);
    Permutations(n);
    getch();
    return 0;
}
//******************************************************************************
void Permutations(int n)
{
    int *s;
    s = new int[n];    
    
    for(int counter = 0;counter < n;counter ++)
        s[counter ] = counter ;
    
    Print(s,n);
    
    for(int counter = 1;counter < Fact(n);counter ++)
    {
        int m = n - 2;
        
        while (s[m] > s[m + 1])
                m--;
        
        int k = n-1;
        while (s[m] > s[k])
                k--;
        
        Swap(s[m],s[k]);
        
        int p = m + 1;
        int q = n-1;
        
        while(p < q)
        {
            Swap(s[p],s[q]);    
            p++;
            q--;
        }
        Print(s,n);
    }    
    
}
//******************************************************************************
void Print(int *arr,int size)
{
    for(int counter = 0;counter < size ;counter ++)    
        printf("%d",arr[counter]+1);
    
    printf("\n");
}
//******************************************************************************
int Fact(int n)
{
    if(n <= 0)
        return 1;
    else
        return n*Fact(n - 1);
}
//******************************************************************************
void Swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;    
}
//******************************************************************************
