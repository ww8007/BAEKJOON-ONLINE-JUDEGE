//백준 : 미로 탐색 (bfs) 2178번
//N×M크기의 배열로 표현되는 미로가 있다.
//
//1	0	1	1	1	1
//1	0	1	0	1	0
//1	0	1	0	1	1
//1	1	1	0	1	1
//미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.이러한 미로가 주어졌을 때, (1, 1)에서 출발하여(N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.]
//한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
//위의 예에서는 15칸을 지나야(N, M)의 위치로 이동할 수 있다.칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
//
//입력 

//첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다.다음 N개의 줄에는 M개의 정수로 미로가 주어진다.각각의 수들은 붙어서 입력으로 주어진다.
//4 6
//101111
//101010
//101011
//111011
//
//출력

//첫째 줄에 지나야 하는 최소의 칸 수를 출력한다.항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
//15

//풀이 bfs를 이용함 (도움받음)
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