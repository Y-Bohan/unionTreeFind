#ifndef unionFind_H
#define unionFind_H
#include <iostream>
using namespace std;

class UFTree
{
public:
	UFTree(int N);
	~UFTree();
	bool connected(int x, int y);		//判断元素x和元素y是否在同一个分组
	int findGroup(int x);		//查找元素x所在组中树的根结点
	void unionGroup(int x, int y);		//将x所在的组合并到y所在的组
	int findGroupCount();		//查找共有多少个分组
private:
	int* eleGroup;		//索引存放元素，索引处的值存放该元素的父结点，如eleGroup[5]=6.表示5的父结点是6
	int groupCount;		//分组个数
};

UFTree::UFTree(int N)
{
	groupCount = N;
	eleGroup = new int[N];					//堆上开辟N个空间存放元素的分组初始信息
	for (int i = 0; i < N; i++)				//初始每个元素单独一组，索引值就是其父结点，也是根结点，即eleGroup[i] == i,元素i的父结点和根结点是本身
	{
		eleGroup[i] = i;		
	}
}

int UFTree::findGroup(int x)			//查找x的根结点
{
	while (1)
	{
		if (eleGroup[x] == x)
			return x;
		else x = eleGroup[x];			//逐层向上查找其父结点，
	}
}

bool UFTree::connected(int x, int y)			//通过x和y的根结点是否相同来判断x和y是否在同一组，
{
	return findGroup(x) == findGroup(y);
}

void  UFTree::unionGroup(int x, int y)		//将x所在的组合并到y所在的组
{
	int xRoot = findGroup(x);
	int yRoot = findGroup(y);
	if (xRoot == yRoot)				//x和y在同一个分组，不需要合并
		return;
	else
	{
		eleGroup[xRoot] = yRoot;		//y所在分组的根结点成为x所在分组的根结点的父结点
		groupCount--;
	}
}

int  UFTree::findGroupCount()			//返回当前所有元素总共的组数
{
	return groupCount;
}

UFTree::~UFTree()		//析构释放堆中内存
{
	if (eleGroup != NULL)
	{
		delete[] eleGroup;
		eleGroup = NULL;
	}
}

#endif 

