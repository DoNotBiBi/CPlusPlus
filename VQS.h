#include <iostream>
#include <cstdio>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#include<algorithm>
#include<iterator>
#include <string>
#include<cctype>
bool compare(int a, int b)
{
	return a > b;
}
void print_vector(vector<int> test_v)
{
	for (vector<int>::iterator it = test_v.begin(); it != test_v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void print(int s)
{
	cout << s << " ";
}
void print_vector2(vector<int> test_v)
{
	for_each(test_v.begin(), test_v.end(), print);
	cout << endl;
}

void print_vector3(vector<int> test_v)
{
	for (int e : test_v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void Test_Vector()
{
	vector<int> test_v;

	for (int i = 0; i < 10; i++)
	{
		test_v.push_back(i);
	}
	print_vector(test_v);
	for (int i = 0; i < 5; i++)
	{
		test_v.pop_back();
	}
	print_vector(test_v);

	sort(test_v.begin(), test_v.end(), compare);
	/*for (int i = 0; i < test_v.size(); i++) {
		cout << test_v[i] << " ";
	}*/
	print_vector(test_v);


	vector<int> h(test_v.begin(), test_v.begin() + 2);
	print_vector(h);


	int test_array[10] = { 2,3,4,6,4,3,4 };
	vector<int> test_h(10);
	copy(test_array, test_array + 7, test_h.begin());
	print_vector2(test_h);

	vector<int> h2;
	h2.push_back(3);
	h2.push_back(5);
	h2.push_back(7);
	h2.push_back(4);
	h2.push_back(0); // pop_back() 
	test_v.swap(h2);
	print_vector(test_v);
	print_vector(h2);


	reverse(test_v.begin(), test_v.end());  //
	print_vector(test_v);

	if (test_v.empty())
	{
		cout << "Test Vector's empty function" << endl;
	}

	test_v.insert(test_v.begin() + 1, 2, 5);
	print_vector(test_v);


	test_v.erase(test_v.begin() + 2, test_v.begin() + 5);// 批量删除  也可以单个删除test_v.erase(x) 下角标或者begin()+x


	*(test_v.begin() + 2) = 100;
	test_v.at(3) = 101;
	print_vector2(test_v);



	cout << test_v.size() << endl;
	test_v.reserve(100);

	cout << test_v.capacity() << endl;
	cout << test_v.max_size() << endl;

}
/*
	test_v.assign(2,0);
	test_v.clear();
*/

template<typename T>
void print_Queue(queue<T> test)
{
	while (!test.empty())
	{
		cout << test.front() << " ";
		test.pop();
	}
}

void Test_Queue()
{
	char e;
	queue<char> test;
	while (cin >> e && e != '#')
	{
		test.push(e);
	}
	char fe = test.front(); // 队头元素
	char be = test.back();  // 队尾元素
	cout << fe << "    " << be << endl;
	cout << "test.size():" << test.size() << endl;
	print_Queue(test);
}

void test_stack()
{
	char e, top_e;
	stack<char> test_s;
	while (cin >> e && e != '#')
	{
		test_s.push(e);
	}
	cout << test_s.size() << endl;
	while (!test_s.empty())
	{
		top_e = test_s.top();
		cout << top_e << " ";
		test_s.pop();
	}
}


int Priority(char c)
{
	if (c == '#')
	{
		return 0;
	}
	else if (c == '$')
	{
		return 1;
	}
	else if (c == '+' || c == '-')
	{
		return 2;
	}
	else
	{
		return 3;
	}
}


double GetNumber(string str, int& index)
{
	double number = 0;
	while (isdigit(str[index]))
	{
		number = number * 10 + str[index] - '0';
		index++;
	}

	return number;
}

double Calculate(double x, double y, char op)
{
	double result = 0;
	if (op == '+')
	{
		result = x + y;
	}
	else if (op == '-')
	{
		result = x - y;
	}
	else if (op == '*')
	{
		result = x * y;
	}
	else if (op == '/')
	{
		result = x / y;
	}
	return result;
}

void GetResult()
{
	string str;
	getline(cin, str);

	if (str == "")
	{
		return;
	}
	int index = 0;
	stack<char> oper, oper2;
	stack<double> data;
	str += '$';
	oper.push('#');
	while (index < (int)str.size())
	{
		if (str[index] == ' ')
		{
			index++;
		}

		else if (isdigit(str[index]))
		{
			data.push(GetNumber(str, index));
		}
		else
		{

			if (Priority(oper.top()) < Priority(str[index]))
			{
				oper.push(str[index]);
				index++;
			}
			else
			{
				double y = data.top();
				data.pop();
				double x = data.top();
				data.pop();
				data.push(Calculate(x, y, oper.top()));
				oper.pop();
			}
		}

	}

	cout << "The result is ";
	cout << data.top() << endl;

}

// 优先级队列
void Test_Prority_queue() {
	priority_queue<int> q;
	q.push(20);
	q.push(30);
	q.push(100);
	q.push(50);
	while (!q.empty()) {
		int t = q.top();
		cout << t << endl;
		q.pop();
	}
}

void Test_Prority_queue2() {
	priority_queue<string> q;
	q.push("hello");
	q.push("world");
	q.push("i am");
	q.push("a Chinese");
	while (!q.empty()) {
		string t = q.top();
		cout << t << endl;
		q.pop();
	}
}

// 自定义结构体的优先级排序
typedef struct Test_Struct {
	int real;
	int imag;
	Test_Struct(int a, int b) :real(a), imag(b) {}
	bool operator<(Test_Struct c) const {
		return real < c.real;
	}
}Test_Struct;

void Test_Prority_queue3() {
	priority_queue<Test_Struct> q;
	Test_Struct arr[] = { {1,2},{3,5},{2,4},{6,7},{5,6} };
	for (int i = 0; i < 5; i++) {
		q.push(arr[i]);
	}
	while (!q.empty()) {
		Test_Struct r = q.top();
		cout << "a=" << r.real << "  " << "b=" << r.imag << endl;
		q.pop();
	}
}

//中序变后序
int opPri(char s) {
	switch (s)
	{
	case '+':
	case '-':return 2;
	case '*':
	case '/':return 3;
	case '(':return 1;
	case ')':return 4;
	default:
		return 0;
		break;
	}
}

void InToPost(string ss, queue<char>& q) {
	stack<char> stk;
	for (char s : ss) {
		if (!opPri(s)) {
			q.push(s);
		}
		else if (stk.size() == 0) {
			stk.push(s);
		}
		else if (s == ')') {
			while (s = stk.top(), stk.pop(), s != '(') {
				q.push(s);
			}
		}
		else if (opPri(s) > opPri(stk.top()) || s == '(') {
			stk.push(s);
		}
		else {
			while (opPri(s) <= opPri(stk.top())) {
				q.push(stk.top());
				stk.pop();
				if (!stk.size()) break;
			}
			stk.push(s);
		}
	}
	while (stk.size()) {
		q.push(stk.top());
		stk.pop();
	}

}
