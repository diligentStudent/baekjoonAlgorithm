#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;//여학생수
int M;//남학생수
int K;//인턴쉽학생수

int main(void)
{
	bool manhigh = true;
	int doubleman = 0;
	
	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &K);

	for (int i = 0; i < K; i++)
	{
		doubleman = M * 2;
		//남학생의 두배보다 여학생이 많을경우 여학생 1명을 대회에 내보내고 같거나 적을경우 남학생 1명을 대회에 내보냄
		if (doubleman < N)
			N -= 1;
		else
			M -= 1;
	}
	//남학생의 두배보다 여학생의 수가 많을경우
	manhigh = N >= M*2 ? true : false;

	//남학생의 숫자만큼 팀이 만들어짐
	if (manhigh)
		printf("%d", M);

	//아닐경우 여학우의 절반만큼 팀이 만들어짐
	else
	{
		printf("%d", N / 2);
	}

	return 0;
}