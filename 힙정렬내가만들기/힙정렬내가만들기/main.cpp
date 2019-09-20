#include <iostream>
//자식노드의 부모노드 구하는 매크로 
#define parent(x) (x-1)/2

using namespace std;

void heap(int* data, int num) {
	int root;//부모 노드
	int temp;

	for (int i = 1; i < num; i++) {
		int child = i;

		while (child > 0) {
			root = parent(child);
			//자식노드와 비교하여 자식노드가 더크다면 스왑
			if (data[root] < data[i]) {
				temp = data[root];
				data[root] = data[i];
				data[i] = temp;
			}
			//부모노드를 자식노드로하여 index가 0이 될때까지 트리를 올라가며 계속비교
			child = root;
		}
	}
}

int main(void) {
	int count = 9;
	int data[] = { 100, 15, 20, 68, 72, 36, 97, 11, 28 };
	heap(data, count);

	//data[0]에는 최대값 혹은 최솟값이 들어 있으므로 배열의 마지막 값으로 전달한뒤 heap정렬에서 제외한다.
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