#include <stdio.h>

//
// 二叉树的头文件：BinaryTree.h

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#define OK 1
#define ERROR 0
#define OVERFLOW -1

//
// 结点的数据的类型
typedef char ElemType;

//
// 二叉树结构体
typedef struct tagBinaryTree
{
	ElemType data;                 // 数据
	struct tagBinaryTree *lchild;     // 指向左孩子
	struct tagBinaryTree *rchild;     // 指向右孩子
}BTree;

#endif