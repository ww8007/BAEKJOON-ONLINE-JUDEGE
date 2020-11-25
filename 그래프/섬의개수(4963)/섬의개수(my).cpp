//���� : ���� ���� 4963��(bfs, dfs)
//
//���簢������ �̷���� �ִ� ���� �ٴ� ������ �־�����.���� ������ ���� ���α׷��� �ۼ��Ͻÿ�.
//�� ���簢���� ����, ���� �Ǵ� �밢������ ����Ǿ� �ִ� �簢���� �ɾ �� �ִ� �簢���̴�.
//�� ���簢���� ���� ���� ��������, �� ���簢������ �ٸ� ���簢������ �ɾ �� �� �ִ� ��ΰ� �־�� �Ѵ�.������ �ٴٷ� �ѷ��ο� ������, ���� ������ ���� �� ����.
//
//�Է� 
//
//�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�.
//�� �׽�Ʈ ���̽��� ù° �ٿ��� ������ �ʺ� w�� ���� h�� �־�����.w�� h�� 50���� �۰ų� ���� ���� �����̴�.
//��° �ٺ��� h�� �ٿ��� ������ �־�����. 1�� ��, 0�� �ٴ��̴�.
//�Է��� ������ �ٿ��� 0�� �� �� �־�����.
//1 1
//0
//2 2
//0 1
//1 0
//3 2
//1 1 1
//1 1 1
//5 4
//1 0 1 0 0
//1 0 0 0 0
//1 0 1 0 1
//1 0 0 1 0
//5 4
//1 1 1 0 1
//1 0 1 0 1
//1 0 1 0 1
//1 0 1 1 1
//5 5
//1 0 1 0 1
//0 0 0 0 0
//1 0 1 0 1
//0 0 0 0 0
//1 0 1 0 1
//0 0
//
//���
//
//0
//1
//1
//3
//1
//9
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <cstring>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1,1,0,0 };
int num1, num2;
int a[51][51];
int d[51][51];
void bfs(int x, int y, int cnt)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = cnt;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[i];
				int ny = y + dy[j];
				if (0 <= nx && nx < num1 && 0 <= ny && ny < num2)
				{
					if (a[nx][ny] == 1 && d[nx][ny]==0)
					{
						q.push(make_pair(nx, ny));
						d[nx][ny] = cnt;
					}
				}
			}
		}
	}
}

int main(void)
{
	while (1)
	{
		cin >> num2 >> num1;
		if (num1 == 0 && num2 == 0)
			break;
		memset(a, 0, sizeof(a));
		memset(d, 0, sizeof(d));
		for (int i = 0; i < num1; i++)
		{
			for (int j = 0; j < num2; j++)
			{
				cin >> a[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < num1; i++)
		{
			for (int j = 0; j < num2; j++)
			{
				if (a[i][j] == 1 && d[i][j] == 0)
					bfs(i, j, ++cnt);
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}