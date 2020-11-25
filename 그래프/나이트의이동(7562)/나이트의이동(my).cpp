//백준 : 나이트의이동(bfs) 7562번
//
//문제 
//
//체스판 위에 한 나이트가 놓여져 있다.나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다.
//나이트가 이동하려고 하는 칸이 주어진다.나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까 ?
//
//입력
//
//입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.
//각 테스트 케이스는 세 줄로 이루어져 있다.첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다.
//체스판의 크기는 l × l이다.체스판의 각 칸은 두 수의 쌍{ 0, ..., l - 1 } ×{ 0, ..., l - 1 }로 나타낼 수 있다.
//둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.
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
//출력
//
//각 테스트 케이스마다 나이트가 몇 번만에 이동할 수 있는지 출력한다.
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