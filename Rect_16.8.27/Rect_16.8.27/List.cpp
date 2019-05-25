#include "stdafx.h"
#include "List.h"
#include <iostream>
#include <string>
using namespace std;

List::List() :head(NULL), tail(NULL)
{

}
List::List(const List &s)
{
	head = tail = NULL;
	Node *p = s.head;
	while (p != NULL)
	{
		this->push_back(p->quad);
		p = p->next;
	}

}

List::~List()
{
	Node *p = head, *q;
	if (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
}
List::Node::Node(QUADPTR q) :quad(q)
{

}
/*void List::init()
{
	head = tail = NULL;
}*/
void List::push_back(const QUADPTR quad)
{
	Node * p=new Node(quad);
	//p->quad = const_cast<QUADPTR>(quad);
	p->next = NULL;
	if (tail == NULL)
		head = tail = p;
	else
	{
		tail->next = p;
		tail = p;
	}
}
void List::push_front(const QUADPTR quad)
{
	Node *p = new Node(quad);
	//p->quad = const_cast<QUADPTR>(quad);
	p->next = head;
	head = p;
	if (tail == NULL)
		tail = p;
}
/*void List::clear()
{
	Node *p = head, *q;
	if (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
}*/
void List::traverse(ACCESSFUN f)//遍历
{
	Node *p= head;
	while (p != NULL)
	{
		f(p->quad);//f什么都没干，暂时只需要知道f是输入一个quad的指针，无输出的函数就可以了。
		p = p->next;
	}
}
List::operator bool()const
{
	return head != NULL;
}
int List::operator()()const
{
	Node *p = head;
	int a = 0;
	while (p != NULL)
	{
		p = p->next;
		++a;
	}
	return  a;
}
List & List::operator=(const List & list)
{
	head = list.head;
	tail = list.tail;
	return *this;
}
List &List::operator+=(const QUADPTR quad)
{
	push_back(quad);
	return *this;
}