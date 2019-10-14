#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<set>
using namespace std;

unordered_map<int, int> score_gap;

int solution(int k, vector<int>score) {
	int answer = 0;
	int pre_iter = 0;
	int num = 0;
	set<int> temp;
	vector<int> cmp;
	for (auto& iter : score)
	{
		if (pre_iter == 0)
			pre_iter = iter;

		else {
			num = pre_iter - iter;
			pre_iter = iter;

			if (!(score_gap.insert(pair<int, int>(num, 1)).second))
				score_gap[num]++;
		}
	}

	for (auto& iter : score_gap) {
		if (iter.second >= k)
			cmp.push_back(iter.first);
	}

	pre_iter = 0;

	for (auto& iter : score)
	{
		if (pre_iter == 0)
			pre_iter = iter;

		else {
			num = pre_iter - iter;
			
			for (auto& iter2 : cmp) {
				if (num == iter2) {
					temp.insert(iter);
					temp.insert(pre_iter);
					break;
				}
			}
			pre_iter = iter;
		}
	}

	return answer = score.size() - temp.size();
}

int main(void)
{
	int k = 2;
	vector<int> score;
	score.push_back(1300000000);
	score.push_back(700000000);
	score.push_back(668239490);
	score.push_back(618239490);
	score.push_back(568239490);
	score.push_back(568239486);
	score.push_back(518239486);
	score.push_back(157658638);
	score.push_back(157658634);
	score.push_back(100000000);
	score.push_back(100);
	cout << solution(k,score) << endl;
	return 0;
}