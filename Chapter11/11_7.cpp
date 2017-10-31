#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class CFamily
{
public:
	CFamily() {}
	CFamily(string family_name)
	{
		family_children = { { family_name, vector<string>() } };
	}
public:
	void addNewFamily(string new_family_name)
	{
		family_children[new_family_name] = vector<string>();
	}
	void addChild(string family_name, string child_name)
	{
		const auto& mv = family_children[family_name];
		if (mv.empty())
		{
			addNewFamily(family_name);
			auto& vec = family_children[family_name];
			vec.push_back(child_name);
		}
		else
		{
			auto& vec = family_children[family_name];
			vec.push_back(child_name);
		}
		
	}

	void printFamily()
	{
		for (const auto &f : family_children)
		{
			cout << "family name: " << f.first << endl;
			cout << "family children: " << endl;
			for (const auto& name : f.second)
			{
				cout << name << " ";
			}
			cout << endl;
			cout << endl;
		}
	}
private:
	map<string, vector<string>> family_children;
};

int main(int argc, char *argv[])
{	
	CFamily family;

	//先添加家庭姓氏，再逐一添加孩子名
	family.addNewFamily("李");
	family.addChild("李", "大孩");
	family.addChild("李", "二孩");
	family.addChild("李", "三孩");

	//直接添加孩子名(自动创建家庭)
	family.addChild("王", "王一");
	family.addChild("王", "王二");
	family.addChild("王", "王三");

	//输出所有的家庭
	family.printFamily();
	cout << endl;
	return 0;
}
