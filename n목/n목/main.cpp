#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int h, int w, int n, vector<string>board)
{
	int answer = 0;
	int count;
	int temp_x;
	int temp_y;
	//아래
	for (int x = 0; x < w; x++) {
		for (int y = 0; y <= h - n; y++) {
			temp_x = x;
			temp_y = y;

			if (temp_y - 1 >= 0 && board[temp_y - 1][temp_x] == '1')
				continue;
			
			count = 1;
			//현재위치가 1이면 while을 돌기 시작
			if (board[temp_y][temp_x] == '1') {
				while (true) {
					if (temp_y + 1 >= h)
						break;
					//아래로 내려가며 '1'이면 카운트 증가
					if (board[++temp_y][temp_x] == '1')
						count++;
					//'1'이 아니라면 break로 다음 위치를 확인
					else
						break;
				}
				//count가 n이라면 answer을 1증가
				if (count == n) {
					answer++;
				}
			}
		}
	}

	//오른
	for (int x = 0; x <= w - n; x++) {
		for (int y = 0; y < h; y++) {
			temp_x = x;
			temp_y = y;

			if (temp_x - 1 >= 0 && board[temp_y][temp_x - 1] == '1')
				continue;

			count = 1;
			//현재위치가 1이면 while을 돌기 시작
			if (board[temp_y][temp_x] == '1') {
				while (true) {
					if (temp_x + 1 >= w)
						break;
					//오른쪽으로 가며 '1'이면 카운트 증가
					if (board[temp_y][++temp_x] == '1')
						count++;
					//'1'이 아니라면 break로 다음 위치를 확인
					else
						break;
				}
				//count가 n이라면 answer을 1증가
				if (count == n) {
					answer++;
				}
			}
		}
	}

	//오른쪽 아래
	for (int x = 0; x < w - (n - 1); x++) {
		for (int y = 0; y < h - (n - 1); y++) {
			temp_x = x;
			temp_y = y;

			if (temp_x - 1 >= 0 && temp_y - 1 >= 0 && board[temp_y - 1][temp_x - 1] == '1')
				continue;

			count = 1;
			//현재위치가 1이면 while을 돌기 시작
			if (board[temp_y][temp_x] == '1') {
				while (true) {
					if (temp_x + 1 >= w || temp_y + 1 >= h)
						break;
					//오른쪽아래로 가며 '1'이면 카운트 증가
					if (board[++temp_y][++temp_x] == '1')
						count++;
					//'1'이 아니라면 break로 다음 위치를 확인
					else
						break;
				}
				//count가 n이라면 answer을 1증가
				if (count == n) {
					answer++;
				}
			}
		}
	}

	//오른쪽 위
	for (int x = 0; x < w - (n - 1); x++) {
		for (int y = 0; y < h ; y++) {
			temp_x = x;
			temp_y = y;

			if (temp_x - 1 >= 0 && temp_y + 1 < h && board[temp_y + 1][temp_x - 1] == '1')
				continue;

			count = 1;
			//현재위치가 1이면 while을 돌기 시작
			if (board[temp_y][temp_x] == '1') {
				while (true) {
					if (temp_x + 1 >= w || temp_y - 1 < 0)
						break;
					//오른쪽위로 가며 '1'이면 카운트 증가
					if (board[--temp_y][++temp_x] == '1')
						count++;
					//'1'이 아니라면 break로 다음 위치를 확인
					else
						break;
				}
				//count가 n이라면 answer을 1증가
				if (count == n) {
					answer++;
				}
			}
		}
	}
	return answer;
}

int main(void)
{
	int h = 7;
	int w = 9;
	int n = 4;
	string temp;
	vector<string> board;

	temp = "111100000";
	board.push_back(temp);
	temp = "000010011";
	board.push_back(temp);
	temp = "111100011";
	board.push_back(temp);
	temp = "111110011";
	board.push_back(temp);
	temp = "111100011";
	board.push_back(temp);
	temp = "111100010";
	board.push_back(temp);
	temp = "111100000";
	board.push_back(temp);

	cout << solution(h, w, n, board) << endl;

	return 0;
}