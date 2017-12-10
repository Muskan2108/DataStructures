#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};
Node* head;
Node* tail;
void InsertAtHead(int x)
{
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	if((head==NULL)&&(tail==NULL))
	{
		head=temp;
		tail=temp;
		return;
	}
	head->prev=temp;
	temp->next=head;
	head=temp;
}
void InsertAtTail(int x)
{
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	if((head==NULL)&&(tail==NULL))
	{
		head=temp;
		tail=temp;
		return;
	}
	tail->next=temp;
	temp->prev=tail;
	tail=temp;
}
void print()
{
	Node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}	
	cout<<endl;
}
void printrev()
{
	Node* temp=tail;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->prev;
	}	
	cout<<endl;	
}
int main()
{
	head=NULL;
	tail=NULL;
	InsertAtHead(5); //5
	print();
	InsertAtHead(3); //3 5
	print();
	InsertAtHead(1); //1 3 5
	print();
	InsertAtTail(7); //1 3 5 7
	print();
	InsertAtTail(0); // 1 3 5 7 0
	print();
	printrev();
}
