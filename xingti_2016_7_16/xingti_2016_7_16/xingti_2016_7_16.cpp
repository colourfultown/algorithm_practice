// xingti_2016_7_16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "list.h"


int _tmain(int argc, _TCHAR* argv[])
{
	List list;
	Parallelogram para;
	init(list);
	create(para);
	push_back(list, reinterpret_cast<QUADPTR>(&para));

	traverse(list, access);
	return 0;
}

