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
	//5.1 ��̬�滮������������˻�������
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
	//5.1����һ������ΪN���������飬ֻ�����ó˷��������ó�������������(N-1)����������г˻�����һ�顣
	int maxOnlyProductNumOfN(vector<int> v){
		int n = v.size();
		if (n == 0) return 0;
		if (n == 1) return 0;
		vector<int> left(n, 1), right(n, 1);
		for (int i = 1; i < n; i++){
			left[i] = left[i-1] * v[i-1];//��1��n-1
		}
		for (int j = n - 2; j >= 0; j--){
			right[j] = right[j + 1] * v[j + 1];//��0��n-2
		}
		int res = left[0] * right[0];
		for (int i = 1; i < n; i++)
			res = max(res, left[i] * right[i]);
		return res;
	}
	//5.2�ַ����༭���� ���� �� ɾ �滻 ʹs1��s2���һ��
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
	//5.3����ȡ������ 
	//����v��n*n��
	int gridMinPathSum_2Time(vector<vector<int>> v){
		int n = v.size();
		vector<vector<vector<int>>> dp(2 * n - 2 + 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
		
	}
	//5.4�����ַ��� s��s1��s2�����������
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
					//�����ʱ���ǵ��ڶԽ��� ���ǵ�����������ֵ�Ļ�����
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
	//5.5�������ַ���������������е��ַ����� �������ű�
	int MaxLongestCommonSubsequence(string s1, string s2){
		int len1 = s1.length();
		int len2 = s2.length();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				if (s1[i - 1] == s2[j - 1]){
					dp[i][j] = dp[i-1][j-1] + 1;
					//dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), dp[i][j]);
					// ��һ�䵽�׿ɲ�����ʡ��
				}
				else{
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}
		return dp[len1][len2];
	}
	//5.6�������ַ�����������Ӵ����ַ�����
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
	//5.7�����������������е����ָ��� ʱ�临�Ӷ���O(n��2�η�)
	int maxIncreaseNum(vector<int> v){
		int n = v.size();
		vector<int> dp(n, 1);//dp[i]������iλ��Ϊ��β������������и���
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
	//5.8 �ö�̬�滮���ַ������������������:���Բ�������abcfgbda 5
	//Ҳ����ѹ���������������Ƶ���now �� 1-now
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
	//5.8.1�ַ���������Ӷ��ٸ��ַ����һ�������ַ���
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
	//5.9���ַ�����������Ӵ�
	string maxSubstringPalindromic(string s){
		//Manacher�㷨:ά��һ������rl ����ֵ pos �� maxright
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
			if (rl[i] - 1 > result){//result�������Ļ����Ӵ�����
				result = rl[i] - 1;
				resultpos = i;
			}
		}
		return s.substr(resultpos / 2 - result / 2, result);
	}

	//2.1�ҵ���������С��k����
	//2.2Ѱ�Һ�Ϊ��ֵ��������
	vector<pair<int, int>> findTwoNumSumTarget(vector<int> v, int target){
		// ˼·������v��û����ͬ������,������Ȼ��ǰ��ָ�룬���м�б�
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
	//2.3Ѱ�Һ�Ϊ��ֵ�Ķ���� 1~n��ѡ���� ��Ϊtarget ������ѡ��
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
			//���Է�תv����ת��ȥ
			res.push_back(v);
			return;
		}
		v.push_back(n);
		FindN_NumSumTarget_help(res,v,n - 1, target - n);
		v.pop_back();
		FindN_NumSumTarget_help(res, v, n - 1, target);
	}
	//2.4�������������ĺ�
	int maxContinueSubArraySum(vector<int> v){
		if (v.empty()) return 0;
		int glomax = v[0];
		int submax = v[0];
		int left=0, right=0, start=0, end=0;
		//left,right��¼�ֲ����ֵ������  start,end��¼ȫ�����ֵ������
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
		
	/*	//��һ�ִ� ̰��
		int res = 0;
		int sub = 0;
		for (int i = 0; i < v.size(); i++){
			sub += v[i];
			res = max(res, sub);
			if (sub < 0) sub = 0;
		}
		return res;*/
	}
	//2.4 ��������Ϊn���������У�a0,a1,..,an-1���Լ�����S��������л��������������е������ܺʹ���S�ģ�
	//����Щ�����У���С�ĳ��ȡ�
	int findShortestBiggerThanTarget(vector<int> &v, int target){
		//˼·��ǰ������ָ�룬�����ж�
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
	//2.4������Ӿ����
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
		for (int i = 0; i < m; i++){//��i�е�j��
			for (int j = i; j < m; j++){
				vector<int> v(n, 0);
				for (int k = 0; k < n; k++){
					if (i == 0) v[k] = total[j][k];
					else v[k] = total[j][k] - total[i - 1][k];
				}
				int submax = maxContinueSubArraySum(v);
				//�����õ��� �������������� �ĺ���
				res = max(res, submax);
			}
		}
		return res;
	}
	//2.5 100Ԫ��1 2 5 10 �ж����ֻ���
	//�ö�̬�滮 ����01�������⣬ÿһ����Ʒ���Ա����ȡ
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

		//Ӧ��·��ѹ������һά����
		int n = coins.size();
		vector<int> dp(money + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= n; i++){
			for (int j = money; j >= 0; j--){
				for (int k = 1; k*coins[i-1] <= j; k++){
					dp[j] += dp[j - k*coins[i-1]];
					//����ע��dp[j]+=dp[j]��Ҫд��, ��Ȼ���ظ���,��k��1��ʼ�ͺ�
				}
			}
		}
		return dp[money];
	}
	//2.6������������ǰ�� ż�����ں���
	//˼·�����ƿ��ţ�ͷβ����ָ��
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
	//2.7������������ �����ҵ�012����
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
	//2.9����ϴ���㷨 û����

};

