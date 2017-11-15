#include <stdio.h>

//
// 二叉树的头文件：BST.h

#ifndef BST_H
#define BST_H

#define OK 1
#define ERROR 0
#define OVERFLOW -1

//
// 结点的数据的类型
typedef char ElemType;

//
// 二叉树结构体
typedef struct BinarySearchTree
{
	ElemType data;                 // 数据
	struct BinarySearchTree *lchild;     // 指向左孩子
	struct BinarySearchTree *rchild;     // 指向右孩子
}BSTree;

#endif