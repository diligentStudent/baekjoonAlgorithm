// 소수관련문제.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>

#define MAX pow(2,16)

using namespace std;

vector<int> minority_storage;

void PushMinority() {
	int count;

	for (int i = 1; i < MAX; i++) {

		count = 0;
		for (int j = 2; j < i; j++) {
			//하나라도 나누어떨어지면 소수가 아니기 때문에 탈출하고 다음 숫자를 시도
			if (i%j == 0) {
				count++;
				j = i;
			}
		}

		//나왔을때 count가 0이라면 나누어 떨어지는 수가 없었다는 것이므로 소수라고 할수 있음
		//따라서 vector에 넣어준다
		if (count == 0 && i != 1) {
			minority_storage.push_back(i);
		}
	}
}

void Solution(vector<int>* arr, int num) {
	int temp = num;
	
	vector<int>::iterator it = minority_storage.begin();
	while (1) {
		//temp가 1이 되면 retrun;
		if (temp == 1)
			return;

		//소수로나누어 떨어지면 arr vector에 넣어준다
		if (temp % *it == 0) {
			temp = temp / *it;
			arr->push_back(*it);
			it = minority_storage.begin();
		}
		//나누어 떨어지지 않는 다면 다음 소수를 비교
		else 
			it++;		
	}
}

int main()
{
	int num;
	vector<int> arr;
	PushMinority();

	cin >> num;

	Solution(&arr, num);

	while (!arr.empty())
	{
		cout << arr.back() << endl;
		arr.pop_back();
	}
}