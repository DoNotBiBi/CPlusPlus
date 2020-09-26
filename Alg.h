#include <iostream>
#include <cstdlib>// itoa() 和 atoi()的头文件
#include <algorithm> // 使用sort的头文件
#include <vector>
#include <stack>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <string.h>
#include<string>
using namespace std;
#define N 4
#define M 3


int b[M];

// 组合数
void search(int depth, int n, int m)
{
	int count = 0;
	//cout << "depth="<<depth<<" "<<"n=" << n <<" " << "m=" <<m<<endl;
	if (m == 0)
	{
		for (int i = 0; i < M; i++) //必须是M，否则无输出
			cout << b[i] << " ";
		cout << endl;
		count++;
	}
	if ((m > n) || (n <= 0))
		return;
	b[depth] = n;
	search(depth + 1, n - 1, m - 1);
	search(depth, n - 1, m);
}


// 杨辉三角
void yanghuitriangle(int n)
{
	deque<int> q; // 循环队列
	int l = 0, r = 0, s = 0;
	q.push_back(1);
	for (int i = 0; i <= n; i++)
	{
		q.push_back(0);
		for (int j = 1; j <= i + 2; j++)
		{
			r = q.front();
			q.pop_front();
			if (r)
				cout << r << " ";
			s = l + r;
			q.push_back(s);
			l = r;
		}
		cout << endl;
	}
}

// 哈夫曼
struct element {
	int weight;
	int lchild, rchild, parent;
};
// 选出权值两个最小的结点 
void selectMin(element a[], int n, int& s1, int& s2) {
	for (int i = 0; i < n; i++) {
		if (a[i].parent == -1) {
			s1 = i;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i].parent == -1 && a[i].weight < a[s1].weight) {
			s1 = i;
		}
	}
	for (int j = 0; j < n; j++) {
		if (a[j].parent == -1 && j != s1) {
			s2 = j;
			break;
		}
	}
	for (int j = 0; j < n; j++) {
		if (a[j].parent == -1 && a[j].weight < a[s2].weight && j != s1) {
			s2 = j;
		}
	}

}

/*
	
*/
void HuffmanTree(element huftree[], int w[], int n) {
	for (int i = 0; i < 2 * n - 1; i++) {
		huftree[i].parent = -1;
		huftree[i].lchild = -1;
		huftree[i].rchild = -1;
	}
	for (int i = 0; i < n; i++) {
		huftree[i].weight = w[i];
	}
	for (int k = n; k < 2 * n - 1; k++) {
		int i1, i2;
		selectMin(huftree, k, i1, i2);
		huftree[i1].parent = k;
		huftree[i2].parent = k;
		huftree[k].lchild = i1;
		huftree[k].rchild = i2;
		huftree[k].weight = huftree[i1].weight + huftree[i2].weight;
	}
}

// 打印哈夫曼树
void print(element hT[], int n)
{
	cout << "index weight parent lChild rChild" << endl;
	cout << left;    // 左对齐输出
	for (int i = 0; i < n; ++i)
	{
		cout << setw(5) << i << " ";
		cout << setw(6) << hT[i].weight << " ";
		cout << setw(6) << hT[i].parent << " ";
		cout << setw(6) << hT[i].lchild << " ";
		cout << setw(6) << hT[i].rchild << endl;
	}
}
/*
	在建造完之后可以进行哈夫曼编码 查看叶子节点是左还是右 然后将查看的对象传给父节点 以此类推 最后将顺序倒过来
*/
// 括号匹配
bool judge(string& str)
{
	stack<char> S;
	char ch;
	char op;
	for (int i = 0; i < (int)str.size(); i++)
	{
		ch = str[i];
		switch (ch)
		{
		case '(':
			S.push(ch); break;
		case '[':
			S.push(ch); break;
		case '{':
			S.push(ch); break;
		case ')':
			op = S.top();
			S.pop();
			if (op != '(') return false;
			break;
		case ']':
			op = S.top();
			S.pop();
			if (op != '[') return false;
			break;
		case '}':
			op = S.top();
			S.pop();
			if (op != '{') return false;
			break;
		default:
			return false;
		}
	}
	if (S.empty()) return true;
	else return false;
}
// 寻找最长公共的字符串
int common_string(string str1, string str2, string& comstr)
{
	int i = str2.size();
	string substr1;
	while (i > 0)
	{
		int j = 0;
		while ((j + i) <= (int)str2.size())
		{
			int pos = 0;
			substr1 = str2.substr(j, i); // 看清楚
			if ((pos = str1.find(substr1)) != -1)
			{
				comstr = substr1;
				return pos;
			}
			else
			{
				j++;
			}
		}
		i--;
	}
	return -1;;
}
// 判断标识符
bool IsValid(string str)
{
	int i = 0;
	if (str[i] == '_' || isalpha(str[i]))
	{
		while (str[i] == '_' || isalpha(str[i]) || isdigit(str[i]))
		{
			i++;
		}
		if (i >= (int)str.size())
			return true;
		else
			return false;
	}
	else
		return false;
}

// 整数拆分 连续的三个或者三个以上整数相加
void zhengshuchaifen()
{
	int n;
	cout << "input the number:\n";
	cin >> n;
	int i, k;
	int sum = 0, count = 0;
	bool success = false;
	for (i = 1; i < n / 2; i++)
	{
		for (k = i; ; k++)
		{
			sum += k;
			if (sum >= n)
				break;
			count++;
		}
		if (sum == n)
		{
			success = true;
			for (k = 0; k <= count; k++)
				cout << i + k << " ";
			cout << endl;
		}
		sum = 0;// 重新归零
		count = 0;
	}
	if (success == false)
		cout << "fail to split" << endl;
}
// 约瑟夫环
void yuesefu()
{
	int n, m, s;
	cin >> n >> s >> m; // n为个数 s 为起点 m为步数
	vector<int> v;
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	int count = s - 1;
	while (!v.empty())
	{
		n = v.size();
		count = (count + m - 1) % n;
		cout << v[count] << " ";
		v.erase(v.begin() + count); // 抹除相关元素 后面元素向前移动
	}
	cout << endl;
}
/*
int fib(int n){
	if(n==0) return 0;
	if(n==1||n==2) return 1;
	else return fib(n-1)+fib(n-2);
}
*/
void fib(int n)
{
	int a = 1, b = 1, c = 0, i = 1;
	cout << a << " " << b << " ";
	while (i < n - 1)   // 这里需要注意
	{

		c = a + b;
		cout << c << " ";
		b = a;
		a = c;
		i++;
	}
}

// 根据相应大小进行排序
bool sortSpecial(int v1, int v2)
{
	return v1 > v2;
}

// 十进制转m进制
void TentoBinary(int n, int m)
{
	string s = "";
	while (n)
	{

		cout << n << "  " << m << "  " << s << endl;
		s = to_string(n % m) + s;
		n = n / m;
	}
	cout << s;
	cout << endl;
}

//完数
bool judge_Perfect_Num(int n, vector<int>& v)
{
	int i = 1;
	for (i = 1; i < n; i++)
	{
		if (n % i == 0)
			v.push_back(i); // 把真因子装进v
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v.at(i);
	}
	if (sum == n)
		return true;
	else
		return false;
}

// 判断闰年

int is_leapyear(int year)
{
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		return 1;
	else
		return 0;
}


// 全排列
void swap(int A[], int i, int j)
{
	int temp = A[j];
	A[j] = A[i];
	A[i] = temp;
}

void func(int A[], int i, int n)
{
	if (i == n - 1)
	{
		for (int j = 0; j < n; j++)
			cout << A[j];
		cout << endl;
	}
	else
	{
		for (int j = i; j < n; j++)
		{
			swap(A, i, j);
			func(A, i + 1, n);
			swap(A, i, j);
		}
	}
}

// 组合
void combine(vector<int>& s, vector<int>& v, int n, int m)
{
	if (m == 0 || m == n)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
		if (m == n)
		{
			for (int i = 0; i < m; i++)
				cout << s[i];
		}
		cout << endl;
	}
	else
	{
		v.push_back(s[n - 1]);
		combine(s, v, n - 1, m - 1);
		v.pop_back();
		combine(s, v, n - 1, m);
	}
}

void zuichangdizeng(string ss) {
	int i_ss[100] = { 0 };
	for (int i = 0; i < ss.size(); ++i) {
		i_ss[i] = 0;
	}
	int pos = 0;
	int k = 0;
	for (int i = 1; i < ss.size(); ++i) {
		if ((ss[i] - '0') > (ss[i - 1] - '0')) {
			i_ss[i] = i_ss[i - 1] + 1;
			if (pos < i_ss[i]) {
				k = i;
				pos = i_ss[i];
			}
		}
		else {
			i_ss[i] = 0;
		}
	}
	for (int i = 0; i < ss.size(); ++i) {
		cout << i_ss[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < ss.size(); ++i) { //考虑多种情况
		if (i_ss[i] == pos) {
			cout << ss.substr(i - pos, pos + 1);
			cout << endl;
		}
	}

}

//s为待分割串，按照delim中的各种字符分割，结果保存在ans中
void String_Split(string s, string delim, vector<string>& ans)
{
	int pos_1, pos_2 = 0;
	while (pos_2 != s.npos) {
		pos_1 = s.find_first_not_of(delim, pos_2);
		if (pos_1 == s.npos) break;
		pos_2 = s.find_first_of(delim, pos_1);
		ans.push_back(s.substr(pos_1, pos_2 - pos_1));
	}
}

void String_Split_Reverse(string& result, string s, string delim)
{
	int pos_1, pos_2 = 0;
	while (pos_2 != s.npos) {
		pos_1 = s.find_first_not_of(delim, pos_2);  // 第二个是偏移量
		if (pos_1 == s.npos) break;
		pos_2 = s.find_first_of(delim, pos_1);
		string temp_substr = s.substr(pos_1, pos_2 - pos_1);
		reverse(temp_substr.begin(), temp_substr.end());
		result += temp_substr + delim;

	}
	result.erase(result.size() - 1);
	result += "!";
}


int count = 0;

typedef struct ValueType
{
	string word;
	int at_line;
	int count;
} ValueType;
int find(vector<ValueType>& v, string word)
{
	for (int i = 0; i < (int)v.size(); i++)
	{
		if (v.at(i).word == word)
			return i;
	}

	return -1;
}


// KMP 算法
void GetNext(char* p, int next[]) {
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1) {
		if (k == -1 || p[j] == p[k]) {
			++k;
			++j;
			next[j] = k;
		}
		else {
			k = next[k];
		}
	}
}

int KMP(char* s, char* p, int next[]) {
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	while (i < sLen && j < pLen) {
		if (j == -1 || s[i] == p[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}


	if (j == pLen) {
		return i - j;
	}
	else {
		return -1;
	}
}
void test_alg()
{

	char s[] = "abcdabce";
	int next[100];
	GetNext(s, next);
	for (int i = 0; i < 8; i++) {
		cout << next[i]<<" ";
	}
	cout << endl;

	char p[] = "dabc";
	cout << KMP(s, p, next) << endl;


	string result = "";
	string s2 = "wangkang helo guagua";
	const string delim = " ";
	String_Split_Reverse(result, s2, delim);
	cout << result;

	char as[128];
	int a=123;
	//itoa(a,as,10); // 将整数x转化为字符串
	//cout<<as<<endl;
	char ab[128]="23";
	float a2=atoi(ab); // 将数字字符串转化为单精度浮点数
	cout<<a2<<endl;

	ifstream ifs;
	ifs.open("in.txt");
	int year, month;
	int days[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
					{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	while(!ifs.eof())
	{
		ifs>>year>>month;
		cout<<year<<" "<<month<<endl;
		cout<<days[is_leapyear(year)][month]<<" "<<endl;
	}
	ifs.close();







	
	int n1 = 100;
	int m1 = 2;
	TentoBinary(n1, m1);
	

/*
	ifstream ifs;
	string filename = "in.txt";
	ifs.open(filename);
	string line;
	int n=0;
	const string delim = " ";
	vector<ValueType> v;
	while(!ifs.eof())
	{
		vector<string> ss;
		ifs >> line;
		n++;
		String_Split(line, delim, ss);
		for (int i = 0; i < ss.size(); i++) {
			string word = ss.at(i);
			cout << word << endl;;
			int pos;
			if ((pos = find(v, word)) == -1)
			{
				ValueType k;
				k.word = word;
				k.at_line = n;
				k.count = 1;
				v.push_back(k);
			}
			else
			{
				v[pos].count++;
			}

		}
		ss.clear();
	}

	ofstream ofs;
	ofs.open("out.txt");
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i].count >= 1)
			ofs<<v.at(i).word<<" "<<v.at(i).at_line<<" "<<v.at(i).count<<endl;
	}
	ifs.close();
	ofs.close();

	*/
}