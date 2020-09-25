// Test_File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<vector>
#include<map>
using namespace std;
/*
ios::app  追加
ios::ate
ios::binary
ios::in
ios::out
ios::nocreate
ios::noreplace
ios::trunc
*/
void String_Split(string s, string delim, vector<string>& ans)
{
	int pos_1, pos_2 = 0;
	while (pos_2 != s.npos) {
		pos_1 = s.find_first_not_of(delim, pos_2); // 第二个参数为偏移量
		if (pos_1 == s.npos) break;
		pos_2 = s.find_first_of(delim, pos_1);
		ans.push_back(s.substr(pos_1, pos_2 - pos_1));
	}
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

// 写二进制文件
void test_ofs(string filename) {
	ofstream ofs;
	ofs.open(filename, ios_base::binary | ios_base::app); // 追加模式 二进制
	string test = "hello";
	ofs << test;
	ofs.clear();
	ofs.close();
}

// 读二进制文件
void test_ifs(string filename) {
	ifstream in;
	in.open(filename.c_str(), ios_base::in | ios_base::binary);
	char* buffer = new char[100];
	in.seekg(0, ios_base::end);
	int a = in.tellg();
	cout << a << endl;
	in.seekg(0, ios_base::beg);
	in.read(buffer, a);

	in.close();
	string s(buffer, buffer + a);
	cout << s;
	delete[] buffer;
}
//


// 统计单词个数
void Countword(string filename) {
	ifstream ifs;
	ifs.open(filename);
	if (!ifs.is_open()) {
		cout << "打开文件失败";
	}
	map<string, int> m; //使用map省下好多事情
	while (!ifs.eof()) {
		string line;
		ifs >> line; //直接一个个单词的读 读取不了空格
		cout << line << endl;
		if (!line.empty()) {//是为了防止最后读取的空格，出现一个的1
			m[line]++;
		}
		
	}

	map<string, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		cout<<it->first<<" "<<it->second<<endl;
	}

}
void test_file()
{
	ifstream ifs;
	string filename = "in.txt";
	
	//Countword(filename);
	/*
	ifstream ifs;
	string filename = "in.txt";
	ifs.open(filename);
	if(!ifs.is_open()){
		cout<<"打开文件失败";
	}
	string line;
	int n = 0;
	const string delim = " ";
	vector<ValueType> v;
	while (!ifs.eof())
	{
		vector<string> ss;
		getline(ifs,line);
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
	ifs.close();
	ofstream ofs;
	ofs.open("out.txt");
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].count >= 1)
			ofs << v.at(i).word << " " << v.at(i).at_line << " " << v.at(i).count << endl;
	}
	ofs.close();
	*/
	
	
	


	
}