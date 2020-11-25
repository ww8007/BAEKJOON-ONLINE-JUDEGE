#include <iostream>
#include <stack>

using namespace std;

bool check[10];
int a[10][10];
int n = 10;
// 기본적 dfs 탐색 재귀 이용
void dfs(int x)
{
	check[x] = true;
	for (int i = 0; i < n; i++)
	{
		if (a[x][i] == 1 && check[i] == false)
			dfs(i);
	}
}

int main(void)
{
	return 0;
}