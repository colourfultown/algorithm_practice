// 网易笔试.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<stack>
#include<math.h>
#include<numeric>
#include<limits.h>
using namespace std;
bool isyiyang(vector<int> a,vector<int> b ){
	if (a == b)
		return true;
	int lena = a.size();
	int lenb = b.size();
	if (abs(lena - lenb) != 1)
		return false;
	if (lena - lenb == 1){
		for (int i = 0; i < lena;i++){
			vector<int> tmp = a;
			tmp.erase(tmp.begin() + i);
			if (tmp == b){
				return true;
			}
		}
	}
	else{
		for (int i = 0; i < lenb; i++){
			vector<int> tmp = b;
			tmp.erase(tmp.begin() + i);
			if (tmp == a){
				return true;
			}
		}
	}
	return false;
}
vector<string> paixing({"Royal Flush","Straight Flush","",});
void func(){
	int n; cin >> n;
	vector<vector<string>> v(n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 7; j++){
			string s;
			cin >> s;
			v[i].push_back(s);
		}
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	func();
	return 0;
}
/*
int Get(int n){
int k = 1;
int oldlast = 0;
int last = 0;
int oldcom = 0;
int com = 0;
while (com < n){
int start = last + k;
int time = pow(10, k) - pow(10, k - 1);
int end = start + (time - 1)*k;
int now = (start + end)*time / 2;
oldcom = com;
com += now;
k++;
oldlast = last;
last = end;
}
k--;
int start = oldlast + k;
n -= oldcom;
int oldn = n;
int num = pow(10, k-1);
while (n > 0){
oldn = n;
n = n - start;
start += k;
num++;
}
num--;
k = 1;
int tmp = 0;
while (oldn>0){
tmp = (pow(10, k)-pow(10,k-1))*k;
oldn -= tmp;
k++;
}
oldn += tmp;
k--;
int jige = oldn / k;
int nawei = oldn%k;
if (nawei == 0){
nawei = k;
}
start = pow(10, k-1)+jige-1;
int tt = k  - nawei;
int result = start / (int)(pow(10, tt)) % 10;
return result;
}
void obj(){

}
int maxContinueSubArraySum(vector<int> v){
if (v.empty()) return 0;
int glomax = v[0];
int submax = v[0];
int left = 0, right = 0, start = 0, end = 0;
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
return res;
}
void func(){
vector<int> v;
int i = 0;
char c;
int t;
cin >> t;
v.push_back(t);
while ((c = getchar()) != '\n'){
cin >> t;
v.push_back(t);
}
int res = 0;
int sub = 0;
for (int i = 0; i < v.size(); i++){
sub += v[i];
res = max(res, sub);
if (sub < 0) sub = 0;
}
cout << res;
}
void fun23(){
vector<int> v;
char c;
int t;
cin >> t;
v.push_back(t);
while ((c = getchar()) != '\n'){
cin >> t;
v.push_back(t);
}
int n; cin >> n;
sort(v.begin(), v.end());
cout << v[v.size() - n];

}
void perdown(vector<int> &a, int i, int n){
int child;
int tmp = a[i];
for (; 2 * i + 1<n; i = child){
child = 2 * i + 1;
if (child + 1 != n&&a[child]<a[child + 1]){
child++;
}
if (tmp<a[child])
a[i] = a[child];
else
break;
}
a[i] = tmp;
}
void fun2(){
vector<int> v;
char c;
int t;
cin >> t;
v.push_back(t);
while ((c = getchar()) != '\n'){
cin >> t;
v.push_back(t);
}
int k; cin >> k;
int n = v.size();
for (int i = n / 2; i >= 0; --i)
perdown(v, i, n);
for (int j = n - 1, jishu = 1; j>0 && (jishu != k); --j, ++jishu){
v[0] ^= v[j] ^= (v[0] ^= v[j]);
perdown(v, 0, j);
}
cout << v[0];

}
void insertionSort_binary(vector<int> &a, vector<int> &b) {
for (int i = 1; i < a.size(); ++i) {
int tmp = a[i];
int left = 0;
int right = i - 1;
while (left <= right) {
int mid = (right + left) / 2;
if (a[mid] <= tmp)
left = mid + 1;
else
right = mid - 1;
}
for (int j = i; j > left; --j) {
a[j] = a[j - 1];
}
a[left] = tmp;
b[i] = i - left;
}
}
void func360(){
int n; cin >> n;
vector<int> v(n, 0);
for (int i = 0; i < n; i++)
cin >> v[i];
vector<int> b(n, 0);
insertionSort_binary(v, b);
for (int i = 0; i < n - 1; i++){
cout << b[i] << " ";
}
cout << b[n - 1];

}

void func3602(){
int n, m, a, b, c, d, x, y, z;
cin >> n >> m >> a >> b >> c >> d >> x >> y >> z;
vector<vector<int>> dp(n + 1, vector<int>(m+1, 0));
for (int i = 0; i <= m; i++)
dp[0][i] = i / c*y;
for (int i = 0; i <= n; i++)
dp[i][0] = i / d*z;
for (int i = 1; i <= n; i++){
for (int j = 1; j <= m; j++){
int res = 0;
//for (int k = 1; i - k*a >= 0 && j - k*b >= 0; k++){
int k = 1;
if (i - k*a >= 0 && j - k*b >= 0){
int tmp = dp[i - k*a][j - k*b] + k*x;
res = max(tmp, res);
}
//for (int k = 1;  j - k*c >= 0; k++){
if (j - k*c >= 0){
int tmp = dp[i][j - k*c] + k*y;
res = max(tmp, res);
}
//for (int k = 1; i - k*d >= 0 ; k++){
/*if (i - k*d >= 0){
int tmp = dp[i - k*d][j ] + k*z;
res = max(tmp, res);
}
dp[i][j] = res;
}
}
cout << dp[n][m];
}
#include<unordered_map>
unordered_map<char, int> helper{ { '3', 1 }, { '4', 2 }, { '5', 3 }, { '6', 4 }, { '7', 5 }, { '8', 6 },
{ '9', 7 }, { '1', 8 }, { 'J', 9 }, { 'Q', 10 }, { 'K', 11 }, { 'A', 12 }, { '2', 13 } };
string delete_0(string str) {
while (str.find('0') != string::npos)
str.erase(str.find('0'), 1);
return str;
}
void function(){
string str, s1, s2, s1_, s2_;
while (getline(cin, str)) {
s1_ = str.substr(0, str.find('-'));
s1 = delete_0(s1_);
s2_ = str.substr(str.find('-') + 1);
s2 = delete_0(s2_);
if (s1 == "joker JOKER" || s2 == "joker JOKER") cout << "joker JOKER" << endl;
else if (s1.size() == 7 || s2.size() == 7) {
if (s1.size() == 7 && s2.size() == 7)
if (helper[s1[0]] > helper[s2[0]]) cout << s1_ << endl;
else cout << s2_ << endl;
else if (s1.size() == 7) cout << s1_ << endl;
else cout << s2_ << endl;
}
else if (s1.size() == s2.size())
if (helper[s1[0]] > helper[s2[0]]) cout << s1_ << endl;
else cout << s2_ << endl;
else cout << "ERROR" << endl;
}
}*/
