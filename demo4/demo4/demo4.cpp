// demo4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;

char * STR(const char *str1, const char *str2)
{
	char * str = new char [strlen(str1) + strlen(str2)+1 ];
	cout << strlen(str1) << endl;
	char * p = str;
	while (*p++ = *str1++);
	p;
	while (*p++ = *str2++);
	return str;


}
int _tmain(int argc, _TCHAR* argv[])
{
	char * a="hahahahahaha";//如果这里不初始化一个值得话，就会出现在下一行加断点时出现读取内存问题，但是再下一行的输出没有错误？？
	a = STR("abc", "def");
	cout << a << endl;
	delete a;
	return 0;
}

