// hebing_8.00_8.10_22ge.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include<iostream>
#include<fstream>
#include <strstream>
#include <string>
using namespace std;
struct answer{
	double x;
	double y;
} ;
vector<answer> ans;
struct answer_2{
	double x;
	double y;
	int z;
};
vector<answer_2> ans_2;
void write_answer(string s);
void read_write_(){
	int date[21] = {1,2,3,6,8,9,10,13,14,15,16,17,20,21,21,23,24,27,28,29,30};
	string str[21] ;
	string str_now[21];
	for (int i = 0; i < 21; i++){
		strstream ss;
		string s;
		ss << date[i];
		ss >> str[i];
	}
	//int time[144] ;for (int i = 0; i < 144; i++){ time[i] = i; }
	string str_time[144];
	for (int i = 0; i < 144; i++){
		strstream ss;
		string s; 
		int a = i + 1;
		ss << a;
		ss >> str_time[i];
	}
	for (int n = 0; n < 144; ++n){
		string str_timee = str_time[n];
		string str_out = "G:/taxi/c/21tianD/" + str_timee + "_zongD.txt";
		ofstream out(str_out);
		out.setf(ios::fixed);
		out.precision(8);
		for (int i = 0; i < 21; i++){
			str_now[i] = "G:/taxiod/" + str[i] + "/d" + str_timee + "-r-00000";
			//cout << str[a] << endl;
		}
		for (int j = 0; j < 21; j++){
			string sss = str_now[j];
			write_answer(sss);
		}

		
		int size_ans = ans.size();
		for (int m = 0; m < size_ans; m++){
			out << ans[m].x << "," << ans[m].y << endl;
		}
		out.close();
		ans.clear();
	}
}
void write_answer(string s){
	//cout << s << endl;
	ifstream in(s, ios::in);
	while (!in.eof()){
		double x1;
		double x2;
		char c;
		in >> x1 >> c >> x2 ;
		//cout << c << endl;
		answer an;
		an.x = x1;
		an.y = x2;
		ans.push_back(an);
	}
	ans.pop_back();
	//cout << ans[0].x << endl;
	in.close();
}
void OD_combine(){
	for (int i = 1; i < 145; ++i){
		int i_ = i;
		strstream ss;
		string s;
		ss << i;
		ss >> s;
		string str_O = "G:/taxi/c/21tianO/" + s + "_zong.txt";
		string str_D = "G:/taxi/c/21tianD/" + s + "_zongD.txt";
		ifstream in_O(str_O);
		while (!in_O.eof()){
			double jing;
			double wei;
			char c;
			in_O >> jing >> c >> wei;
			answer_2 a_temp;
			a_temp.x = jing;
			a_temp.y = wei;
			a_temp.z = 1;
			ans_2.push_back(a_temp);
		}
		ans_2.pop_back();
		in_O.close();
		ifstream in_D(str_D);
		while (!in_D.eof()){
			double jing;
			double wei;
			char c;
			in_D >> jing >> c >> wei;
			answer_2 a_temp;
			a_temp.x = jing;
			a_temp.y = wei;
			a_temp.z = 2;
			ans_2.push_back(a_temp);
		}
		ans_2.pop_back();
		in_D.close();
		string out_OD = "G:/taxi/c/21tian/" + s + "_OD.txt";
		ofstream out(out_OD);
		out.setf(ios::fixed);
		out.precision(8);
		for (vector<answer_2>::iterator it = ans_2.begin(); it != ans_2.end(); ++it){
			out << it->x << "," << it->y << "," << it->z << endl;
		}
		out.close();
		ans_2.clear();
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	//write_answer("G:/taxiod/1/o48-r-00000");
	//read_write_();
	OD_combine();
	cout << 1 << endl;
	getchar();
	return 0;
}

