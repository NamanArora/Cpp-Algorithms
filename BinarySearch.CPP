#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>

int binary(int a[],int size,int search)
{
 int middle=0,first=0,last=size-1;
 while(first<=last) //remember this!
 {
  middle=(first+last)/2;
  if(search>a[middle])
  first=middle+1;
  else if(search<a[middle])
  last=middle-1;
  else
  return middle;
 }                                                     
 return 0;
}

void main()
{
int a[]={1,2,3,4,5,6,7};
int size=sizeof(a)/sizeof(a[0]);
int n;
cin>>n;
int chk=binary(a,size,n);
if(chk)
cout << "Match found at " << chk;
else
cout << "Match not found";
}
