#include <iostream>
using namespace std;
#include<algorithm>
// 01背包
const int MAXN = 100;
int test_rucksuck()
{
	int dp[MAXN] = { 0 };
	int v[MAXN] = { 0 }; //物件价值
	int w[MAXN] = { 0 }; //物品重量
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		cin >> w[i] >> v[i];
	}
	for (int i = 0; i < m; ++i) {
		dp[i] = 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = m; j >= w[i]; --j) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			cout << j<<" "<<dp[j] <<" "<<endl;
		}
		cout << "------------------------------------------------------------------------------------------"<<endl;

	}
	cout << " "<<dp[m]<<endl;
	for (int i = 0; i <=m;i++) {
		cout << dp[i] << " ";
	}

}