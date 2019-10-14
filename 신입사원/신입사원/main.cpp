#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int T;//테스트 갯수
int N;//지원자 수

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

		//먼저 서류심사 점수를 비교하여 자신보다 높은 사람들을 winner에 넣어준다
		for (me = 0; me < N; me++) {
			for (app = 0; app < N; app++) {
				if (me == app)
					continue;

				if (score[0][me] > score[0][app])
					winner[me].push_back(app);
			}
		}

		//자신보다 높은 사람들과 면접 점수를 비교하여 면접점수도 놓다면 loser에 넣어준다
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

		//최대 인원은 전체인원에서 loser에 들어있는 면접자의 수를 빼준것
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