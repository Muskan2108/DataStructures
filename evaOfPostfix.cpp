#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool IsNumericDigit(char C) 
{
	if(C >= '0' && C <= '9') return true;
	return false;
}
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}
int PerformOperation(char operation, int operand1, int operand2)
{
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;

	else cout<<"Unexpected Error \n";
	return -1; 
}

int evaluate(string str)
{
	int res,temp,op1,op2,tem;
	stack<int> s;
	for(int i=0;i<str.length();i++)
	{
		if((str[i]==' ')||(str[i]==','))
		{
			continue;
		}
		else if(IsNumericDigit(str[i]))
		{
			tem=0;
			while(i<str.length() && IsNumericDigit(str[i])) { 
				tem = (tem*10) + (str[i] - '0'); 
				i++;
			}
			i--;
			s.push(tem);	
		}
		else if(IsOperator(str[i]))
		{
			op1=s.top();
			s.pop();
			op2=s.top();
			s.pop();
			temp=PerformOperation(str[i],op1,op2);
			s.push(temp);	
		}
	}
	return s.top();
}
int main()
{
	int t;
	string a;
	cout<<"Enter the Postfix Expression: ";
	getline(cin,a);
	t=evaluate(a);
	cout<<"The result is "<<t<<endl;
}
