#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>

int delet(int a[], int size, int del)
{
  int i;
  for(i=0; a[i]!=del; i++);
  int loc=i;
  while(i<=size-2)
  {
   a[i]=a[i+1];
   i++;
  }
  return loc;
}

void main()
{
int a[10]={1,2,3,4,5,8,9};
int size=7;
int del;
cin >> del;
int loc=delet(a,size,del);
cout << "Element deleted at " << loc << endl;
for(int i=0; i<=size-2; i++)
cout << a[i];
getch();
}
