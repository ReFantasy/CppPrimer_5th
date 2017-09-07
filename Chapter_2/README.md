# Chapter_2

**以下是第二章的习题解答**

*EX为题号，灰色阴影部分为答案，其余为题目或其它说明*

## Ex2.1
```
short <= int <= long <= long long

有符号和无符号数的区别：
无符号数所有的位都用来保存数据，有符号数一般会拿出一位作为符号位。
它们表示的数的范围相等，无符号的最大值是有符号的两倍

float <= double
float和double的计算代价相差无几，然而double比float有着更高的精度。对于有些机器，双精度甚至比单精度的运算还要快。
```

## Ex2.2
```
很明显，double。。。
```

## Ex2.3 & Ex2.4
```
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;  //result 32
std::cout << u - u2 << std::endl;  //-32转化为无符号数 result 4294967264 (unsigned u 大小为 4 Byte)

int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;  //result 32
std::cout << i - i2 << std::endl;  //result -32
std::cout << i - u << std::endl;   //result 0
std::cout << u - i << std::endl;   //result 0

Note:有符号和无符号混合运算时，默认先将有符号隐式转换为无符号数。
若有符号数为非负，其值不变。若有符号为负数，转换的结果为其值和该类型无符号数表示的数值个数的和。
```

## Ex2.5
```
(a) 'a', L'a', "a", L"a"
    char类型字符，宽字符类型字符，字符数组，宽字符数组
(b) 10, 10u, 10L, 10UL, 012, 0xc
    十进制整型字面值10， 十进制无符号整型字面值10， 十进制长整型， 十进制无符号长整型， 八进制整型10， 十六进制整型字面值12
(c) 3.14, 3.14f, 3.14L
    double, float, long double
(d) 10, 10u, 10., 10e-2
    int, unsigned int, douoble, double 
```

## Ex2.6
```
int mounth = 9, day = 7;     //十进制表示
int mounth = 09, day = 07;   //mounth = 09 错误 ，09表示八进制表示，八进制每位最大值为7
```

## Ex2.7
```
(a) "Who goes with F\145rgus?\012"
    \145 = 'e', \012 = '\n'
(b) 3.14e1L  //31.4 long double
(c) 1024f    //相当于1024.0 float
(d) 3.14L    //3.14 long double
```

## Ex2.8
```
十六进制：
  "\x32\x4d\xA"
  "\x32\t\x4d\xA"
八进制：
  "\062\115\012"
  "\062\t\115\012"
  
  Note:八进制转义字符 \ 后面紧接3个数字，不满3个数字的 用0填充
       十六进制转义字符 \ 后面紧接x，然后后面的数字全部用来作为转义字符，
       直到遇到第一个不在 0~F 之间的字符 （十六进制f表示十进制的15）
```

## Ex2.9
```
(a) std::cin >> int input_value; //error
(b) int i = {3.14};  //error 未执行转换，因为存在信息丢失的风险
(c) double salary = wage = 9999.99;  
    //入果wage之前有过定义，则这条语句正确，否则错误
(d) int i = 3.14;  // right 但信息有丢失
```

## Ex2.10
```
std::string gloval_str;  //空字符串
int global_int; //0
int main()
{
    int local_int;  //未定义的值
    std::string local_str; //string类默认初始化未空字符串
}
```

## Ex2.11
```
(a) extern int ix = 1024;  // 定义
(b) int iy; //定义
(c) extern int iz; //声明
```

## Ex2.12
```
(a) int double = 3.14;  //error
(b) int _;  //right
(c) int catch-22;  //error
(d) int 1_or_2 = 1;  //error
(e) double Double = 3.14;  //right
```

## Ex2.13
```
int i = 42;
int main()
{
  int i = 100;
  int j = i;  // j == 100
}
```

## Ex2.14
```
合法： 输出
100 45
```

## Ex2.15
```
(a) int ival = 1.01;
    语法正确，数值有损失
(b) int &rvall = 1.01;
    错误，引用不能绑定到字面值常量，同时数据类型应该严格匹配
(c) int &rval2 = ival;
    正确
(d) int &rval3;
    错误，引用必须初始化
```

## Ex2.16
```
int i = 0, &r1 = i;  double d = 0, &r2 = d;
(a) r2 = 3.1415926;
    合法，等价于 d = 3.1415926
(b) r2 = r1;
    合法， 等价于d = i;
(c) i = r2;
    合法， 等价于 i = d;//精度损失
(d) r1 = d;
    合法， 等价于 i = d;
```

## Ex2.17
```
输出： 10 10
```

## Ex2.19
```
其一，指针本身就是一个对象，允许对指针赋值和拷贝，而且在指针的生命周期内它可以先后指向几个不同的对象。
其二，指针无需在定义时赋值。
```

## Ex2.20
```
int i = 42;
int *p1 = &i;  //定义指向i的指针
*p1 = *p1 * *p1; //计算i的平方并赋值给i
```

## Ex2.21
```
int i = 0;
(a) double *dp = &i;  //非法，数据类型不匹配
(b) int *ip = i;  //非法，不能将int型的值直接赋值给指针
(c) int *p = &i;  //合法
```

## Ex2.22
```
if(p)  //判断p是否是空指针
if(*p)  //判断p指向的变量的值是否为0
```

## Ex2.23
```
不能
```

## Ex2.24
```
略
```

## Ex2.25
```
(a) int* ip,i,&r = i;
    ip:指向int型的指针
    i:int型变量
    r:指向i的指针的引用
(b) int i, *ip=0;
    i:int型指针
    ip：指向int型指针并初始化未空指针
(c) int *p,ip2;
    ip:指向int型的指针
    ip2:int型变量
```
