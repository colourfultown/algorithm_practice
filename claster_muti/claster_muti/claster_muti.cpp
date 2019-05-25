// muti_cluster.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include<string>
#include "head_.h"
#include "point_.h"
#include <math.h>
#include <strstream>
using namespace std;

vector <point_> vec;//保存输入数据
vector<head_> res;//一共有多少个方格
deque<int> que;
vector<point_> vec_point;//保存同一层的方格的左下角坐标
vector<int> vec_point_num;
int layer_total = 1;
struct num_vectorint{ int num; vector<int>index_inhead; };
struct answer{
	int clafi;
	double x;
	double y;
	double banjing;
	int num_;
};
vector <answer> ans;//保存格子的类别
num_vectorint p_num(vector<int>index, point_ p, double len); 
void call(head_ h, int yuzhi_ = 50){

	int yuzhi = yuzhi_;
	queue<head_> q;
	q.push(h);
	while (!q.empty()){
		head_ out = q.front();
		if (out.num > yuzhi){
			double in_len = out.len / 2;
			num_vectorint num_temp;

			head_ a(out.layer + 1, out.p, in_len);
			layer_total = out.layer + 1;
			num_temp = p_num(out.index_inthehead, a.p, a.len);
			a.num = num_temp.num;
			a.index_inthehead = num_temp.index_inhead;
			if (a.num < yuzhi)
				res.push_back(a);
			else
				q.push(a);

			point_ poi;
			poi.x = out.p.x + in_len;
			poi.y = out.p.y;
			head_ b(out.layer + 1, poi, in_len);
			num_temp = p_num(out.index_inthehead, b.p, b.len);
			b.num = num_temp.num;
			b.index_inthehead = num_temp.index_inhead;
			if (b.num < yuzhi)
				res.push_back(b);
			else
				q.push(b);

			poi.x = out.p.x;
			poi.y = out.p.y + in_len;
			head_ c(out.layer + 1, poi, in_len);
			num_temp = p_num(out.index_inthehead, c.p, c.len);
			c.num = num_temp.num;
			c.index_inthehead = num_temp.index_inhead;
			if (c.num < yuzhi)
				res.push_back(c);
			else
				q.push(c);

			poi.x = out.p.x + in_len;
			poi.y = out.p.y + in_len;
			head_ d(out.layer + 1, poi, in_len);
			num_temp = p_num(out.index_inthehead, d.p, d.len);
			d.num = num_temp.num;
			d.index_inthehead = num_temp.index_inhead;
			if (d.num < yuzhi)
				res.push_back(d);
			else
				q.push(d);
		}
		else
			res.push_back(out);
		q.pop();
	}


}

void write(vector<head_> res, string str){
	ofstream out(str, ios::out);
	vector<head_>::iterator it;
	//out.setf(ios::fixed);
	//out.precision(6);
	for (it = res.begin(); it != res.end(); it++){
		out << it->layer << " " << it->num << " " << it->p.x << " " << it->p.y << " " << it->len << endl;
	}
	out.close();
}


void init_vec(string str){
	ifstream f(str, ios::in);
	point_ p;
	char s;
	int x;
	while (!f.eof()){
		f >> p.x >> s >> p.y >> s >> x >> s;
		vec.push_back(p);
	}
	vec.pop_back();
	f.close();
}
num_vectorint p_num(vector<int>index, point_ p, double len){
	int num_ = 0;
	vector<int> vecint;
	vector <int>::iterator it;
	for (it = index.begin(); it != index.end(); it++){
		if ((p.x < vec[*it].x) && (vec[*it].x < p.x + len) && (p.y < vec[*it].y) && (vec[*it].y < p.y + len)){
			num_++;
			vecint.push_back(*it);
			//index.erase(it);
		}
	}
	num_vectorint a;
	a.index_inhead = vecint;
	a.num = num_;
	return a;
}
int returnindex(point_ p){
	int vec_size = vec_point.size();
	for (int i = 0; i < vec_size; i++){
		if (vec_point[i] == p)
			return i;
	}
	return -1;
}

int cal(point_ p, point_ site[4]){
	int num = 0;
	for (int i = 0; i < 4; i++){
		int index = returnindex(site[i]);
		if (index >= 0){
			num++;
		}
	}
	int x = num;
	return x;
}
int c = 1;
vector<int> process(double len, int samenum_yuzhi){
	int vec_size = vec_point.size();
	vector<int> flag(vec_size, 0);
	vector<int> cfi(vec_size, 0);

	for (int i = 0; i < vec_size; i++){
		int samenum = 0;
		point_ p = vec_point[i];
		point_ site[4];
		site[0].x = p.x; site[0].y = p.y + len;
		site[1].x = p.x; site[1].y = p.y - len;
		site[2].x = p.x + len; site[2].y = p.y;
		site[3].x = p.x - len; site[3].y = p.y;

		if (cal(p, site) < 3 || flag[i] == 1)
			continue;

		flag[i] = 1; cfi[i] = c;
		samenum++;

		for (int j = 0; j < 4; j++){
			int index = returnindex(site[j]);
			if (index >= 0){
				que.push_back(index);
				cfi[index] = c;
				flag[index] = 1;
				samenum++;
			}
		}
		while (!que.empty()){
			if (samenum < samenum_yuzhi){//samenum限定最多聚在一起的格子
				int current_index = que.front();
				que.pop_front();
				point_ current_point = vec_point[current_index];
				point_ current_site[4];
				current_site[0].x = current_point.x; current_site[0].y = current_point.y + len;
				current_site[1].x = current_point.x; current_site[1].y = current_point.y - len;
				current_site[2].x = current_point.x + len; current_site[2].y = current_point.y;
				current_site[3].x = current_point.x - len; current_site[3].y = current_point.y;
				if (cal(current_point, current_site) < 2)
					continue;
				for (int k = 0; k < 4; k++){
					int index = returnindex(current_site[k]);
					if (index >= 0 && flag[index] == 0){
						que.push_back(index);
						cfi[index] = c;
						flag[index] = 1;
						samenum++;
					}
				}
			}
			else
				break;
		}
		que.clear();
		c++;

	}
	return cfi;
}
/*void write_vec_two(vector<int> cfi){
ofstream out("G:/taxi/c/total_out.txt", ios::app);
vector<point_>::iterator it;
//out.setf(ios::fixed);
//out.precision(6);
int num1 = vec_point.size();
for (int it = 0; it < num1; it++){
out << cfi[it] << "," << vec_point[it].x << "," << vec_point[it].y << endl;
}
out.close();
}*/
void pro(string str, int delete_num, int samenum_yuzhi){
	int layer_num = layer_total;//一共有多少层
	ofstream out(str, ios::out);//输出的格子与分类标号
	for (int i = 2; i <= layer_num; ++i){

		vector <head_>::iterator it;
		double len = 0;

		for (it = res.begin(); it != res.end(); it++){
			if (it->layer == i && (it->num) >= delete_num){//判断该层的所有点，num数等于0的直接删除
				point_ pp(it->p.x, it->p.y);
				vec_point.push_back(pp);
				int aaa = it->num;
				vec_point_num.push_back(aaa);
				len = it->len;
			}
		}
		//int vec_size = vec_point.size();
		vector<int> cfi = process(len, samenum_yuzhi);

		vector<point_>::iterator its;
		int num1 = vec_point.size();
		double dd = 120000 / pow(2, i - 1) / 46.875;

		for (int its = 0; its < num1; its++){
			double x1 = (vec_point[its].x - 1170000) / 46.875;
			double y1 = (vec_point[its].y - 3420000) / 46.875;
			out << cfi[its] << "," << x1 << "," << y1 << "," << dd << endl;
			answer ans_temp;
			ans_temp.clafi = cfi[its];
			ans_temp.x = vec_point[its].x;
			ans_temp.y = vec_point[its].y;
			ans_temp.banjing = 120000 / pow(2, i - 1);
			ans_temp.num_ = vec_point_num[its];
			ans.push_back(ans_temp);

		}

		//write_vec_two(cfi);
		vec_point.clear();
		vec_point_num.clear();
	}
	out.close();
}
vector<double>rou;//保存不同类别的密度值
void cal_rou(){
	int ans_size = ans.size();
	vector <double>area_s((c + 1), 0);
	vector <int> point_num_((c + 1), 0);
	vector<double>rout((c + 2), 0);
	for (int i = 0; i < ans_size; ++i){
		int ci = ans[i].clafi;
		double banjing = ans[i].banjing;
		int num = ans[i].num_;
		area_s[ci] = area_s[ci] + pow(banjing, 2);
		point_num_[ci] = point_num_[ci] + num;
	}

	for (int i = 1; i < c + 1; ++i){
		rout[i] = point_num_[i] / area_s[i] * 1000000;
	}
	rout[0] = 0;
	rou = rout;
	//cout << rout.size()-2 << endl;
	//cout << rou.size() << endl;
}
void write_piont_class(string str1, string str2){
	int size_vec = vec.size();
	vector<int> fenleijieguo(size_vec + 1, 0);
	vector<double>rou_density(size_vec + 1, 0);
	int size_ans = ans.size();
	for (int i = 0; i < size_vec; ++i){
		double point_x = vec[i].x;
		double point_y = vec[i].y;
		for (int j = 0; j < size_ans; ++j){
			double x1 = ans[j].x;
			double x2 = ans[j].x + ans[j].banjing;
			double y1 = ans[j].y;
			double y2 = ans[j].y + ans[j].banjing;
			if ((point_x>x1) && (point_x<x2) && (point_y>y1) && (point_y < y2)){
				int ccc = ans[j].clafi;
				fenleijieguo[i] = ans[j].clafi;
				rou_density[i] = rou[ccc];
				//cout <<"ainiyou"<< fenleijieguo[i] << endl;
				break;
			}
			else{
				fenleijieguo[i] = 0;
				rou_density[i] = 0;
			}

		}
	}
	ofstream out(str1, ios::out);//输出的经纬度与分类标号
	//ofstream out2("G:/taxi/c/quantian/jingwei_density.txt", ios::out);
	out.setf(ios::fixed);
	out.precision(8);
	//out2.setf(ios::fixed);
	//out2.precision(8);
	ifstream in(str2, ios::in);//输入的经纬度的坐标
	char s;
	double a;
	double b; int cnono = 0; int dnono = 0; int x;
	while (!in.eof()){
		in >> a >> s >> b >> s >> x;
		if (a != 0){
			out << a << " " << b << " " << rou_density[dnono++] << " " << fenleijieguo[cnono++] << " " << x << endl;
		}
	}
		out.close();
		//out2.close();
		in.close();
	
}

void every_pro(int t,string str1,string str2,string str3,string str4){
	string strin = str1;//输入的变换后的坐标初始值
	string strin_2 = str2;//输入的经纬度的坐标
	string strout = str3;//输出的格子与分类标号
	string strout_2 = str4;//输出的经纬度坐标、密度、分类标号

	init_vec(strin);
	point_ p1;
	p1.x = 1170000; p1.y = 3420000;
	double max_len = 120000;
	head_ h1(1, p1, max_len);
	num_vectorint num_temp;
	vector<int> vec_int;
	int vec_num = vec.size();
	for (int i = 0; i < vec_num; i++){ vec_int.push_back(i); }
	num_temp = p_num(vec_int, h1.p, h1.len);
	h1.num = num_temp.num;
	h1.index_inthehead = num_temp.index_inhead;

	call(h1, 50);//改一个格子中最多的点数，阈值参数
	//cout << "格子划分结束" << endl;

	pro(strout, 5, 100);//如果格子内点数少于这个阈值，删除格子//第二个参数是限定最多多少个格子聚在一起
	cal_rou();
	write_piont_class(strout_2, strin_2);
	/*cout << "共有多少个点" << vec.size() << endl;
	cout << "有多少格子" << res.size() << endl;
	cout << "有多少层" << layer_total << endl;
	cout << "分类数：" << c << endl;*/
	ofstream out("G:/taxi/c/O/A_huizong.txt",ios::app);
	out << t << "共有多少个点" << vec.size() << "有多少格子" << res.size() << "有多少层" << layer_total << "分类数：" << c << endl;
	out.close();

	vec.clear();
	res.clear();
	que.clear();
	vec_point.clear();
	vec_point_num.clear();
	layer_total = 1;
	ans.clear();
	c = 1;
	rou.clear();
}
void zong_pro(){
	for (int i = 41; i < 145; ++i){
		strstream ss;
		string s;
		int a = i;
		ss << i;
		ss >> s;
		string str1 = "G:/taxi/c/144_quantian/" + s + "_zong1.txt";
		string str2 = "G:/taxi/c/144_quantian/" + s + "_zong.txt";
		string str3 = "G:/taxi/c/O/" + s + "_50_5_100_gezi.txt";
		string str4 = "G:/taxi/c/O/" + s + "_50_5_100.txt";
		every_pro(a,str1, str2, str3, str4);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{

	zong_pro();
	return 0;
}

