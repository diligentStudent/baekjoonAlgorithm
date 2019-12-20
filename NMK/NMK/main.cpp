#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;//원소의 개수, 최대부분증가수열, 최대부분감소수열

vector<int> elements;//N개의원소를 담을 vector

int main(void)
{
	
	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &K);

	for (int i = 0; i < N; i++)
	{
		elements.push_back(i + 1);
	}

	if (M + K - 1 > N || N > M * K)
	{
		printf("%d", -1);
		return 0;
	}

	int offset = 0;
	int count = N;

	while (1)
	{
		M = M - 1;//남은 구간
		count = count - K;//남은 elements

		if (M == 0) {
			reverse(elements.begin() + offset * K, elements.end());
			break;
		}

		if (count / M == 0 || count <= 0)//limit = offset * K + 1
		{
			int remainder = offset * K + 1 + K - 1 - (M - count);
			reverse(elements.begin() + offset * K , elements.begin()+remainder);
			break;
		}

		else {
			reverse(elements.begin() + offset * K, elements.begin() + (offset + 1) * K);
			offset++;
		
		}
	}

	for (auto& iter : elements)
	{
		printf("%d ", iter);
	}
	return 0;
}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int N, M, K;
//	cin >> N >> M >> K;
//
//	bool b = true;
//
//	int limit = 1;
//	int count = N;
//
//	if (N<M + K - 1 || N>N * K) {
//		b = false;
//		printf("-1");
//	}
//
//	if (b)
//	{
//		while (1)
//		{
//			M = M - 1;
//			count = count - K;
//			if (M == 0) {
//				for (int i = N; i >= limit; i--) printf("%d", i);
//				break;
//			}
//			if (count / M == 0 || count <= 0) {
//				for (int i = limit + K - 1 - (M - count); i >=limit; i--)
//					printf("%d ", i);
//				for (int i = limit + K - (M - count); i <= N; i++)
//					printf("%d ", i);
//				break;
//			}
//			else {
//				for (int i = limit + K - 1; i >= limit; i--)
//					printf("%d ", i);
//				limit = limit + K;
//			}
//
//		}
//	}
//	printf("\n");
//	return 0;
//}