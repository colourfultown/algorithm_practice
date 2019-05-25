#pragma once
//工厂方法

class IFactoryBase
{
public:
	IFactoryBase(void);
	virtual ~IFactoryBase(void);

public:
	virtual IProductBase* CreateProduct() = 0;
};

class IProductBase
{
public:
	IProductBase(void);
	~IProductBase(void);

public:
	virtual void SetProductInfo() = 0;
};

class CFactoryA : public IFactoryBase
{
public:
	CFactoryA(void);
	~CFactoryA(void);

public:
	virtual IProductBase* CreateProduct();
};

IProductBase* CFactoryA::CreateProduct()
{
	return new CProductA();
}

class CProductA : public IProductBase
{
public:
	CProductA(void);
	~CProductA(void);

public:
	void SetProductInfo(){}
};

class CFactoryB : public IFactoryBase
{
public:
	CFactoryB(void);
	~CFactoryB(void);

public:
	virtual IProductBase* CreateProduct();
};

IProductBase* CFactoryB::CreateProduct()
{
	return new CProductB();
}

class CProductB : public IProductBase
{
public:
	CProductB(void);
	~CProductB(void);

public:
	virtual void SetProductInfo(){}
};

/*int _tmain(int argc, _TCHAR* argv[])
{
	IFactoryBase *pFactory = new CFactoryA();
	if (NULL != pFactory)
	{
		IProductBase *pProductBase = pFactory->CreateProduct();
		if (NULL != pProductBase)
		{
			pProductBase->SetProductInfo();
		}

		delete pProductBase;//不用智能指针的话要记得删除
	}

	delete pFactory;

	return 0;
}*/