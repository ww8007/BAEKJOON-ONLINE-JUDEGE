//���� : ���ٲ���4 13913��
//
//���� 
//
//�����̴� ������ ���ٲ����� �ϰ� �ִ�.�����̴� ���� �� N(0 �� N �� 100, 000)�� �ְ�, ������ �� K(0 �� K �� 100, 000)�� �ִ�.�����̴� �Ȱų� �����̵��� �� �� �ִ�.
//����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X - 1 �Ǵ� X + 1�� �̵��ϰ� �ȴ�.�����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2 * X�� ��ġ�� �̵��ϰ� �ȴ�.0
//�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է� 
//
//ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����.N�� K�� �����̴�.
//5 17
//
//��� 
//
//ù° �ٿ� �����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.
//��° �ٿ� ��� �̵��ؾ� �ϴ��� �������� ������ ����Ѵ�.
//4
//5 10 9 18 17
#include <iostream>
#include <queue>
#include <stack>
#define myMax 1000000
using namespace std;

int dist[myMax+1];
bool check[myMax+1];
int from[myMax+1];


int main(void)
{
	int n, k;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n >> k;
	queue <int> q;

	q.push(n);
	check[n] = true;
	dist[n] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x - 1 >= 0)
		{
			if (check[x - 1] == false)
			{
				q.push(x - 1);
				check[x - 1] = true;
				dist[x - 1] = dist[x] + 1;
				from[x - 1] = x;
			}
		}
		if (x + 1 < myMax)
		{
			if (check[x +1] == false)
			{
				q.push(x + 1);
				check[x + 1] = true;
				dist[x + 1] = dist[x] + 1;
				from[x + 1] = x;
			}
		}
		if (x *2 < myMax)
		{
			if (check[x * 2] == false)
			{
				q.push(x * 2);
				check[x * 2] = true;
				dist[x * 2] = dist[x] + 1;
				from[x * 2] = x;
			}
		}
	}
	cout << dist[k] << '\n';
	stack<int> s;
	for (int i = k; i != n; i=from[i])
	{
		s.push(i);
	}
	s.push(n);
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';
	return 0;
}