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

	// begin을 words에서 삭제
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == begin) {
			words.erase(words.begin() + i);
			break;
		}
	}

	//변환하는 경우 return 조건
	if (begin == target)
	{
		answer.push_back(answers - 1);
	}

	//못변환하는 경우 return 조건
	if (words.size() == 0)
		return;

	//words안의 모든 단어를 돌면서 begin과 하나차이나는 단어들을 구별하는 작업
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
	//words안의 모든 단어를 돌면서 begin과 하나차이나는 단어들을 구별하는 작업
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