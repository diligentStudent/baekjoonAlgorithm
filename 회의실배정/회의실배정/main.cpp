//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//#include <set>
//
//using namespace std;

//int N;//회의 갯수
//int answer = 0;//답
//vector< pair<int, int> > conferenceInfo;//시작시간과 종료시간이 들어갈 vector
//set<int> elements;
//bool cmp(pair<int, int> a, pair<int, int> b)
//{
//	if(a.first != b.first)
//		return a.first < b.first ? true : false;
//	
//	return a.second < b.second ? true : false;
//}
//
//int main(void)
//{
//	scanf("%d", &N);
//	conferenceInfo.resize(N + 1);
//	for (int i = 1; i <= N; i++)
//	{
//		int start;//시작시간
//		int end;//종료시간
//
//		scanf("%d", &start);
//		scanf("%d", &end);
//
//		conferenceInfo[i] = { start, end };
//	}
//
//	sort(conferenceInfo.begin(), conferenceInfo.end(), cmp);
//
//	for (int i = 1; i <= N-answer ; i++)
//	{
//		int count = 1;
//		int end = conferenceInfo[i].second;
//			for (int j = i + 1; j <= N; j++)
//			{
//				if (end > conferenceInfo[j].first)
//					continue;
//				else
//				{
//					if (end <= conferenceInfo[j].second) {
//						end = conferenceInfo[j].second;
//						count++;
//					}
//				}
//			}
//		if (answer < count)
//			answer = count;
//	}
//	
//	printf("%d\n", answer);
//	return 0;
//}
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//int N;
//int answer = 0;
//vector<pair<int, int>> conferenceInfo;
//map<int, int> samestartConference;//회의시작시간과 몇번째인덱스에 있는지
//
//bool cmp(pair<int, int> a, pair<int, int> b)
//{
//	if (a.first != b.first)
//		return a.first < b.first ? true : false;
//
//	return a.second < b.second ? true : false;
//}
//
//int main(void)
//{
//	scanf("%d", &N);
//
//	int start;
//	int end;
//
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &start);
//		scanf("%d", &end);
//
//		//중복된것이있으면 값만올리고 아니면 새로 넣어줌
//		if (samestartConference.find(start) == samestartConference.end())
//		{
//			samestartConference.insert(make_pair(start, 1));
//		}
//
//		else
//		{
//			samestartConference[start]++;
//		}
//
//		conferenceInfo.push_back( make_pair(start, end));
//	}
//
//	sort(conferenceInfo.begin(), conferenceInfo.end(), cmp);
//
//	for (int i = 0; i < N; i++)
//	{
//		int count = 1;
//		int index = 0;
//		int end = conferenceInfo[i].second;
//		for (int j = i + 1; j < N; j++)
//		{		
//			if (end <= conferenceInfo[j].first)
//			{
//				if (end == conferenceInfo[j].second)
//				{
//					index++;
//					count++;
//				}
//				else if (end < conferenceInfo[j].second) {
//					end = conferenceInfo[j].second;
//					count++;
//					index++;
//				}
//			}
//			else if (end > conferenceInfo[j].first)
//			{
//				j += samestartConference[conferenceInfo[j].first] - 1 - index;
//				index = 0;
//			}
//		}
//		if (answer < count)
//			answer = count;
//	}
//
//	printf("%d", answer);
//	return 0;
//}
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N;//회의 갯수
//int answer = 0;//답
//vector< pair<int, int> > conferenceInfo;//시작시간과 종료시간이 들어갈 vector
//
//bool cmp(pair<int, int> a, pair<int, int> b)
//{
//	/*if(a.first != b.first)
//		return a.first < b.first ? true : false;
//	*/
//	return a.second < b.second ? true : false;
//}
//
//int main(void)
//{
//	scanf("%d", &N);
//	conferenceInfo.resize(N + 1);
//	for (int i = 1; i <= N; i++)
//	{
//		int start;//시작시간
//		int end;//종료시간
//
//		scanf("%d", &start);
//		scanf("%d", &end);
//
//		conferenceInfo[i] = { start, end };
//	}
//
//	sort(conferenceInfo.begin(), conferenceInfo.end(), cmp);
//
//	int count = 1;
//	int end = conferenceInfo[1].second;
//
//	for (int i = 1; i <= N; i++)
//	{
//		if (conferenceInfo[i].first < end)
//			continue;
//		else
//		{
//			end = conferenceInfo[i].second;
//			count++;
//
//		}
//
//	}
//
//	printf("%d\n", answer);
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//#include <set>
//
//using namespace std;

//int N;//회의 갯수
//int answer = 0;//답
//vector< pair<int, int> > conferenceInfo;//시작시간과 종료시간이 들어갈 vector
//set<int> elements;
//bool cmp(pair<int, int> a, pair<int, int> b)
//{
//	if(a.first != b.first)
//		return a.first < b.first ? true : false;
//	
//	return a.second < b.second ? true : false;
//}
//
//int main(void)
//{
//	scanf("%d", &N);
//	conferenceInfo.resize(N + 1);
//	for (int i = 1; i <= N; i++)
//	{
//		int start;//시작시간
//		int end;//종료시간
//
//		scanf("%d", &start);
//		scanf("%d", &end);
//
//		conferenceInfo[i] = { start, end };
//	}
//
//	sort(conferenceInfo.begin(), conferenceInfo.end(), cmp);
//
//	for (int i = 1; i <= N-answer ; i++)
//	{
//		int count = 1;
//		int end = conferenceInfo[i].second;
//			for (int j = i + 1; j <= N; j++)
//			{
//				if (end > conferenceInfo[j].first)
//					continue;
//				else
//				{
//					if (end <= conferenceInfo[j].second) {
//						end = conferenceInfo[j].second;
//						count++;
//					}
//				}
//			}
//		if (answer < count)
//			answer = count;
//	}
//	
//	printf("%d\n", answer);
//	return 0;
//}
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//int N;
//int answer = 0;
//vector<pair<int, int>> conferenceInfo;
//map<int, int> samestartConference;//회의시작시간과 몇번째인덱스에 있는지
//
//bool cmp(pair<int, int> a, pair<int, int> b)
//{
//	if (a.first != b.first)
//		return a.first < b.first ? true : false;
//
//	return a.second < b.second ? true : false;
//}
//
//int main(void)
//{
//	scanf("%d", &N);
//
//	int start;
//	int end;
//
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &start);
//		scanf("%d", &end);
//
//		//중복된것이있으면 값만올리고 아니면 새로 넣어줌
//		if (samestartConference.find(start) == samestartConference.end())
//		{
//			samestartConference.insert(make_pair(start, 1));
//		}
//
//		else
//		{
//			samestartConference[start]++;
//		}
//
//		conferenceInfo.push_back( make_pair(start, end));
//	}
//
//	sort(conferenceInfo.begin(), conferenceInfo.end(), cmp);
//
//	for (int i = 0; i < N; i++)
//	{
//		int count = 1;
//		int index = 0;
//		int end = conferenceInfo[i].second;
//		for (int j = i + 1; j < N; j++)
//		{		
//			if (end <= conferenceInfo[j].first)
//			{
//				if (end == conferenceInfo[j].second)
//				{
//					index++;
//					count++;
//				}
//				else if (end < conferenceInfo[j].second) {
//					end = conferenceInfo[j].second;
//					count++;
//					index++;
//				}
//			}
//			else if (end > conferenceInfo[j].first)
//			{
//				j += samestartConference[conferenceInfo[j].first] - 1 - index;
//				index = 0;
//			}
//		}
//		if (answer < count)
//			answer = count;
//	}
//
//	printf("%d", answer);
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;//회의 갯수
int answer = 0;//답
vector< pair<int, int> > conferenceInfo;//시작시간과 종료시간이 들어갈 vector

bool cmp(pair<int, int> a, pair<int, int> b)
{
	//종료시간이 다를경우 종료시간을 비교하여 오름차순으로
	if (a.second != b.second)
		return a.second < b.second ? true : false;
	//같은경우 시작시간을 비교하여 오름차순으로
	return a.first < b.first ? true : false;
}

int main(void)
{
	scanf("%d", &N);
	conferenceInfo.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		int start;//시작시간
		int end;//종료시간

		scanf("%d", &start);
		scanf("%d", &end);

		conferenceInfo[i] = { start, end };
	}
	//vector정렬
	sort(conferenceInfo.begin(), conferenceInfo.end(), cmp);

	answer = 0;//답출력
	int end = 0;//최근 회의의 종료 시간

	for (int i = 1; i <= N; i++)
	{
		//다음회의 시작시간이 이미 지났으면 continue
		if (conferenceInfo[i].first < end)
			continue;

		//다음회의 시작시간이 최근회의의 종료시간과 같거나 느릴경우
		else
		{
			end = conferenceInfo[i].second;
			answer++;
		}

	}

	printf("%d\n", answer);
	return 0;
}