////트리의 임의의 두점사이의 거리중 가장 긴것을 의미
//#define _CRT_SECURE_NO_WARNINGS
//#include <vector>
//#include <queue>
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//int V;
//vector<bool> visit;
//vector<pair<int, int>> tree[100001];
//
//int dfs(int, int);
//
//int main(void)
//{
//	ios::sync_with_stdio(true);
//	string input;
//	cin >> V;
//	visit.resize(100000);
//
//	for (int i = 0; i <= V; i++)
//	{
//		int count = 0, offset = 0, index = 0, desti = 0, dis = 0;// offset => input의 위치, iㄴndex =>인덱스, desti =>목적지, dis =>거리
//
//		getline(std::cin, input);
//		while (input.size() != 0)
//		{
//			if (input[offset] == '-')
//				break;
//
//			if (offset == 0)
//			{
//				index = atoi(&input[offset]);
//				offset += 2;
//				continue;
//			}
//
//			if (count % 2 == 0)
//			{
//				desti = atoi(&input[offset]);
//				offset += 2;
//				count++;
//				continue;
//			}
//
//			if (count % 2 == 1)
//			{
//				dis = atoi(&input[offset]);
//				tree[index].push_back(make_pair(desti, dis));
//				offset += 2;
//				count++;
//				continue;
//			}
//		}
//	}
//
//	cout << dfs(1, 0);
//
//	return 0;
//}
//
//int dfs(int current, int Maxdis)
//{
//	int max = Maxdis, temp = 0, answer = 0;
//	visit[current] = true;
//
//	for (auto& iter : tree[current])
//	{
//		if (visit[iter.first] != true && iter.second != 0)
//		{
//			max += iter.second;
//			temp = dfs(iter.first, max);
//
//			if (answer < temp)
//			{
//				answer = temp;
//			}
//
//			max -= iter.second;
//		}
//	}
//	if (answer == 0)
//	{
//		return Maxdis;
//	}
//	return answer;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <queue>
//#include <vector>
//#include <string.h>
//using namespace std;
//
//bool visited[100001] = { 0, };
//int V;
//int MAX = 0;
//int diameter = 0;
//int farthestNode = 0;
//vector< pair<int, int>> tree[100001];
//
//void dfs(int, int);
//
//int main(void)
//{
//	int index = 0, desti = 0, dis = 0;
//	scanf("%d", &V);
//
//	for (int i = 0; i < V; i++)
//	{
//		scanf("%d", &index);
//		while (1)
//		{
//			scanf("%d", &desti);
//
//			if (desti == -1)
//				break;
//
//			scanf("%d", &dis);
//
//			tree[index].push_back(make_pair(desti, dis));
//		}
//	}
//
//	dfs(1, 0);
//	memset(visited, false, sizeof(visited));
//	diameter = 0;
//	dfs(farthestNode, 0);
//
//	printf("%d\n", diameter);
//
//	return 0;
//}
//
//void dfs(int node, int cost)
//{
//	if (visited[node])
//		return;
//
//	visited[node] = true;
//
//	//지름 업데이트
//	if (diameter < cost)
//	{
//
//		diameter = cost;
//
//		farthestNode = node;
//	}
//
//	for (int i = 0; i < tree[node].size(); i++)
//
//		dfs(tree[node][i].first, cost + tree[node][i].second);
//}

#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

bool visit[100001] = { 0, };
int V;
vector< pair<int, int>> tree[100001];

int dfs(int, int);
int farnode;
int Max;
int main(void)
{
	int index = 0, desti = 0, dis = 0;
	scanf("%d", &V);

	for (int i = 0; i < V; i++)
	{
		scanf("%d", &index);
		while (1)
		{
			scanf("%d", &desti);

			if (desti == -1)
				break;

			scanf("%d", &dis);

			tree[index].push_back(make_pair(desti, dis));
		}
	}
	
	printf("%d\n", dfs(1, 0));
	printf("farnode : %d\n", farnode);
	memset(visit, false, sizeof(visit));
	printf("%d\n", dfs(farnode, 0));
	return 0;
}

int dfs(int current, int max)
{
	int answer = max, result = 0, maxDis = max;

	visit[current] = true;

	for (int i = 0; i < tree[current].size(); i++)
	{
		if (visit[tree[current][i].first] != true)
		{
			maxDis += tree[current][i].second;
			result = dfs(tree[current][i].first, maxDis);
			if (answer < result)
			{
				if (farnode < tree[current][i].first)
				{
					farnode = tree[current][i].first;
				}

				answer = result;
			}
			maxDis -= tree[current][i].second;
		}
	}
	return answer;
}