#include <queue>
#include <algorithm>
#include <iostream>	

using namespace std;

queue <int> my;
int main(void)
{
	int num;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> num;
	while (num--)
	{
		string a;
		cin >> a;
		if (a == "push")
		{
			int a;
			cin >> a;
			my.push(a);
		}
		else if (a == "pop")
		{
			if (my.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				int c = my.front();
				my.pop();
				cout << c << '\n';
			}
		}
		else if (a == "size")
		{
			cout << my.size() << '\n';
		}
		else if (a == "empty")
		{
			if (my.empty())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (a == "front")
		{
			if (my.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				int k = my.front();
				cout << k << '\n';
			}
		}
		else if (a == "back")
		{
			if (my.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				int k = my.back();
				cout << k << '\n';
			}
		}
	}
}