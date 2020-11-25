//���� : ���ٲ��� 1697�� bfs
//����
//
//�����̴� ������ ���ٲ����� �ϰ� �ִ�.�����̴� ���� �� N(0 �� N �� 100, 000)�� �ְ�, ������ �� K(0 �� K �� 100, 000)�� �ִ�.
//�����̴� �Ȱų� �����̵��� �� �� �ִ�.����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X - 1 �Ǵ� X + 1�� �̵��ϰ� �ȴ�.�����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2 * X�� ��ġ�� �̵��ϰ� �ȴ�.
//�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է� 
//
//ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����.N�� K�� �����̴�.
//5 17
//���
//
//�����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.
//4
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
bool check[1000000];
queue<int> q;
int dist[1000000];


int main(void)
{
	cin >> n >> k;
	check[n] = true;
	dist[n] = 0;
	q.push(n);
	while (!q.empty())
	{
		int pt = q.front();
		q.pop();
		if (pt - 1 >= 0)
		{
			if (check[pt - 1] == false)
			{
				q.push(pt - 1);
				check[pt - 1] = true;
				dist[pt - 1] = dist[pt] + 1;
			}
		}
		if (pt + 1 < 1000000)
		{
			if (check[pt + 1] == false)
			{
				q.push(pt + 1);
				check[pt + 1] = true;
				dist[pt + 1] = dist[pt] + 1;
			}
		}
		if (pt * 2 < 1000000)
		{
			if (check[pt*2] == false)
			{
				q.push(pt * 2);
				check[pt * 2] = true;
				dist[pt * 2] = dist[pt] + 1;
			}
		}
		
		
	}
	cout << dist[k] << '\n';
	return 0;
}