#pragma once
#include <string>
using namespace std; //��������ֿռ䣬�������ĵ�string Ҫ��std::string
class Quadrangle//�ı�����
{
public:
	string name;
	static int counter;

	Quadrangle();
	~Quadrangle();
};
typedef Quadrangle * QUADPTR;
