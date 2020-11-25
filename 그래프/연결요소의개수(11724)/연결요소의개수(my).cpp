//백준 11724번 연결 요소의 개수
//방향 없는 그래프가 주어졌을 때, 연결 요소(Connected Component)의 개수를 구하는 프로그램을 작성하시오.

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> a[1001];
queue<int> q;
bool check[1001];
int ans = 0;
void dfs(int num)
{
	check[num] = true;
	
	q.push(num);
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++)
		{
			int next = a[node][i];
			if (check[next] == false)
			{
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(a[i].begin(), a[i].end());
	}
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == false)
		{
			dfs(i);
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}