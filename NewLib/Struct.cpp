// Test_Struct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include<iostream>
using namespace std;
union MyUnion
{
	int a;
	double b;
	float c;
};


enum MyEnum
{
	monday = 1,
	tuesday = 2,
	thresday = 3
};

typedef struct myStruct {
	int n_num;
	float f_num;
	string s_string;
}*mystruct_p;
void test_pointer()
{
	mystruct_p test = new myStruct{ 3, 4, "hello" };
	cout << test->f_num << " " << test->n_num << " " << test->s_string << endl;

	myStruct TEST2[2] = { {1,2,"HELLO"},{3,4,"WORLD"} };
	cout << TEST2[1].s_string << endl;

	MyUnion test_union;
	test_union.a = 1;
	cout << test_union.a << endl;
	test_union.b = 3;
	cout << test_union.b << endl;

	MyEnum test_Enum{};
	cout << monday << endl;
	int aa = 3, * p;
	p = &aa;
	cout << *p << endl;
	int* p2 = new int;
	*p2 = 213;
	cout << sizeof(p2) << endl;
	delete p2;

	int* p_int_array = new int[10]{ 1,4,2,0,3,5,8,9,6,7 };
	for (int i = 0; i < 10; i++)
	{
		cout << *(p_int_array + i) << " ";
	}

	cout << endl;
	int* pp = p_int_array;
	for (; pp != (p_int_array + 10); ++pp)
	{
		cout << *pp << " ";
	}

	delete[] p_int_array;
	cout << endl;
	mystruct_p test_struct = new myStruct{ 1,3,"hello" };
	cout << test_struct->s_string << endl;
}

void test_pointer2() {
	int test[4][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	int a = 9;
	int* p1 = &a;
	int** p2 = &p1;
	cout << *p1 << endl;
	cout << **p2 << endl;
	/*
	int** p=new int*[4];
	p = (int**)test;
	for (int i = 0; i < 4; i++) {
		p[i] = new int[4];
	}
	for (int i = 0; i < 4; i++) {
		p[i] = &test[i][0];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << (int)(*(*(p + i) + j)) << " ";
		}
		cout << endl;
	}
	//�ͷ�ÿһ��ָ��
	for (int i = 0; i < 4; i++) {
		delete[] p[i];
	}
	*/
	int(*p)[4][4] = &test;
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			cout << (*p)[i][j] << " ";
		}
		cout << endl;
	}


	int(*p3)[4];
	p3 = &test[0];
	int i = 0;
	while (i < 4) {
		for (int j1 = 0; j1 < 4; j1++) {
			cout << (*p3)[j1] << " ";
		}
		cout << endl;
		p3++;
		i++;
	}

}

void test_p(int(*p)[4], int n) {
	int i = 0;
	while (i < 4) {
		for (int j1 = 0; j1 < n; j1++) {
			cout << (*p)[j1] << " ";
		}
		cout << endl;
		p++;
		i++;
	}
}


void test_pointer3() {
	void (*p1)(void);
	p1 = test_pointer2;
	p1();
}


void swap1(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void swap2(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void swap3(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}


int add(int& x) {
	x = x + x;
	return x;
}

mystruct_p test_pointer4(mystruct_p& TEST) {
	mystruct_p test = new myStruct;
	test->f_num = TEST->f_num;
	test->n_num = TEST->n_num;
	test->s_string = TEST->s_string;
	return test;
}
/*
	mystruct_p p1 = new myStruct{ 2,3,"wangkang" };
	mystruct_p p2 = test_pointer4(p1);
*/
int main()
{
    std::cout << "Hello World!\n";
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct STU1 { // typedef 前后名字可以不一致
    char* name;
    int age;
}STU1;
typedef struct STU2 { // typedef 前后名字可以不一致
    char name[20];
    int age;
}STU2;
void setname1(char name[]) {
    strcpy(name, "NAME21");
}
void setname2(char* name) {
    name = (char*)malloc(10);
    strcpy(name, "NAME22");
}
void setname3(char* name) {
    strcpy(name, "NAME23");
}
int main()
{
    STU1 s1 = { NULL,23 };
    s1.name = (char*)malloc(10); // 当为字符串时，必须要给予空间
    strcpy(s1.name, "NAME0");
    printf("s1:%s-%d\n", s1.name, s1.age);

    STU1 s2 = { NULL,26 };
    setname2(s2.name); // 值传递，并不能起作用
    printf("s2:%s-%d\n", s2.name, s2.age);

    s2 = s1;
    s2.age = 26;
    strcpy(s2.name, "common_name");  // 由于两者共用字符串内存，故两者相等
    printf("s1:%s-%d\n", s1.name, s1.age);
    printf("s2:%s-%d\n", s2.name, s2.age);

    s2.name = (char*)malloc(10); // 这时候s2.name才有自己的空间
    strcpy(s2.name, "s2_name");
    printf("s1:%s-%d\n", s1.name, s1.age);
    printf("s2:%s-%d\n", s2.name, s2.age);

    printf("-------------------------------------\n");
    STU2 s3 = { "s3_name",25 };
    printf("s3:%s-%d\n", s3.name, s3.age);
    setname1(s3.name);
    printf("s3_setname1:%s-%d\n", s3.name, s3.age);
    setname2(s3.name); // 此时不能起作用
    printf("s3_setname2:%s-%d\n", s3.name, s3.age);
    setname3(s3.name);
    printf("s3_setname3:%s-%d\n", s3.name, s3.age);
    STU2 s4 = s3;
    printf("s4:%s-%d\n", s4.name, s4.age);
    strcpy(s4.name, "s4_newname"); // 由于是字符数组，所以不用担心内存的问题
    printf("s4:%s-%d\n", s4.name, s4.age);
    return 0;
}
*/