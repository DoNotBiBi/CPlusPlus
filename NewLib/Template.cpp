#include<iostream>
using namespace std;
#include<string>
template <class Type>
class T_Class
{
private:
	Type a;
	Type b;
public:
	~T_Class();
	T_Class(Type a, Type b);  // 模板类的类默认的的构造函数只需要自定义的 
	Type add();
};

template<typename T>
T square(T &x) {
	// typedef decltype(x) hello //可以通用x的类型
	return x * x;
}
T_Class<int>::T_Class(int a,int b) {
	this->a = a;
	this->b = b;
}

int T_Class<int>::add() {
	return this->a + this->b;
}
//int a = 2;
//int b = square<int>(a);
//cout << b << endl;

int main()
{
	T_Class<int>* t = new T_Class<int>(2,3);
	cout<<t->add()<<endl;
	return 0;
}