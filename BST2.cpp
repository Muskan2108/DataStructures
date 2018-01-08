#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
Node* Insert(Node* root,int x)
{
	if(root==NULL)
	{
		Node* np=new Node();
		np->data=x;
		np->left=NULL;
		np->right=NULL;
		root=np;
	}
	else if(x<=root->data)
	{
		root->left=Insert(root->left,x);
	}
	else
	{
		root->right=Insert(root->right,x);
	}
	return root;
	
}
bool IsSTLesser(Node* root,int value)
{
	if(root==NULL)	return true;
	if((root->data<=value)&&(IsSTLesser(root->left,value))&&(IsSTLesser(root->right,value)))	return true;
	else return false;	
}
bool IsSTGreater(Node* root,int value)
{
	if(root==NULL)	return true;
	if((root->data>value)&&(IsSTGreater(root->left,value))&&(IsSTGreater(root->right,value)))	return true;
	else return false;	
}
bool IsBST(Node* root)
{
	if (root==NULL)	return true;
	if((IsSTLesser(root->left,root->data))&&(IsSTGreater(root->right,root->data))&&(IsBST(root->left))&&(IsBST(root->right)))	return true;
	else 	return false;
}
bool Search(Node* root,int data)
{
	if(root==NULL)	return false;
	else if(root->data==data)	return true;
	else if(data <= root->data )	return Search(root->left,data);
	else return Search(root->right,data); 
}
int minimum(Node* root)
{
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return -1;
	}
	Node* tmp;
	tmp=root;
	while(tmp->left!=NULL)
	{
		tmp=tmp->left;
	}
	return tmp->data;
}
int maximum(Node* root)
{
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return -1;
	}
	Node* tmp;
	tmp=root;
	while(tmp->right!=NULL)
	{
		tmp=tmp->right;
	}
	return tmp->data;	
}
bool IsBSTbyRange(Node* root,int min,int max)
{
	if(root==NULL)	return true;
	if((root->data>min)&&(root->data<max)&&(IsBSTbyRange(root->left,min,root->data))&&(IsBSTbyRange(root->right,root->data,max)))	return true;
	else 	return false;
}
int minRec(Node* root)
{
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return -1;
	}
	else if(root->left==NULL)
	{
		return root->data;
	}
	
	return minRec(root->left);
}
int maxRec(Node* root)
{
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return -1;
	}
	else if(root->right==NULL)
	{
		return root->data;
	}
	
	return maxRec(root->right);
}
int height(Node* root)
{
	if(root==NULL)
	{
		return -1;	
	}
	int l=height(root->left);
	int r=height(root->right);
	if(l>=r)
	{
		return (l+1);
	}
	else
	{
		return (r+1);
	}
}
void LevelOrder(Node* root)
{
	if(root==NULL)	return;	
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* tmp=q.front();
		cout<<tmp->data<<" ";
		if(tmp->left!=NULL)	q.push(tmp->left);
		if(tmp->right!=NULL)	q.push(tmp->right);
		q.pop();
	}
}
void Preorder(Node* root)
{
	if(root==NULL) return;
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}
void Inorder(Node* root)
{
	if(root==NULL) return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
void Postorder(Node* root)
{
	if(root==NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<<" ";
}
Node* minim(Node* root)
{
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return NULL;
	}
	Node* tmp;
	tmp=root;
	while(tmp->left!=NULL)
	{
		tmp=tmp->left;
	}
	return tmp;
}
Node* del(Node* root,int data)
{
	if(root==NULL)	return root;
	else if(data<root->data)	root->left=del(root->left,data);
	else if(data>root->data)	root->right=del(root->right,data);
	else
	{
		if((root->left==NULL)&&(root->right==NULL))
		{
			delete root;
			root=NULL;
			return root;
		}
		else if(root->left==NULL)
		{
			Node* tmp=root;
			root=root->right;
			delete tmp;
			return root;
		}
		else if(root->right==NULL)
		{
			Node* tmp=root;
			root=root->left;
			delete tmp;
			return root;
		}
		else
		{
			Node* tmp=minim(root->right);
			root->data=tmp->data;
			root->right=del(root->right,tmp->data);
			return root;
		}
	}
}
Node* searchnode(Node* root,int data)
{
	if(root->data==data)	return root;
	else if(data <= root->data )	return searchnode(root->left,data);
	else if(data > root->data ) return searchnode(root->right,data); 
	else return NULL;
}
Node* gerSuc(Node* root,int data)
{
	Node* cur=searchnode(root,data);
	if(cur==NULL)	return NULL;
	if(cur->right!=NULL)
	{
		Node* tmp=cur->right;
		while(tmp->left!=NULL)
		{
			tmp=tmp->left;
		}
		return tmp;
	}	
	else
	{
		Node* successor=NULL;
		Node* ancestor=root;
		while(ancestor!=cur)
		{
			if(cur->data<ancestor->data)
			{
				successor=ancestor;
				ancestor=ancestor->left;
			}
			else
			{
				ancestor=ancestor->right;
			}
		}
		return successor;
	}
	
}
int main()
{
	Node* root;
	root=NULL;
	root=Insert(root,15);
	root=Insert(root,10);
	root=Insert(root,20);
}
