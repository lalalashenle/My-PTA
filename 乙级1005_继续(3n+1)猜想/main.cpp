/// Source : https://pintia.cn/problem-sets/994805260223102976/problems/994805320306507776
/// Author : lalalashenle
/// Time   : 2020-1月
/// Description:	乙级 / 1005 / 继续(3n+1)猜想 (25分)

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

bool cmp1(int a, int b) {
	return b < a;
}

int main() {
	int K;
	cin >> K;
	vector<int> test(K);
	map<int, int> memo;
	for (int i = 0; i < K; i++) {
		cin >> test[i];
		memo[test[i]]++;
	}

	for (int i = 0; i < K; i++) { // 3 5 6 7 8 11
		//if (memo.find(test[i]) == memo.end())
			//break;
		while (test[i] != 1) {
			if (test[i] % 2 == 0) {
				test[i] /= 2;
				if (memo.find(test[i]) != memo.end())
					memo.erase(test[i]);
			}
			else {
				test[i] = (test[i] * 3 + 1) / 2;
				if (memo.find(test[i]) != memo.end())
					memo.erase(test[i]);
			}
		}
	}
	map<int, int>::iterator it;

	//for (it = memo.begin(); it != memo.end(); it++) 
			//cout << it->first << " ";   // 3 6 7 11
	vector<int> res;
	for (it = memo.begin(); it != memo.end(); it++) {
		res.push_back(it->first);
	}

	sort(res.begin(), res.end(), cmp1);

	for (int i = 0; i < res.size(); i++) {
		if (i != res.size() - 1)
			cout << res[i] << " ";
		else cout << res[i];
	}

	return 0;
}
