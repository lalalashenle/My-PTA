/// Source : https://pintia.cn/problem-sets/994805260223102976/problems/994805313708867584
/// Author : lalalashenle
/// Time   : 2020-03-05
/// Description:	乙级 / 1010 / 一元多项式求导 (25分)

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<int> answer(vector<int> test) {
	vector<int> zero = { 0, 0 };
	vector<int> res;
	int n = test.size();

	if (n == 2 && test[1] == 0)
		return zero;

	for (int i = 0; i < n - 1; i += 2) {
		if (test[i + 1] > 0) {
			res.push_back(test[i] * test[i + 1]);
			res.push_back(test[i + 1] - 1);
		}
	}

	return res;
}

int main()
{
	vector<int> test;
	int i;
	while (cin >> i)
		test.push_back(i);

	vector<int> res = answer(test);

	int index = 0;
	for (auto e : res) {
		if (index != res.size() - 1)
			cout << e << " ";
		else cout << e;
		index++;
	}

	return 0;
}
