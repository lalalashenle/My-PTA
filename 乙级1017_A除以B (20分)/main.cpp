/// Source : https://pintia.cn/problem-sets/994805260223102976/problems/994805305181847552
/// Author : lalalashenle
/// Time   : 2020-03-05
/// Description:	乙级 / 1017 / A除以B (20分)

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

// 模拟竖式除法运算
// 两个大数的除法还需进一步学习
void answer(string A, int B) { // 2 7
	string res;
	int n = A.size();
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (flag * 10 + (A[i] - '0') < B) { // 后置位进位再除
			flag = A[i] - '0';
			res.push_back('0');
		}
		else {
			int tmp = flag * 10 + (A[i] - '0');
			res.push_back(tmp / B + '0');
			flag = tmp % B;
		}	
	}
	if (res[0] == '0' && res.size() > 1) // 去除前置零
		res.erase(res.begin());
	cout << res << " " << flag;
}


int main() {
	string A;
	int B;
	while(cin >> A >> B)
		answer(A, B);

	return 0;
}
