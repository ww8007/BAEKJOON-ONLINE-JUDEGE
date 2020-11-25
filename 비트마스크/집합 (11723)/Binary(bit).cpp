#include <iostream>
#include <string>
using namespace std;

class Binary
{
private:
	bool a[21];
public:
	Binary();
	void add(int num);
	void remove(int num);
	bool check(int num);
	void toggle(int num);
	void all();
	void empty();
};
Binary::Binary()
{
	for (int i = 1; i <= 20; i++)
	{
		a[i] = false;
	}
}
void Binary::add(int num)
{
	if (a[num])
		return;
	a[num] = true;
	return;
}
void Binary::remove(int num)
{
	if (a[num])
	{
		a[num] = false;
		return;
	}
	return;
}
bool Binary::check(int num)
{
	if (a[num])
	{
		return true;
	}
	else
		return false;
}
void Binary::toggle(int num)
{
	if (a[num])
	{
		a[num] = false;
		return;
	}
	else
	{
		a[num] = true;
		return;
	}
}
void Binary::all()
{
	for (int i = 1; i <= 20; i++)
	{
		a[i] = true;
	}
	return;
}
void Binary::empty()
{
	for (int i = 1; i <= 20; i++)
	{
		a[i] = false;
	}
	return;
}
int main(void)
{
	int num1;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> num1;
	Binary my;
	while (num1--)
	{
		string a;
		cin >> a;
		if (a == "add")
		{
			int mynum;
			cin >> mynum;
			my.add(mynum);
		}
		else if (a == "check")
		{
			int mynum;
			cin >> mynum;
			cout << my.check(mynum);
			cout << '\n';
		}
		else if (a == "remove")
		{
			int mynum;
			cin >> mynum;
			my.remove(mynum);
		}
		else if (a == "toggle")
		{
			int mynum;
			cin >> mynum;
			my.toggle(mynum);
		}
		else if (a == "all")
		{
			my.all();
		}
		else if (a == "empty")
		{
			my.empty();
		}
	}
	return 0;
}