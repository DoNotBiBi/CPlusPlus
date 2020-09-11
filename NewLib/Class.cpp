#include <iostream>
using namespace std;
#include <string>
class myClass
{
private:
    string gender;
    string address;

public:
    myClass();  // 默认的构造函数
    ~myClass(); // 析构函数
    void setGender(string gender)
    {
        this->gender = gender;
    }
    string getGender()
    {
        return this->gender;
    }

    void setAddress(string address)
    {
        this->address = address;
    }
    string getAddress()
    {
        return this->address;
    }

    myClass(const string &gender, const string &address); // 自定义构造函数  构造函数可以重载
    // 另一种形式 直接定义构造 省下一波代码
    // myClass(string g="male", string a="hb"):gender(g),address(a){}
    myClass operator+(myClass &temp) const;
    myClass operator+=(string &s) const;
    friend myClass changeaddress(string s, const myClass &t)
    { // 友元函数是可以直接访问私有部分的内容
        return t.operator+=(s);
    }
};
class STU : public myClass
{
    private:
        int id;
        string name;
        int age;

    public:
        STU();
        ~STU();
        STU(int id, string name, int age);
        STU(unsigned int id, string name, int age, string gender, string address);
        int getID();
        string getName();
        int getAge();
};
STU::STU()
{
}
STU::~STU()
{
}
STU::STU(int id, string name, int age)
{
    this->id = id;
    this->name = name;
    this->age = age;
}
STU::STU(unsigned int id, string name, int age, string gender, string address) : myClass(gender, address)
{ 
    //可以直接使用基类的构造函数
    this->id = id;
    this->name = name;
    this->age = age;
}

int STU::getID()
{
    return this->id;
}

string STU::getName()
{
    return this->name;
}

int STU::getAge()
{
    return this->age;
}

int main()
{

    //myClass* t_class = new myClass("male","hb");
    //cout << t_class->getGender() << endl;
    //cout << t_class->getAddress() << endl;
    //delete t_class;  // ´ËÊ±Îö¹¹º¯ÊýÆð×÷ÓÃ

    STU* s_class = new STU(1, "wangkang", 25, "male", "hb");
    cout << s_class->getID() << endl;
    cout << s_class->getName() << endl;
    cout << s_class->getAge() << endl;
    cout << s_class->getGender() << endl;
    cout << s_class->getAddress() << endl;
    return 0;
    
}