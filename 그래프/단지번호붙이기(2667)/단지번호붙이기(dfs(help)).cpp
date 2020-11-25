//���� 2667 ���� ��ȣ ���̱� 
//<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�. 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����.
//ö���� �� ������ ������ ����� ������ ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�.
//���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�.�밢���� ���� �ִ� ���� ����� ���� �ƴϴ�. 
//<�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�.������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//���� �Է� 
//7
//0110100
//0110101
//1110101
//0000111
//0100000
//0111110
//0111000
//���� ���
//3
//7
//8
//9
//dfs�� Ǯ��� (���� ����)
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "stdio.h"
#include <cstdio>
using namespace std;

int a[26][26];
int d[26][26];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int num;
int ans[26 * 26];
void dfs(int x, int y, int cnt)
{
	d[x][y] = cnt;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < num && ny >= 0 && ny < num)
		{
			if (a[nx][ny] == 1 && d[nx][ny] == 0)
				dfs(nx, ny, cnt);
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
			scanf("%1d", &a[i][j]);
			d[i][j] = 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (a[i][j] == 1 && d[i][j] == 0)
				dfs(i, j, ++cnt);
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