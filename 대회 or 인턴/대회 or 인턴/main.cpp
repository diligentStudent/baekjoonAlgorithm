#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;//���л���
int M;//���л���
int K;//���Ͻ��л���

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
		//���л��� �ι躸�� ���л��� ������� ���л� 1���� ��ȸ�� �������� ���ų� ������� ���л� 1���� ��ȸ�� ������
		if (doubleman < N)
			N -= 1;
		else
			M -= 1;
	}
	//���л��� �ι躸�� ���л��� ���� �������
	manhigh = N >= M*2 ? true : false;

	//���л��� ���ڸ�ŭ ���� �������
	if (manhigh)
		printf("%d", M);

	//�ƴҰ�� ���п��� ���ݸ�ŭ ���� �������
	else
	{
		printf("%d", N / 2);
	}

	return 0;
}