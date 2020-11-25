//백준 : Two Dots 16929번

//문제
//
//Two Dots는 Playdots, Inc.에서 만든 게임이다.게임의 기초 단계는 크기가 N×M인 게임판 위에서 진행된다.
//각각의 칸은 색이 칠해진 공이 하나씩 있다.이 게임의 핵심은 같은 색으로 이루어진 사이클을 찾는 것이다.
//다음은 위의 게임판에서 만들 수 있는 사이클의 예시이다.
//점 k개 d1, d2, ..., dk로 이루어진 사이클의 정의는 아래와 같다.
//모든 k개의 점은 서로 다르다.
//k는 4보다 크거나 같다.
//모든 점의 색은 같다.
//모든 1 ≤ i ≤ k - 1에 대해서, di와 di + 1은 인접하다.또, dk와 d1도 인접해야 한다.두 점이 인접하다는 것은 각각의 점이 들어있는 칸이 변을 공유한다는 의미이다.
//게임판의 상태가 주어졌을 때, 사이클이 존재하는지 아닌지 구해보자.
//
//입력
//
//첫째 줄에 게임판의 크기 N, M이 주어진다.둘째 줄부터 N개의 줄에 게임판의 상태가 주어진다.
//게임판은 모두 점으로 가득차 있고, 게임판의 상태는 점의 색을 의미한다.점의 색은 알파벳 대문자 한 글자이다.
//
//3 4
//AAAA
//ABCA
//AAAA
//
//출력
//
//사이클이 존재하는 경우에는 "Yes", 없는 경우에는 "No"를 출력한다.
//
//Yes
//풀이
//
//거리를 계산하면서 처음 시작점과의 거리와 카운트가 4이상 차이나면 이는 같은
//선상에 있는 것 이므로 답을 찾았다 보면된다.
#include <iostream>
#include <cstring>

using namespace std;

int n, m;
char a[51][51];
bool check[51][51];
int dist[51][51];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool dfs(int x, int y, int cnt, char color)
{
	if (check[x][y])
	{
		if (cnt - dist[x][y] >= 4)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	check[x][y] = true;
	dist[x][y] = cnt;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < m)
		{
			if (a[nx][ny] == color)
			{
				if (dfs(nx, ny, cnt + 1, color))
				{
					return true;
				}
			}
				
		}
	}
	return false;
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (check[i][j])
				continue;
			memset(dist, 0, sizeof(dist));
			bool ok = dfs(i, j, 1, a[i][j]);
			if (ok)
			{
				cout << "Yes" << '\n';
				return 0;
			}
		}
	}
	cout << "No" << '\n';
	return 0;
}