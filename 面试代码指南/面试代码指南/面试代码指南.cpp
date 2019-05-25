// 面试代码指南.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "july.h"
#include"zuochengyun.h"
#include"leetcode.h"
#include"Algorithm.h"
using namespace std;

int main()
{
	vector<int> v = {-2,4,0,3,5,8,-1};
	july ju;
	leetcode lee;
	Algorithm alg;
	zuochengyun zuo;
	zuo.numberPatternPrint(5);
	int glomax=ju.maxProductSubVec(v);
	int glomax2 = ju.maxOnlyProductNumOfN(v);
	int modifiNum = ju.StringAToStringBModificationNum("algorithm", "altruisttc");
	int nQnum = lee.totalNQueens(4);
	bool istinterstring = ju.isInterString("aadbbcbcac","aabcc", "dbbca");
	string bigNumMultiplyRes = lee.multiply("0289", "758");
	int maxLCSNum = ju.MaxLongestCommonSubString("abcdef", "efgabcf");
	int maxInNum = ju.maxIncreaseNum(vector<int>({ 5, 6, 7, 1, 2, 8 }));
	string strSayCount = lee.countAndSay(4);
	vector<int> rangeTarget = lee.searchRangeEqualTarget(vector<int>{ 2, 3, 8, 8, 8}, 5, 8);
	int longestValidParent = lee.longestValidParentheses(")()())()()(");
	vector<pair<int, int>> ftnst = ju.findTwoNumSumTarget({ 1, 2, 3, 4, 5 }, 6);
	vector<int> fsubsP = lee.findSubstringPos("abababab", vector<string>({"a","a","b"}));
	int Divided = lee.divide(-15, -5);
	vector<vector<int>> FindN_NumSumT = ju.FindN_NumSumTarget(9, 1);
	int maxContinueSubSum = ju.maxContinueSubArraySum(vector<int>({1,-2,3,10,-4,7,2,-5}));
	int findShortestBigger = ju.findShortestBiggerThanTarget(vector<int>({ 5 ,1, 3, 5, 10, 7, 4, 9, 2, 8 }), 16);
	int maxSub = ju.maxSubMatrix(vector<vector<int>>({ vector<int>({ 0, -2, -7, 0 }), vector<int>({ 9, 2, -6, 2 }), vector<int>({ -4, 1, -4, 1 }), vector<int>({ -1, 8, 0, -2 }) }));
	int changeMoneyTime = ju.changeMoneyNum(vector<int>({ 1, 2, 5, 10 }), 100);
	ju.oddEvenSort(v);
	v = { 1, 0, 2, 0 };
	ju.HelanNationalFlag(v);
	vector<vector<int> > foursumres = lee.fourSum(vector<int>({ 1, 0, -1, 0, -2, 2 }), 0);
	bool ismatch = lee.isMatch("aa", "aa");
	lee.isPalindrome(10);
	int leeatoi=lee.atoi(" +004500");
	string leecon=lee.convert("ABC",2);
	int maxsubpali = ju.maxSequenceStringPalindromic("abcfgbda");
	string maxSubstrPali = ju.maxSubstringPalindromic("a");
	int lengthOfLon = lee.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
	alg.MP("sdfsfsdfsdfsdf","caatcat");
	lee.reOrderArray(vector<int>({1,2,3,4,5,6,7}));
	lee.Permutation("abcd");
	v = vector<int>({ 5, 1, 3, 5, 10, 7, 4, 9, 2, 8 });
	lee.heapSort(v);
	v = vector<int>({ 3,2,1 });
	lee.InversePairs(v);
	v = { 0, 0, 0, 4, 7 }; bool isShunzi = lee.IsContinuous(v);
	int lastremain=lee.LastRemaining_Solution(5, 3);
	return 0;
}