#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
Node* root;
Node* tmp;
void Insert(int x)
{
	Node* np=new Node();
	np->data=x;
	np->left=NULL;
	np->right=NULL;
	if(root==NULL)
	{
		root=np;
		return;
	}
	tmp=root;
	while(()||())
	
}
int main()
{
	root=NULL;
}
