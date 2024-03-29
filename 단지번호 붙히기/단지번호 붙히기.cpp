#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <string>

using namespace std;

string mat[25];
int visit[25][25] = { 0, }; //방문했는지 표시하기위한 2차원 배열

//왼쪽과 아래쪽으로 아파트가 있는지 확인하기위한 변수x,y

int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,-1,1 };

int mat_Size = 0; //N
int apt_cnt = 0; //아파트를 카운트 하는 변수
int aptComplex_cnt = 0; //아파트단지 카운트하는 변수

void Count_complex(int y_num, int x_num) {
	if (y_num < 0 || x_num < 0 || y_num >= mat_Size || x_num >= mat_Size || visit[y_num][x_num] == 1 || mat[y_num][x_num] == '0') {

		return;

	}

	visit[y_num][x_num] = 1;
	apt_cnt++;
	
	for (int i = 0; i < 4; i++) {
		Count_complex(y_num + y[i], x_num + x[i]);
	}
}



int main(void) {
	priority_queue<int, vector<int>, greater<int> >pq;
	cin >> mat_Size;

	for (int i = 0; i < mat_Size; i++) {
		cin >> mat[i];
	}

	for (int y = 0; y < mat_Size; y++) {

		for (int x = 0; x < mat_Size; x++) {

			Count_complex(y, x);

			if (apt_cnt != 0) {

				aptComplex_cnt += 1;
				pq.push(apt_cnt);
				apt_cnt = 0;

			}

		}

	}

	cout << aptComplex_cnt << endl;

	while (!pq.empty()) {

		cout << pq.top() << endl;

		pq.pop();

	}

	return 0;

}

