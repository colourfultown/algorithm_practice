// didi_xgboost.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void model66ge(string str1, string str2)
{
	ifstream in(str1);
	ofstream out(str2);
	int in_array[14] = { 0 };
	double gailv;
	double ij[67][145][7] = { 0 };
	while (!in.eof())
	{
		in >> in_array[1] >> in_array[2] >> in_array[3] >> in_array[4] >> in_array[5] >> in_array[6] >> in_array[7] >>
			in_array[8] >> in_array[9] >> in_array[10] >> in_array[11] >> in_array[12] >> in_array[13] >> gailv;
		ij[in_array[2]][in_array[3]][0] = in_array[4];
		ij[in_array[2]][in_array[3]][1] = in_array[6];
		ij[in_array[2]][in_array[3]][2] = in_array[7];
		ij[in_array[2]][in_array[3]][3] = in_array[8];
		ij[in_array[2]][in_array[3]][4] = in_array[9];
		ij[in_array[2]][in_array[3]][5] = in_array[10];
		ij[in_array[2]][in_array[3]][6] = gailv;
     }


}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

