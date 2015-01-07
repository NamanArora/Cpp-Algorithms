#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>

void selectionsort(int a[],int size)
{
  int temp,small,loc;
  for(int i=0; i<size; i++)
  {
  small=a[i];
   //search for smallest no in unsorted array
   for(int j=i; j<size; j++)
    if(a[j]<=small) //incase no number is smaller than 'small' then keep the loc=original
    {
      loc=j;
      small=a[j];
    }

   temp=a[i];
   a[i]=a[loc];
   a[loc]=temp;
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
