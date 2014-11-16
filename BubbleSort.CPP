#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>

void bubblesort(int a[],int size)
{
int flag=1;
while(flag)
 {
flag=0;
 for(int i=0; i<size-1; i++)
 {
  if(a[i+1]<a[i])
  {
   int temp=a[i];
   a[i]=a[i+1];
   a[i+1]=temp;
   flag=1;
  }
 }
 }
}

void main()
{
int a[10]={11,22,553,20,65,81,19};
int size=7;
bubblesort(a,size);
for(int i=0; i<size; i++)
cout << a[i] << " ";
getch();
}
