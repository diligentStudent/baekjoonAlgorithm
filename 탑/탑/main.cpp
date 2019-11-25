#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	int size = heights.size();

	for (int i = 0; i < size; i++) {

		for (int j = i; j >= 0; j--) {

			if (heights[i] < heights[j])
			{
				answer.push_back(j + 1);
				break;
			}

			if (j == 0) {
				answer.push_back(0);
			}
		}
	}

	return answer;
}