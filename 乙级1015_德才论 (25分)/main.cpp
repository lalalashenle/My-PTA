/// Source : https://pintia.cn/problem-sets/994805260223102976/problems/994805307551629312
/// Author : lalalashenle
/// Time   : 2020-03-05
/// Description:	乙级 / 1015 / 德才论 (25分)

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct stdu {
	int num; // 准考证号
	int DE;  // 德分
	int CAI;  // 才分
};

bool cmp1(stdu std1, stdu std2) {
	if ((std1.CAI + std1.DE) != (std2.CAI + std2.DE))
		return (std1.CAI + std1.DE) > (std2.CAI + std2.DE);
	else if (std1.DE != std2.DE)
		return std1.DE > std2.DE;
	else return std1.num < std2.num;
}

int main() {
	int N, L, H; // N:考生总数 L:取最低分数线 H:优先录取线
	cin >> N >> L >> H;
	vector<stdu> test(N);
	vector<stdu> class1; // 按德才总分从高到低排序
	vector<stdu> class2; // 按总分排序，但排在第一类考生之后
	vector<stdu> class3; // 按总分排序，但排在第二类考生之后
	vector<stdu> class4; // 按总分排序，但排在第三类考生之后

	for (int i = 0; i < N; i++) {
		cin >> test[i].num >> test[i].DE >> test[i].CAI;
		if (test[i].DE >= H && test[i].CAI >= H)    // 才德全尽 class1
			class1.push_back(test[i]);
		else if (test[i].DE >= H && test[i].CAI >= L) // 德胜才 class2
			class2.push_back(test[i]);
		else if (test[i].DE >= test[i].CAI && test[i].DE >= L && test[i].CAI >= L)  // 才德兼亡 class2
			class3.push_back(test[i]);
		else if (test[i].DE >= L && test[i].CAI >= L)
			class4.push_back(test[i]);
	}

	int n1 = class1.size(), n2 = class2.size(), n3 = class3.size(), n4 = class4.size();
	cout << n1 + n2 + n3 + n4 << endl;

	//stable_sort(class1.begin(), class1.end(), cmp1);
	sort(class1.begin(), class1.end(), cmp1);
	for (int i = 0; i < n1; i++) {
		if (i == n1 - 1 && (n2 + n3 + n4 == 0))
			cout << class1[i].num << " " << class1[i].DE << " " << class1[i].CAI;
		else
			cout << class1[i].num << " " << class1[i].DE << " " << class1[i].CAI << endl;
	}

	//stable_sort(class2.begin(), class2.end(), cmp1);
	sort(class2.begin(), class2.end(), cmp1);
	for (int i = 0; i < n2; i++) {
		if (i == n2 - 1 && (n3 + n4 == 0))
			cout << class2[i].num << " " << class2[i].DE << " " << class2[i].CAI;
		else
			cout << class2[i].num << " " << class2[i].DE << " " << class2[i].CAI << endl;
	}

	//stable_sort(class3.begin(), class3.end(), cmp1);
	sort(class3.begin(), class3.end(), cmp1);
	for (int i = 0; i < n3; i++) {
		if (i == n3 - 1 && (n4 == 0))
			cout << class3[i].num << " " << class3[i].DE << " " << class3[i].CAI;
		else
			cout << class3[i].num << " " << class3[i].DE << " " << class3[i].CAI << endl;
	}

	//stable_sort(class4.begin(), class4.end(), cmp1);
	sort(class4.begin(), class4.end(), cmp1);
	for (int i = 0; i < n4; i++) {
		if (i == n4 - 1)
			cout << class4[i].num << " " << class4[i].DE << " " << class4[i].CAI;
		else
			cout << class4[i].num << " " << class4[i].DE << " " << class4[i].CAI << endl;
	}


	return 0;
}
