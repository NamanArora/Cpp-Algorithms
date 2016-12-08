#include <iostream>

using namespace std;

struct node
{
  int key;
  int height;
  node *left;
  node *right;
};

void preorder(node *root)
{
  if(root==NULL)
    return;

  cout << root->key << " ";
  preorder(root->left);
  preorder(root->right);
}

node *createnode(int key)
{
  node *t = new node;
  t->height=1;
  t->key=key;
  t->left=NULL;
  t->right=NULL;
  return t;
}

int height(node *t)
{
  return t==NULL? 0: t->height;
}

int getBalance(node *t)
{
  return t==NULL? 0 : height(t->left)-height(t->right);
}

node *rightRotate(node *root)
{
  node *b = root->left;
  node *b2 = b->right;

  root->left = b2;
  b->right = root;

  root->height = max(height(root->left), height(root->right)) + 1;
  b->height = max(height(b->left), height(b->right)) +1;

  return b;
}

node *leftRotate(node *root)
{
  node *b = root->right;
  node *b1= b->left;

  root->right=b1;
  b->left = root;

  root->height = max(height(root->left), height(root->right)) + 1;
  b->height = max(height(b->left), height(b->right)) +1;

  return b;
}

node *insert(node *root, int key)
{
  if(root==NULL)
    return createnode(key);
  if(key < root->key)
    root->left = insert(root->left,key);
  else
    root->right = insert(root->right,key);

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    if(balance > 1 && key < root->left->key)
      return rightRotate(root);
    else if( balance <-1 && key > root->right->key)
      return leftRotate(root);
    else if(balance > 1 && key > root->left->key)
    {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
    else if(balance <-1 && key < root->right->key)
    {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }


  return root;
}

int main()
{
  node *root=NULL;
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
  preorder(root);
  return 0;
}
