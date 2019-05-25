#pragma once
class point_
{
public:
	point_();
	point_(double x1, double y1);
	~point_();
	double x;
	double y;
	bool operator==(point_ p){
		if (this->x == p.x && this->y == p.y)
			return true;
		else
			return false;
	}
};


