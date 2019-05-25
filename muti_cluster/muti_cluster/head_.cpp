#include "stdafx.h"
#include "head_.h"

head_::head_(){
	layer = -1;
	len = 0;
}
head_::head_(int layer_in, point_ p_in,double len_)
{
	layer = layer_in;
	p = p_in;
	len = len_;
	classfication = 0;
	
}


head_::~head_()
{
}


