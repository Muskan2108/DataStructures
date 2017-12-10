#include<iostream>
using namespace std;
#define max 10000
int top;
int a[max];
int b[2*max];
int ch,no;
char ans;
void push(int x)
{
	top+=1;
	
	if((top)==max)
	{
		for(int i=0;i<top;i++)
		{
			b[i]=a[i];	
		}
		b[top]=x;
	}
	else if((top)>max)
	{
		b[top]=x;
	}
	else
	{
		a[top]=x;
	}
}
void pop()
{
	if(top==-1)
	{
		cout<<"Cannot pop"<<endl;
	}
	else
	{
		top=top-1;
	}
}
void peep()
{
	if((top)>=max)
	{
		for(int i=0;i<=top;i++)
		{
			cout<<b[i]<<" ";	
		}
		cout<<endl;	
	}
	else
	{
		for(int i=0;i<=top;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;	
	}
}
bool isEmpty()
{
	if(top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void menu()
{
	cout<<"====================MENU===================="<<endl;
	cout<<"1. Push"<<endl;
	cout<<"2. Peep"<<endl;
	cout<<"3. Pop"<<endl;
	cout<<"4. Check the list is empty or not"<<endl;
	cout<<"5. Find Top element"<<endl;
	cout<<endl<<"Enter your choice:";
	cin>>ch;
	cout<<endl;
}
int main()
{
	top=-1;
	x:
	cout<<endl;
	menu();
	switch(ch)
	{
		case 1:
			{
				cout<<"Enter the element: ";
				cin>>no;
				push(no);
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
				pop();
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
				if(top<max)
				{
					cout<<a[top];
				}
				else
				{
					cout<<b[top];
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
