#pragma once
#include <string>
using namespace std; //必须加名字空间，否则下文的string 要用std::string
class Quadrangle//四边形类
{
public:
	string name;
	static int counter;

	Quadrangle();
	~Quadrangle();
};
typedef Quadrangle * QUADPTR;
