#include <iostream>
using namespace std;

class Base
{
protected:
	int x;
public:
	Base()
	{
		printf("Base()\n");
		x = 0;
	}
	Base(int _x)
	{
		printf("Base(int _x)\n");
		x = _x;
	}
	Base(const Base &b)
	{
		printf("Base(const Base &b)\n");
		x = b.x;
	}
	virtual ~Base()
	{
		printf("~Base()\n");
	}
	virtual void method()
	{
		printf("virtual void method()\n");
	}
	void method_1()
	{
		printf("void method_1()\n");
	}
	virtual void method_2()
	{
		printf("virtual void method_2()\n");
	}
	virtual void method_3()
	{
		printf("virtual void method_3()\n");
		method();
		method_1();
		method_2();
	}
};
class Inheritor : public Base
{
private:
	int x;
public:
	Inheritor()
	{
		printf("Inheritor()\n");
		x = 0;
	}
	Inheritor(int _x) : Base(_x)
	{
		printf("Inheritor(int _x)\n");
	}
	Inheritor(const Inheritor &inh)
	{
		printf("Inheritor(int _x)\n");
		x = inh.x;
	}
	~Inheritor()
	{
		printf("~Inheritor()\n");
	}
	void method() override
	{
		printf("void method() override\n");
	}
	void method_1() //override
	{
		printf("void method_1() override\n");
	}
};

class Base2
{
protected:
	int x;
public:
	Base2()
	{
		printf("Base2()\n");
		x = 0;
	}
	Base2(int _x)
	{
		printf("Base2(int _x)\n");
		x = _x;
	}
	Base2(const Base2& b)
	{
		printf("Base2(const Base &b)\n");
		x = b.x;
	}
	~Base2() //not virtual destructor
	{
		printf("~Base2()\n");
	}
	virtual void method()
	{
		printf("virtual void method()\n");
	}
	virtual void method_2()
	{
		printf("virtual void method_2()\n");
	}
	virtual void method_3()
	{
		printf("virtual void method_3()\n");
		method();
		method_2();
	}
};
class Inheritor2 : public Base2
{
private:
	int x;
public:
	Inheritor2()
	{
		printf("Inheritor2()\n");
		x = 0;
	}
	Inheritor2(int _x) : Base2(_x)
	{
		printf("Inheritor2(int _x)\n");
	}
	Inheritor2(const Inheritor2& inh)
	{
		printf("Inheritor2(int _x)\n");
		x = inh.x;
	}
	~Inheritor2()
	{
		printf("~Inheritor2()\n");
	}
	void method() override
	{
		printf("void method() override\n");
	}
};

int main()
{
	//виртуальные , наследуемые, перекрываемые методы, виртуальный деструктор
	Inheritor* inh = new Inheritor(); printf("\n");
	inh->method(); printf("\n"); //переопределенный метод
	inh->method_1(); printf("\n"); //вызов виртуального метода при обращении к объекту через указатель на класс потомок
	inh->method_2(); printf("\n"); //наследуемый метод
	inh->method_3(); printf("\n"); //вызывает переопределенный, наследуемый методы, переопределенный метод невиртуальный в базовом классе
	delete inh; printf("\n\n");

	Base* base_inh = new Inheritor(); printf("\n");
	base_inh->method_1(); printf("\n"); //вызов невиртуального метода при обращении к объекту через указатель на базовый класс
	delete base_inh; printf("\n\n");

	Base2* base = new Inheritor2(); //Удаление производится через указатель на базовый класс и 
	delete base; printf("\n\n");	//для вызова деструктора компилятор использует раннее связывание.
									//Деструктор базового класса не может вызвать деструктор производного, 
									//потому что он о нем ничего не знает.




	return 0;
}