#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>

int add(int a[],int size,int put)
{
int i=size-1;
  while(a[i]>put)
  {
   a[i+1]=a[i];
   i--;
  }
  a[i+1]=put;
  return i+1;
}

void main()
{
int a[10]={1,2,3,4,5,8,9};
int size=7;
int put;
cin >> put;
int loc=add(a,size,put);
cout << "Element inserted at " << loc;
getch();
}
