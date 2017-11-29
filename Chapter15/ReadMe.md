## Chapter 15
#### **第十五章的习题解答**

## Ex15.1
虚函数：
- 基类希望其子类能重新定义该函数
- 虚函数可以执行动态绑定
- 虚函数在其派生类中隐式地是虚函数

## Ex15.2
private:
  只能在类内访问，其他任何用户不能访问。包括其派生类。
  
protected:
  派生类有权访问，禁止其它用户访问。

## Ex15.4
```C++
class Base { ... };
(a) class Derived : public Derived { ... }; //错误，不能继承自身
(b) class Derived : private Base { ... };  //不是声明，是定义
(c) class Derived : public Base;  //错误，声明中不能出现派生列表
```

## Ex15.7
```C++
class Quote  //基类 按原价销售
{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price)
		:bookNo(book), price(sales_price) {}
	std::string isbn()const
	{
		return bookNo;
	}

	//返回给定数量的书籍的销售总额
	//派生类负责改写并使用不同的折扣计算算法
	virtual double net_price(std::size_t n)const
	{
		return n*price;
	}

	virtual ~Quote() = default;
private:
	std::string bookNo;  //书籍ISBN编号
protected:
	double price = 0.0; //原价
};

class MaxQty_quote :public Quote
{
public:
	MaxQty_quote() = default;
	MaxQty_quote(const std::string &book, double sales_price, std::size_t maxqty, double mdiscount)
		:Quote(book, sales_price), max_qty(max_qty), discount(mdiscount) {}
	double net_price(std::size_t cnt)const override
	{
		if (cnt <= max_qty)
		{
			return cnt*(1 - discount)*price;
		}
		else
		{
			return (cnt-max_qty)*price+ max_qty*(1 - discount)*price;
		}
	}
private:
	std::size_t max_qty = 0;
	double discount = 0.0;

};
```

## Ex15.8
- 静态类型：变量声明时的类型，或者是表达式生成的类型，在编译时是已知的。
- 动态类型：变量或表达式表示的内存中的对象的类型，动态类型直到运行时才可知。

## Ex15.9
指针或引用时，指针或引用的类型可能和对象的实际类型不同。

## Ex15.11
```C++

class Quote  //基类 按原价销售
{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price)
		:bookNo(book), price(sales_price) {}
	std::string isbn()const
	{
		return bookNo;
	}

	//返回给定数量的书籍的销售总额
	//派生类负责改写并使用不同的折扣计算算法
	virtual double net_price(std::size_t n)const
	{
		return n*price;
	}

	virtual ~Quote() = default;
	virtual void debug() const 
	{
		cout << "data members:" << endl << "\tbookNo" << bookNo << "\tprice" << price << endl;
	}
private:
	std::string bookNo;  //书籍ISBN编号
protected:
	double price = 0.0; //原价
};
   

class Bulk_quote :public Quote
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &, double, std::size_t, double)
	{
		;
	}
	//覆盖基类的函数版本以实现基于大量购买的折扣政策
	double net_price(std::size_t cnt)const override;
	void debug()const override
	{
		Quote::debug();
		cout << "data members:" << endl << "\tmin_qty" << min_qty << "\tdiscount" << discount << endl;
	}
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};
```

## Ex15.12
没必要

## Ex15.13
```C++
class base {
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
private:
    string basename;
};
class derived : public base {
public:
    void print(ostream &os) { print(os); os << " " << i; }
private:
    int i;
};
```
无限递归
修改：
```C++
class base {
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
private:
    string basename;
};
class derived : public base {
public:
    void print(ostream &os) { base::print(os); os << " " << i; }
private:
    int i;
};
```
