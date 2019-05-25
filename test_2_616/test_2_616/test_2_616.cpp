// test_2_616.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
using namespace std;

int runningFarm(){
	int n, k;
	cin >> n >> k;
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n, 0)));
	dp[0][0][0] = 1;
	//vector<vector<int>>
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= i; j++){
			for (int s = 0; s < n; s++){
				dp[i][j][s] = dp[i - 1][j][s] + dp[i - 1][j - 1][(s - i + n) % n];
			}
		}
	}
	return dp[n][k][0];
}
int _tmain(int argc, _TCHAR* argv[])
{
	int res=runningFarm();
	cout << res;
	/*double n;
	cin >> n;
	double res;
	double up = 0;
	vector<double> v({ 2.0, 2.0 });

	double down = 2;
	for (int i = 2; i <= n; i++){
		vector<double> v2;
		for (int i = 0; i<v.size(); i++){
			v2.push_back(v[i]);
			v2.push_back(v[i] + 1);
		}
		v = v2;
		down = 2 * down;
	}
	for (int i = 0; i<v.size(); i++){
		up += v[i];
	}
	if (n == 1) up = 4.0;
	res = (double)up / down;
	res = double((int)(res * 10)) / 10.0;
	printf("%.1f", res);*/
	return 0;
}
	/*string s;
	cin >> s;
	int size = s.length();
	stack<char> sta;
	int count = 0;
	int res = 0;
	for (int i = 0; i < size; i++){
		char tmp = s[i];
		if (tmp == 'A' || tmp == 'B'){
			if (count == 0){

			}
			else{
				if (sta.empty()){
					
				}
				else{
					char top = sta.top();
					if (top == tmp){
						if (count % 2 == 0) res++;
					}
					else{
						if (count % 2 == 1) res++;
					}
				}
			}
			sta.push(tmp);
			count = 0;
		}
		else if (tmp == '?'){
			count++;
		}	
	}
	for (int i = 1; i < size; i++){
		if ((s[i] == 'A'&&s[i - 1] == 'A') || (s[i] == 'B'&&s[i - 1] == 'B')){
			res++;
		}
	}
	cout << res;*/


