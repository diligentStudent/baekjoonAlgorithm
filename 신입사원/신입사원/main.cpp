#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int T;//�׽�Ʈ ����
int N;//������ ��

vector<int> score[2][100000];
//vector<int> interview[100000];
vector<int> winner[100000];
vector<int> loser;

int main(void)
{
	cin >> T;
	int resume_score, inter_score, app, me;
	int temp, size;

	while (T) {
		cin >> N;
		for (app = 0; app < N; app++) {
			cin >> resume_score;
			cin >> inter_score;

			score[0][app].push_back(resume_score);
			score[1][app].push_back(inter_score);
		}

		//���� �����ɻ� ������ ���Ͽ� �ڽź��� ���� ������� winner�� �־��ش�
		for (me = 0; me < N; me++) {
			for (app = 0; app < N; app++) {
				if (me == app)
					continue;

				if (score[0][me] > score[0][app])
					winner[me].push_back(app);
			}
		}

		//�ڽź��� ���� ������ ���� ������ ���Ͽ� ���������� ���ٸ� loser�� �־��ش�
		for (me = 0; me < N; me++) {
			size = winner[me].size();
			for (app = 0; app < size; app++) {
				temp = winner[me].back();
				winner[me].pop_back();
				if (score[1][me] > score[1][temp]) {
					loser.push_back(me);
					break;
				}
			}
		}

		//�ִ� �ο��� ��ü�ο����� loser�� ����ִ� �������� ���� ���ذ�
		cout << N - loser.size() << endl;

		for (int i = 0; i < N; i++) {
			score[0][i].clear();
			score[1][i].clear();
		}

		loser.clear();
		T--;
	}
	return 0;
}