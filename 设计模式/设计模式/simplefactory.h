#pragma once
//简单工厂
#include <iostream>
#include  <memory>

using namespace std;

class Operation
{
private:
	double A, B;
public:
	double GetA() const { return A; }
	double GetB() const { return B; }
	void SetA(double x) { A = x; }
	void SetB(double y) { B = y; }
	double virtual GetResult(){ return 0; }
	Operation() :A(0), B(0){}
};

class Add : public Operation
{
public:
	double GetResult()
	{
		return GetA() + GetB();
	}
};

class Sub : public Operation
{
public:
	double GetResult()
	{
		return GetA() - GetB();
	}
};

class Mul : public Operation
{
public:
	double GetResult()
	{
		return GetA()*GetB();
	}
};

class Div : public Operation
{
public:
	double GetResult()
	{
		return GetA() / GetB();
	}
};

class simplefactory
{
public:
	static Operation * CreateOpeartor(char ch)
	{
		Operation * p;
		switch (ch)
		{
		case '+':
			p = new Add();
			break;
		case '-':
			p = new Sub();
			break;
		case '*':
			p = new Mul();
			break;
		case '/':
			p = new Div();
			break;
		}
		return p;
	}
};
/*
int main(int argc, char *argv[])
{
	double A = 0;
	double B = 0;
	char ch = '\0';
	cin >> A >> ch >> B;

	tr1::shared_ptr<Operation> op(SimpleFactory::CreateOpeartor(ch));用一个静态函数来创建其他算数类
	//使用了智能指针类shared_ptr，当该对象的生命期结束时，其析构函数能够自动析构掉指针所指的对象。
	op->SetA(A);
	op->SetB(B);
	cout << op->GetResult() << endl;
}
*/