#include "pch.h"
#include <iostream>

using namespace std;

int row;
int total_cell[500][500] = { 0, };//최대 움직일수 있는 카운트를 저장하는 이차원 배열
int bamboo_amount[500][500] = { 0, };//대나무 양을 나타내는 이차원배열
int x_move[4] = { -1,1,0,0 };//x축이동
int y_move[4] = { 0,0,-1,1 };//y축이동

int max(int param1, int param2) {
	if (param1 >= param2)
		return param1;
	else
		return param2;
}

int Move_Count(int y, int x) {

	if (total_cell[y][x])
		return total_cell[y][x];

	total_cell[y][x] = 1;
	
	for (int i = 0; i < 4; i++) {//상하좌우로 움직이는 코드
		int my = y + y_move[i];
		int mx = x + x_move[i];

		if (my<0 || my>row || mx<0 || mx>row)//my<0 세로첫번째줄이거나 my>row 세로끝줄이거나 mx<0가로 첫번째줄이거나 mx>row 가로 맨끝줄이면 다시
			continue;

		if (bamboo_amount[y][x] >= bamboo_amount[my][mx])//기존 위치가 움직이려는 위치보다 대나무 양이 많으면 continue;
			continue;

		total_cell[y][x] = max(total_cell[y][x], Move_Count(my, mx) + 1);//기존위치의 최대 움직일수 있는 카운트가 더높다면 유지 아니라면 업데이트함
	}

	return total_cell[y][x];
}

int main()
{
	cin >> row;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			cin >> bamboo_amount[i][j];
		}
	}

	int ans = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++) {
			ans = max(ans, Move_Count(i, j));
		}
	}
	cout << ans << endl;
	return 0;
}
