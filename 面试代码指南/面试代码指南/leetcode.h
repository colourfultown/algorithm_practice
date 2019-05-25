#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<queue>
using namespace std;
class leetcode
{
public:
	leetcode();
	~leetcode();
	//leetcode 判断n皇后个数 两个辅助函数
	int totalNQueens(int n) {
		//判断对角线相等 可以用对应行减行列减列 差相等就在一个对角线上
		//用一个数组保存第几行的Q在第几列
		int result = 0;
		if (n == 0) return 0;
		if (n == 1) return 1;
		vector<int> state(n, -1);
		helpQueens(result, state, 0);
		return result;

	}
	void helpQueens(int result, vector<int> &state, int row){
		int n = state.size();
		if (row == n){
			result++; return;
		}
		for (int col = 0; col<n; col++){
			if (isValidQueens(state, row, col)){
				state[row] = col;
				helpQueens(result, state, row + 1);
				state[row] = -1;
			}
		}
	}
	bool isValidQueens(vector<int> &state, int row, int col){
		for (int i = 0; i<row; i++){
			if (state[i] == col || abs(row - i) == abs(col - state[i]))
				return false;
		}
		return true;
	}
	//两个大数string相乘
	string multiply(string num1, string num2) {
		int m = num1.length(), n = num2.length();
		int k = m + n;
		vector<int> v(k, 0);
		for (int i = 0; i<m; i++){
			for (int j = 0; j<n; j++){
				v[i + j+1] += (num1[i] - '0')*(num2[j] - '0');
			}
		}
		int carry = 0;
		for (int i = k - 1; i >= 0; i--){
			v[i] += carry;
			carry = v[i] / 10;
			v[i] = v[i] % 10;
		}
		int i;
		for (i = 0; i<k; i++){
			if (v[i] != 0){
				break;
			}
		}
		if (i == k) return "0";
		string str;
		for (int j = i; j < k;j++)
			str += to_string(v[j]);
		return str;
	}
	//num中不能重复选择 和等于target的组合
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int>> result;
		vector<int> v;
		sort(num.begin(), num.end());
		help(result, num, v, target, 0, 0);
		//set<vector<int>> s(result.begin(),result.end());
		//vector<vector<int>> res(s.begin(),s.end());

		return result;
	}
	void help(vector<vector<int>> &result, vector<int> &num,
		vector<int> &v, int target, int sum, int pos){
		if (sum == target){
			result.push_back(v);
			return;
		}
		for (int i = pos; i<num.size();i++){
			int newnum = num[i];
			if (newnum + sum <= target){
				v.push_back(newnum);
				help(result, num, v, target, newnum + sum, i + 1);
				v.pop_back();
			}
			else{
				break;
			}
			i++;
			while (i<num.size() && num[i] == num[i - 1]) i++;
			//这两行代码保证了某一个数被选择后，跟它相等的数在此回合不会再被选择
		}
	}
	//1->11->21->1211->111221->312211
	string countAndSay(int n) {
		vector<int> v({1});
		for (int i = 1; i < n; i++){
			vector<int> t;
			int count = 1;
			int tmp = v[0];
			for (int k = 1; k < v.size(); k++){
				if (v[k] == tmp){
					count++;
				}
				else{
					t.push_back(count);
					t.push_back(tmp);
					tmp = v[k];
					count = 1;
				}
			}
			t.push_back(count);
			t.push_back(tmp);
			v = t;
		}
		string str;
		for (int i = 0; i < v.size(); i++)
			str += to_string(v[i]);
		return str;
	}
	//解决9*9的数独方格
	void solveSudoku(vector<vector<char> > &board) {
		int row = board.size();
		if (row != 9) return;
		int col = board[0].size();
		if (col != 9) return;
		solveSudoku(board, 0, 0);
	}
	bool solveSudoku(vector<vector<char> > &board, int i, int j){
		//返回一个布尔型，判断数独是否能被破解
		if (j >= 9) return solveSudoku(board, i + 1, 0);
		if (i == 9) return true;
		if (board[i][j] == '.'){
			for (int k = 1; k <= 9; k++){
				board[i][j] = '0' + k;
				//bool result = false;
				if (isValidSudoku(board, i, j)){
					if (solveSudoku(board, i , j+1))
						return true;
				}
				board[i][j] = '.';
			}
		}
		else{
			return solveSudoku(board, i, j + 1);
		}
		return false;//这个false是因为某个位置1~9都尝试了一遍结果都不行，那就返回false，回溯
	}
	bool isValidSudoku(vector<vector<char> > &board,int row,int col){
		int x = row, y = col;
		for (int i = 0; i < 9; i++){
			if (i != x&&board[i][y] == board[x][y]) return false;
		}
		for (int j = 0; j < 9; j++){
			if (j != y&&board[x][j] == board[x][y]) return false;
		}
		for (int i = x / 3 * 3; i <= x / 3 * 3 + 2; i++){
			for (int j = y / 3 * 3; j <= y / 3 * 3 + 2; j++){
				if ((i != x&&j != y) && (board[i][j] == board[x][y])) return false;
			}
		}
		return true;
	}
	//二分法找区间
	vector<int> searchRangeEqualTarget(vector<int> &A, int n, int target) {
		int left = 0, right = n - 1;
		int start = -1, end = -1;
		while (left <= right){
			int mid = (left + right) / 2;
			if (A[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		if (A[left] == target) start = left;
		left = 0; right = n - 1;
		while (left <= right){
			int mid = (left + right) / 2;
			if (A[mid] <= target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		if (A[right] == target) end = right;
		return vector<int>({ start, end });
	}
	//找最长合法的()()()()(())个数
	int longestValidParentheses(string s){//)()())()()( 4
		int n = s.length();
		int start = 0;
		int result = 0;
		stack<int> sta;
		for (int i = 0; i < n; i++){
			char c = s[i];
			if (c == '(')
				sta.push(i);
			else{
				if (sta.empty())
					start=i+1;
				else{
					int submax = 0;
					sta.pop();
					if (sta.empty())
						submax = i-start+1;
					else
						submax = i - sta.top();
					result = max(result, submax);
				}
			}
		}
		return result;
	}
	//给定一个字符串S和一个字符串数组L，L中的字符串长度都相等，找出S中所有的子串恰好
	//包含L中所有字符各一次，返回子串的起始位置。
	vector<int> findSubstringPos(string S, vector<string> &L){
		//暴力搜索
		vector<int> res;
		int Slen = S.length();
		int n = L.size();
		int Llen = L[0].length();
		map<string, int> m;
		for (int i = 0; i < n; i++)
		    m[L[i]]++;
		for (int i = 0; i <= Slen - n*Llen; i++){
			int j;
			map<string, int> tmp = m;
			for (j = 0; j < n*Llen; j += Llen){
				string str = S.substr(i+j, Llen);
				if (tmp.find(str) != tmp.end()){
					tmp[str]--;
					if (tmp[str] == 0)
						tmp.erase(tmp.find(str));
				}
				else
					break;
			}
			if (tmp.empty())
				res.push_back(i);
		}
		return res;

	}
	//不用乘法 和mod 计算减法 
	int divide(int dividend, int divisor) {
		if (dividend == 0) return 0;
		int a = dividend, b = divisor;
		int count = 0;
		if (a>0 && b>0){
			count = 0;
			while (a >= 0){
				a -= b;
				count++;
			}
			count--;
		}
		else if (a<0 && b>0){
			count = 0;
			while (a <= 0){
				a += b;
				count--;
			}
			count++;
		}
		else if (a>0 && b<0){
			count = 0;
			while (a >= 0){
				a += b;
				count--;
			}
			count++;
		}
		else{
			count = 0;
			while (a <= 0){
				a -= b;
				count++;
			}
			count--;
		}
		return count;
	}
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector<vector<int> > result;
		vector<int> res;
		helpfourSum(result, res, num, target, 1, 0);
		return result;
	}
	void helpfourSum(vector<vector<int> > &result, vector<int> &res, vector<int> &num, int target, int i, int j){
		//i是找到了4个中的第几个,j是遍历到num中的第几个
		if (i == 5 && target == 0){
			result.push_back(res);
			return;
		}
		if (i < 5 && j < num.size()){
			int k = j;
			for (; k < num.size() - 4 + i;){
				helpfourSum(result, res, num, target, i, k + 1);
				res.push_back(num[k]);
				helpfourSum(result, res, num, target - num[k], i + 1, k + 1);
				res.pop_back();
				k++;
				while (k < num.size() - 4 + i&&num[k] == num[k - 1])
					k++;
			}
		}
	}
	//匹配字符串 *代表可以匹配一切字符
	bool isMatch(const char *s, const char *p) {
		int slen = strlen(s);
		int plen = strlen(p);
		vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= slen; i++){
			if (s[i - 1] == '*') dp[i][0] = dp[i - 1][0];
			else dp[i][0] = false;
		}
		for (int j = 1; j <= plen; j++){
			if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
			else dp[0][j] = false;
		}
		for (int i = 1; i <= slen; i++){
			for (int j = 1; j <= plen; j++){
				if (s[i - 1] == '*' || p[j - 1] == '*')
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				else if (s[i - 1] == '.' || p[j - 1] == '.')
					dp[i][j] = dp[i - 1][j - 1];
				else{
					if (s[i - 1] == p[j - 1]){
						dp[i][j] = dp[i - 1][j - 1];
					}
					else{
						dp[i][j] = false;
					}
				}
			}
		}
		return dp[slen][plen];
	}
	//匹配字符串 *代表前一个字符可以有0个或者多个
	bool isMatch2(const char *s, const char *p) {
		int slen = strlen(s);
		int plen = strlen(p);
		vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
		dp[0][0] = true;
		for (int j = 1; j<plen; j += 2){
			if (p[j] == '*') dp[0][j + 1] = true;
			else break;
		}
		for (int i = 1; i <= slen; i++){
			for (int j = 1; j <= plen; j++){
				if (p[j - 1] == '.' || p[j - 1] == s[i - 1]){
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (j >= 2 && p[j - 1] == '*'){
					if ((s[i - 1] == p[j - 2]) || (p[j - 2] == '.')){
						dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
					}
					else{
						dp[i][j] = dp[i][j - 2];
					}
				}
				
			}
		}
		return dp[slen][plen];
	}
	//判断一个数字是不是回文数字
	bool isPalindrome(int x) {
		//回文数字
		if (x<0) return false;
		int ans = 0;
		int z = x;
		while (x>=10){
			int y = x % 10;
			x = x / 10;
			ans = ans * 10 + y;
		}
		if (x>INT_MAX / 10) return false;
		ans = ans * 10 + x;
		if (ans == z) return true;
		else return false;
	}

	//atoi 前面有空格 0 +-号 中间也有空格字母字符 遇到这些东西就结束 只返回前面的数字 也要小心超出int的最大限制 超出了直接等于最大值
	int atoi(const char *str) {
		int n = strlen(str);
		if (n == 0) return 0;
		int i = 0;
		while (str[i] == ' ' || str[i] == '0')
			i++;
		long long res = 0;//用个longlong解决超出限制的问题
		int flag = 1;
		if (str[i] == '+'){
			flag = 1; i++;
		}
		else if (str[i] == '-'){
			flag = -1; i++;
		}
		for (; i<n; i++){
			if (isdigit(str[i])){
				res = res * 10 + (str[i] - '0');
				if (res>INT_MAX)
					return flag == 1 ? INT_MAX : INT_MIN;
			}
			else
				break;
		}
		return flag*res;
	}
	//zigzag-conversion
	string convert(string s, int nRows) {
		int n = s.length();
		string str;
		if (n <= 1 || nRows <= 1) return s;
		int row = nRows;
		int col = n / (2 * row - 2)*(row - 1) + n % (2 * row - 2) / row + n % (2 * row - 2) % row;
		vector<string> v(row, string(col, ' '));
		int j = 0;
		int k = 0;
		while (1){
			for (int i = 0; i<row&&k<n; i++){
				v[i][j] = s[k++];
			}
			j++;
			for (int i = row - 2; i>0 && k<n; i--){
				v[i][j++] = s[k++];
			}
			if (k == n) break;
		}
		for (int i = 0; i<row; i++){
			for (j = 0; j<col; j++){
				if (v[i][j] != ' ')
					str += v[i][j];
			}
		}
		return str;
	}
	//求不重复字符的最长子串
	int lengthOfLongestSubstring(string s) {
		set<char> se;
		queue<char> q;
		int result = 0;
		for (int i = 0; i<s.length(); i++){
			char c = s[i];
			if (se.find(c) == se.end()){
				//没找到

			}
			else{
				//找到了
				while (q.front() != c){
					se.erase(q.front());
					q.pop();
				}
				se.erase(q.front());
				q.pop();
			}
			se.insert(c);
			q.push(c);
			result = result>q.size() ? result : q.size();
		}
		return result;
	}
	void reOrderArray(vector<int> &array) {
		int n = array.size();
		int i = 0;
		for (; i<n; i++){
			if (array[i] % 2 == 0){
				break;
			}
		}
		if (i >= n - 1) return;
		int j = i + 1;
		for (; j<n; j++){
			if (array[j] % 2 == 1){
				int tmp = array[j];
				for (int k = j; k>i; k--){
					array[k] = array[k - 1];
				}
				array[i] = tmp;
				i++;
			}
		}
	}

	//一个有重复字符的字符串的字典序全排列
	vector<string> Permutation(string str) {
		vector<string> result;
		int n = str.length();
		if (n == 0) return result;
		sort(str.begin(), str.end());
		hPermutation(result, 0, str);
		return result;
	}
	void hPermutation(vector<string> &result, int pos, string str){
		if (pos == str.length() - 1){
			result.push_back(str);
			return;
		}
		for (int i = pos; i<str.length(); i++){
			if (i == pos || str[i] != str[pos]){
				swap(str[i], str[pos]);
				hPermutation(result, pos + 1, str);
				//swap(str[i],str[pos]);
			}
		}

	}
	//堆排序
	void heapSort(vector<int> &v){
		for (int i = v.size() / 2; i >= 0; i--)
			percDown(v, i, v.size());
		for (int j = v.size() - 1; j >= 1; j--){
			swap(v[0], v[j]);
			percDown(v, 0, j);
		}

	}
	void percDown(vector<int> &v, int x, int n){
		int tmp = v[x];
		int child;
		int i = x;
		for (; 2 * i + 1 < n;){
			child = 2 * i + 1;
			if (child + 1 < n&&v[child] < v[child + 1])
				child++;
			if (tmp < v[child])
				v[i] = v[child];
			else
				break;
			i = child;
		}
		v[i] = tmp;
	}
	//归并排序求逆序对
	int InversePairs(vector<int> data) {
		int res = 0;
		int n = data.size();
		vector<int> copy(n, 0);
		mergeSort(data, copy, res, 0, n - 1);
		return res;
	}
	void mergeSort(vector<int> &data, vector<int> &copy, int &res, int left, int right){
		if (left >= right)
			return;
		int mid = (left + right) / 2;
		mergeSort(data, copy, res, left, mid);
		mergeSort(data, copy, res, mid + 1, right);
		merge(data, copy, res, left, mid, right);
		res = res % 1000000007;
	}
	void merge(vector<int> &data, vector<int> &copy, int &res, int left, int mid, int right){

		int i = left, j = mid + 1;
		int k = left;
		while (i <= mid&&j <= right){
			if (data[i] <= data[j]){
				copy[k++] = data[i++];
			}
			else{
				copy[k++] = data[j++];
				res += mid - i + 1;
			}
		}
		while (i <= mid) copy[k++] = data[i++];
		while (j <= right) copy[k++] = data[j++];
		int n = right - left + 1;
		k = left;
		while (n--){
			data[k] = copy[k]; k++;
		}
	}
	//判断大小王是不是顺子
	bool IsContinuous(vector<int> numbers) {
		int numwang = 0;
		int i = 0;
		for (; i<numbers.size(); ++i){
			if (numbers[i] == 0)
				numwang++;
			else
				break;
		}
		int shun = numbers[i];
		while (i<numbers.size()){
			if (i + 1<numbers.size() && numbers[i + 1] != shun + 1){
				numwang--;
				shun++;
			}
			else{
				i++;
			}
			if (numwang<0)
				return false;
		}
		return true;
	}
	//约瑟夫环问题
	int LastRemaining_Solution(int n, int m)
	{
		vector<int > v;
		if (n == 0 || m == 0) return 0;
		for (int i = 0; i<n; ++i)
			v.push_back(i);
		int i = -1; int count = -1;
		while (v.size() != 1){
			i++;
			if (i == v.size()) i = 0;
			count++;
			if (count == m - 1){
				v.erase(v.begin() + i);
				count = -1; 
				i--;
			}
		}
		return v[0];
	}
};

