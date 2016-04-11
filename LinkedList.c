#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

node *head=NULL;
node *curr=NULL;

void insert()
{
    node *temp=(node *) malloc(sizeof(node));
    printf("Enter data: ");
    int in;
    scanf("%d",&in);
    temp->data=in;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        curr=temp;
    }
    else
    {
        curr->next=temp;
        curr=temp;
    }
}

void del()
{
    int flag=0;
    printf("Enter item to be deleted: ");
    int in;
    scanf("%d",&in);
    for(node *temp=head,*prev=head; temp!=NULL; prev=temp,temp=temp->next)
    {
        if(temp->data==in)
        {
            flag=1;
            if(temp==head)
            {
                head=head->next;
                free(temp);
                break;
            }
            else
            {
                prev->next=temp->next;
                if(temp==curr) //we need to update curr if incase we remove the last node
                    curr=prev;
                free(temp);
                break;
            }
        }
        
    }
    if(flag)
        printf("Entery delteld");
        else
            printf("Entry not found");
    getch();
}


void display()
{
    for(node *temp=head; temp!=NULL; temp=temp->next)
        printf("%d ",temp->data);
        getch();
}
int main()
{
    int in;
    do
    {
        system("cls");
        printf("1.Insert element\n2.Delete element\n3.Display elements\n");
        scanf("%d",&in);
        switch(in)
        {
            case 1: insert(); break;
            case 2: del(); break;
            case 3: display();break;
        }
    }while(in!=-1);
    return 0;
}
