// test_demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
bool isIn(map<char, int> &m, map<char, int> &c);
string minWindow(string S, string T) {
	string result;
	int slen = S.length();
	int tlen = T.length();
	map<char, int> map_T;
	for (int i = 0; i<tlen; ++i){
		if (map_T.count(T[i]) == 0){
			map_T[T[i]] = 1;
		}
		else{
			map_T[T[i]]++;
		}
	}
	
	int start = 0, end = 0;
	int left = 0, right = slen - 1;
	int min = slen;
	map<char, int> com;
	while (end<slen){
		char c = S[end];
		if (map_T.count(c)>0){
			if (com.count(c) == 0){
				com[c] = 1;
			}
			else{
				com[c]++;
			}
			
			while ((map_T.count(S[start])==0)||
				(start<end&&com.count(S[start])>0 && com[S[start]]>map_T[S[start]])){
				if (map_T.count(S[start]) == 0){
					start++;
				}
				else if (start<end&&com.count(S[start])>0 && com[S[start]]>map_T[S[start]]){
					com[S[start]] = com[S[start]] - 1;
					start++;
					
				}
			}
			bool flag = isIn(map_T, com);
			if (flag == true){
				if ((end - start)<(right - left)){
					left = start;
					right = end;
				}
			}
			else{

			}
			end++;
		}
		else{
			end++;
		}
	}
	bool flag = isIn(map_T, com);
	if (flag == true){
		result = S.substr(left, right - left + 1);
	}
	return result;
}
bool isIn(map<char, int> &m, map<char, int> &c){
	//判断c里面包含了所有的m
	for (auto it = m.begin(); it != m.end(); ++it){
		if (c.count(it->first)>0 && c[it->first] >= it->second){

		}
		else{
			return false;
		}
	}
	return true;
}


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> res;
		int n = intervals.size();
		int a = newInterval.start, b = newInterval.end;
		int i, j;
		int flag_start = 2, flag_end = 0;
		for (i = 0; i < n; i++){
			Interval tmp = intervals[i];
			int start = tmp.start, end = tmp.end;
			if (a<start){
				flag_start = 0;
				break;
			}
			else if (a >= start&&a <= end){
				flag_start = 1;
				break;
			}
			else if (a>end){

			}
		}

		for (j = n - 1; j >= 0; j--){
			Interval tmp = intervals[j];
			int start = tmp.start, end = tmp.end;
			if (b>end){
				flag_end = 2;
				break;
			}
			else if (b <= end&&b >= start){
				flag_end = 1;
				break;
			}
			else if (a<start){

			}
		}

		if (i == n){
			res = intervals;
			res.push_back(newInterval);
			return res;
		}
		if (j == -1){
			res = intervals;
			res.insert(res.begin(), newInterval);
			return res;
		}
		for (int k = 0; k<i; k++)
			res.push_back(intervals[k]);
		int left, right;
		if (flag_start == 0){
			left = a;
		}
		else{
			left = intervals[i].start;
		}
		if (flag_end == 2){
			right = b;
		}
		else{
			right = intervals[j].end;
		}
		res.push_back(Interval(left, right));
		for (int k = j + 1; k<n; k++)
			res.push_back(intervals[k]);
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	//测试1：S中包含T的最小子串
	string S = "ADOBECODEBANC", T = "ABC";
	string result = minWindow(S, T);
	//测试2：区间问题
	Solution solu;
	
	return 0;
}

