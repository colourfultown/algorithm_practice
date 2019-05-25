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

	//void create();//���˹��캯����create����Ҫ�ˣ�ע�͵���
	void draw()const;
	double area()const;
	string what()const;

	//���������
	friend ofstream & operator << (ofstream &os, const Rectangle & rect);
	friend bool operator >(const Rectangle &r1, const Rectangle &r2);
	friend bool operator >(const Rectangle &r1, double area);
	Rectangle & operator =(const Rectangle & r);
	string operator ()() const;

private:
	int width, height;

};

