/// Source : https://pintia.cn/problem-sets/994805260223102976/problems/994805309963354112
/// Author : lalalashenle
/// Time   : 2020-03-05
/// Description:	乙级 / 1013 / 数素数 (20分)

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<int> answer(int M, int N) { // M ≤ N
	vector<bool> memo(9999999, true);
	vector<int> ans;
	int counter = 0;
	for (int i = 2; ; i++) {
		if (memo[i] == true) {
			for (int j = 2 * i; j <= 9999999; j += i)
				memo[j] = false;
			counter++;
			if (counter > N)
				break;
			if (counter >= M)
				ans.push_back(i);
		}
	}

	return ans;
}

int main()
{
	int M, N; // M 到 N 之间的素数
	cin >> M >> N;

	vector<int> res = answer(M, N);

	for (int i = 0; i < res.size(); i++) {
		if (i % 10 == 9 && i != res.size() - 1)
				cout << res[i] << endl;
		else if(i == res.size() - 1) 
			cout << res[i];
		else cout << res[i] << " ";
	}

	return 0;
}
