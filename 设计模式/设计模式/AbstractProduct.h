class AbstractProduct

{

protected:

	AbstractProduct(){}

public:

	void SharedThing(){}//ʵ�ֲ�Ʒ�Ĺ��Թ���
                       //ÿ����Ʒ���еĹ��ܣ�����ʵ���в���
	int virtual SomeThing(){}
	virtual ~AbstractProduct(){}
	};

	//���ֲ�ͬ�Ĳ�Ʒ������㣩

	class AbstactProductA :public AbstractProduct

	{};

	class AbstactProductB :public AbstractProduct

	{};

	//��Ʒ����ֻ���eg�����Ѿ�ȷ�����й��ˣ��ձ��ˣ���Ҫ������Ů�ˡ�

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