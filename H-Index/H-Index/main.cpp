#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//int solution(vector<int> citations) {
//	int answer = 0;
//	int index = citations.size() / 2, size = citations.size();
//	int count;
//	sort(citations.begin(), citations.end(),less<int>());
//
//	for(int i=0; i<size; i++){
//		if (size - index < citations[index])
//			index--;
//
//		else if (size - index > citations[index])
//			index++;
//
//		else if (size - index == citations[index]) {
//			answer = citations[index];
//			break;
//		}
//
//	}
//
//	return answer;
//}

int solution(vector<int> citations) {
	int index = 0;
	sort(citations.begin(), citations.end(), greater<int>());
	while (index < citations.size()) {
		if (citations[index] <= index)break;
		index++;
	}
	return index;
}

int main(void) {
	vector<int> citations;
	citations.push_back(3);
	citations.push_back(0);
	citations.push_back(6);
	citations.push_back(1);
	citations.push_back(5);

	cout << solution(citations);
	return 0;
}