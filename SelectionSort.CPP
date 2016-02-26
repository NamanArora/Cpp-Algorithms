#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>

void selectionsort(int a[],int size)
{
  int min,loc;
    for(int i=1; i<size; i++)
    {
        min=a[i-1];
        loc=i-1;
        for(int j=i; j<size; j++)
            if(a[j]<min)
                loc=j;
        if(loc!=i-1)
        {
            int temp=a[loc];
            a[loc]=a[i-1];
            a[i-1]=temp;
        }
    }
}

void main()
{
int a[10]={1,2,3,4,5,8,9};
int size=7;
selectionsort(a,size);
for(int i=0; i<size; i++)
cout << a[i];
getch();
}
