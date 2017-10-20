# Chapter_3

**以下是第三章的习题解答**

*EX为题号，灰色阴影部分为答案，其余为题目或其它说明*

## [Ex3.2](./ex3_2.cpp)

## Ex3.3
```
string: 以空格或者换行符作为输入的结束标志,并忽略字符串前面的空字符
getline: 以换行符作为输入的结束
```

## [Ex3.4](./ex3_4.cpp)

## [Ex3.5](./ex3_5.cpp)

## [Ex3.6](./ex3_6.cpp)

## Ex3.9
```
不合法。应该先判断字符串是否为空
```

## [Ex3.10](./ex3_10.cpp)

## Ex3.11
```
c的类型是：const string &
只能读不能写
```

## Ex3.12
```
b错误
```

## Ex3.13
```
v1 empty
v2 10个0
v3 10个42
v4 一个10
v5 一个10一个42
v6 10个空string
v7 10个"hi"
```

## [Ex3.14](./3_14.cpp)

## [Ex3.15](./3_15.cpp)

## [Ex3.17](./3_17.cpp)

## Ex3.19
```C++
    vector<int> ivec1(10, 42);
    vector<int> ivec2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    vector<int> ivec3;
    for (int i = 0; i != 10; ++i) ivec3.push_back(42);
```

## [Ex3.20](./3_20.cpp)

## [Ex3.21](./3_21.cpp)

## [Ex3.22](./3_22.cpp)

## [Ex3.23](./3_23.cpp)

## Ex3.26
```
两个迭代器之间没有定义加减运算
```

## Ex3.27
```
a,c非法
d非法 st[11]含有11个元素，"fundamental" 含有12个元素（隐含'\0'）
```

## Ex3.28
```C++
string sa[10]; //元素 空string
int ia[10]; //元素int 0

int main() {
  string sa2[10]; //元素 空string
  int ia2[10]; //未定义int
  
}
```

## Ex3.29
```
数组的大小固定，缺少灵活性，而且标准库对数组的支持没有vector多。
```

## [Ex3.41](./3_41.cpp)