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
