#include <iostream>
#include <algorithm>
using namespace std;
// 快速排序
int getStandard(int a[], int low, int high)
{
	int key = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= key)
		{
			high--;
		}
		if (low < high)
		{
			a[low] = a[high];
		}

		while (low < high && a[low] <= key)
		{
			low++;
		}
		if (low < high)
		{
			a[high] = a[low];
		}
	}
	a[low] = key; // 每一趟的最后步骤
	return low;
}
void QuickSort(int a[], int low, int high)
{
	if (low < high)
	{
		//分段位置下标
		int standard = getStandard(a, low, high);
		QuickSort(a, low, standard - 1);
		QuickSort(a, standard + 1, high);
	}

}

// 冒泡排序
void BubbleSort(int a[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;

			}
		}
		for (int i = 0; i < len; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}


//简单选择

void SelectSort(int a[], int length)
{
	//对数组a排序,length是数组元素数量
	for (int i = 0; i < length; i++)
	{
		// 找到从i开始到最后一个元素中最小的元素,k存储最小元素的下标.
		int k = i;
		for (int j = i + 1; j < length; j++)
		{
			if (a[j] < a[k])
			{
				k = j;
			}
		}

		// 将最小的元素a[k] 和 开始的元素a[i] 交换数据.
		if (k != i)
		{
			int temp;
			temp = a[k];
			a[k] = a[i];
			a[i] = temp;
		}
	}
}
//插入排序
void Insertsort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) //与一个的进行比较，小的话就交换
		{
			arr[j + 1] = arr[j];//交换
			j--;//下标往前移动
		}
		arr[j + 1] = key;//不比前一个小，就不进行交换
	}
}

bool compare(int x, int y)
{
	return x > y;
}

typedef struct ss {
	int x;
	int y;
};
bool compare2(ss s1, ss s2) {
	if (s1.x == s2.x) {
		return s1.y < s2.y;
	}
	else {
		return s1.x < s2.x;
	}
}
int main()
{
	ss s[4] = { {1,2},{2,3},{2,2},{0,3} };
	sort(s, s+4,compare2);
	for (ss e : s) {
		cout << e.x << " " << e.y << endl;
	}
	int a[10] = { 1,4,8,2,9,2,0,12,5,8 };
	sort(a, a + 10);
	for (int e : a) {
		cout << e << endl;
	}
	/*
	int a[10]= {1,4,8,2,9,2,0,12,5,8};
	QuickSort(a,0,10);
	for(int i=0; i<10; i++)
	{
		cout<<a[i]<<" " ;
	}
	cout <<endl;
	
	
	int b[10] = { 1,4,8,2,9,2,0,12,5,8 };
	BubbleSort(b, 10);
	cout << "------------------";
	for (int i = 0; i < 10; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	
	int c[10]= {1,4,8,2,9,2,0,12,5,8};
	SelectSort(c,10);
	for(int i=0; i<10; i++)
	{
		cout<<c[i]<<" " ;
	}
	cout <<  endl;
	int d[10]= {1,4,8,2,9,2,0,12,5,8};
	Insertsort(d,10);
	for(int i=0; i<10; i++)
	{
		cout<<d[i]<<" " ;
	}
	cout <<  endl;
	int e[10] = { 1,4,8,2,9,2,0,12,5,8 };
	sort(e, e + 10, compare); // 从大到小
	// sort() vector.begin(),vector.end(),compare
	// sort() 结构体也可以排序 根据回调函数的特征
	for (int i = 0; i < 10; i++)
	{
		cout << e[i] << " ";
	}
	*/
	return 0;
}
