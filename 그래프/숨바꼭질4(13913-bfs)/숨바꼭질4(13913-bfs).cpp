//백준 : 숨바꼭질4 13913번
//
//문제 
//
//수빈이는 동생과 숨바꼭질을 하고 있다.수빈이는 현재 점 N(0 ≤ N ≤ 100, 000)에 있고, 동생은 점 K(0 ≤ K ≤ 100, 000)에 있다.수빈이는 걷거나 순간이동을 할 수 있다.
//만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X - 1 또는 X + 1로 이동하게 된다.순간이동을 하는 경우에는 1초 후에 2 * X의 위치로 이동하게 된다.0
//수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
//
//입력 
//
//첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다.N과 K는 정수이다.
//5 17
//
//출력 
//
//첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
//둘째 줄에 어떻게 이동해야 하는지 공백으로 구분해 출력한다.
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