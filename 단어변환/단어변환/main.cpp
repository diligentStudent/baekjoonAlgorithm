#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> answer;
void reculsive(string begin, string target, vector<string> words, int answers)
{
	int count = 0;
	int tempanswer;
	//int answer = 0;
	string cmp;
	vector<string> wordstr;

	// begin�� words���� ����
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == begin) {
			words.erase(words.begin() + i);
			break;
		}
	}

	//��ȯ�ϴ� ��� return ����
	if (begin == target)
	{
		answer.push_back(answers - 1);
	}

	//����ȯ�ϴ� ��� return ����
	if (words.size() == 0)
		return;

	//words���� ��� �ܾ ���鼭 begin�� �ϳ����̳��� �ܾ���� �����ϴ� �۾�
	for (auto& iter : words)
	{
		count = 0;
		cmp = iter;
		for (int i = 0; i < begin.size(); i++) {
			if (begin[i] != cmp[i])
				count++;

			if (count >= 2)
				break;
		}

		if (count == 1)
			wordstr.push_back(cmp);
	}

	for (auto& iter : wordstr)
	{
		reculsive(iter, target, words, answers + 1);
	}

	return;
}

int solution(string begin, string target, vector<string> words) {
	int answer1 = 0;
	int tempanswer;
	int count;
	vector<string> wordstr;
	vector<int> answers;
	string cmp;
	//words���� ��� �ܾ ���鼭 begin�� �ϳ����̳��� �ܾ���� �����ϴ� �۾�
	for (auto& iter : words)
	{
		count = 0;
		cmp = iter;
		for (int i = 0; i < begin.size(); i++) {
			if (begin[i] != cmp[i])
				count++;

			if (count >= 2)
				break;
		}

		if (count == 1)
			wordstr.push_back(cmp);
	}

	for (auto& iter : wordstr)
	{
		reculsive(iter, target, words, 2);
	}

	sort(answer.begin(), answer.end(), greater<int>());
	if (answer.size() == 0)
		return 0;
	return answer.back();
}
int main(void)
{
	string begin = "hit";
	string target = "cog";
	vector<string> words;

	words.push_back("hot");
	words.push_back("dot");
	words.push_back("dog");
	words.push_back("lot");
	words.push_back("log");
	words.push_back("cog");
	cout <<solution(begin, target, words);
	return 0;
}