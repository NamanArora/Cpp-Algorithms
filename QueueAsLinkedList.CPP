#include<fstream.h>

struct node
{
  int data;
  node* next;
};

class queue
{
  node *front;
  node *rear;
  public:
  queue(){front=rear=NULL;}
  void add(int item)
  {
   node *t=new node;
   t->data=item;
   t->next=NULL;
   if(rear==NULL)
   {
    rear=t;
    front=t;
   }else
   {
    rear->next=t;
    rear=t;
   }
  }
  void del()
  {
   if(front==NULL)
   cout << "Queue is empty";
   else
   {
   node *t=front;
   front=front->next;
   if(front==NULL)
   rear=NULL;
   delete t;
   }

  }
};

void main()
{

}
