// Test_Basic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
namespace mySpace { // 名称空间
	int add(int a, int b) {
		return a + b;
	}
	int a = 2;
}
int main()
{
	//const为限定符  
	// 1.明确指定类型
	// 2.将定义限制在特定的函数或文件中
	// 3.使用const可以避免无意中修改数据的编程错误;
	// 4.使用const使函数能够处理const和非const实参，否则将只能接受非const数据;
	// 5.使用const引用使函数能够正确生成并使用临时变量。

	const int months = 12;

	// int& 指向int变量的引用
	// 声明时必须初始化 相当于起了一个别名
	int r = 1;
	int& r2 = r;
	cout << r2 << endl;


	int a1 = 2, a2 = 4;
	cout << mySpace::add(a1, a2) << endl;
	cout << mySpace::a << endl;
	cout << "hello wangkang";
}