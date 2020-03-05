/// Source : https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528
/// Author : lalalashenle
/// Time   : 2020-03-05
/// Description:	乙级 / 1001 / 害死人不偿命的(3n+1)猜想 (15分)

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int answer(int n) {
	int res = 0;
	while (n != 1) {
		if (n % 2 == 0)
			n /= 2;
		else n = (n * 3 + 1) / 2;
		res++;
	}

	return res;
}

int main() {
	int n;
	cin >> n;
	cout << answer(n);

	return 0;
}
