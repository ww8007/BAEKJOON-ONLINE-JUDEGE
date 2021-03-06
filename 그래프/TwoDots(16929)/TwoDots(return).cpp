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
//이 풀이는 전 풀이와 달리 시작점에서 다시 시작점으로 돌아오면 루프가 존재한다는 가정하에 
//푸는 알고리즘이라 볼 수 있다. 
#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
char a[51][51];
bool check[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1, 0,0 };
bool dfs(int x, int y, int px, int py, char color)
{
	if (check[x][y])
		return true;
	check[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m)
		{
			if (!(nx == px && ny == py))
			{
				if (a[nx][ny] == color)
				{
					if (dfs(nx, ny, x, y, color))
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
			bool ok = dfs(i, j, -1, -1, a[i][j]);
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