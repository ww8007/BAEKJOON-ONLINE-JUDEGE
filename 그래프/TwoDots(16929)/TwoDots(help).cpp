//���� : Two Dots 16929��

//����
//
//Two Dots�� Playdots, Inc.���� ���� �����̴�.������ ���� �ܰ�� ũ�Ⱑ N��M�� ������ ������ ����ȴ�.
//������ ĭ�� ���� ĥ���� ���� �ϳ��� �ִ�.�� ������ �ٽ��� ���� ������ �̷���� ����Ŭ�� ã�� ���̴�.
//������ ���� �����ǿ��� ���� �� �ִ� ����Ŭ�� �����̴�.
//�� k�� d1, d2, ..., dk�� �̷���� ����Ŭ�� ���Ǵ� �Ʒ��� ����.
//��� k���� ���� ���� �ٸ���.
//k�� 4���� ũ�ų� ����.
//��� ���� ���� ����.
//��� 1 �� i �� k - 1�� ���ؼ�, di�� di + 1�� �����ϴ�.��, dk�� d1�� �����ؾ� �Ѵ�.�� ���� �����ϴٴ� ���� ������ ���� ����ִ� ĭ�� ���� �����Ѵٴ� �ǹ��̴�.
//�������� ���°� �־����� ��, ����Ŭ�� �����ϴ��� �ƴ��� ���غ���.
//
//�Է�
//
//ù° �ٿ� �������� ũ�� N, M�� �־�����.��° �ٺ��� N���� �ٿ� �������� ���°� �־�����.
//�������� ��� ������ ������ �ְ�, �������� ���´� ���� ���� �ǹ��Ѵ�.���� ���� ���ĺ� �빮�� �� �����̴�.
//
//3 4
//AAAA
//ABCA
//AAAA
//
//���
//
//����Ŭ�� �����ϴ� ��쿡�� "Yes", ���� ��쿡�� "No"�� ����Ѵ�.
//
//Yes
//Ǯ��
//
//�Ÿ��� ����ϸ鼭 ó�� ���������� �Ÿ��� ī��Ʈ�� 4�̻� ���̳��� �̴� ����
//���� �ִ� �� �̹Ƿ� ���� ã�Ҵ� ����ȴ�.
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