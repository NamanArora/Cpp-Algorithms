#include<iostream>

using namespace std;

struct node 
{
	node *left;
	node *right;
	int key;
	int height;
};

node *createnode(int key)
{
	node *t= new node;
	t->left=NULL;
	t->right=NULL;
	t->key=key;
	t->height=1;
	return t;
}

int height(node *t)
{
	if(t==NULL)
		return 0;
	return t->height;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
 

int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}



struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights IMPORTANT
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}

node *insert(node *root, int key)
{

	if(root==NULL)
		return createnode(key);

	if(root->key < key)
		root->left= insert(root->left, key);
	else
		root->right= insert(root->right, key);

	root->height= max(height(root->left),height(root->right))+1;

	int balance = getBalance(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);
 
    // Right Right Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);
 
    // Left Right Case
    if (balance > 1 && key > root->left->key)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Left Case
    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

/*
	int balFactor= getBalance(root);

	if(balFactor < -1 && key> root->right->key)
		return lRotate(root);
	else if (balFactor < -1 && key< root->right->key)
	{
		root->right=rRotate(root->right);
		return lRotate(root);
	}
	else if(balFactor > 1 && key< root->left->key)
		return rRotate(root);
	else if (balFactor > 1 && key>root->left->key)
	{
		root->left=lRotate(root->left);
		return rRotate(root);
	}
	*/

	return root;

}

void traversal(node *root)
{
	if(root==NULL)
		return;
	cout << "Key: " << root->key << " Height=" << root->height << endl;
	traversal(root->left);
	traversal(root->right);
}



 int main(int argc, char *argv[])
{
	node *root=NULL;
	
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

	traversal(root);
	return 0;
}
