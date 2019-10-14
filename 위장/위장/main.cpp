#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0, size = 0, res = 0, count = 0;
	vector<int> vres;
	unordered_map<string, int> type;
	size = clothes.size();

	for (int i = 0; i < size; i++) {
		if (!(type.insert(pair<string,int>(clothes[i][1], 1)).second)) {
			++type[clothes[i][1]];
		}
	}

	auto iter =	type.begin();

	while (iter != type.end()) {
		if (iter == type.begin()) {
			vres.push_back(iter->second);
		}

		else {
			for (int i = 0; i < count; i++) {
				res += vres[i] * iter->second;
			}
			res += iter->second;
			vres.push_back(res);
			res = 0;
		}

		iter++;
		count++;
		
	}

	while (!vres.empty())
	{
		answer += vres.back();
		vres.pop_back();
	}
	return answer;
}