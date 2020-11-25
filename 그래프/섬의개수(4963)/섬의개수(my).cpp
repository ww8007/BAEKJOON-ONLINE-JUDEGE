//백준 : 섬의 개수 4963번(bfs, dfs)
//
//정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다.섬의 개수를 세는 프로그램을 작성하시오.
//한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.
//두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다.지도는 바다로 둘러싸여 있으며, 지도 밖으로 나갈 수 없다.
//
//입력 
//
//입력은 여러 개의 테스트 케이스로 이루어져 있다.
//각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다.w와 h는 50보다 작거나 같은 양의 정수이다.
//둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.
//입력의 마지막 줄에는 0이 두 개 주어진다.
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
//출력
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