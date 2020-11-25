#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>	

using namespace std;
vector <int> a[20001];
int color[20001];

bool dfs(int num, int c)
{
	color[num] = c;
	for (int i = 0; i < a[num].size(); i++)
	{
		int next = a[num][i];
		if (color[next] == 0)
		{
			if (dfs(next, 3 - c) == false)
				return false;
			
		}
		else if (color[next] == color[num])
			return false;
	}
	return true;
}
int main(void)
{
	int ct;
	cin >> ct;
	for (int i = 0; i < ct; i++)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			color[i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			int t1, t2;
			cin >> t1 >> t2;
			a[t1].push_back(t2);
			a[t2].push_back(t1);
		}
		bool ok = true;
		for (int i = 1; i <= n; i++)
		{
			if (color[i] == 0)
			{
				if (dfs(i, 1) == false)
					ok = false;
			}
		}
		if (ok == false)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
	return 0;
}