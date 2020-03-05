/// Source : https://pintia.cn/problem-sets/994805260223102976/problems/994805317546655744
/// Author : lalalashenle
/// Time   : 2020-03-04
/// Description:	乙级 / 1007 / 素数对猜想 (20分)

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int answer(int N) {
	if (N < 5)
		return 0;
	vector<bool> memo(N + 1, true);
	vector<int> res;
	for (int i = 2; i <= N; i++) {
		if (memo[i]) {
			res.push_back(i);
			for (int j = i * 2; j <= N; j += i)
				memo[j] = false;
		}
	}
	int counter = 0;

	for (int i = 1; i < res.size(); i++) {
		if (res[i] - res[i - 1] == 2)
			counter++;
	}

	return counter;
}

int main()
{
	int N; // 不超过 N 的素数对个数
	cin >> N;

	cout << answer(N);

	return 0;
}
