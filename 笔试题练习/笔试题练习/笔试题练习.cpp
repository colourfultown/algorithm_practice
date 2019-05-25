// 笔试题练习.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

void richman(){
	int n;
	cin >> n;
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	for (int j = 1; j <= n&&j <= 6; j++)
		dp[1][j] = 1;
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= 6; k++){
				if (j - k > 0)
				    dp[i][j] += dp[i - 1][j - k];
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		res += dp[i][n];
	cout << res;
}
void makeUpMoney(){//1 5 10 20 50 100
	int n; cin >> n;
	typedef long long ll;//当我用int时 数太大会越界的 改用longlong都通过了
	vector<vector<ll>> dp(7, vector<ll>(n + 1, 0));
	vector<ll> money({ 1, 5, 10, 20, 50, 100 });
	for (int i = 0; i < 7; i++)
		dp[i][0] = 1;
	for (int i = 1; i < 7; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 0; j-k*money[i - 1] >= 0; k++)
				dp[i][j] += dp[i - 1][j - k*money[i - 1]];
		}
	}
	cout<<dp[6][n];
}
void maxMatrix(){
	int n; cin >> n;
	vector<int> v(n,0);
	for (int i = 0; i < n; i++){
		int t; cin >> t;
		v[i] = t;
	}
	stack<int> s;
	int res = 0;
	for (int i = 0; i < n; i++){
		while (!s.empty() && v[i]<=v[s.top()]){
			int j = s.top();
			s.pop();
			int k = s.empty() == 1 ? -1 : s.top();
			res = max(res, v[j] * (i - k - 1));
		}
		s.push(i);
	}
	while (!s.empty()){
		int j = s.top();
		s.pop();
		int k = s.empty() == 1 ? -1 : s.top();
		res = max(res, v[j] * (n - k - 1));
	}
	cout << res;
}
void maxSubstring(){
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int len1 = s1.length();
	int len2 = s2.length();
	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1,0));
	for (int i = 1; i <= len1; i++){
		for (int j = 1; j <= len2; j++){
			if (s1[i - 1] == s2[j - 1]){
				dp[i][j] = dp[i - 1][j - 1]+1;
			}
			else{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	cout << dp[len1][len2];

}
//假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，
//形成一个数组如下
void charCode(){

}
void game1024(){
	int id1, id2; cin >> id1 >> id2;
	if (id1 > 1024 || id1<1 || id2>1024 || id2 < 1){
		cout << -1;
		return;
	}
	unsigned int arr[32] = {0};
	arr[(id1 - 1) / 32] |= 1 << ((id1 - 1) % 32);
	cout << ((arr[(id2 - 1) / 32] & (1 << ((id2 - 1) % 32)))!=0);
}
bool isSu(int k){
	if (k < 3) return false;
	for (int i = 2; i <= k / 2; i++){
		if (0 == k%i) return false;
	}
	return true;
}
void sushudui(){
	int n; cin >> n;
	int left = n/2;
	int right = n % 2 == 1 ? n / 2 + 1 : n / 2;
	int res = 0;
	while (left > 1){
		if (isSu(left) && isSu(right))
			res++;
		left--;
		right++;
	}
	cout << res;
}
void geohash(){
	int x; cin >> x;
	int left = -90;
	int right = 90;
	string s;
	int count = 6;
	while (count--){
		int mid = (left + right) / 2;
		if (mid <= x){
			left = mid;
			s += "1";
		}
		else{
			right = mid;
			s += "0";
		}
	}
	cout << s;
}
int _tmain(int argc, _TCHAR* argv[])
{

	char c = 255;
	cout << (int)c << endl;
	unsigned short b = c;
	cout << b << endl;
	return 0;
}

