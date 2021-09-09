#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int pre(char a)
{

	if(a=='^')
	return 4;
	else if(a=='*' or a=='/')
	return 3;
	else if(a=='+' or a=='-')
	return 2;
	else return 1;
}

string intopost(string s)
{
	stack<char> aayush;
	aayush.push('@');
	string r;
	int len=s.length();
	string :: iterator m;
	for(m=s.begin();m!=s.end();m++)
	{
		if((*m>='A' and *m<='Z') or (*m>='a' and *m<='z') or (*m>='0' and *m<='9'))
		{	
			r+=*m;	
		}
		else if(*m=='(')
		{
			aayush.push(*m);
		}
		else if(*m==')')
		{
			while(aayush.top()!='(' || aayush.top()!='@' )
			{
				r+=aayush.top();
				aayush.pop();
			}
			aayush.pop();
		}
		else
		{	
			
			while(aayush.top()!='(' && aayush.top()!='@' && pre(aayush.top())>=pre(*m))
				{
					r+=aayush.top();
					aayush.pop();
				}
			aayush.push(*m);
		}
	}
		while(aayush.top()!='@')
		{
			char ttp;
			ttp=aayush.top();
			r+=ttp;
			aayush.pop();
		}
	return r;
}
int main()
{
	string s,r;
	
	r=intopost("w1*f1*1/2+w2*f2*1/2+w3*f3");
	cout<<r;
}
