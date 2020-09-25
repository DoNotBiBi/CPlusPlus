#include <iostream>
#include<algorithm>
using namespace std;
const int MAXN = 10000;
long long arr[MAXN], dp[MAXN];
long long matrix[MAXN][MAXN],total[MAXN][MAXN];
long long MaxSubSequence(int n) {
    long long maxinum = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            dp[i] = arr[i];
        }
        else {
            dp[i] = max(arr[i],dp[i-1]+arr[i]);
        }
        maxinum = max(maxinum, dp[i]);
    }

    return maxinum;
}

long long MaxSubmatrix(int n) {
    int maximal = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (i == 0) {
                    arr[k] = total[j][k];
                }
                else {
                    arr[k] = total[j][k] - total[i - 1][k];
                }
            }

            long long current = MaxSubSequence(n);
            maximal = max(maximal, (int)current);
        }
    }

    return maximal;
}
void test_dynamic()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0) {
                total[i][j] = matrix[i][j];
            }
            else {
                total[i][j] = total[i - 1][j] + matrix[i][j];
            }
        }
    }

    int answer = MaxSubmatrix(n);
    cout << answer << endl;

    
    cout << "arr:";
    for (int i = 0; i < 100; ++i) cout << arr[i] << " ";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---" << endl;;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout <<total[i][j] << " ";
        }
        cout << endl;
    }
    
    
    
}