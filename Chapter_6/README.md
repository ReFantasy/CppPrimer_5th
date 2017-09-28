# Chapter_6

**以下是第六章的习题解答**

EX为题号，灰色阴影部分为答案，其余为题目或其它说明

## Ex6.1
```
实参用来初始化形参
```

## Ex6.2
```C++
(a) string f() 
    {
        string s;
        //..
        return s;  
    }
    
(b) void f2(int i){/*..*/}

(c) int calc(int v1, int v2){/*...*/}

(d) double square (double x) { return x * x; }
```

## [Ex6.3 && Ex6.4](./6_4.cpp)

## [Ex6.5](./6_5.cpp)

## Ex6.6
```
形参          作用域：从参数列表到函数体 生命周期：函数的执行整个周期
局部变量       作用域：当前所在的代码块 生命周期：从定义开始到代码块结束
局部静态变量   作用域：当前所在的代码块 生命周期：整个程序的执行过程
```

## [Ex6.7](./6_7.cpp)

## Ex6.32
```
合法
```

## [Ex6.10](./6_10.cpp)

## Ex6.13
```
void f(T);
通过值传递，将类型T的拷贝传入函数。
void f(&T);
不懂这种声明，难道不应该是 void f(T&);
```

## Ex6.15
```
why is s a reference to const but occurs is a plain reference?
因为s明显没必要改变，而occurs是要记录出现的次数，值需要改变

Why are these parameters references, but the char parameter c is not?
因为一个char很小，比起引用，直接复制过来，效率更高

Why are these parameters references, but the char parameter c is not?
so easy.I do not want to explain.
```

## Ex6.16
```C++
bool is_empty(const string& s) { return s.empty(); }
```

## [Ex6.17](./6_17.cpp)

## Ex6.18
```C++
(a) bool compare(const matrix &m1, const matrix &m1);
(b) vector<int>::iterator change_val(int, vector<int>::iterator);
```

## Ex6.19
```
(a) illegal, only one parameter.
(b) legal. 
(c) legal. 
(d) legal.
```

## Ex6.20
```
常量引用：当不需要改变数据的值的时候，最好都声明为常量引用
常量引用改为普通引用，不仅仅缩小了函数参数的范围，无法对常量进行引用，还容易导致错误，改变了不应该改变的值。
```

## [Ex6.21](./6_21.cpp)

## [Ex6.22](./6_22.cpp)

## Ex6.24
```C++
void print(const (&ia)[10]);
```

## [Ex6.25 && Ex6.26](./6_25.cpp)

## [Ex6.27](./6_27.cpp)

## Ex6.28
```C++
string &
```

## Ex6.39
```
(a) illegal

(b) illegal

(c) legal
```

## Ex6.40
```
(a) no error

(b)  'wd', 'bckgrnd'缺少默认参数.
```

## Ex6.41
```
(a) 错误
(b) 完全匹配
(c) 匹配， ht = 14, wd = '*', backgrnd = ' '
```

## Ex6.43
```
全部放在头文件
```

## Ex6.44
```C++
#include <iostream>
#include <string>

using std::string;

inline bool isShorter(const string& s1, const string& s2)
{
    return s1.size() < s2.size();
}

int main()
{
    std::cout << isShorter("shanghai", "beijing") << std::endl;
}
```

## Ex6.52
```
(a) 提升
(b) 转换
```
