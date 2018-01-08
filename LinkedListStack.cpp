#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void menu();
void Pop();
void Peep();
void Push();
struct Node
{
	int data;
	Node *next;
}*top,*np,*tmp,*ptr;
int main()
{
	cout<<endl;
	top=NULL;
	menu();
}
void menu()
{
	int ans;
	cout<<endl;
	cout<<"PROGRAM OF PUSH PEEP AND POP USING LINK IMPLEMENTATION\n";
	cout<<"======================================================\n";
	cout<<"\n1. To add an element in stack.......";
	cout<<"\n2. To pop an element from stack.....";
	cout<<"\n3. To display elements of stack.....";
	cout<<"\n4. To exit..........................";
	cout<<"\n\nEnter your choice :";
	cin>>ans;
	switch(ans)
	{
		case 1: Push();		break;
		case 2: Pop();		break;
		case 3: Peep();		break;
		case 4: exit(0);	break;
		default:menu();         break;
	}
}
void Push()
{
	np=new Node();
	cout<<"\nEnter the data    :";
	cin>>np->data;
	if(top==NULL)
	{
		top=np;
		top->next=NULL;
	}
	else
	{
		np->next=top;
		top=np;
	}
	menu();
}
void Peep()
{
	ptr=top;
	cout<<endl<<endl;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<"\nDisplaying of list completed..."<<endl;
	menu();
}
void Pop()
{
	if(top==NULL)
	{
		cout<<"Cannot pop"<<endl;
		menu();
	}
	tmp=top;
	top=top->next;
	delete tmp;
	Peep();
	menu();
}
