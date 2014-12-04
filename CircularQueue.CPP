#include<fstream.h>



class queue
{
 int a[4];
 int front,rear,count;
 public:
 queue(){front=rear=count=0;}
 void add(int item)
 {
  if(rear==front && count)
  cout << "Queue is full";
  else
  {
   a[rear]=item;
   rear=(rear+1)%4;
   count++;
  }
 }
 void del()
 {
  if(front==rear && !count)
  cout << "Queue is empty";
  else
  {
   front=(front+1)%4;
   count--;
  }
 }
};

void main()
{

}
