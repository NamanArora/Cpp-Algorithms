#include<fstream.h>

class queue
{
  int a[10];
  int rear,front;
  public:
  queue(){front=0;rear=0;}
  void add(int item)
  {
   if(rear==10)
   cout << "Queue is full";
   else
   a[rear++]=item;
  }
  void del()
  {
   if(front==rear)
   cout << "Queue is already empty";
   else
   front++;
  }
};

void main()
{

}
