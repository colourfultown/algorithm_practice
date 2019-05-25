#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

struct point{
	double x;
	double y;
};

struct head{
	int layer = 0;  //层数
	point p;  //左下角坐标
	double len;  //边长
	int num = -1;  //点数
};

vector<point> vec;
vector<point>::iterator it;
vector<head> res;

int p_num(point p, double len){       //计算区域内有多少个点
	int num = 0;
	for (it = vec.begin(); it != vec.end(); it++){
		if ((p.x < it->x) && (it->x < p.x + len) && (p.y < it->y) && (it->y < p.y + len)){
			num++;
		}
	}
	return num;
}

void write(){
	ofstream out("out.txt", ios::out);
	vector<head>::iterator it;
	//out.setf(ios::fixed);
	//out.precision(6);
	for (it = res.begin(); it != res.end(); it++){
		out << it->layer << " " << it->num << " " << it->p.x << " " << it->p.y << " " << it->len << endl;
	}
}

void cal(head h){
	queue<head> q;
	q.push(h);
	while (!q.empty()){
		head out = q.front();
		if (out.num > 50){
			double in_len = out.len / 2;

			head in[4];
			in[0].p = out.p;
			in[0].layer = out.layer + 1;
			in[0].len = in_len;
			in[0].num = p_num(in[0].p, in[0].len);
			if (in[0].num < 50)
				res.push_back(in[0]);
			else
				q.push(in[0]);

			in[1].p.x = out.p.x + in_len;
			in[1].p.y = out.p.y;
			in[1].layer = out.layer + 1;
			in[1].len = in_len;
			in[1].num = p_num(in[1].p, in[1].len);
			if (in[1].num < 50)
				res.push_back(in[1]);
			else
				q.push(in[1]);

			in[2].p.x = out.p.x;
			in[2].p.y = out.p.y + in_len;
			in[2].layer = out.layer + 1;
			in[2].len = in_len;
			in[2].num = p_num(in[2].p, in[2].len);
			if (in[2].num < 50)
				res.push_back(in[2]);
			else
				q.push(in[2]);

			in[3].p.x = out.p.x + in_len;
			in[3].p.y = out.p.y + in_len;
			in[3].layer = out.layer + 1;
			in[3].len = in_len;
			in[3].num = p_num(in[3].p, in[3].len);
			if (in[3].num < 50)
				res.push_back(in[3]);
			else
				q.push(in[3]);
		}
		else
			res.push_back(out);
		q.pop();
	}
}


void main(){
	ifstream f("111.txt", ios::in);
	point p;
	char s;
	while (!f.eof()){
		f >> p.x >> s >> p.y >> s;
		vec.push_back(p);
	}
	f.close();

	it = vec.begin();
	double x_min, x_max, y_min, y_max;
	x_min = x_max = it->x;
	y_min = y_max = it->y;
	for (; it != vec.end(); it++){
		if (it->x < x_min)
			x_min = it->x;
		if (it->x > x_max)
			x_max = it->x;
		if (it->y < y_min)
			y_min = it->y;
		if (it->y > y_max)
			y_max = it->y;
	}
	cout.setf(ios::fixed);
	cout.precision(6);
	cout << "总点数：" << vec.size() << endl;
	cout << x_min << " " << x_max << " " << y_min << " " << y_max << endl;
	cout << "x方向范围： " << x_max - x_min << endl;
	cout << "y方向范围： " << y_max - y_min << endl;
	point p1;
	p1.x = 1170000; p1.y = 3420000;
	double max_len = 120000;
	cout << p_num(p1, max_len) << endl;
	head h;
	h.layer = 1;
	h.len = max_len;
	h.num = p_num(p1, max_len);
	h.p = p1;
	cal(h);
	cout << res.size() << endl;
	write();
	getchar();
}