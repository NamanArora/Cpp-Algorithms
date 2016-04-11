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

int height(tree *node)
{
    if(node == NULL)
        return 0;
    else
    {
        int lheight=height(node->left);
        int rheight=height(node->right);
        
        if(lheight>rheight)
            return lheight+1;
        else
            return rheight+1;
    }
}

void printer(int i,tree *node)
{
    if(node==NULL)
        return;
    if(i==0)
        printf("%d ",node->info);
    else
    {
        printer(i-1,node->left);
        printer(i-1,node->right);
    }
}

void levelordertraversal()
{
    int h=height(root);
    printf("Height=%d",h);
    getch();
    for(int i=0; i<h; i++)
        printer(i,root);
}

int main()
{
    int in;
    int num;
    do
    {
        system("cls");
        printf("1.Insert element\n2.Search element\n3.Level order traversal\n");
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
            case 3:
            levelordertraversal();
            getch();
            break;
        }
    }while(in!=-1);
    return 0;
}
