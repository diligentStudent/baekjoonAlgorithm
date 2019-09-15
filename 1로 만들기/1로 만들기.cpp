#include "pch.h"
#include <iostream>

using namespace std;

int count_Storage[1000000] = { 0, };

int calcul_func(int num) {

	if (num <= 1)
		return 0;

	if (count_Storage[num] != 0)
		return count_Storage[num];

	if (num % 3 == 0) {
		if (count_Storage[num - 1] < count_Storage[num / 3]) {
			return count_Storage[num] = count_Storage[num - 1] + 1;
		}
		return count_Storage[num] = count_Storage[num / 3] + 1;
	}


	if (num % 2 == 0) {
		if (count_Storage[num - 1] < count_Storage[num / 2]) {
			return count_Storage[num] = count_Storage[num - 1] + 1;
		}
		return count_Storage[num] = count_Storage[num / 2] + 1;
	}


	return count_Storage[num] = count_Storage[num - 1] + 1;
}

int main()
{

	int input_Num = 0;

	for (int i = 1; i <= 1000000; i++) {
		count_Storage[i] = calcul_func(i);
	}

	cin >> input_Num;
	cout << count_Storage[input_Num];
}

