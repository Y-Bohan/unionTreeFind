#include <iostream>
#include "unionFind.h"
using namespace std;
int main()
{
	UFTree uf(10);
	cout << uf.findGroupCount() << endl;		//初始化时每个元素为1组，所以此时应该有10组
	/*****将0，1，2，3合并到1组****************/
	uf.unionGroup(0, 3);
	uf.unionGroup(1,3);
	uf.unionGroup(2, 3);
	uf.unionGroup(3, 3);

	/*****将4，5，6合并到1组****************/
	uf.unionGroup(4, 6);
	uf.unionGroup(5, 6);
	uf.unionGroup(6, 6);

	/*****将7，8，9合并到1组****************/
	uf.unionGroup(7, 9);
	uf.unionGroup(8, 9);
	uf.unionGroup(9, 9);
	cout << uf.findGroupCount() << endl;				//此时还剩3组

	for (int i = 0; i < 10; i++)
		cout << i << " :root 为" << uf.findGroup(i) << endl;		//输出每个元素的根结点

	uf.unionGroup(2, 5);		//将2所在的组合并到5所在的组
	cout << uf.findGroupCount() << endl;				//此时还剩2组
	for (int i = 0; i < 10; i++)
		cout << i << " :root 为" << uf.findGroup(i) << endl;		//输出每个元素的根结点

	uf.unionGroup(2, 5);		//将2所在的组合并到5所在的组
	cout << uf.findGroupCount() << endl;				//此时由于2和5已经在同一组，所以没有合并操作，此时还是2组

	uf.unionGroup(2, 8);		//将2所在的组合并到5所在的组
	cout << uf.findGroupCount() << endl;				//此时还剩1组
	for (int i = 0; i < 10; i++)
		cout << i << " :root 为" << uf.findGroup(i) << endl;		//输出每个元素的根结点
	return 0;
}