#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> calculator(vector<vector<int>> price, int num) {
	int share;
	int mineach = 0, minprice = 0, minshare = 0;
	vector<int> answer;
	for (auto& iter : price) {
		share = num / iter[1];

		if (num % iter[1] != 0)
			share += 1;

		if (mineach == 0) {
			mineach = share * iter[1];
			minprice = iter[0];
			minshare = share;
		}
		else {
			if ((mineach * minprice) > (share * iter[1] * iter[0])) {
				mineach = share * iter[1];
				minprice = iter[0];
				minshare = share;
			}
		}
	}

	answer.push_back(minprice);
	answer.push_back(mineach/minshare);

	return answer;	
}

int solution(int n, vector<vector<int>> battery) {
	int amount = n;
	int answer = 0;
	int each;
	int total_price;
	int minprice, mineach;
	int pre = 0;
	vector<vector<int>> price;//개당 가격, 갯수
	vector<int> temp;
	for (auto& iter : battery)
	{
		each = iter[0];
		total_price = iter[1];
		temp.push_back((total_price / each));
		temp.push_back(each);
		price.push_back(temp);
		temp.clear();
	}

	sort(price.begin(), price.end());

	while(amount>0){
		temp = calculator(price, amount);
		minprice = temp[0];
		mineach = temp[1];
		amount -= mineach;
		answer += minprice * mineach;
	}

	return answer;
}

int main(void) {
	int n = 50;
	vector<int> priceandeach;
	vector<vector<int>> battery;
	/*priceandeach.push_back(6);
	priceandeach.push_back(30000);
	battery.push_back(priceandeach);
	priceandeach.clear();

	priceandeach.push_back(3);
	priceandeach.push_back(18000);
	battery.push_back(priceandeach);
	priceandeach.clear();

	priceandeach.push_back(4);
	priceandeach.push_back(28000);
	battery.push_back(priceandeach);
	priceandeach.clear();

	priceandeach.push_back(1);
	priceandeach.push_back(9500);
	battery.push_back(priceandeach);
	priceandeach.clear();
*/
	priceandeach.push_back(10);
	priceandeach.push_back(100000);
	battery.push_back(priceandeach);
	priceandeach.clear();
	priceandeach.push_back(4);
	priceandeach.push_back(35000);
	battery.push_back(priceandeach);
	priceandeach.clear();
	priceandeach.push_back(1);
	priceandeach.push_back(15000);
	battery.push_back(priceandeach);
	priceandeach.clear();
	

	cout << solution(n, battery) << endl;
	return 0;
}