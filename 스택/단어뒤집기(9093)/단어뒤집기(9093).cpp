// ���� 9093�� �ܾ� ������

// ���� 
//
//������ �־����� ��, �ܾ ��� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//��, �ܾ��� ������ �ٲ� �� ����.�ܾ�� ���� ���ĺ����θ� �̷���� �ִ�.
//
//�Է� 
//
//ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, ������ �ϳ� �־�����.�ܾ��� ���̴� �ִ� 20, ������ ���̴� �ִ� 1000�̴�.�ܾ�� �ܾ� ���̿��� ������ �ϳ� �ִ�.
//
//���
//�� �׽�Ʈ ���̽��� ���ؼ�, �Է����� �־��� ������ �ܾ ��� ������ ����Ѵ�.
//
//���� �Է� 1
//2
//I am happy today
//We want to win the first prize
//
//���� ��� 1
//I ma yppah yadot
//eW tnaw ot niw eht tsrif ezirp

// ������ : getline �Լ� ����ϴ� ���� ���� 
//getline(cin, str);
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		string str;
		getline(cin, str);
		str += '\n';
		stack<char> s;
		int mynum = str.size();
		for (int i = 0; i < mynum; i++) 
		{
			if (str[i] == ' ' || str[i] == '\n')
			{
				while (!s.empty())
				{
					cout << s.top();
					s.pop();
				}
				cout << str[i];

			}
			else
			{
				s.push(str[i]);
			}
		}
	}
	return 0;
}


