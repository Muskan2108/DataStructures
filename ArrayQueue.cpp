#include<iostream>
#include<stdlib.h>
using namespace std;
#define max 10000
int top,rear;
int a[max];
int ch,no,i;
char ans;
bool isEmpty()
{
	if ((top==-1)&&(rear==-1))	return true;
	return false;
}
bool isFull()
{
	if(((rear+1)%max)==top) return true;
	return false;
}
void Enqueue(int x)
{
	if(isEmpty()==true)
	{
		top=0;
		rear=0;
		a[top]=x;
	}
	else if(!isFull())
	{
		rear=(rear+1)%max;
		a[rear]=x;
		
	}
	else
	{
		cout<<"Queue is full"<<endl;
		//return;
	}
}
void Dequeue()
{
	if(isEmpty())
	{
		cout<<"Nothing to dequeue"<<endl;
		//return;
	}	
	else if(rear==top)
	{
		rear=-1;
		top=-1;
	}
	else
	{
		top=(top+1)%max;
	}
}
void peep()
{	if(!isEmpty())
	{
		if(top<rear)
		{
			for(i=top;i<=rear;i++)
			{
				cout<<a[i]<<" ";
			}			
		}
		else
		{
			for(i=rear;i<=top;i++)
			{
				cout<<a[i]<<" ";
			}		
		}
		cout<<endl;
	}
	else
	{
		cout<<"List is Empty"<<endl;
	}
}
void menu()
{
	cout<<"====================MENU===================="<<endl;
	cout<<"1. Enqueue"<<endl;
	cout<<"2. Peep"<<endl;
	cout<<"3. Dequeue"<<endl;
	cout<<"4. Check the list is empty or not"<<endl;
	cout<<"5. Find Top element"<<endl;
	cout<<endl<<"Enter your choice:";
	cin>>ch;
	cout<<endl;
}
int main()
{
	top=-1;
	rear=-1;
	x:
	cout<<endl;
	menu();
	switch(ch)
	{
		case 1:
			{
				cout<<"Enter the element: ";
				cin>>no;
				Enqueue(no);
				
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
				peep();
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
				Dequeue();
				
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
				if(isEmpty()==true)
				{
					cout<<"yes"<<endl;
				}
				else
				{
					cout<<"no"<<endl;
				}
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
				cout<<a[top]<<endl;
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
