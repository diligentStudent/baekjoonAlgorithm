#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

int mat[1001][1001] = { 0, };//인접행렬을 통한 노드간 간선표시
int visit_dfs[1001] = { 0, };//dfs시 방문한 노드 표시
int visit_bfs[1001] = { 0, };//bfs시 방문한 노드 표시
int node_Count; //정점 갯수
int line_Count; //간선 갯수
int start_node; //시작 정점

queue<int> temp_Storage;

void dfs(int num) {

	if (visit_dfs[num] == 1)
		return;

	cout << num << ' ';

	visit_dfs[num] = 1;

	for (int i = 0; i <= node_Count; i++) {
		if (visit_dfs[i] == 1 || mat[num][i] == 0)
			continue;

		dfs(i);
	}
}

void bfs(int num) {
	queue<int> q;
	q.push(num);
	visit_bfs[num] = 1;

	while(!q.empty()) {
		num = q.front();
		cout << q.front() << ' ';
		q.pop();
		for (int i = 1; i <= node_Count; i++) {
			if (visit_bfs[i] == 1 || mat[num][i] == 0)
				continue;
			q.push(i);
			visit_bfs[i] = 1;
		}
	}
}

int main() {

	int x, y; //간선 입력을 받을 변수

	cin >> node_Count;
	cin >> line_Count;
	cin >> start_node;

	for (int i = 0; i < line_Count; i++) {
		cin >> x >> y;

		mat[x][y] = 1;
		mat[y][x] = 1;		
	}
	
	dfs(start_node);
	cout << endl;
	bfs(start_node);
}