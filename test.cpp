#include <iostream>
#include "unionFind.h"
using namespace std;
int main()
{
	UFTree uf(10);
	cout << uf.findGroupCount() << endl;		//��ʼ��ʱÿ��Ԫ��Ϊ1�飬���Դ�ʱӦ����10��
	/*****��0��1��2��3�ϲ���1��****************/
	uf.unionGroup(0, 3);
	uf.unionGroup(1,3);
	uf.unionGroup(2, 3);
	uf.unionGroup(3, 3);

	/*****��4��5��6�ϲ���1��****************/
	uf.unionGroup(4, 6);
	uf.unionGroup(5, 6);
	uf.unionGroup(6, 6);

	/*****��7��8��9�ϲ���1��****************/
	uf.unionGroup(7, 9);
	uf.unionGroup(8, 9);
	uf.unionGroup(9, 9);
	cout << uf.findGroupCount() << endl;				//��ʱ��ʣ3��

	for (int i = 0; i < 10; i++)
		cout << i << " :root Ϊ" << uf.findGroup(i) << endl;		//���ÿ��Ԫ�صĸ����

	uf.unionGroup(2, 5);		//��2���ڵ���ϲ���5���ڵ���
	cout << uf.findGroupCount() << endl;				//��ʱ��ʣ2��
	for (int i = 0; i < 10; i++)
		cout << i << " :root Ϊ" << uf.findGroup(i) << endl;		//���ÿ��Ԫ�صĸ����

	uf.unionGroup(2, 5);		//��2���ڵ���ϲ���5���ڵ���
	cout << uf.findGroupCount() << endl;				//��ʱ����2��5�Ѿ���ͬһ�飬����û�кϲ���������ʱ����2��

	uf.unionGroup(2, 8);		//��2���ڵ���ϲ���5���ڵ���
	cout << uf.findGroupCount() << endl;				//��ʱ��ʣ1��
	for (int i = 0; i < 10; i++)
		cout << i << " :root Ϊ" << uf.findGroup(i) << endl;		//���ÿ��Ԫ�صĸ����
	return 0;
}