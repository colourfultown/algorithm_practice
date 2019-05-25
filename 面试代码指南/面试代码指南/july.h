#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
class july
{
public:
	july();
	~july();
	//5.1 动态规划——最大连续乘积子数组
	int maxProductSubVec(vector<int> v){
		int size = v.size();
		if (size == 0) return 0;
		int submax = v[0];
		int submin = v[0];
		int glomax = v[0];
		for (int i = 1; i < size; ++i){
			int t1 = submax*v[i], t2 = submin*v[i];
			submax = max(max(t1, t2), v[i]);
			submin = min(min(t1, t2), v[i]);
			glomax = max(glomax, submax);
		}
		return glomax;
	}
	//5.1给定一个长度为N的整数数组，只允许用乘法，不能用除法，计算任意(N-1)个数的组合中乘积最大的一组。
	int maxOnlyProductNumOfN(vector<int> v){
		int n = v.size();
		if (n == 0) return 0;
		if (n == 1) return 0;
		vector<int> left(n, 1), right(n, 1);
		for (int i = 1; i < n; i++){
			left[i] = left[i-1] * v[i-1];//从1到n-1
		}
		for (int j = n - 2; j >= 0; j--){
			right[j] = right[j + 1] * v[j + 1];//从0到n-2
		}
		int res = left[0] * right[0];
		for (int i = 1; i < n; i++)
			res = max(res, left[i] * right[i]);
		return res;
	}
	//5.2字符串编辑距离 可以 增 删 替换 使s1和s2变得一样
	int StringAToStringBModificationNum(string s1, string s2){
		int len1 = s1.length();
		int len2 = s2.length();
		vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
		dp[0][0] = 0;
		for (int i = 1; i <= len1; i++)
			dp[i][0] = i;
		for (int i = 1; i <= len2; i++)
			dp[0][i] = i;
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				int tihuan = dp[i - 1][j - 1];
				if (s1[i - 1] == s2[j - 1])
					;
				else
					tihuan += 1;
				dp[i][j] = min(min(dp[i-1][j],dp[i][j-1] )+1,tihuan );
			}
		}
		return dp[len1][len2];
	}
	//5.3格子取数问题 
	//假设v是n*n的
	int gridMinPathSum_2Time(vector<vector<int>> v){
		int n = v.size();
		vector<vector<vector<int>>> dp(2 * n - 2 + 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
		
	}
	//5.4交替字符串 s是s1与s2交替而来的吗？
	bool isInterString(string s, string s1, string s2){
		int len = s.length();
		int len1 = s1.length();
		int len2 = s2.length();
		if ((len1 + len2) != len) 
			return false;
		vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, true));
		for (int k = 1; k <= len1; k++){
			if (s[k - 1] == s1[k - 1]){
				dp[k][0] = dp[k - 1][0];
			}
			else{
				dp[k][0] = false;
			}
		}
		for (int k = 1; k <= len2; k++){
			if (s[k - 1] == s2[k - 1]){
				dp[0][k] = dp[0][k - 1];
			}
			else{
				dp[0][k] = false;
			}
		}
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				if (s[i + j - 1] == s1[i - 1] && s[i + j - 1] == s2[j - 1]){
					//都相等时不是等于对角线 而是等于相邻两个值的或运算
					dp[i][j] = dp[i][j - 1]||dp[i-1][j];
				}
				else if (s[i + j - 1] == s1[i - 1]){
					dp[i][j] = dp[i - 1][j];
				}
				else if (s[i + j - 1] == s2[j - 1]){
					dp[i][j] = dp[i][j - 1];
				}
				else{
					dp[i][j] = false;
				}
			}
		}
	  /*for (int i = 0; i <= len1; i++){
			for (int j = 0; j <= len2; j++)
				cout << dp[i][j] << " ";
			cout << endl;
		}*/
		
		return dp[len1][len2];
	}
	//5.5求两个字符串的最长公共子序列的字符个数 可以跳着比
	int MaxLongestCommonSubsequence(string s1, string s2){
		int len1 = s1.length();
		int len2 = s2.length();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				if (s1[i - 1] == s2[j - 1]){
					dp[i][j] = dp[i-1][j-1] + 1;
					//dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), dp[i][j]);
					// 这一句到底可不可以省略
				}
				else{
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}
		return dp[len1][len2];
	}
	//5.6求两个字符串的最长公共子串的字符个数
	int MaxLongestCommonSubString(string s1, string s2){
		int len1 = s1.length();
		int len2 = s2.length();
		int res = 0;
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				if (s1[i - 1] == s2[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
					res = max(res, dp[i][j]);
				}
				else{
					dp[i][j] = 0;
				}
			}
		}
		return res;
	}
	//5.7求数组的最长递增子序列的数字个数 时间复杂度是O(n的2次方)
	int maxIncreaseNum(vector<int> v){
		int n = v.size();
		vector<int> dp(n, 1);//dp[i]保存以i位置为结尾的最长递增子序列个数
		int res = 0;
		for (int i = 1; i < n; ++i){
			for (int j = i - 1; j >= 0; --j){
				if (v[i]>v[j]&&dp[j]+1>dp[i]){
					dp[i] = dp[j] + 1;
					res = max(res, dp[i]);
				}
			}
		}
		return res;
	}
	//5.8 用动态规划求字符串最长回文子序列问题:可以不连续的abcfgbda 5
	//也可以压缩成两行来互相推导，now 与 1-now
	int  maxSequenceStringPalindromic(string s){
		int n = s.length();
		vector<vector<int>> dp(n,vector<int>(n,0));
		for (int k = 0; k < n; k++)
			dp[k][k] = 1;
		for (int k = 1; k < n; k++){
			for (int i = 0,j = k; i < n&&j < n; i++, j++){
				if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1] + 2;
				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		return dp[0][n - 1];
	}
	//5.8.1字符串最少添加多少个字符变成一个回文字符串
	int minAddCharNumChangeToPalindromic(string s){
		int n = s.length();
		if (0 == n) return 0;
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int k = 1; k < n; k++){
			for (int i = 0, j = k; i < n&&j < n; i++, j++){
				if (s[i] == s[j]){
					dp[i][j] = dp[i + 1][j - 1];
				}
				else{
					dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
				}
			}
		}
		return dp[0][n - 1];
	}
	//5.9求字符串的最长回文子串
	string maxSubstringPalindromic(string s){
		//Manacher算法:维护一个数组rl 两个值 pos 和 maxright
		string tmp(s);
		int n = s.length();
		for (int i = 0, k = 0; i <= n; i++, k += 2)
			tmp.insert(k, "#");
		int len = 2 * n + 1;
		int pos = 0, maxright = 0;
		int result = 0, resultpos = 0;
		vector<int> rl(len, 1);
		for (int i = 0; i < len; i++){
			if (i < maxright){
				rl[i] = min(rl[2 * pos - i], maxright - i);
			}
			else{
				rl[i] = 1;
			}
			while (i - rl[i] >= 0 && i + rl[i] < len && tmp[i - rl[i]] == tmp[i + rl[i]]){
				rl[i]++;
			}
			if ((i + (rl[i] - 1)) > maxright){
				maxright = rl[i] + i - 1;
				pos = i;
			}
			if (rl[i] - 1 > result){//result就是最大的回文子串长度
				result = rl[i] - 1;
				resultpos = i;
			}
		}
		return s.substr(resultpos / 2 - result / 2, result);
	}

	//2.1找到数组中最小的k个数
	//2.2寻找和为定值的两个数
	vector<pair<int, int>> findTwoNumSumTarget(vector<int> v, int target){
		// 思路：假设v中没有相同的数字,先排序，然后前后指针，往中间夹逼
		sort(v.begin(), v.end());
		int left = 0; int right = v.size() - 1; 
		vector<pair<int, int>> result;
		while (left < right){
			if (v[left] + v[right] == target){
				result.push_back(pair<int, int>({ v[left], v[right] }));
				left++; right--;
			}
			else if (v[left] + v[right] > target){
				right--;
			}
			else {
				left++;
			}
		}
		return result;
	}
	//2.3寻找和为定值的多个数 1~n中选择数 和为target 的所有选法
	vector<vector<int>> FindN_NumSumTarget(int n,int target){
		vector<vector<int>> res;
		vector<int> v;
		FindN_NumSumTarget_help(res, v, n, target);
		return res;
	}
	void FindN_NumSumTarget_help(vector<vector<int>> &res, vector<int> &v, int n,int target){
		if (n < 0 || target < 0)
			return;
		if (target == 0){
			//可以翻转v，再转回去
			res.push_back(v);
			return;
		}
		v.push_back(n);
		FindN_NumSumTarget_help(res,v,n - 1, target - n);
		v.pop_back();
		FindN_NumSumTarget_help(res, v, n - 1, target);
	}
	//2.4最大连续子数组的和
	int maxContinueSubArraySum(vector<int> v){
		if (v.empty()) return 0;
		int glomax = v[0];
		int submax = v[0];
		int left=0, right=0, start=0, end=0;
		//left,right记录局部最大值的区间  start,end记录全局最大值的区间
		for (int i = 1; i < v.size(); i++){
			if (submax + v[i]>v[i]){
				right = i;
			}
			else{
				left = i;
				right = i;
			}
			submax = max(submax + v[i], v[i]);
			if (submax > glomax){
				start = left;
				end = right;
			}
			else{

			}
			glomax = max(submax, glomax);

		}
		return glomax;
		
	/*	//另一种答案 贪心
		int res = 0;
		int sub = 0;
		for (int i = 0; i < v.size(); i++){
			sub += v[i];
			res = max(res, sub);
			if (sub < 0) sub = 0;
		}
		return res;*/
	}
	//2.4 给定长度为n的整数数列：a0,a1,..,an-1，以及整数S。这个数列会有连续的子序列的整数总和大于S的，
	//求这些数列中，最小的长度。
	int findShortestBiggerThanTarget(vector<int> &v, int target){
		//思路：前后两个指针，不断判断
		int start = 0, end = 0;
		int res = INT_MAX;
		int sum = 0;
		while (end < v.size()){
			sum += v[end++];
			if (sum < target) continue;
			while (sum >= target){
				sum -= v[start++];
			}
			res = min(res, end - start + 1);
		}
		return res;
	}
	//2.4求最大子矩阵和
	int maxSubMatrix(vector<vector<int>> &matrix){
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> total = matrix;
		for (int i = 1; i < m; i++){
			for (int j = 0; j < n; j++){
				total[i][j] = total[i - 1][j]+total[i][j];
			}
		}
		int res = 0;
		for (int i = 0; i < m; i++){//从i行到j行
			for (int j = i; j < m; j++){
				vector<int> v(n, 0);
				for (int k = 0; k < n; k++){
					if (i == 0) v[k] = total[j][k];
					else v[k] = total[j][k] - total[i - 1][k];
				}
				int submax = maxContinueSubArraySum(v);
				//这里用到求 最大连续子数组和 的函数
				res = max(res, submax);
			}
		}
		return res;
	}
	//2.5 100元换1 2 5 10 有多少种换法
	//用动态规划 类似01背包问题，每一个物品可以被多次取
	int changeMoneyNum(vector<int> &coins, int money){
		/*int n = coins.size();
		vector<vector<int>> dp(n + 1, vector<int>(money + 1, 0));
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++){
			for (int j = 0; j <= money; j++){
				if (j == 0) dp[i][j] = 1;
				else{
					dp[i][j] = dp[i - 1][j];
					for (int k = 1; k*coins[i - 1] <= j; k++){
						dp[i][j] += dp[i - 1][j - k*coins[i - 1]];
					}
				}
			}
		}
		return dp[n][money];*/

		//应用路径压缩，用一维数组
		int n = coins.size();
		vector<int> dp(money + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= n; i++){
			for (int j = money; j >= 0; j--){
				for (int k = 1; k*coins[i-1] <= j; k++){
					dp[j] += dp[j - k*coins[i-1]];
					//这里注意dp[j]+=dp[j]不要写了, 不然就重复了,让k从1开始就好
				}
			}
		}
		return dp[money];
	}
	//2.6奇数放在数组前面 偶数放在后面
	//思路：类似快排，头尾两个指针
	void oddEvenSort(vector<int> &v){
		int left = 0, right = v.size()-1;
		while (left < right){
			if ((v[left] & 1) == 1){
				left++;
			}
			else if ((v[right] & 1) == 0){
				right--;
			}
			else{
				swap(v[left], v[right]);
			}
		}
	}
	//2.7荷兰国旗问题 将打乱的012排序。
	void HelanNationalFlag(vector<int> &v){
		int start = 0, cur = 0, end = v.size() - 1;
		while (cur <= end){
			if (v[cur] == 0){
				swap(v[cur], v[start]);
				start++;
				cur++;
			}
			else if (v[cur] == 1){
				cur++;
			}
			else if (v[cur] == 2){
				swap(v[cur], v[end]);
				end--;
			}
		}
	}
	//2.9完美洗牌算法 没看懂

};

