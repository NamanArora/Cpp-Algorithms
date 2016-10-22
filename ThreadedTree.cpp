#include <iostream>
#include <queue>
using namespace std;

struct node
{
	node *left,*right;
	int key;
	bool threaded;
};

node *createNode(int key)
{
	node *t= new node;
	t->left=NULL;
	t->right=NULL;
	t->key=key;
	t->threaded=false;
	return t;
}

void storeQueue(node *root, queue<node *> *q)
{
	if(root==NULL)
		return;
	if(root->left)
		storeQueue(root->left,q);
	q->push(root);
	if(root->right)
		storeQueue(root->right,q);
}

void createThread(node *root, queue<node *> *q)
{
	if(root==NULL)
		return;
	if(root->left)
		createThread(root->left,q);
	q->pop();
	if(root->right)
		createThread(root->right,q);
	else
	{
		root->right=q->front();
		root->threaded=true;
	}

}

void threadify(node *root)
{
	queue<node *> q;
	storeQueue(root,&q);
	createThread(root,&q);
}

node *leftmost(node *root)
{
	while(root->left)
		root=root->left; //we are at the leftmost node/leaf
	return root;

}

void traverse(node *root)
{
	node *t=leftmost(root);

	while(t!=NULL)
	{
	cout << t->key << " ";
	if(t->threaded)
		t=t->right;
	else
		t=leftmost(t->right);
	}
}

int main()
{
	node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    threadify(root);
    traverse(root);

    return 0;
}