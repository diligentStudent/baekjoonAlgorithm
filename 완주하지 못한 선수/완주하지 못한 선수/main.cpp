
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string Solution(vector<string> participant, vector<string> completion) {

	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < completion.size(); i++) {
		if (participant[i] != completion[i])
			return participant[i];
	}
	return participant[participant.size()];
}

int main(void)
{
	string input;
	char name[20] = { NULL, };
	bool condition = true;
	int find_end = 0, size;
	int count = 0;

	vector<string> participant;
	vector<string> completion;

	while (condition) {
		cin >> input;
		if (input.find(']') != string::npos) {
			input.erase(std::find(input.begin(), input.end(), ']'));
			condition = false;
		}

		else {
			input.erase(std::find(input.begin(), input.end(), '['));
		}

		input.erase(std::find(input.begin(),input.end(),','));
		participant.push_back(input);

	}

	condition = true;
	while (condition) {
		cin >> input;
		if (input.find(']') != string::npos) {
			input.erase(std::find(input.begin(), input.end(), ']'));
			condition = false;
		}

		else {
			input.erase(std::find(input.begin(), input.end(), '['));
		}

		input.erase(std::find(input.begin(), input.end(), ','));
		completion.push_back(input);
	}

	cout << Solution(participant, completion) << endl;;

	return 0;
}