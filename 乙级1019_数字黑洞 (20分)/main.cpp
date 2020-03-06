/// Source : https://pintia.cn/problem-sets/994805260223102976/problems/994805302786899968
/// Author : lalalashenle
/// Time   : 2020-03-06
/// Description:	乙级 / 1019 / 数字黑洞 (20分)

#include <iostream>
#include <functional>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
	int N; // 正整数 N
	cin >> N;
	vector<int> test(4);
	test[3] = N % 10;
	N /= 10;
	test[2] = N % 10;
	N /= 10;
	test[1] = N % 10;
	N /= 10;
	test[0] = N % 10;

	if (test[0] == test[1] && test[1] == test[2] && test[2] == test[3]) {
		cout << test[0] << test[1] << test[2] << test[3];
		cout << " - ";
		cout << test[0] << test[1] << test[2] << test[3];
		cout << " = " << "0000";
		N = 6174;
	}
	while (N != 6174) {

		sort(test.begin(), test.end(), greater<int>()); // 降序，大
		int N1 = 1000 * test[0] + 100 * test[1] + 10 * test[2] + test[3];
		cout << test[0] << test[1] << test[2] << test[3];

		sort(test.begin(), test.end(), less<int>()); // 升序，小
		int N2 = 1000 * test[0] + 100 * test[1] + 10 * test[2] + test[3];
		cout << " - ";
		cout << test[0] << test[1] << test[2] << test[3];

		N = N1 - N2;
		int tmp = N;
		test[3] = tmp % 10;
		tmp /= 10;
		test[2] = tmp % 10;
		tmp /= 10;
		test[1] = tmp % 10;
		tmp /= 10;
		test[0] = tmp % 10;
		cout << " = " << test[0] << test[1] << test[2] << test[3];
		if (N != 6174)
			cout << endl;
	}

	return 0;
}
