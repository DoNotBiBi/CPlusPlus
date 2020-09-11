
#include <iostream>

using namespace std;
// 排好序的二分法
bool BinarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (arr[middle] < target) left = middle + 1;
        else if (arr[middle] > target) right = middle - 1;
        else return true;
    }
    return false;
}
int main()
{
    int x[] = { 1,3,4,5,7,8,9 };
    if (BinarySearch(x, 7, 8)) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
    return 0;
}