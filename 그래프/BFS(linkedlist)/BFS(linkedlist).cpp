#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue <int> q;
bool check[10];
vector <vector<int>> a;
int main(void)
{
	check[1] = true;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i <a[x].size(); i++)
		{
			int y = a[x][i];
			if (check[y] == false)
			{
				check[y] = true;
				q.push(y);
			}
		}
	}
}