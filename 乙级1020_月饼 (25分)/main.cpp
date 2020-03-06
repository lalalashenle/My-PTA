/// Source : https://pintia.cn/problem-sets/994805260223102976/problems/994805301562163200
/// Author : lalalashenle
/// Time   : 2020-03-06
/// Description:	乙级 / 1020 / 月饼 (25分)

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct moonbiscuit {
	double volumn;  // 每种月饼的库存量
	double prices;  // 每种月饼的总售价
	double price;   // 单价
};

bool cmp1(moonbiscuit mb1, moonbiscuit mb2) {
	return mb1.price > mb2.price;
}

int main() {
	int N, D; // N:月饼的种类数 D:市场最大需求量
	cin >> N >> D;
	vector<moonbiscuit> test(N);
	for (int i = 0; i < N; i++)
		cin >> test[i].volumn;
	for (int i = 0; i < N; i++) {
		cin >> test[i].prices;
		test[i].price = test[i].prices / test[i].volumn;
	}
	sort(test.begin(), test.end(), cmp1);

	//for (int i = 0; i < N; i++)
		//cout << test[i].price << " ";

	double res = 0.00;
	for (int i = 0; i < N; i++) {
		if (D > test[i].volumn)
			res += test[i].prices;
		else {
			res += test[i].price * (double)D;
			break;
		}
		D -= test[i].volumn;
	}

	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << res;

	return 0;
}
