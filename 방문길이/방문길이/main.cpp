//mat[5][5] 는 (0,0)
#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
	//int x;
	//int y;
	int visit[4] = { 0, }; //UP,DOWN,LEFT,RIGHT
}nd;

int mov_count = 0;
int cur_x = 5, cur_y = 5;
int index = 0;

int main(void) {
	int temp_x;
	int temp_y;
	string input;
	nd mat[11][11];

	cin >> input;

	string::iterator it = input.begin();
	while (it != input.end()) {

		if (*it == 'U') {
			if (mat[cur_y][cur_x].visit[0] != 1) {//방문을 안한경우
				mat[cur_y][cur_x].visit[0] = 1;
				
				if (cur_y > 0) {
					cur_y -= 1;
					mov_count += 1;
				}

				else {
					it++;
					continue;
				}
			}
			
			else {//방문한경우
				if (cur_y > 0)
					cur_y -= 1;

				else {//현재 cur_y가 0보다 작거나 같으면 걍넘김
					it++;
					continue;
				}
			}
		}

		else if (*it == 'D') {
			if (mat[cur_y][cur_x].visit[1] != 1) {//방문을 안한경우
				mat[cur_y][cur_x].visit[1] = 1;

				if (cur_y < 10) {
					cur_y += 1;
					mov_count += 1;
				}

				else {
					it++;
					continue;
				}
			}

			else {//방문한경우
				if (cur_y < 10)
					cur_y += 1;

				else {
					it++;
					continue;
				}
			}
		}

		else if (*it == 'R') {
			if (mat[cur_y][cur_x].visit[2] != 1) {//방문을 안한경우
				mat[cur_y][cur_x].visit[2] = 1;

				if (cur_x < 10) {
					cur_x += 1;
					mov_count += 1;
				}

				else {
					it++;
					continue;
				}
			}

			else {//방문한경우
				if (cur_x < 10)
					cur_x += 1;

				else {
					it++;
					continue;
				}
			}
		}


		else if (*it == 'L') {
			if (mat[cur_y][cur_x].visit[3] != 1) {//방문을 안한경우
				mat[cur_y][cur_x].visit[3] = 1;

				if (cur_x > 0) {//방문을 안햇지만 cur_x가 0보다 같거나작아서 갈수없는경우
					cur_x -= 1;
					mov_count += 1;
				}

				else {
					it++;
					continue;
				}
			}

			else {//방문한경우
				if (cur_x > 0)
					cur_x -= 1;

				else {
					it++;
					continue;
				}
			}
		}

		it++;
	}

	cout << mov_count << endl;

	return 0;
}