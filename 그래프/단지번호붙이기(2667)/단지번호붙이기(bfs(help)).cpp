//���� : ������ȣ���̱� 2667��

//<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�. 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����.
//ö���� �� ������ ������ ����� ������ ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�.
//���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�.�밢���� ���� �ִ� ���� ����� ���� �ƴϴ�. 
//<�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�.������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

//�Է� 
//ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�, �� ���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Էµȴ�.
//7
//0110100
//0110101
//1110101
//0000111
//0100000
//0111110
//0111000

//���
//ù ��° �ٿ��� �� �������� ����Ͻÿ�.�׸��� �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ͻÿ�.
//3
//7
//8
//9

//bfs(�ʺ� �켱 Ž��)�� �̿��ؼ� Ǭ ����
#include <iostream>
#include <vector>
#include <queue>	
#include <stdio.h>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[26][26];
int d[26][26];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int num;
int ans[25 * 25];
void bfs(int x, int y, int cnt)
{
	d[x][y] = cnt;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < num && 0 <= ny && ny < num)
			{
				if (a[nx][ny] == 1 && d[nx][ny] == 0)
				{
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
				}
			}
		}
	}
}

int main(void)
{
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			scanf_s("%1d", &a[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (a[i][j] == 1 && d[i][j] == 0)
				bfs(i, j, ++cnt);
		}
	}
	cout << cnt << '\n';

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			ans[d[i][j]]++;
		}
	}
	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}