// demo4.cpp : �������̨Ӧ�ó������ڵ㡣
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
	char * a="hahahahahaha";//������ﲻ��ʼ��һ��ֵ�û����ͻ��������һ�мӶϵ�ʱ���ֶ�ȡ�ڴ����⣬��������һ�е����û�д��󣿣�
	a = STR("abc", "def");
	cout << a << endl;
	delete a;
	return 0;
}

