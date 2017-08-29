
# Chapter 1
**以下是第一章的习题解答**
## Ex1.1
```
//main返回0，正常结束
int main(int argc, char** argv)
{
    return 0;  
}
```

## Ex1.2
```
//main返回-1，ubuntu17.04 下 查看返回结果为255
//可见 ubuntu下系统接受的主函数的返回值类型是非负整型
int main((int argc, char** argv)
{
    return -1;  //main返回-1
}
``` 
<img src="./picture/ex1_1.jpg" width = "50%" /> 

## [Ex1.3](./ex1_3.cpp)

## [Ex1.4](./ex1_4.cpp)

## [Ex1.5](./ex1_5.cpp)

## Ex1.6
解释下面程序片段是否合法
```
std::cout << "The sum of" << v1;
          << " and " << v2;
          << " is " << v1 + v2 <<std::endl;
```
**答**：不合法。原因：C++中每个分号代表一条语句的结束。这段代码有三条语句，而第二条语句和第三条语句的输出运算符 << 的左侧没有运算对象。

**修改的方案如下**：

方案一：
```
std::cout << "The sum of" << v1  //去掉v1后面的分号
          << " and " << v2       //去掉v2后面的分号
          << " is " << v1 + v2 <<std::endl;
```

方案二：
```
std::cout << "The sum of" << v1;
std::cout << " and " << v2;   //加上运算对象std::cout，使之成为一条单独完整的语句
std::cout << " is " << v1 + v2 <<std::endl;  //同上
```

## Ex1.7
```
/*
*  源文件 test.cpp
*/
#include <iostream>
int main(int argc, char** argv)
{
    /*Hello*/World*/
    return 0;
}
```

**编译输出**

<img src="./picture/ex1_7.jpg" width = "50%" /> 

