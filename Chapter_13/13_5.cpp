class HasPtr
{
public:
	HasPtr(const std::string &s = std::string())
		:ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr & hp)
		:ps(new std::string(hp.getString())), i(hp.getI()){}

	const string getString()const
	{
		return *ps;
	}
	const int getI()const
	{
		return i;
	}
private:
	std::string *ps;
	int i;
};

