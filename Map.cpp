#include <iostream>
using namespace std;
#include<string>
#include <map>
#include<stdlib.h>

typedef struct student {
    string name;
    string gender;
    int age;
}student;
// map 
// key 自动判断有没有重复 若没有直接添加 反正不会重复
int main()
{
    /*
    map<string, int> stu;  // 默认 first元素 自动排序 不排序用unordered_map
    stu["wangkang"] = 25;
    stu["heqing"] = 19;
    stu.insert(pair<string, int>("chenqinwu", 19));
    stu.insert(pair<string, int>("maohaoyu", 20));
    stu.insert(pair<string, int>("xiaowei", 23));
    cout << stu.size() << endl;
    cout << stu["chenqinwu"] << endl;
    cout << stu.at("xiaowei") << endl;
    stu.erase("chenqinwu");
    cout << "------------------------------------------------"<<endl;
    map<string, int>::iterator it;
    for (it = stu.begin(); it != stu.end(); it++) {   // 使用迭代器
        cout << it->first << " " << it->second << endl;
    }
    */
    map<int, student> stu2;
    for (int i = 0; i < 5; i++) {
        string str;
        getline(cin, str);
        int pos = str.find(" ");
        string name = str.substr(0, pos);
        str.erase(0, pos+1);
        pos = str.find(" ");
        string gender= str.substr(0, pos);
        str.erase(0, pos+1);
        int age = atoi(str.c_str());
        stu2.insert(pair<int, student>(i, { name,gender,age }));
    }

    for (int i = 0; i < 5; i++) {
        cout << stu2[i].name << " "<<stu2[i].gender<<" "<<stu2[i].age << endl;
    }
    return 0;
}





int Reverse(int x)
{
    int revx = 0;
    while (x != 0)
    {
        revx *= 10;
        revx += x % 10;
        x = x / 10;
    }
    return revx;
}

void print_ss(char a[][30], int n, char c1, char c2)
{
    for (int i = 0; i <= n / 2; i++)
    {
        for (int j = 0; j <= n / 2; j++)
        {
            if (j <= i)
            {
                if (j % 2 == 0)
                    a[i][j] = c1;
                else
                    a[i][j] = c2;
            }
            else
            {
                a[i][j] = a[i][i];
            }
        }

        for (int j2 = n / 2 + 1; j2 < n; j2++)
        {
            a[i][j2] = a[i][n - 1 - j2];
        }
    }
    for (int i2 = n / 2; i2 < n; i2++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i2][j] = a[n - 1 - i2][j];
        }

    }
    if (n > 1) {
        a[0][0] = ' ';
        a[0][n - 1] = ' ';
        a[n - 1][0] = ' ';
        a[n - 1][n - 1] = ' ';
    }
    
}


int daytab[2][13] =
{
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};
int IsleapYear(int year)
{
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Dayofyear(int year)
{
    if (IsleapYear(year))
    {
        return 366;
    }
    else
    {
        return 365;
    }
}

const int MAX = 1000;
bool arr[MAX];
void t_2_9(int n1, int n2)
{
    int l, m;
    int count = n1 + 1;
    for (int i = 0; i <= n1; i++)
    {
        arr[i] = false;
    }
    while (n2 > 0)
    {
        scanf("%d%d", &l, &m);


        for (int k = l; k <= m; k++)
        {
            if (!arr[k])
            {
                arr[k] = true;
                count--;
            }
        }

        --n2;
    }

    cout << count;
    /*
    for(int i=0; i<=n1; i++)
    {
        if(!arr[i])
            count++;
    }
    */

}
// int main()
// {
//     /*char c[30][30];
//     int n=5;
//     char c1='@';
//     char c2='W';
//     print_ss(c,n,c1,c2);
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             cout<<c[i][j];
//         }
//         cout<<endl;
//     }
//     t_2_9(500,3);
//     */
//     int a =/**/ 3;
//     cout << a;
//     return 0;
// }