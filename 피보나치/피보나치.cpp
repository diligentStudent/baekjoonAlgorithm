//#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int fibonacci_Count_Storage[2][41] = { 0, };
int fibonacci(int n);

int main()
{
	int input_Count = 0, input_Num = 0;

	for (int i = 0; i <= 40; i++) {
		if (i == 0) {
			fibonacci_Count_Storage[0][i] = 1;
			fibonacci_Count_Storage[1][i] = 0;
		}
		else if (i == 1) {
			fibonacci_Count_Storage[0][i] = 0;
			fibonacci_Count_Storage[1][i] = 1;
		}

		else {
			fibonacci_Count_Storage[0][i] = fibonacci_Count_Storage[0][i - 1] + fibonacci_Count_Storage[0][i - 2];
			fibonacci_Count_Storage[1][i] = fibonacci_Count_Storage[1][i - 1] + fibonacci_Count_Storage[1][i - 2];
		}
	}

	cin >> input_Count;

	while (input_Count) {
		cin >> input_Num;
		cout << fibonacci_Count_Storage[0][input_Num] << ' ' << fibonacci_Count_Storage[1][input_Num] << endl;
		input_Count--;
	}
}

int fibonacci(int n) {
	if (n == 0) {
		printf("0");
		return 0;
	}
	else if (n == 1) {
		printf("1");
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
