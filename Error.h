#include <iostream>
using namespace std;
#include<cstdlib>
#include<string>
#include <exception>
#include<math.h>
// 使用abort() 强制终止 
int r_value(int x, int y) {
	if ((x + y) < 0) {
		cout << "error occored" << endl;
		abort(); 
	}
	else {
		return (int)sqrt(x + y);
	}
}

// 异常的处理器 自定义捕获的异常
int r_value2(int x, int y) {
	if ((x + y) < 0) {
		throw "error occored"; // 抛出异常
	}
	return (int)sqrt(x + y);
}
void T_Error() {
	int x, y, z;
	while (cin >> x >> y) {
		try
		{
			z = r_value2(x, y);
		}
		catch (const char* s) // 捕获异常
		{
			cout << s << endl;
			continue;
		}
		cout << "z=" << z << endl;
	}
}


// 将对象作为异常类型
class bad_Input
{
public:
	bad_Input();
	~bad_Input();
	bad_Input(int a, int b);
	void mesg();
private:
	int a;
	int b;
};

bad_Input::bad_Input() {
	this->a = 0;
	this->b = 0;
}

bad_Input::~bad_Input() {}
inline bad_Input::bad_Input(int a, int b)
{
	this->a = a;
	this->b = b;
}
inline void bad_Input::mesg() {
	cout << "error occored" << endl;
}
int r_value3(int x, int y) {
	if ((x + y) < 0) {
		throw bad_Input(x, y); // 将对象作为异常类型 抛出异常
	}
	return (int)sqrt(x + y);
}
void T_Error2() {
	int x, y, z;
	while (cin >> x >> y) {
		try
		{
			z = r_value3(x, y);
		}
		catch (bad_Input& bi) // 捕获异常
		{
			bi.mesg();
			continue;
		}
		cout << "z=" << z << endl;
	}
}

void T_Error3() {  // hello
	int x, y, z=0;
	while (cin >> x >> y) {
		try
		{
			z = sqrt(x + y);
			cout << z << endl;
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}
}
