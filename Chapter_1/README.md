
# Chapter 1
**以下是第一章的习题解答**
## Ex1.1
```
//main返回0，正常结束
int main((int argc, char** argv)
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

## Ex1.3
```
int main((int argc, char** argv)
{
    std::cout<<"Hello,World";  //输出字符串字面值常量
    return 0;
}
```

## Ex1.4
```
int main((int argc, char** argv)
{
   int v1 = 0;
   int v2 = 0;
   std::cin >> v1 >> v2;
   std::cout << v1*v2 << std::endl;  //输出乘积
   return 0;
}
```
