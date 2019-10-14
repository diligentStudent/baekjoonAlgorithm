#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int solution(vector<int> target, vector<vector<int>>positions)
{
	int answer = 0;
	int radius = 0;
	float area;
	int arrow_area;
	int x, y;
	int size;
	int count;
	vector<float> extend;
	vector<float> arrow_pos;
	
	for (auto& iter : target)
	{
		radius += iter;
		area = sqrt(pow(radius, 2));
		extend.push_back(area);
	}
	
	for (auto& iter : positions) {
		y = iter.back();
		iter.pop_back();
		x = iter.back();
		iter.pop_back();

		area = sqrt(pow(y, 2) + pow(x, 2));
		arrow_pos.push_back(area);
	}

	
	for (auto& arrow_iter : arrow_pos) {
		count = 0;
		for (auto& target_iter : extend){
			if (arrow_iter <= target_iter) {
				answer += 10 - ((count) * 2);
				break;
			}
			count++;
		}
	}

	return answer;
}

int main(void)
{
	vector<int> target;
	vector<int> position;
	vector<vector<int>> positions;

	target.push_back(2);
	target.push_back(3);
	target.push_back(4);
	target.push_back(3);
	target.push_back(2);
	position.push_back(0);
	position.push_back(0);
	positions.push_back(position);
	position.clear();
	position.push_back(0);
	position.push_back(1);
	positions.push_back(position);
	position.clear();
	position.push_back(1);
	position.push_back(1);
	positions.push_back(position);
	position.clear();
	position.push_back(-3);
	position.push_back(5);
	positions.push_back(position);
	position.clear();
	position.push_back(7);
	position.push_back(5);
	positions.push_back(position);
	position.clear();
	position.push_back(10);
	position.push_back(0);
	positions.push_back(position);
	position.clear();
	position.push_back(-15);
	position.push_back(22);
	positions.push_back(position);
	position.clear();
	position.push_back(-6);
	position.push_back(-5);
	positions.push_back(position);
	position.clear();
	position.push_back(3);
	position.push_back(3);
	positions.push_back(position);
	position.clear(); 
	position.push_back(5);
	position.push_back(-5);
	positions.push_back(position);
	position.clear();

	cout << solution(target, positions);

	return 0;
}