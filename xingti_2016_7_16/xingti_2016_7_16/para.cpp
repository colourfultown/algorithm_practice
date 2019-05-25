#include "stdafx.h"
#include "para.h"
#include<string>
#include <iostream>
#include<cstdlib>
using namespace std;

string what(Quadrangle & q)
{
	return q.name;
}

void create(Parallelogram &quad, int w, int h)
{
	quad.name = "a";
	
	quad.height = (h == 0) ? rand() % 10 + 5 : h;
	quad.width = (w == 0) ? rand() % 10 + 10 : w;
}
void draw(Parallelogram &quad)
{
	cout << what(reinterpret_cast<Quadrangle &>(quad)) << endl;
}
double area(Parallelogram & quad)
{
	return quad.width *quad.height;
}