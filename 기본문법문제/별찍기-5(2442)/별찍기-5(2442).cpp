//백준 : 별찍기-5 2442번 for문 문제

//문제
//첫째 줄에는 별 1개, 둘째 줄에는 별 3개, ..., N번째 줄에는 별 2×N - 1개를 찍는 문제
//
//별은 가운데를 기준으로 대칭이어야 한다.
//
//입력
//첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.
//
//출력
//첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.
//
//예제 입력 1
//5
//예제 출력 1
//*
//***
//*****
//*******
//*********

// 느낀점 : 인터넷에 다른 사람들의 코드를 찾아보니 파이썬으로 2줄 안에
// 끝난 코드를 보며 효율성이 너무 떨어진다는 것을 느꼈다.
// 앞으로 코딩을 할 때 효율성 면도 생각을 하면서 해야겠다.
#include <iostream>

using namespace std;

int main(void)
{
	int num;
	cin >> num;
	int num2 = num * 2 - 1;
	char* a = new char[num2];
	int cnt = 0;
	for (int i = 0; i < num2; i++)
	{
		a[i] = ' ';
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = num-1; j <= num-1 + cnt; j++) // 가운데에서 끝까지
		{
			a[j] = '*';
		}
		for (int k = num-1; k >= num-1 - cnt; k--) // 가운데에서 처음까지
		{
			a[k] = '*';
		}
		cnt++;
		for (int m = 0; m < num-1 + cnt; m++) // 출력부분
		{
			cout << a[m];
		}
		if (i != num2 - 1) // 맨마지막 줄이 아니면 줄바꿈 시킴
		{
			cout << '\n';
		}
		
	}
	return 0;
}

