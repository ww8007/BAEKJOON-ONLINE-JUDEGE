#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

stack <char> my;
stack <char> my1;
int main(void)
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	// 문자열 받아주기
	// getline 유의 getline(cin, a)
	string a;
	getline(cin, a);

	int szof = a.size();
	for (int i = 0; i < szof; i++)
	{
		my1.push(a[i]);
	}
	int num;
	cin >> num;
	
	while (num--)
	{
		char word;
		cin >> word;
		if (word == 'L')
		{
			if (!my1.empty())
			{
				char n = my1.top();
				my1.pop();
				my.push(n);
			}
		}
		else if (word == 'D')
		{
			if (!my.empty())
			{
				char n = my.top();
				my.pop();
				my1.push(n);
			}
		}
		else if (word == 'B')
		{
			if (!my1.empty())
			{
				my1.pop();
			}
		}
		else if (word == 'P')
		{
			char n;
			cin >> n;
			my1.push(n);
		}
	}

	stack <char> j;
	
	for (int i = 0; i <= my1.size(); i++)
	{
		char n = my1.top();
		j.push(n);
		my1.pop();
	}
	
	for (int i = 0; i < j.size(); i++)
	{
		cout << j.top();
		j.pop();
	}
	for (int i = 0; i < my.size(); i++)
	{
		cout << my.top();
		my.pop();
	}
}