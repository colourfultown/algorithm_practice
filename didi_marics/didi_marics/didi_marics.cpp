// didi_marics.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void turn_marics(string str1 , string str2)
{
	ifstream in(str1);
	ofstream out(str2);
	int ij[6] = { 0 };
	int ij_num[67][145] = { 0 };
	while (!in.eof())
	{
		in >> ij[1] >> ij[2] >> ij[3] >> ij[4] >> ij[5];
		ij_num[ij[1]][ij[2]] = ij[5];
	}
	for (int j = 1; j < 145; j+=3)
	{
		for (int i = 1; i < 67; i++)
			out << ij_num[i][j] << " " << ij_num[i][j + 1] <<" "<<ij_num[i][j+2]<< endl;
	}
	in.close();
	out.close();
}

void turn_marics_test(string str1, string str2)
{
	ifstream in(str1);
	ofstream out(str2);
	int ij[6] = { 0 };
	int ij_num[67][145] = { 0 };
	int timedian[9] = { 46, 58, 70, 82, 94, 106, 118, 130, 142 };
	while (!in.eof())
	{
		in >> ij[1] >> ij[2] >> ij[3] >> ij[4] >> ij[5];
		ij_num[ij[1]][ij[2]] = ij[5];
	}
	for (int j = 1; j < 9; j ++)
	{
		for (int i = 1; i < 67; i++)
			out << ij_num[i][timedian[j] - 3] << " " << ij_num[i][timedian[j] - 2] << " " << ij_num[i][timedian[j] - 1] << endl;
	}
	in.close();
	out.close();
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*turn_marics("G:/ij_num/ij_num_01","G:/matrics/matrics_01.txt");
	turn_marics("G:/ij_num/ij_num_02", "G:/matrics/matrics_02.txt");
	turn_marics("G:/ij_num/ij_num_03", "G:/matrics/matrics_03.txt");
	turn_marics("G:/ij_num/ij_num_04", "G:/matrics/matrics_04.txt");
	turn_marics("G:/ij_num/ij_num_05", "G:/matrics/matrics_05.txt");
	turn_marics("G:/ij_num/ij_num_06", "G:/matrics/matrics_06.txt");
	turn_marics("G:/ij_num/ij_num_07", "G:/matrics/matrics_07.txt");
	turn_marics("G:/ij_num/ij_num_08", "G:/matrics/matrics_08.txt");
	turn_marics("G:/ij_num/ij_num_09", "G:/matrics/matrics_09.txt");
	turn_marics("G:/ij_num/ij_num_10", "G:/matrics/matrics_10.txt");
	turn_marics("G:/ij_num/ij_num_11", "G:/matrics/matrics_11.txt");
	turn_marics("G:/ij_num/ij_num_12", "G:/matrics/matrics_12.txt");
	turn_marics("G:/ij_num/ij_num_13", "G:/matrics/matrics_13.txt");
	turn_marics("G:/ij_num/ij_num_14", "G:/matrics/matrics_14.txt");
	turn_marics("G:/ij_num/ij_num_15", "G:/matrics/matrics_15.txt");
	turn_marics("G:/ij_num/ij_num_16", "G:/matrics/matrics_16.txt");
	turn_marics("G:/ij_num/ij_num_17", "G:/matrics/matrics_17.txt");
	turn_marics("G:/ij_num/ij_num_18", "G:/matrics/matrics_18.txt");
	turn_marics("G:/ij_num/ij_num_19", "G:/matrics/matrics_19.txt");
	turn_marics("G:/ij_num/ij_num_20", "G:/matrics/matrics_20.txt");
	turn_marics("G:/ij_num/ij_num_21", "G:/matrics/matrics_21.txt");*/

	turn_marics_test("G:/test2/ijnum29", "G:/test2/matri_29");
	return 0;
}

