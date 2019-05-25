#pragma once
#include <string>
#include <iostream>
using namespace std;
class Rectangle
{
public:
	Rectangle(int w=5,int h=5);
	Rectangle(const Rectangle & r);
	~Rectangle();

	string name;

	//void create();//有了构造函数，create不需要了，注释掉。
	void draw()const;
	double area()const;
	string what()const;

	//重载运算符
	friend ofstream & operator << (ofstream &os, const Rectangle & rect);
	friend bool operator >(const Rectangle &r1, const Rectangle &r2);
	friend bool operator >(const Rectangle &r1, double area);
	Rectangle & operator =(const Rectangle & r);
	string operator ()() const;

private:
	int width, height;

};

