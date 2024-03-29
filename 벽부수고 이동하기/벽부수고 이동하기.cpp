// 벽부수고 이동하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

string mat[1000];
priority_queue<int, vector<int>, less<int> > pq;
int mov_x[3] = { 0, 1,-1 };
int mov_y[3] = { 1, 0, 0 };
int visit[1000][1000] = {0,};
int N;//y input값
int M;//x input값

void Min_dist(int x, int y, int total, int count)//total 총움직인 횟수 count 1을 방문한 횟수
{
	if (x < 0 || x >= M || y >= N || visit[x][y] == 1)
		return;

	if (mat[y][x] == '1')
		count++;

	if (count >= 2)
		return;

	if (x == M - 1, y == N - 1) {
		pq.push(total);
	}

	total += 1;

	for (int i = 0; i < 3; i++) {
		visit[x][y] = 1;//이전에 방문한 매트릭스는 방문하지 않기위해
		Min_dist(x + mov_x[i], y + mov_y[i], total, count);
		visit[x][y] = 0;//이후에 방문한 매트릭스에서 돌아오면 방문하지 않았다고 표시를 해주어야함
	}
}

int main(void) {

	int total_mov = 1; //총 움직인 횟수

	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++) {
		cin >> mat[i];
	}

	Min_dist(0, 0, total_mov, 0);

	if (pq.empty()) {
		cout << -1 << endl;
	}
	else {
		cout << pq.top() << endl;
	}
	
	return 0;
}