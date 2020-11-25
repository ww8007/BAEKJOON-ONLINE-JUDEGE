//���� : �̷� Ž�� (bfs) 2178��
//N��Mũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.
//
//1	0	1	1	1	1
//1	0	1	0	1	0
//1	0	1	0	1	1
//1	1	1	0	1	1
//�̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 0�� �̵��� �� ���� ĭ�� ��Ÿ����.�̷��� �̷ΰ� �־����� ��, (1, 1)���� ����Ͽ�(N, M)�� ��ġ�� �̵��� �� ������ �ϴ� �ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.]
//�� ĭ���� �ٸ� ĭ���� �̵��� ��, ���� ������ ĭ���θ� �̵��� �� �ִ�.
//���� �������� 15ĭ�� ������(N, M)�� ��ġ�� �̵��� �� �ִ�.ĭ�� �� ������ ���� ��ġ�� ���� ��ġ�� �����Ѵ�.
//
//�Է� 

//ù° �ٿ� �� ���� N, M(2 �� N, M �� 100)�� �־�����.���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����.������ ������ �پ �Է����� �־�����.
//4 6
//101111
//101010
//101011
//111011
//
//���

//ù° �ٿ� ������ �ϴ� �ּ��� ĭ ���� ����Ѵ�.�׻� ������ġ�� �̵��� �� �ִ� ��츸 �Է����� �־�����.
//15

//Ǯ�� bfs�� �̿��� (�������)
#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

int num, num2;
int a[101][101];
bool check[101][101];
int ans[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1, 1, 0, 0 };
void bfs(int x, int y)
{
	check[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	int cnt = 1;
	ans[x][y] = cnt;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < num && 0 <= ny && ny < num2)
			{
				if (a[nx][ny] == 1 && check[nx][ny] == false)
				{
					q.push(make_pair(nx, ny));
					ans[nx][ny] = ans[x][y]+1;
					check[nx][ny] = true;
				}
			}
		}
	}
}


int main(void)
{
	cin >> num >> num2;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			scanf_s("%1d", &a[i][j]);
			ans[i][j] = 1;
		}
	}
	bfs(0, 0);
	num--;
	num2--;
	cout << ans[num][num2] <<'\n';
}