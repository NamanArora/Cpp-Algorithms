#include<stdio.h>
#include<stdlib.h>

struct binTree 
{
    struct binTree *left;
    int info;
    struct binTree *right;
};
typedef struct binTree tree;
tree *root=NULL;

void insert(tree *root, tree *node)
{
    char dir;
    printf("l or r");
    dir=getch();
    if(dir=='l')
    {
        if(root->left==NULL)
            root->left=node;
        else
            insert(root->left,node);
    }
    else if(dir=='r')
    {
        if(root->right==NULL)
            root->right=node;
        else
            insert(root->right,node);
    }
}

void create()
{
    tree *node= (tree *) malloc(sizeof(tree));
    printf("Enter data: ");
    int data;
    scanf("%d",&data);
    node->left=NULL;
    node->right=NULL;
    node->info=data;
    if(root==NULL)
        root=node;
    else
        insert(root,node);
}

int search(int data, tree *node)
{
    //inorder based
    int temp;
    if(node==NULL)
        return 0;
    temp=search(data,node->left);
    if(node->info==data || temp==1) //we need to send the value to upper levels
        return 1;
    temp=search(data,node->right);
    if(node->info==data || temp==1)
        return 1;
    return 0;
}

int main()
{
    int in;
    int num;
    do
    {
        system("cls");
        printf("1.Insert element\n2.Search element\n");
        scanf("%d",&in);
        switch(in)
        {
            case 1: create(); break;
            case 2: 
            printf("Enter num to be searched: ");
            scanf("%d",&num);
            if(search(num,root))
                printf("Found");
            else
                printf("Not found");
            getch();
            break;
            
        }
    }while(in!=-1);
    return 0;
}
