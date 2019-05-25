#pragma once
#include "point_.h"
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;





class head_
{
public:
	head_();
	head_(int layer_in ,point_ p_in,double len_);
	~head_();
	int layer ;  //层数
	point_ p;  //左下角坐标
	double len;  //边长
	int num = -1;  //点数
	int classfication;
	vector<int> index_inthehead;

	 

	//int p_num();
	

	
};

