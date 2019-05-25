
#ifndef _LIST_
#define _LIST_
#include "para.h"
#include<iostream>
using namespace std;
struct Node{ QUADPTR quad; Node * next; };
struct List{ Node * head, * tail; };

typedef void(*ACCESSFUN)(QUADPTR);
extern void init(List &list);
extern void push_back(List &list, const QUADPTR quad);
extern void push_front(List &list, const QUADPTR quad);
extern void clear(const List &list);
extern void traverse(const List &list, ACCESSFUN f);
extern void access(QUADPTR quad);

#endif



