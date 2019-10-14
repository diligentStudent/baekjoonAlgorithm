#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef struct element {
	int costTime;
	int mileage;
	bool connection = false;

}E;

E elements[1000][1000];

bool cmp(pair<int, int>p1, pair<int, int>p2) {
	if (p1.first == p2.first)
		return p1.second > p2.second ? true : false;
	else
		return p1.first > p2.first ? false : true;
}

vector<int> reculsive(int k, int index, int size, int totalTime, int totalmil, E element[1000][1000]) {
	int Time = totalTime;
	int mileage = totalmil;
	vector<int> answer;
	vector<int> temp_answer;
	for (int i = 0; i < size; i++) {
		if (element[index][i].connection == false)
			continue;

		else {
			Time += element[index][i].costTime;
			mileage += element[index][i].mileage;

			if (i == k - 1) {
				answer.clear();
				answer.push_back(Time);
				answer.push_back(mileage);
				return answer;

			}
					   
			element[index][i].connection = false;
			element[i][index].connection = false;
			if (answer.empty()) {
				answer = reculsive(k, i, size, Time, mileage, element);
			}

			else {
				temp_answer = reculsive(k, i, size, Time, mileage, element);
				if (!temp_answer.empty()) {
					if (answer[0] > temp_answer[0]) {
						answer = temp_answer;
						temp_answer.clear();
					}

					else if (answer[0] < temp_answer[0])
						continue;

					else if (answer[0] == temp_answer[0]) {
						if (answer[1] < temp_answer[1]) {
							answer = temp_answer;
							temp_answer.clear();
						}
					}
				}
			}
			element[i][index].connection = true;
			element[index][i].connection = true;
		}

	}

	return answer;
}



vector<int> solution(int n, int k, vector<vector<int>>paths)

{
	vector<int> answer;
	vector<int> temp_answer;
	vector<pair<int, int>> answers;

	//이차원 element생성

	for (auto& iter : paths) {
		if (iter[1] == 1)
			continue;

		elements[iter[0] - 1][iter[1] - 1].connection = true;
		elements[iter[0] - 1][iter[1] - 1].costTime = iter[2];
		elements[iter[0] - 1][iter[1] - 1].mileage = iter[3];

		if (iter[0] == 1)
			continue;

		elements[iter[1] - 1][iter[0] - 1].connection = true;
		elements[iter[1] - 1][iter[0] - 1].costTime = iter[2];
		elements[iter[1] - 1][iter[0] - 1].mileage = iter[3];
	}



	for (int i = 0; i < n; i++) {

		if (elements[0][i].connection == false)
			continue;

		else {
			temp_answer = reculsive(k, i, n, elements[0][i].costTime, elements[0][i].mileage, elements);
			
			if (!temp_answer.empty())
			{
				pair<int, int> p = make_pair(temp_answer.front(), temp_answer.back());
				answers.push_back(p);
			}
		}

	}



	sort(answers.begin(), answers.end(), cmp);

	answer.push_back(answers.front().first);
	answer.push_back(answers.front().second);

	return answer;

}



int main(void)

{
	vector<int> input;
	vector<int> answer;
	vector<vector<int>> paths;

	int n = 5;

	int k = 4;

	input.push_back(1);
	input.push_back(5);
	input.push_back(1);
	input.push_back(1);
	paths.push_back(input);
	input.clear();

	input.push_back(1);
	input.push_back(2);
	input.push_back(4);
	input.push_back(3);
	paths.push_back(input);
	input.clear();

	input.push_back(1);
	input.push_back(3);
	input.push_back(3);
	input.push_back(2);
	paths.push_back(input);
	input.clear();

	input.push_back(2);
	input.push_back(5);
	input.push_back(2);
	input.push_back(1);
	paths.push_back(input);
	input.clear();

	input.push_back(2);
	input.push_back(4);
	input.push_back(2);
	input.push_back(3);
	paths.push_back(input);
	input.clear();

	input.push_back(3);
	input.push_back(4);
	input.push_back(2);
	input.push_back(2);
	paths.push_back(input);
	input.clear();

	answer = solution(n, k, paths);

	cout << answer.front() << ',' << answer.back();

	return 0;

}