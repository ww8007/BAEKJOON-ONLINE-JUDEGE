//���� DFS BFS 1260��
//�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
//��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�.
//���� ��ȣ�� 1������ N�������̴�.
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
	memset(check, false, sizeof(check)); // �ʱ�ȭ ����� ��
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
		a[t2].push_back(t1); // �� �� ���ִ� ���� �߿�	
							 // �� ���� ������ �ƴ� ����� ����
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