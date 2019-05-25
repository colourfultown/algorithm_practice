#pragma once
#include"Quadrangle.h"
typedef void(*ACCESSFUN) (QUADPTR);


class List
{
public:
	List();
	
	List(const List &s);
	~List();
private:
	struct Node{
		QUADPTR quad;
		Node * next;
		Node(QUADPTR q);//加了一个函数，类似于构造函数，以后p->quad = const_cast<QUADPTR>(quad)省略，外面也无法访问Node
	} * head, *tail;
public:
	//void init();在构造函数中
	void push_back(const QUADPTR quad);
	void push_front(const QUADPTR quad);
	//void clear();在析构函数中销毁
	void traverse(ACCESSFUN f);

	//重载运算符
	operator bool()const;
	int operator ()()const;
	List &operator=(const List &s);
	List & operator +=(const QUADPTR quad);//为什么不用引用

};

