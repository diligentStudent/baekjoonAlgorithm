//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//#include <set>
//
//using namespace std;

//int N;//ȸ�� ����
//int answer = 0;//��
//vector< pair<int, int> > conferenceInfo;//���۽ð��� ����ð��� �� vector
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
//		int start;//���۽ð�
//		int end;//����ð�
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
//map<int, int> samestartConference;//ȸ�ǽ��۽ð��� ���°�ε����� �ִ���
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
//		//�ߺ��Ȱ��������� �����ø��� �ƴϸ� ���� �־���
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
//int N;//ȸ�� ����
//int answer = 0;//��
//vector< pair<int, int> > conferenceInfo;//���۽ð��� ����ð��� �� vector
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
//		int start;//���۽ð�
//		int end;//����ð�
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

//int N;//ȸ�� ����
//int answer = 0;//��
//vector< pair<int, int> > conferenceInfo;//���۽ð��� ����ð��� �� vector
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
//		int start;//���۽ð�
//		int end;//����ð�
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
//map<int, int> samestartConference;//ȸ�ǽ��۽ð��� ���°�ε����� �ִ���
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
//		//�ߺ��Ȱ��������� �����ø��� �ƴϸ� ���� �־���
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

int N;//ȸ�� ����
int answer = 0;//��
vector< pair<int, int> > conferenceInfo;//���۽ð��� ����ð��� �� vector

bool cmp(pair<int, int> a, pair<int, int> b)
{
	//����ð��� �ٸ���� ����ð��� ���Ͽ� ������������
	if (a.second != b.second)
		return a.second < b.second ? true : false;
	//������� ���۽ð��� ���Ͽ� ������������
	return a.first < b.first ? true : false;
}

int main(void)
{
	scanf("%d", &N);
	conferenceInfo.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		int start;//���۽ð�
		int end;//����ð�

		scanf("%d", &start);
		scanf("%d", &end);

		conferenceInfo[i] = { start, end };
	}
	//vector����
	sort(conferenceInfo.begin(), conferenceInfo.end(), cmp);

	answer = 0;//�����
	int end = 0;//�ֱ� ȸ���� ���� �ð�

	for (int i = 1; i <= N; i++)
	{
		//����ȸ�� ���۽ð��� �̹� �������� continue
		if (conferenceInfo[i].first < end)
			continue;

		//����ȸ�� ���۽ð��� �ֱ�ȸ���� ����ð��� ���ų� �������
		else
		{
			end = conferenceInfo[i].second;
			answer++;
		}

	}

	printf("%d\n", answer);
	return 0;
}