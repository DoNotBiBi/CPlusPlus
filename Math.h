// Test_Math.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
#include <iostream>
using namespace std;
#include<string>
#include<iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include<cmath>
using namespace std;
	int abs(int i);
	double fabs(double x);
	long labs(long n);
	double exp(double x);
	double log(double x);
	double log10(double x)ֵ
	double pow(double x,double y)
	double pow10(int p)
	double sqrt(double x)
	double acos(double x)
	double asin(double x)
	double atan(double x)
	double cos(double x)
	double sin(double x)
	double tan(double x)
	double hypot(double x,double y)
	double ceil(double x)
	double floor(double x)
	int rand()
	double atof(char *nptr)
	double atol(char *nptr)
	int atoi(char *nptr)
	long atol(char *nptr)
*/
#include<cctype>
/*
	isalnum
	isalpha
	iscntrl
	isdigit
	isgraph
	islower
	isprint
	ispunt
	isspace
	isupper
	isxdigit
	tolower
	toupper
// 任何整数(不超过30位的数)转x进制(10以内)
string Divide(string str, int x) {
	int remainder = 0;
	for (int i = 0; i < str.size(); i++) {
		int current = remainder * 10 + str[i] - '0';
		str[i] = current / x + '0';
		remainder = current % x;
	}
	int pos = 0;
	while (str[pos] == '0') {
		pos++;
	}
	return str.substr(pos);
}
void DecToBin(string str) {
	vector<int> binary;
	while (str.size() != 0) {
		int last = str[str.size() - 1] - '0';
		binary.push_back(last % 2);
		str = Divide(str, 2);
	}
	for (int i = binary.size() - 1; i >= 0; --i) {
		cout << binary[i];
	}
}
string to2(int x) {
	string s="";
	while (x > 0) {
		s =  to_string(x % 2)+s;
		x = x / 2;
	}
	return s;
}
string s = "";
void f(string x) {
	int a=0;
	for (char e : x) {
		if (islower(e)) {
			a = e - 'a'+10;
		}
		if (isupper(e)) {
			a = a - 'A'+10;
		}
		if (isdigit(e)) {
			a = e - '0';
		}
		s = s + to2(a);
	}
	
}
// 字符串与一个数相乘
string Multiple(string str, int x) {
	int carry = 0;
	for (int i = str.size() - 1; i >= 0; --i) {
		int current = x * (str[i] - '0') + carry;
		str[i] = current % 10 + '0';
		carry = current / 10;
	}
	if (carry != 0) {
		str = to_string(carry) + str;  // 有意思
	}
	return str;
}
// 字符串与一个数相加
string Add(string str, int x) {
	int carry = x;
	for (int i = str.size() - 1; i >= 0; --i) {
		int current = (str[i] - '0') + carry;
		str[i] = current % 10 + '0';
		carry = current / 10;
	}
	if (carry != 0) {
		str = "1" + str;  // 有意思
	}
	return str;
}
// 二进制转十进制
void BinToDec(string s1) {
	string s2 = "0";
	for (int i = 0; i < s1.size(); i++) {
		s2 = Multiple(s2, 2);
		s2 = Add(s2, s1[i]);
	}
	cout << s2;
}
// 大数相加
string BigNumAdd(string s1, string  s2) {
	int carry = 0;
	int s1_l = s1.size();
	int s2_l = s2.size();
	vector<char> result;
	string s = "";
	if (s1_l >= s2_l) {
		for (int i = 0; i < abs(s1_l - s2_l); i++) {
			s2 = "0" + s2;
		}
	}
	else {
		for (int i = 0; i < abs(s1_l - s2_l); i++) {
			s1 = "0" + s1;
		}
	}
	for (int i = s1.size() - 1; i >= 0; --i) {
		int current = (s1[i] - '0') + (s2[i] - '0') + carry;
		char c = current % 10 + '0';
		s = c+s;
		carry = current / 10;
	}
	if (carry != 0) {
		s ="1"+s;
	}
	return s;
}
void BinToDec2(string s1) {
	string s2 = "0";
	for (int i = 0; i < s1.size(); i++) {
		s2 = Multiple(s2, 2);
		s2 = Add(s2, s1[i]);
	}
	cout << s2;
}
// 大数相乘
string BigNumMul(string s1, string s2) {
	vector<string> result_v;
	int i;
	for (int i = s2.size() - 1; i >= 0; --i) {
		string current = Multiple(s1, s2[i] - '0');
		for (int j = 0; j < (s2.size() - 1 - i); j++) {
			current = current + "0";
		}
		result_v.push_back(current);
	}
	string result = result_v.at(0);
	for (int i = 1; i < result_v.size(); i++) {
		result = BigNumAdd(result, result_v.at(i));
	}
	return result;
}
// 整数幂
string NumPow(string s1, int s2) {
	string result = s1;
	for (int i = 1; i < s2; i++) {
		result = BigNumMul(result, s1);
	}
	return result;
}
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#define M 10000 
char s1[M], s2[M];
int a[M], b[M], c[M];
#pragma disable(warning:C4996)




void test_math()
{
	/*
		const char *s1 = "12.32E2";
		double f = atof(s1);
		int e_i= (int)log10(f);
		cout << f / (pow(10, e_i)) << "e" << e_i << endl;
		int a = 100;
		int b = 101;
		int c = a ^ b;
		cout << c;
	
	
	//int s = 13;
	//string s = "12D3";
	//f(s);
	int a1, a2, i, j, sum1, sum2;
	while (scanf("%s%s", s1, s2) != EOF) {


		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		a1 = strlen(s1);
		a2 = strlen(s2);

		int x = 0, sum1 = 0;
		for (i = a1 - 1; i >= 0; i--)
		{
			a[x] = s1[i] - 48;
			sum1 += a[x];
			x++;
		}

		x = 0;
		sum2 = 0;
		for (j = a2 - 1; j >= 0; j--)
		{
			b[x] = s2[j] - 48;
			sum2 += b[x];
			x++;
		}
		if (sum1 == 0 || sum2 == 0)
		{
			printf("s1的长度=%d s2的长度=%d\n", a1, a2);
			printf("0\n");
		}
		else
		{

			for (i = 0; i < a1; i++)
			{
				for (j = 0; j < a2; j++)
				{
					c[i + j] += a[i] * b[j];
				}
			}
			for (i = 0; i < M; i++)
			{
				if (c[i] > 10)
				{
					c[i + 1] += c[i] / 10;
					c[i] %= 10;
				}
			}

			for (i = M - 1; i >= 0; i--)
			{
				if (c[i] != 0)
					break;
			}

			printf("s1的长度=%d s2的长度=%d\n", a1, a2);
			for (; i >= 0; i--)
			{
				printf("%d", c[i]);
			}
			printf("\n");
		}
	}
	*/
}