#include <iostream>
#include <stack>

using namespace std;

bool check[10];
int a[10][10];
int n = 10;
// �⺻�� dfs Ž�� ��� �̿�
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