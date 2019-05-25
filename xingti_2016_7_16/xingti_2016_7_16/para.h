

#include<string>
using namespace std;


#ifndef _QUAD_
#define _QUAD_

struct Quadrangle{ string name; };
typedef Quadrangle* QUADPTR;
extern string what(Quadrangle & q);
#endif


#ifndef _PARA_
#define _PARA_

//平行四边形
struct Parallelogram{
	string name; 
	int width, height; 
};
extern void create(Parallelogram &, int w = 0, int h = 0);
extern void draw(Parallelogram &);
extern double area(Parallelogram &);
#endif

