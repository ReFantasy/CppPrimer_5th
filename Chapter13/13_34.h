#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Message;

class Folder
{
public:
	Folder(string name = string()) :folder_name(name) {}
	Folder(const Folder &f);
	Folder& operator=(const Folder &f);
	void showMsgs();
	void addMsg(Message *);
	void remMsg(Message *);
	string getFolderName();
private:
	string folder_name;
	set<Message*> Msgs;
};

class Message
{
	//friend class Folder;
	friend void swap(Message &lhs, Message &rhs);
public:
	explicit Message(const string &str = "") :contents(str) {}
	Message(const Message &m)
		:contents(m.contents), folders(m.folders)
	{
		addToFolder(m.folders);
	}
	Message& operator=(const Message &m)
	{
		removeFromFolders(folders);
		contents = m.contents;
		folders = m.folders;
		addToFolder(folders);
		return *this;
	}
	~Message()
	{
		removeFromFolders(folders);
	}
	void save(Folder &f)
	{
		folders.insert(&f);
		f.addMsg(this);
	}
	void remove(Folder &f)
	{
		folders.erase(&f);
		f.remMsg(this);
	}
	void showFolders()
	{
		cout << "包含这个消息的文件夹有：" << endl;
		for (auto pf : folders)
		{
			cout << pf->getFolderName() << endl;
		}
	}
	void addFolder(Folder *f)
	{
		save(*f);
	}
	void remFolder(Folder *f)
	{
		remove(*f);
	}
	string getContents()
	{
		return contents;
	}
private:
	string contents;  //消息的内容
	set<Folder*> folders;  //包含本消息的文件夹
	void addToFolder(const set<Folder*> &folders) //从folders中添加本消息
	{
		for (auto &p : folders)
		{
			p->addMsg(this);
		}
	}
	void removeFromFolders(const set<Folder*> &folders) //从folders中删除本消息
	{
		for (auto &p : folders)
		{
			p->remMsg(this);
		}
	}
};
void swap(Message &lhs, Message &rhs)
{
	for (auto p : lhs.folders)
		p->remMsg(&lhs);
	for (auto p : rhs.folders)
		p->remMsg(&rhs);

	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	
	for (auto p : lhs.folders)
		p->addMsg(&lhs);
	for (auto p : rhs.folders)
		p->addMsg(&rhs);
}

void Folder::showMsgs()
{
	cout << folder_name << " 包含的 Message 有：" << endl;
	for (auto pmsg : Msgs)
		cout << pmsg->getContents() << endl;
}

void Folder::addMsg(Message *m)
{
	Msgs.insert(m);
}

void Folder::remMsg(Message *m)
{
	Msgs.erase(m);
}

std::string Folder::getFolderName()
{
	return folder_name;
}

Folder::Folder(const Folder &f)
{
	for (auto &pm : f.Msgs)
	{
		pm->save(*this);
	}
}


Folder& Folder::operator=(const Folder &f)
{
	auto tmpMsgs = Msgs;
	for (auto pm : tmpMsgs)
		pm->remove(*this);
	
	for (auto &pm : f.Msgs)
	{
		pm->save(*this);
	}

	return *this;
}

#endif