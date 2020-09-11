#include<iostream>
#include<string>
#include<set>
#include<iterator>
#include<algorithm>
using namespace std;
void Test_set() {
	cout << "Set的测试" << endl;
	string s1[12] = { "Failure" ,"is","not","threaten" };
	string s2[12] = { "Failure" ,"is","not","threaten" ,"but you should notice it" };
	set<string> A(s1, s1 + 5);
	set<string> B(s2, s2 + 10);
	ostream_iterator<string, char>out(cout, " ");
	cout << "A:" << endl;
	copy(A.begin(), A.end(), out);

	cout << endl;
	cout << "B：" << endl;
	copy(B.begin(), B.end(), out);

	cout << endl;
	cout << "AB并集：" << endl;
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);

	cout << endl;
	cout << "AB交集" << endl;
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);

	cout << endl;
	cout << "AB补集" << endl;
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);

	cout << endl;
	cout << "AB交集赋值给C" << endl;
	set<string> C;
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string> >(C, C.begin()));
	copy(C.begin(), C.end(), out);

	cout << endl;
	cout << "C插入hello后" << endl;
	string stemp("hello");
	C.insert(stemp);
	copy(C.begin(), C.end(), out);


	cout << endl;
	cout << "C的大小：" << C.size() << endl;

	cout << endl;
	cout << "C截取相应字符串" << endl;
	copy(C.lower_bound("but"), C.lower_bound("is"), out); // 从but开始到is之前（不包括is）
	cout << endl;

}
int main()
{
    std::cout << "Hello World!\n";
}