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
	//�Ʒ�
	for (int x = 0; x < w; x++) {
		for (int y = 0; y <= h - n; y++) {
			temp_x = x;
			temp_y = y;

			if (temp_y - 1 >= 0 && board[temp_y - 1][temp_x] == '1')
				continue;
			
			count = 1;
			//������ġ�� 1�̸� while�� ���� ����
			if (board[temp_y][temp_x] == '1') {
				while (true) {
					if (temp_y + 1 >= h)
						break;
					//�Ʒ��� �������� '1'�̸� ī��Ʈ ����
					if (board[++temp_y][temp_x] == '1')
						count++;
					//'1'�� �ƴ϶�� break�� ���� ��ġ�� Ȯ��
					else
						break;
				}
				//count�� n�̶�� answer�� 1����
				if (count == n) {
					answer++;
				}
			}
		}
	}

	//����
	for (int x = 0; x <= w - n; x++) {
		for (int y = 0; y < h; y++) {
			temp_x = x;
			temp_y = y;

			if (temp_x - 1 >= 0 && board[temp_y][temp_x - 1] == '1')
				continue;

			count = 1;
			//������ġ�� 1�̸� while�� ���� ����
			if (board[temp_y][temp_x] == '1') {
				while (true) {
					if (temp_x + 1 >= w)
						break;
					//���������� ���� '1'�̸� ī��Ʈ ����
					if (board[temp_y][++temp_x] == '1')
						count++;
					//'1'�� �ƴ϶�� break�� ���� ��ġ�� Ȯ��
					else
						break;
				}
				//count�� n�̶�� answer�� 1����
				if (count == n) {
					answer++;
				}
			}
		}
	}

	//������ �Ʒ�
	for (int x = 0; x < w - (n - 1); x++) {
		for (int y = 0; y < h - (n - 1); y++) {
			temp_x = x;
			temp_y = y;

			if (temp_x - 1 >= 0 && temp_y - 1 >= 0 && board[temp_y - 1][temp_x - 1] == '1')
				continue;

			count = 1;
			//������ġ�� 1�̸� while�� ���� ����
			if (board[temp_y][temp_x] == '1') {
				while (true) {
					if (temp_x + 1 >= w || temp_y + 1 >= h)
						break;
					//�����ʾƷ��� ���� '1'�̸� ī��Ʈ ����
					if (board[++temp_y][++temp_x] == '1')
						count++;
					//'1'�� �ƴ϶�� break�� ���� ��ġ�� Ȯ��
					else
						break;
				}
				//count�� n�̶�� answer�� 1����
				if (count == n) {
					answer++;
				}
			}
		}
	}

	//������ ��
	for (int x = 0; x < w - (n - 1); x++) {
		for (int y = 0; y < h ; y++) {
			temp_x = x;
			temp_y = y;

			if (temp_x - 1 >= 0 && temp_y + 1 < h && board[temp_y + 1][temp_x - 1] == '1')
				continue;

			count = 1;
			//������ġ�� 1�̸� while�� ���� ����
			if (board[temp_y][temp_x] == '1') {
				while (true) {
					if (temp_x + 1 >= w || temp_y - 1 < 0)
						break;
					//���������� ���� '1'�̸� ī��Ʈ ����
					if (board[--temp_y][++temp_x] == '1')
						count++;
					//'1'�� �ƴ϶�� break�� ���� ��ġ�� Ȯ��
					else
						break;
				}
				//count�� n�̶�� answer�� 1����
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