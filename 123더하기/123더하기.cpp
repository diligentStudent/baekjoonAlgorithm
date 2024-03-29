#include "pch.h"
#include <iostream>

using namespace std;

int Num_Container[10] = {0,};//숫자를 저장할 변수

int Calcul_Add_Count(int num)
{
	if (num < 0)
	{
		return 0;
	}

	else if (num == 1)
	{
		Num_Container[num] = 1;
	}

	else if (num == 2)
	{
		Num_Container[num] = 2;
	}

	else if (num == 3)
	{
		Num_Container[num] = 4;
	}

	else
	{
		if (Num_Container[num] == 0)
		{
			if (Num_Container[num - 1] == 0)
			{
				Calcul_Add_Count(num - 1);
			}

			if (Num_Container[num - 2] == 0)
			{
				Calcul_Add_Count(num - 2);
			}

			if (Num_Container[num - 3] == 0)
			{
				Calcul_Add_Count(num - 3);
			}

			Num_Container[num] = Num_Container[num - 1] + Num_Container[num - 2] + Num_Container[num - 3];
		}
	}
	return Num_Container[num];
}

int main()
{
	int Count = 0;//입력할 횟수
	int num = 0;//숫자를 입력받을 변수

	cout << "입력할 횟수를 입력하세요: ";
	cin >> Count;

	while (Count)
	{
		while (num <= 0 || num >= 11) {
			cout << "숫자 입력: ";
			cin >> num;
		}

		cout << Calcul_Add_Count(num) << endl;

		Count -= 1;
		num = 0;
	}

	return 0;
}

