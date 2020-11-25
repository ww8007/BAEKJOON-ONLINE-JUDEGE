//백준 : 숨바꼭질3 13549번 bfs+deque or bfs + queue(2)
//
//문제
//
//수빈이는 동생과 숨바꼭질을 하고 있다.수빈이는 현재 점 N(0 ≤ N ≤ 100, 000)에 있고, 동생은 점 K(0 ≤ K ≤ 100, 000)에 있다.
//수빈이는 걷거나 순간이동을 할 수 있다.만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X - 1 또는 X + 1로 이동하게 된다.
//순간이동을 하는 경우에는 0초 후에 2 * X의 위치로 이동하게 된다.
//수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
//
//
//입력
//
//첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다.N과 K는 정수이다.
//5 17
//
//출력
//
//수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
//2
//
//풀이
//
//이번 숨바꼭질은 순간이동이 시간을 소요하지 않게 된다. 그러므로 우선순위 큐에
//데이터를 삽입하거나 아니면 큐를 두개 이용하여서 첫번째 큐는 순간이동 두번 째 큐는 +1 -1을 처리하도록 
//한다.
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