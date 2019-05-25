#include "stdafx.h"
#include "list.h"

void init(List &list)
{
	list.head = list.tail = NULL;
}
void push_back(List &list, const QUADPTR quad)
{
	Node * p = new Node;
	p->quad = const_cast<QUADPTR>(quad);
	p->next = NULL;
	if (list.head == NULL)
	{
		list.head = list.tail = p;
	}
	else
	{
		list.tail->next = p;
		list.tail = p;
	}
}
void push_front(List &list, const QUADPTR quad)
{
	Node * p = new Node;
	p->quad = const_cast<QUADPTR>(quad);
	p->next = list.head;
	list.head = p;
	if (list.head == NULL)
	{
		 list.tail = p;
	}

}
void clear(const List &list)
{
	Node *p = list.head, *q;
	while (p !=NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
}
void traverse(const List &list, ACCESSFUN f)
{
	Node *p = list.head;
	while (p != NULL)
	{
		f(p->quad);
		p = p->next;
	}
}
void access(QUADPTR quad)
{
	if (quad->name == "a")
	{
		Parallelogram *p = reinterpret_cast<Parallelogram *>(quad);
		draw(*p);
		//cout << what(*quad) << endl;
		cout << "area=" << area(*p) << endl;
	}
	else 
	{
	}
}