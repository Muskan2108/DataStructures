#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool IsOperand(char C) 
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}
bool HasHigherPrecedence(char a,char b)
{
	if((a=='+')&&(b=='-')) return true;
	else if((a=='-')&&(b=='+')) return true;
	else if((a=='*')&&(b=='/')) return true;
	else if((a=='/')&&(b=='*')) return true;
	else if((a=='*')&&(b=='+')) return true;
	else if((a=='/')&&(b=='+')) return true;
	else if((a=='*')&&(b=='-')) return true;
	else if((a=='/')&&(b=='-')) return true;
	else if((a=='+')&&(b=='*')) return false;
	else if((a=='-')&&(b=='*')) return false;
	else if((a=='+')&&(b=='/')) return false;
	else if((a=='-')&&(b=='/')) return false;
	else if((a=='+')&&(b=='+')) return true;
	else if((a=='-')&&(b=='-')) return true;
	else if((a=='*')&&(b=='*')) return true;
	else if((a=='/')&&(b=='/')) return true;
	else return false;
	
}
string postfix(string str)
{
	string ans;
	stack<char> s;
	int t=-1;
	for(int i=0;i<str.length();i++)
	{
		if(IsOperand(str[i]))
		{
			ans=ans+str[i];
		}
		else if((str[i]==' ')||(str[i]==','))
		{
			continue;
		}
		else if(IsOperator(str[i]))
		{
			while((!s.empty())&&(HasHigherPrecedence(s.top(),str[i]))&&(s.top()!='('))
			{
				ans=ans+s.top();
				s.pop();
			}			
			s.push(str[i]);
		}
		else if(str[i]=='(')
		{
			s.push(str[i]);
		}
		else if(str[i]==')')
		{
			while((!s.empty())&&(s.top()!='('))
			{
				ans=ans+s.top();
				s.pop();
			}	
			s.pop();	
		}
	}
	while(!s.empty())
	{
		ans+=s.top();
		s.pop();
	}
	return ans;	
}

int main()
{
	string ans, s;
	cout<<"Enter the infix expression: ";
	getline(cin,s);
	ans=postfix(s);
	cout<<"Equivalent postfix expression: ";
	cout<<ans<<endl;
}
