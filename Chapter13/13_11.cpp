class HasPtr
{
public:
	HasPtr(const std::string &s = std::string())
		:ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr & hp)
		:ps(new std::string(*hp.ps)), i(hp.i) {}
		
    //拷贝赋值运算符
	HasPtr& operator=(const HasPtr &hp)
	{
		if (ps != nullptr)
			delete ps;
		ps = new string(*hp.ps);
		i = hp.i;
		return *this;
	}
	
    //添加析构函数
    ~HasPtr()
    {
        delete ps;
    }
private:
	std::string *ps;
	int i;