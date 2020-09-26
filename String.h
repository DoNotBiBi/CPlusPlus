#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <stdio.h>
#include<algorithm>
using namespace std;

void t_4_2(string& s) { // 更改实参的值
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = 'a' + (s[i] - 'a' + 1) % 26;
		}
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = 'A' + (s[i] - 'A' + 1) % 26;
		}
	}
}
int num[128];
void countchar(string s) {
	memset(num, 0, sizeof(num));
	for (int i = 0; i < s.size(); i++) {
		num[s[i]]++;
	}
	for (int i = 0; i < 128; i++) {
		if (num[i] != 0) {
			cout << (char)i << " " << num[i] << endl;
		}
	}
}




void test_string()
{
	string str = "hello world";
	sort(str.begin(), str.end());
	cout << str << endl;
	cout << str.size() << endl;
	cout << str[3] << endl;
	str.insert(2, "this");// 任意位置插入
	cout << str << endl;
	str.erase(3); // 若第二个参数没有则默认则到最后一个字符全部删除
	cout << str << endl;
	str.erase(2, 7); // 第一个参数是开始位置，第二个参数是个数（默认到最后一个）
	cout << str << endl;
	str.clear();
	cout << str << endl;
	string str2 = "hello world";
	// 字符串还可以进行逻辑运算
	str2 += "wangkang"; // 末尾添加
	cout << str2 << endl;
	int found = str2.find("world"); // 查找字符或者字符串 下角标都是从0开始的 若未找到则返回string::pos
	cout << found << endl;
	// 截取子串
	string str3 = str2.substr(0, 7);//(m,n) m~n-1
	cout << str3 << endl;

	string s = "ZzHello! How are you!";
	t_4_2(s);
	cout << s << endl;

	string s2 = "ZzHello! How are you!";
	countchar(s2);


	s = "ZzHello! How are you!";
	char x = 'H';
	cout << "x位于s的" << s.find('0') << endl; // 若没有找到返回 string::npos
	string sub = "xy";
	cout << s.find_first_of(sub) << endl;//第一个找到sub其中的一个元素就行 ，第二个参数为偏移量，若没有则默认为0
	cout << s.find_last_of(sub) << endl;//最后找到sub任意一个元素就行
	cout << s.find_first_not_of(sub) << endl;
	cout << s.find_last_not_of(sub) << endl;
	cout << "x小写为:" << (char)tolower(x) << endl;
	cout << "x大写为:" << (char)toupper(x) << endl;
}