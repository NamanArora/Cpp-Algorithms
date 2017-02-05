#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

enum { red, black};
struct node
{
    node *left,*right,*parent;
    int data;
    bool colour;
    node(int key)
    {
        data=key;
        left=right=parent=NULL;
        //color=false by default ie red
    }
};

void rightRotate(node *&root, node *&pt)
{
    node *pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

void leftRotate(node *&root, node *&pt)
{
    node *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}


node *insertBST(node *root, node *t)
{
    if(root==NULL)
        return t;

    if(t->data < root->data)
    {
        root->left = insertBST(root->left,t);
        root->left->parent = root;
        //to prevent recursion fucking up t everytime
        //t->parent = root;
    }
    else if( t->data > root->data)
    {
        root->right = insertBST(root->right,t);
        root->right->parent=root;
        //t->parent = root;
    }
    return root;
}
void violationCheck(node *&root, node *&t)
{

    node *parent = NULL;
    node *gparent = NULL;

    //parent is red, child is red, child is not root
    while((t!=root) && (t->parent->colour == red) && (t->colour ==red))
    {
        parent = t->parent;
        gparent = parent->parent;

        //develop the direction of first link parent-gparent
        if(parent == gparent -> left)
        {
            //determine uncle
            node *uncle = gparent->right;

            //now depending on the uncle we make next move
            if((uncle!=NULL) && (uncle->colour==red))
            {
                //switch colours
                bool x= parent->colour;
                uncle->colour=gparent->colour;
                parent->colour=gparent->colour;
                gparent->colour=x;
                t=gparent;
            }
            else
            {
                //uncle is black or doesn't exist, gotta rotate,recolour(one sided tree)
                if(t == parent->right)
                {
                    leftRotate(root, parent);
                    t = parent;
                    parent = t->parent;

                }
                rightRotate(root, gparent);
                swap(parent->colour, gparent->colour);
                t=parent;
            }

        }
        else
        {
            node *uncle = gparent->left;
            if((uncle!=NULL) && (uncle->colour==red))
            {
                //normal switch
                bool temp = parent->colour;
                parent->colour = gparent->colour;
                uncle->colour = gparent->colour;
                gparent->colour=temp;
            }
            else
            {
                if(t == parent -> left)
                {
                    rightRotate(root, parent);
                    t = parent;
                    parent = t->parent;
                }
                leftRotate(root, gparent);
                swap(gparent->colour, parent->colour);
                t=parent;
            }
        }

    }

    //will always remain black no matter what
    root->colour=black;
}

void levelOrderHelper(node *root)
{
    if (root == NULL)
        return;

    std::queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << "  ";
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

class Tree
{
private:
    node *root;
public:
    Tree(){root=NULL;}

    void insert(int key)
    {
        node *t = new node(key);
        root = insertBST(root,t);
        violationCheck(root,t);

    }

    void level()
    {
        levelOrderHelper(root);
    }
};


int main()
{
    Tree tree;
    tree.insert(7);
    cout << endl;
    tree.level();
    tree.insert(6);
    cout << endl;
    tree.level();
    tree.insert(5);
    cout << endl;
    tree.level();
    tree.insert(4);
    cout << endl;
    tree.level();
    tree.insert(3);
    cout << endl;
    tree.level();
    tree.insert(2);
    cout << endl;
    tree.level();
    tree.insert(1);
    cout << endl;
    tree.level();
    return 0;
}
