//���� : ���ٲ���3 13549�� bfs+deque or bfs + queue(2)
//
//����
//
//�����̴� ������ ���ٲ����� �ϰ� �ִ�.�����̴� ���� �� N(0 �� N �� 100, 000)�� �ְ�, ������ �� K(0 �� K �� 100, 000)�� �ִ�.
//�����̴� �Ȱų� �����̵��� �� �� �ִ�.����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X - 1 �Ǵ� X + 1�� �̵��ϰ� �ȴ�.
//�����̵��� �ϴ� ��쿡�� 0�� �Ŀ� 2 * X�� ��ġ�� �̵��ϰ� �ȴ�.
//�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//
//�Է�
//
//ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����.N�� K�� �����̴�.
//5 17
//
//���
//
//�����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.
//2
//
//Ǯ��
//
//�̹� ���ٲ����� �����̵��� �ð��� �ҿ����� �ʰ� �ȴ�. �׷��Ƿ� �켱���� ť��
//�����͸� �����ϰų� �ƴϸ� ť�� �ΰ� �̿��Ͽ��� ù��° ť�� �����̵� �ι� ° ť�� +1 -1�� ó���ϵ��� 
//�Ѵ�.
#include <iostream>
#include <queue>
#include <deque>
#define MAX 1000001
using namespace std;

bool check[MAX];
int dist[MAX];

int main(void)
{
	int n1, n2;
	cin >> n1 >> n2;

	check[n1] = true;
	deque <int> q;
	queue<int> next_q;
	q.push_back(n1);
	dist[n1] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop_front();
		if (x * 2 <= 1000000)
		{
			if (check[x * 2] == false)
			{
				dist[x * 2] = dist[x];
				check[x * 2] = true;
				q.push_front(x * 2);
			}
		}
		if (x + 1 <= 1000000)
		{
			if (check[x + 1] == false)
			{
				next_q.push(x + 1);
				dist[x + 1] = dist[x] + 1;
				check[x + 1] = true;
				q.push_back(x + 1);
			}
		}
		if (x - 1 >= 0)
		{
			if (check[x -1] == false)
			{
				dist[x -1 ] = dist[x] + 1;
				check[x -1] = true;
				q.push_back(x - 1);
			}
		}
		
	}
	cout << dist[n2] << '\n';
}