#include <iostream>
//�ڽĳ���� �θ��� ���ϴ� ��ũ�� 
#define parent(x) (x-1)/2

using namespace std;

void heap(int* data, int num) {
	int root;//�θ� ���
	int temp;

	for (int i = 1; i < num; i++) {
		int child = i;

		while (child > 0) {
			root = parent(child);
			//�ڽĳ��� ���Ͽ� �ڽĳ�尡 ��ũ�ٸ� ����
			if (data[root] < data[i]) {
				temp = data[root];
				data[root] = data[i];
				data[i] = temp;
			}
			//�θ��带 �ڽĳ����Ͽ� index�� 0�� �ɶ����� Ʈ���� �ö󰡸� ��Ӻ�
			child = root;
		}
	}
}

int main(void) {
	int count = 9;
	int data[] = { 100, 15, 20, 68, 72, 36, 97, 11, 28 };
	heap(data, count);

	//data[0]���� �ִ밪 Ȥ�� �ּڰ��� ��� �����Ƿ� �迭�� ������ ������ �����ѵ� heap���Ŀ��� �����Ѵ�.
	for (int i = count - 1; i >= 0; i--) {
		int temp = data[i];
		data[i] = data[0];
		data[0] = temp;
		heap(data, i);
	}

	for (int i = 0; i < count; i++) {
		cout << data[i] << endl;
	}

	return 0;
}