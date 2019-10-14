#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>

using namespace std;

string input;

int main(void) {
	priority_queue<int> num_storage;
	priority_queue<int> temp_storage;
	int size = 0, total = 0, temp = 0;
	char num;
	cin >> input;

	size = input.size();

	if (input.find('0') == -1) {
		cout << -1 << endl;
	}

	else {
		for (int i = 0; i < size; i++) {
			memcpy(&num,&input[i],sizeof(char));
			temp_storage.push(atoi(&num));
		}

		for (int i = 0; i < size; i++) {
			temp = temp_storage.top();
			temp_storage.pop();
			total += temp;
			num_storage.push(temp);
		}

		if (total % 3 != 0) {
			cout << -1 << endl;
		}

		else{			
			for (int i = 0; i < size; i++) {
				cout << num_storage.top();
				num_storage.pop();
			}
		}
	}
	return 0;
}