#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int curweight = 0;//다리에 올라간 트럭들의 토탈 무게
	int nexttruck = 0;//다음번에 올라가야할 트럭 넘버
	int acrossed_truck = 0;//지나간 트럭의 숫자이자 지나가야할 트럭의 번호
	vector<int> truck_pos;//각트럭의 위치

	for (int i = 0; i < truck_weights.size(); i++) {
		truck_pos.push_back(0);
	}

	while (true)
	{
		//마지막 트럭까지 다건너면 종료
		if (acrossed_truck == truck_weights.size())
			break;

		//현제 지나가야할 트럭이 다리끝자락에 있으면 현제 weight에 서 그트럭의 무게를 빼줌 어짜피 다음턴에 건널차례이기때문
		if (truck_pos[acrossed_truck] == bridge_length) {
			curweight -= truck_weights[acrossed_truck];
		}

		//아직 트럭의 무게를 견딜수있다면 다음 트럭을 추가함
		if (weight >= curweight + truck_weights[nexttruck] && truck_weights.size() > nexttruck)
		{
			curweight += truck_weights[nexttruck];
			nexttruck += 1;
		}

		//올라가있는 트럭들의 포지션을 하나씩증가시켜줌
		for (int i = acrossed_truck; i < nexttruck; i++) {
			truck_pos[i]++;
		}

		//지나야할 트럭이 다리를 건넜는지 체크
		if (truck_pos[acrossed_truck] > bridge_length) {
			acrossed_truck++;
		}
		answer++;
	}

	return answer;
}

int main(void)
{
	int bridge_len = 100;
	int weight = 100;
	int answer;
	vector<int> truck_weight;
	truck_weight.push_back(10);
	/*truck_weight.push_back(10);
	truck_weight.push_back(10);
	truck_weight.push_back(10);
	truck_weight.push_back(10);
	truck_weight.push_back(10);
	truck_weight.push_back(10);
	truck_weight.push_back(10);
	truck_weight.push_back(10);
	truck_weight.push_back(10);*/

	answer = solution(bridge_len, weight, truck_weight);
	cout << "answer : "<<answer;
	return 0;
}