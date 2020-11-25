//백준 DFS BFS 1260번
//그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
//단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다.
//정점 번호는 1번부터 N번까지이다.
#include <iostream>
#include <vector>
#include <queue>	
#include <algorithm>

using namespace std;

vector<int> a[1001];
queue<int> q;
bool check[1001];

void dfs(int num)
{
	check[num] = true;
	cout << num << ' ';
	for (int i = 0; i < a[num].size(); i++)
	{
		int next = a[num][i];
		if (check[next] == false)
		{
			dfs(next);
		}
	}
}
void bfs(int num)
{
	memset(check, false, sizeof(check)); // 초기화 해줘야 함
	check[num] = true;
	q.push(num);
	while (!q.empty())
	{
		int node = q.front();
		cout << node << ' ';
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
	
	int n, m, f;
	cin >> n >> m >> f;
	for (int i = 1; i <= m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		a[t1].push_back(t2);
		a[t2].push_back(t1); // 두 번 해주는 것이 중요	
							 // 단 방향 연결이 아닌 양방향 연결
	}
	for (int i = 1; i <= n; i++)
	{
		sort(a[i].begin(), a[i].end());
	}
	dfs(f);
	cout << '\n';
	bfs(f);
	cout << '\n';
	return 0;
}