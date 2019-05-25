class AbstractProduct

{

protected:

	AbstractProduct(){}

public:

	void SharedThing(){}//实现产品的共性功能
                       //每个产品都有的功能，具体实现有差异
	int virtual SomeThing(){}
	virtual ~AbstractProduct(){}
	};

	//两种不同的产品（抽象层）

	class AbstactProductA :public AbstractProduct

	{};

	class AbstactProductB :public AbstractProduct

	{};

	//产品纵向分化，eg对于已经确定的中国人，日本人，又要区分男女了。

	class ProductA1 :public AbstactProductA

	{};

	class ProductA2 :public AbstactProductA

	{};

	class ProductB1 :public AbstactProductB

	{};

	class ProductB2 :public AbstactProductB

	{};



	class AbstractCreator

	{

	protected:

		AbstractCreator(){}

	public:
		virtual AbstactProductA* CreatProductA() = 0;
		virtual AbstactProductB* CreatProductB() = 0;

		virtual ~AbstractCreator() = 0;

	};

	class Creator1 :public AbstractCreator

	{

		AbstactProductA* CreatProductA()

		{

			return new ProductA1();

		}
		AbstactProductB* CreatProductB()

		{
			return new ProductB1();

		}

	};

	class Creator2 :public AbstractCreator

	{

		AbstactProductA* CreatProductA()

		{

			return new ProductA2();

		}
		AbstactProductB* CreatProductB()

		{
			return new ProductB2();

		}

	};