#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a ? true : false;
}
string solution(vector<int> numbers) {
	int size;
	string answer = "";
	string temp_ans;
	vector<string> temp_storage;
	
	size = numbers.size();
	for (int i = 0; i < size; i++) {
		temp_ans = to_string(numbers.back());
		numbers.pop_back();
		temp_storage.push_back(temp_ans);
	}
	
	sort(temp_storage.begin(), temp_storage.end(), cmp);

	for (string str : temp_storage) {
		answer += str;
	}
	if (answer[0] == '0')
		return "0";

	return answer;
}

void main()
{
	vector<int> numbers;
	numbers.push_back(3);
	numbers.push_back(30);
	numbers.push_back(34);
	numbers.push_back(5);
	numbers.push_back(9);

	cout << solution(numbers) << endl;
}