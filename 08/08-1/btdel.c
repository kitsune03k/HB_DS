#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree2.h"

void ShowIntData(int data)
{
	printf("%d ", data);
}

void ShowAddrData(BTreeNode * bt)
{
	printf("addr : %p, ", bt);
	printf("data : %d\n", GetData(bt));
}

int main(void)
{	
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();
	BTreeNode * bt5 = MakeBTreeNode();
	BTreeNode * bt6 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeRightSubTree(bt3, bt6);

	ShowAddrData(bt1);
	ShowAddrData(bt2);
	ShowAddrData(bt3);
	ShowAddrData(bt4);
	ShowAddrData(bt5);
	ShowAddrData(bt6);	

	PreorderTraverse(bt1, ShowIntData);
	printf("\n");

	DeleteTree(bt1);

	ShowAddrData(bt1);
	ShowAddrData(bt2);
	ShowAddrData(bt3);
	ShowAddrData(bt4);
	ShowAddrData(bt5);
	ShowAddrData(bt6);	

	return 0;
}