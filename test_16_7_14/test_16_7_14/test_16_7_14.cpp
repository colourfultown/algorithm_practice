// test_16_7_14.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
static void f(){}

/*int _tmain1(int argc, _TCHAR* argv[])
{

	enum trafficlight{red,green,yellow};
	trafficlight tra1 = red;
	if (tra1 == 1)
	std::cout << tra1 << std::endl;
	int b = green; 
	return 0;
}
int _tmain2(int argc, _TCHAR* argv[])
{

	int array[10];
	int(*p)[10];
	p = &array;
	(*p)[0] = 0;

	int *pi;
	pi = array;
	pi[0] = 0;

	std::cout << p<< "  "<<pi << std::endl;


	return 0;
}
int _tmain3(int argc, _TCHAR* argv[])
{
	int b = 1;
	typedef int & INT;
	const INT a = b;

	return 0;
}
int _tmain4e(int argc, _TCHAR* argv[])
{
	wchar_t x = 'abcd';
	char *y = "bbb";
	char nima ;
	//int x = 'a';
	std::cout << x << "  " << y << std::endl;//x只输出d
	char m[] = "asd";
	char n[] = {'abcd','v','\0'};//不写\0或者0就不知道在哪结束，会输出乱码。
	std::cout << m << "  " << n << std::endl;

	return 0;
}*/

int _tmain(int argc, _TCHAR* argv[])
{
	/*char *name[] = { "A", "B", "C", "D", "E" };
	std::cout << name[1] << std::endl;
	char name2[] = "zzz";//{ 'A', 'B', 'C', 'D', 'E','\0' };
	std::cout << name2 << std::endl;
	
	char(*name3)[] ;

	int a[2][3] = { { 1, 2, 3 }, { 45, 5, 6 } };
	int(*p)[3];
	p = &a[0];
	std::cout << *p[1] << std::endl;*/


	char p[8] = {0};
	char *q = "avd";
	int t = sizeof(q);
	cout << pow(1.5, 2) << endl;

	getchar();
	return 0;
}