//���� : ����Ʈ���̵�(bfs) 7562��
//
//���� 
//
//ü���� ���� �� ����Ʈ�� ������ �ִ�.����Ʈ�� �� ���� �̵��� �� �ִ� ĭ�� �Ʒ� �׸��� �����ִ�.
//����Ʈ�� �̵��Ϸ��� �ϴ� ĭ�� �־�����.����Ʈ�� �� �� �����̸� �� ĭ���� �̵��� �� ������ ?
//
//�Է�
//
//�Է��� ù° �ٿ��� �׽�Ʈ ���̽��� ������ �־�����.
//�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�.ù° �ٿ��� ü������ �� ���� ���� l(4 �� l �� 300)�� �־�����.
//ü������ ũ��� l �� l�̴�.ü������ �� ĭ�� �� ���� ��{ 0, ..., l - 1 } ��{ 0, ..., l - 1 }�� ��Ÿ�� �� �ִ�.
//��° �ٰ� ��° �ٿ��� ����Ʈ�� ���� �ִ� ĭ, ����Ʈ�� �̵��Ϸ��� �ϴ� ĭ�� �־�����.
//
//example
//3
//8
//0 0
//7 0
//100
//0 0
//30 50
//10
//1 1
//1 1
//
//���
//
//�� �׽�Ʈ ���̽����� ����Ʈ�� �� ������ �̵��� �� �ִ��� ����Ѵ�.
//
//5
//28
//0

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int a[301][301];
bool check[301][301];
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int len;
int c, d;
int x2, y2;
void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (0 <= nx && nx < len && 0 <= ny && ny < len)
			{
				if (a[nx][ny] == 0 && check[nx][ny] == false)
				{
					a[nx][ny] = a[x][y] + 1;
					/*if (nx == x2 && ny == y2)
					{
						break;
					}*/
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
				}
			}
		}
	}
}

int main(void)
{
	int num;
	cin >> num;
	while (num--)
	{
		
		cin >> len;
		
		cin >> c >> d;
		
		cin >> x2 >> y2;
		bfs(c, d);
		cout << a[x2][y2] << '\n';
		memset(a, 0, sizeof(a));
		memset(check, false, sizeof(check));
	}
	return 0;
}