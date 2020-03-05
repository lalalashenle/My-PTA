/// Source : https://pintia.cn/problem-sets/994805260223102976/problems/994805308755394560
/// Author : lalalashenle
/// Time   : 2020-03-05
/// Description:	乙级 / 1014 / 福尔摩斯的约会 (20分)

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<string> day = { "MON","TUE" ,"WED","THU","FRI","SAT" ,"SUN" };

// 注意每次符合题目要求的取值范围！
// DAY：注意大写字母范围在 A ~ G；
// HH/MM：小于 10 的数字要写成 "0x" 
// 判别语句内要记得 break
void answer(vector<string> s) {
	int i = 0;
	while (i < s[0].size() && i < s[1].size()) {
		if (s[0][i] >= 'A' && s[0][i] <= 'G') // 第 1 对相同的大写英文字母
			if (s[0][i] == s[1][i]) {
				cout << day[s[0][i] - 'A'] << " ";
				break;
			}
		i++;
	}

	i++; // i 移到 “第1对相同的大写英文字母” 的后面一位
	while (i < s[0].size() && i < s[1].size()) {  // 第 2 对相同的字符
		if (s[0][i] == s[1][i]) {
			if ((s[0][i] >= 'A' && s[0][i] <= 'N')) {
				int HH = (int)s[0][i] - (int)'A' + 10;
				cout << HH << ":";
				break;
			}
			else if (s[0][i] >= '0' && s[0][i] <= '9') {
				cout << "0" << (int)s[0][i] - (int)'0' << ":";
				//cout << (int)s[0][i] - (int)'0' << ":";
				break;
			}
		}
		i++;
	}
	i = 0;
	while (i < s[2].size() && i < s[3].size()) { // 后面两字符串第 1 对相同的英文字母
		if (s[2][i] == s[3][i]) {
			if ((s[2][i] >= 'a' && s[2][i] <= 'z') || (s[2][i] >= 'A' && s[2][i] <= 'Z')) {
				if (i < 10)
					cout << "0";
				cout << i;
				break;
			}
		}
		i++;
	}
}


int main() {
	vector<string> s(4);
	for (int i = 0; i < 4; i++)
		getline(cin, s[i]);

	answer(s);

	return 0;
}
