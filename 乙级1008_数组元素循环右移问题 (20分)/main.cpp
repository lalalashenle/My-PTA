/// Source : https://pintia.cn/problem-sets/994805260223102976/problems/994805316250615808
/// Author : lalalashenle
/// Time   : 2020-03-04
/// Description:	乙级 / 1008 / 数组元素循环右移问题 (20分)

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int N, M; // N 个整数，右移 M 位
	cin >> N >> M;
	if (M > N)
		M = M%N;
	vector<int> test(N);
	for (int i = 0; i < N; i++)
		cin >> test[i];

	for (int i = 0; i < N / 2; i++)
		swap(test[i], test[N - i - 1]);

	for (int i = 0; i < M / 2; i++)
		swap(test[i], test[M - i - 1]);

	for (int i = M; i < (N + M) / 2; i++) // N = 6, M = 2
		swap(test[i], test[N + M - i - 1]);

	int index = 0;
	for (auto e : test) {
		if (index != N - 1)
			cout << e << " ";
		else cout << e;
		index++;
	}

	return 0;
}
