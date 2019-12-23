#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;//테스트 케이스개수
int N;//지원자 숫자

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first)
		return a.first > b.first ? true : false;


	return a.second > b.second ? true : false;
}

int main(void)
{
	int test1;
	int test2;
	int answer;
	vector<pair<int, int>> appliences;

	cin >> T;

	while (1)
	{
		if (T == 0)
			break;

		cin >> N;
		answer = N;
		appliences.resize(N);

		for (int i = 0; i < N; i++)
		{
			cin >> test1;
			cin >> test2;
			appliences[i] = { test1, test2 };
		}

		sort(appliences.begin(), appliences.end(), cmp);

		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
				if (appliences[i].second > appliences[j].second)
				{
					answer--;
					break;
				}
		}

		cout << "answer: " << answer << endl;

		T--;
	}

	return 0;
}