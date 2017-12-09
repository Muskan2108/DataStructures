#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Node
{
	int data;
	Node* link;
};
int ch;
Node* head;
void insertbeg(int x)
{
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->link = head;
	head=temp;
}
void insertn(int x, int n)
{
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = x;
	if(n==1)
	{
		temp->link = head;
		head=temp;
		return;
	}
	Node* temp1 = head;
	for(int i=0;i<n-2;i++)
	{
		temp1=temp1->link;
	}
	temp->link=temp1->link;
	temp1->link=temp;
}
void print()
{
		struct Node* temp=head;
		cout<<"The list is :  ";
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->link;
		}
		cout<<endl;
}
void insertend(int x)
{
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->link=NULL;
	Node* temp1=head;
	while(temp1->link!=NULL)
	{
		temp1=temp1->link;
	}
	temp1->link=temp;
}
void del(int pos)
{
	Node* temp=head;
	if(pos==1)
	{
		head=temp->link;
		delete(temp);
		return;
	}
	for(int i=0;i<pos-2;i++)
	{
		temp=temp->link;
	}
	Node* temp2=temp->link;
	temp->link=temp2->link;
	delete(temp2);
}
void reverse()
{
	Node *current,*next,*prev;
	current=head;
	prev=NULL;
	while(current!=NULL)
	{
		next=current->link;
		current->link=prev;
		prev=current;
		current=next;
	}
	head=prev;
}
void printbyrecursion(Node* p)
{
	if(p==NULL)	{
	cout<<endl;	
	return;}
	cout<<p->data<<" ";
	printbyrecursion(p->link);
}
void revprintbyrecursion(Node* p)
{
	if(p==NULL)	{
	 return;}
	revprintbyrecursion(p->link);
	cout<<p->data<<" ";

}
void revlistbyrecursion(Node* p)
{
	if(p->link==NULL)
	{
		head=p;
		return;
	}
	revlistbyrecursion(p->link);
	Node* q=p->link;
	q->link=p;
	p->link=NULL;
}
void menu()
{
	cout<<"====================MENU===================="<<endl;
	cout<<"1. Insert at beginning"<<endl;
	cout<<"2. Insert at end"<<endl;
	cout<<"3. Insert at any position"<<endl;
	cout<<"4. Print by iteration"<<endl;
	cout<<"5. Print by recursion"<<endl;
	cout<<"6. Reverse print by recursion"<<endl;
	cout<<"7. Reverse the list by iteration"<<endl;
	cout<<"8. Reverse the list by recursion"<<endl;
	cout<<"9. Delete an element from any position"<<endl;
	cout<<endl<<"Enter your choice:";
	cin>>ch;
}
int main()
{
	head=NULL;
	int tempo,n;
	char ans;
	x:
	
	menu();
	switch(ch)
	{
		case 1:
			{
				cout<<"Enter the number: ";
				cin>>tempo;
				insertbeg(tempo);
				cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}
			}
		case 2:
			{
				cout<<"Enter the number: ";
				cin>>tempo;
				insertend(tempo);
				cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}	
			}
		case 3:
			{
				cout<<"Enter the number:";
				cin>>tempo;
				cout<<endl<<"Enter the position:";
				cin>>n;
				insertn(tempo,n);
				cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}		
			}
		case 4:
			{
				print();
				cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}		
			}
		case 5:
			{	
				printbyrecursion(head);
				cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}		
			}
		case 6:
			{
				revprintbyrecursion(head);
				cout<<endl;
				cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}		
			}
		case 7:
			{
				reverse();
				cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}		
			}
		case 8:
			{
				revlistbyrecursion(head);
				cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}		
			}
		case 9:
			{
				cout<<"Enter the position to delete the element:";
				cin>>n;
				del(n);
				cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}		
			}
		default:
			{
				cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}		
			}
			
	}
	
	
}
