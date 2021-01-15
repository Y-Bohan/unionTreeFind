#ifndef unionFind_H
#define unionFind_H
#include <iostream>
using namespace std;

class UFTree
{
public:
	UFTree(int N);
	~UFTree();
	bool connected(int x, int y);		//�ж�Ԫ��x��Ԫ��y�Ƿ���ͬһ������
	int findGroup(int x);		//����Ԫ��x�����������ĸ����
	void unionGroup(int x, int y);		//��x���ڵ���ϲ���y���ڵ���
	int findGroupCount();		//���ҹ��ж��ٸ�����
private:
	int* eleGroup;		//�������Ԫ�أ���������ֵ��Ÿ�Ԫ�صĸ���㣬��eleGroup[5]=6.��ʾ5�ĸ������6
	int groupCount;		//�������
};

UFTree::UFTree(int N)
{
	groupCount = N;
	eleGroup = new int[N];					//���Ͽ���N���ռ���Ԫ�صķ����ʼ��Ϣ
	for (int i = 0; i < N; i++)				//��ʼÿ��Ԫ�ص���һ�飬����ֵ�����丸��㣬Ҳ�Ǹ���㣬��eleGroup[i] == i,Ԫ��i�ĸ����͸�����Ǳ���
	{
		eleGroup[i] = i;		
	}
}

int UFTree::findGroup(int x)			//����x�ĸ����
{
	while (1)
	{
		if (eleGroup[x] == x)
			return x;
		else x = eleGroup[x];			//������ϲ����丸��㣬
	}
}

bool UFTree::connected(int x, int y)			//ͨ��x��y�ĸ�����Ƿ���ͬ���ж�x��y�Ƿ���ͬһ�飬
{
	return findGroup(x) == findGroup(y);
}

void  UFTree::unionGroup(int x, int y)		//��x���ڵ���ϲ���y���ڵ���
{
	int xRoot = findGroup(x);
	int yRoot = findGroup(y);
	if (xRoot == yRoot)				//x��y��ͬһ�����飬����Ҫ�ϲ�
		return;
	else
	{
		eleGroup[xRoot] = yRoot;		//y���ڷ���ĸ�����Ϊx���ڷ���ĸ����ĸ����
		groupCount--;
	}
}

int  UFTree::findGroupCount()			//���ص�ǰ����Ԫ���ܹ�������
{
	return groupCount;
}

UFTree::~UFTree()		//�����ͷŶ����ڴ�
{
	if (eleGroup != NULL)
	{
		delete[] eleGroup;
		eleGroup = NULL;
	}
}

#endif 

