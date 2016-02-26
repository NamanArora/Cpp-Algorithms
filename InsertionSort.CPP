#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>

void insertionsort(int a[],int size)
{
  for(int i=1; i<size; i++)
  {
   int j=i-1; //top of sorted array
   int p=a[i]; //new element to be inserted
   while(a[j]>p && j>=0)
   {
    a[j+1]=a[j];
    j--;
   }
   a[j+1]=p;
  }
}

void main()
{
int a[10]={12,22,3,4,53,18,69};
int size=7;
insertionsort(a,size);
for(int i=0; i<size; i++)
cout << a[i] << " ";
getch();
}
