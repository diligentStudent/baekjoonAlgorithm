//mat[5][5] �� (0,0)
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
			if (mat[cur_y][cur_x].visit[0] != 1) {//�湮�� ���Ѱ��
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
			
			else {//�湮�Ѱ��
				if (cur_y > 0)
					cur_y -= 1;

				else {//���� cur_y�� 0���� �۰ų� ������ ���ѱ�
					it++;
					continue;
				}
			}
		}

		else if (*it == 'D') {
			if (mat[cur_y][cur_x].visit[1] != 1) {//�湮�� ���Ѱ��
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

			else {//�湮�Ѱ��
				if (cur_y < 10)
					cur_y += 1;

				else {
					it++;
					continue;
				}
			}
		}

		else if (*it == 'R') {
			if (mat[cur_y][cur_x].visit[2] != 1) {//�湮�� ���Ѱ��
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

			else {//�湮�Ѱ��
				if (cur_x < 10)
					cur_x += 1;

				else {
					it++;
					continue;
				}
			}
		}


		else if (*it == 'L') {
			if (mat[cur_y][cur_x].visit[3] != 1) {//�湮�� ���Ѱ��
				mat[cur_y][cur_x].visit[3] = 1;

				if (cur_x > 0) {//�湮�� �������� cur_x�� 0���� ���ų��۾Ƽ� �������°��
					cur_x -= 1;
					mov_count += 1;
				}

				else {
					it++;
					continue;
				}
			}

			else {//�湮�Ѱ��
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