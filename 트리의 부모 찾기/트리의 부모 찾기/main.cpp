//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N = 0;	//����� ����
//
//typedef struct node {
//	int element;		//�ڽ��� ������ ���� �����ϱ� ���� �������
//	int parents_node;	//�θ����� ������ ���� �����ϱ����� �ɹ�����
//	vector <node*> connected_ND; //�ڽŰ� ����� ������ �����ϱ����� �ɹ�����
//}ND;
//
//bool cmp(node* a, node* b)
//{
//	return a->element > b->element ? true : false;
//}
//
//void SetParentNode(int parentNode, ND* curNode)
//{
//	node tempNode;	//curNode�� �����Ͽ� ����� tempNode
//	curNode->parents_node = parentNode;
//	tempNode = *curNode;
//
//	//�������� connected_ND���� parentNode�� ������Ų��
//	for (int i = 0; i < tempNode.connected_ND.size(); i++)
//	{
//
//		if (tempNode.connected_ND[i]->element == parentNode)
//			tempNode.connected_ND.erase(tempNode.connected_ND.begin() + i);
//	}
//
//	while (tempNode.connected_ND.size() != 0)
//	{
//		SetParentNode(tempNode.element, tempNode.connected_ND.back());
//		tempNode.connected_ND.pop_back();
//	}
//}
//
//int main(void)
//{
//	int element1 = 0;
//	int element2 = 0;
//
//	vector<node*> nodes;
//
//	scanf("%d", &N);
//
//	//Init����(���ο� ��带 N�� ����)
//	for (int i = 1; i <= N; i++)
//	{
//		ND* newnode = new ND;
//		newnode->element = i;
//
//		nodes.push_back(newnode);
//	}
//
//	//����� �������� �� ������ connectednode�� ����
//	for (int i = 0; i < N - 1; ++i)
//	{
//		scanf("%d", &element1);
//		scanf("%d", &element2);
//		node* temp1 = NULL;
//		node* temp2 = NULL;
//		for (auto& iter : nodes)
//		{
//			if (iter->element == element1)
//			{
//				temp1 = iter;
//			}
//
//			if (iter->element == element2)
//			{
//				temp2 = iter;
//			}
//		}
//
//		temp1->connected_ND.push_back(temp2);
//		temp2->connected_ND.push_back(temp1);
//	}
//
//	//������� connectedNode�� ������������ ��������
//	for (auto* iter : nodes)
//	{
//		sort(iter->connected_ND.begin(), iter->connected_ND.end(), cmp);
//	}
//
//	//������� parent��带 ��������
//	SetParentNode(0, nodes[0]);
//
//	sort(nodes.begin(), nodes.end(), cmp);
//
//	for (int i = N - 2; i >= 0; i--)
//	{
//		printf(" %d ", nodes[i]->parents_node);
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		delete nodes[i];
//	}
//	return 0;
//}
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//typedef struct node {
//	int element;
//	int parent;
//	vector<node*> desNodes;
//}ND;
//
//int N;
//node* nodes[100000] = { NULL };
//
//bool cmp(node* a, node* b)
//{
//	return a->element > b->element ? true : false;
//}
//
//int main(void)
//{
//	int element1;
//	int element2;
//	queue<node*> answer;
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		if (nodes[i] == NULL)
//			nodes[i] = new node;
//
//		nodes[i]->element = i + 1;
//		nodes[i]->parent = 0;
//	}
//
//	for (int i = 0; i < N - 1; i++)
//	{
//		cin >> element1;
//		cin >> element2;
//
//		if (nodes[element1 - 1]->element == 1 || nodes[element1 - 1]->parent != 0)
//		{
//			nodes[element2 - 1]->parent = nodes[element1 - 1]->element;
//			nodes[element1 - 1]->desNodes.push_back(nodes[element2 - 1]);
//		}
//
//		else
//		{
//			nodes[element1 - 1]->parent = nodes[element2 - 1]->element;
//			nodes[element2 - 1]->desNodes.push_back(nodes[element1 - 1]);
//		}
//	}
//
//	for (int i = 1; i < N; i++)
//	{
//		printf("%d", nodes[i]->parent);
//	}
//
//	/*for (int i=0; i<N; i++)
//	{
//			sort(nodes[i]->desNodes.begin(), nodes[i]->desNodes.end(), cmp);
//	}*/
//
//	//answer.push(nodes[0]);
//	//while (answer.size() != 0)
//	//{
//	//	node* temp = answer.front();
//	//	answer.pop();
//
//	//	if (temp->element == 1)
//	//	{
//	//		while (!temp->desNodes.empty())
//	//		{
//	//			answer.push(temp->desNodes.back());
//	//			temp->desNodes.pop_back();
//	//		}
//	//	}
//
//	//	else
//	//	{
//	//		printf("%d\n", temp->parent);
//	//		
//	//		while (!temp->desNodes.empty())
//	//		{
//	//			answer.push(temp->desNodes.back());
//	//			temp->desNodes.pop_back();
//	//		}
//	//	}
//	//}
//
//	for (int i = 0; i < N; i++)
//	{
//		delete nodes[i];
//	}
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std;

bool visit[100000] = { 0, };
int N;
int parent[100000] = { 0, };
vector<vector<int>> nodes;

int main(void)
{
	queue<int> q;
	ios::sync_with_stdio(true);

	scanf("%d", &N);

	nodes.resize(N);
	for (int i = 0; i < N - 1; i++)
	{
		int element1;
		int element2;

		scanf("%d", &element1);
		scanf("%d", &element2);

		nodes[element1 - 1].push_back(element2);
		nodes[element2 - 1].push_back(element1);

	}

	q.push(1);

	while (!q.empty())
	{
		int temp = q.front();
		int descen = 0;
		q.pop();

		visit[temp - 1] = true;

		while (!nodes[temp - 1].empty())
		{
			descen = nodes[temp - 1].back();
			if (visit[descen - 1] != true) {
				q.push(descen);
				parent[descen-1] = temp;
			}
			nodes[temp - 1].pop_back();
		}
	}

	for (int i = 1; i <N; i++)
	{
		printf("%d\n", parent[i]);
	}

	return 0;
}