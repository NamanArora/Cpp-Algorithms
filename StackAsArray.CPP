#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>

class stack
{
 int a[10];
 int top;
 public:
 stack()
 {
 top=-1;
 }
 void push(int data)
 {
  if(top==9)
  cout << "Stack is full";
  else
  a[++top]=data;
 }
 void pop()
 {
  if(top==-1)
  cout << "Stack empty";
  else
  {
  cout << "Data to be popped: " << a[top] << endl;
  top--;
  }
 }
};
void main()
{
stack obj;
obj.push(10);
obj.push(5);
obj.pop();
obj.pop();

getch();
}
