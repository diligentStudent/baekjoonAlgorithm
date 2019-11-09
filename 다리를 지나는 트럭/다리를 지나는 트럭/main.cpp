#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int curweight = 0;//�ٸ��� �ö� Ʈ������ ��Ż ����
	int nexttruck = 0;//�������� �ö󰡾��� Ʈ�� �ѹ�
	int acrossed_truck = 0;//������ Ʈ���� �������� ���������� Ʈ���� ��ȣ
	vector<int> truck_pos;//��Ʈ���� ��ġ

	for (int i = 0; i < truck_weights.size(); i++) {
		truck_pos.push_back(0);
	}

	while (true)
	{
		//������ Ʈ������ �ٰǳʸ� ����
		if (acrossed_truck == truck_weights.size())
			break;

		//���� ���������� Ʈ���� �ٸ����ڶ��� ������ ���� weight�� �� ��Ʈ���� ���Ը� ���� ��¥�� �����Ͽ� �ǳ������̱⶧��
		if (truck_pos[acrossed_truck] == bridge_length) {
			curweight -= truck_weights[acrossed_truck];
		}

		//���� Ʈ���� ���Ը� �ߵ����ִٸ� ���� Ʈ���� �߰���
		if (weight >= curweight + truck_weights[nexttruck] && truck_weights.size() > nexttruck)
		{
			curweight += truck_weights[nexttruck];
			nexttruck += 1;
		}

		//�ö��ִ� Ʈ������ �������� �ϳ�������������
		for (int i = acrossed_truck; i < nexttruck; i++) {
			truck_pos[i]++;
		}

		//�������� Ʈ���� �ٸ��� �ǳԴ��� üũ
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