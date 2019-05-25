#include "stdafx.h"
#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;
#include "Rectangle.h"
#include "Quadrangle.h"

Rectangle::Rectangle(int w, int h) :name("Rectangle"), width(w), height(h)
{
	++Quadrangle::counter;
}
Rectangle::Rectangle(const Rectangle & r)
{
	++Quadrangle::counter;
}

Rectangle::~Rectangle()
{
}
/*void Rectangle::create()
{
	name = "Rectangle";
	height = rand() % 10 + 5;
	width = rand() % 15 + 5;
	++Quadrangle::counter;
}*/
void Rectangle::draw()const
{
	cout << what() << "高" << height << "长" << width << endl;//这里的what也必须声明为const 不然报错
}
double Rectangle::area()const
{
	return height*width;
}
string Rectangle::what()const
{
	return name;
}
string Rectangle ::operator()()const
{
	return name;
}
Rectangle &Rectangle::operator=(const Rectangle &r)
{
	name = r.name;
	width = r.width;
	height = r.height;
	return *this;
}
bool operator >(const Rectangle r1, const Rectangle r2)
{
	return r1.area() > r2.area();
}
bool operator >(const Rectangle r1, double area)
{
	return r1.area() > area;
}