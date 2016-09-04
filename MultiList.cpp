#include <stdio.h>
#include <algorithm> 
#include <bits/stdc++.h> 

using namespace std;

struct node
{
    char name[20];
    int cgpa;
    node *next;
};

struct branch
{
    char branchname[20];
    branch *down;
    node *next;
};

branch *head=NULL;

void menu()
{
    system("cls");
    cout << "1. Insert a new branch" << endl;
    cout << "2. Add student details" << endl;
    cout << "3. Show toppers" << endl;
    cout << "4. Exit" << endl;
    cout << "Input: ";
}

void createbranch()
{
    branch *temp = new branch;
    cout << "Enter branch name: ";
    cin >> temp->branchname;
    temp->next=NULL;
    temp->down=NULL;
    if(head==NULL)
        head=temp;
    else
    {
        branch *t = head;
        while(t->down!=NULL)
            t=t->down;
        t->down=temp;
    }
}

void addstudent()
{
    branch *t=head;
    node *temp= new node;
    temp->next=NULL;
    cout << "Enter name: ";
    cin >> temp->name;
    cout << "Enter cgpa: ";
    cin >> temp->cgpa;
    
    int i=0;
    while(t!=NULL)
    {
        i++;
        cout << i << ". " <<  t->branchname << endl;
        t=t->down;
    }
    
    int input;
    cout << "In: ";
    cin >> input;
    t=head;
    for(int j=1; j<input; j++)
        t=t->down;
        
        //yeh vaala part thoda faulty hai. Upar ka sab sahi hai
        
    if(t->next==NULL)
        t->next=temp;
    else
    {
        node *line=t->next;
        while(line->next!=NULL)
            line=line->next;
        line->next=temp;
    }
}

void show()
{
    branch *t=head;
    
    while(t!=NULL)
    {
        cout << t->branchname << endl;
        node *line=t->next;
        while(line!=NULL)
        {
            cout << line->name << " ";
            cout << line->cgpa;
            cout << endl;
            line=line->next;
        }
        t=t->down;
    }
}

int main()
{
    int input;
    do
    {
        menu();
        cin >> input;
        switch(input)
        {
            case 1:
            //insert new branch
            createbranch();
            break;
            case 2:
            //add student
            addstudent();
            break;
            case 3:
            show();
            break;
            default:
            break;
        }
    system("pause");
    }while(input!=4);
}
