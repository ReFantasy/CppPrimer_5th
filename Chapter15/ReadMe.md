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
