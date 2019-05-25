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
		Node(QUADPTR q);//����һ�������������ڹ��캯�����Ժ�p->quad = const_cast<QUADPTR>(quad)ʡ�ԣ�����Ҳ�޷�����Node
	} * head, *tail;
public:
	//void init();�ڹ��캯����
	void push_back(const QUADPTR quad);
	void push_front(const QUADPTR quad);
	//void clear();����������������
	void traverse(ACCESSFUN f);

	//���������
	operator bool()const;
	int operator ()()const;
	List &operator=(const List &s);
	List & operator +=(const QUADPTR quad);//Ϊʲô��������

};

