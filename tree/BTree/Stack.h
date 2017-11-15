#ifndef STACK_H
#define STACK_H


#include <stdio.h>

#include "BinaryTree.h"
//
// 栈的头文件声明部分：Stack.h

// 栈初始容量
#define STACK_INIT_SIZE 20

// 栈容量不够用时，栈的增量
#define STACK_SIZE_INCREMENT 10

typedef BTree StackElemType;

//
// 顺序栈结构体
typedef struct tagStack
{
	StackElemType *base; // 指向栈底
	StackElemType *top;  // 指向栈顶
	int stackSize;       // 栈的大小
}Stack;

//
// 初始化栈
int InitStack(Stack *s);

//
// 销毁栈
void DestroyStack(Stack *s);

//
// 入栈
void Push(Stack *s, StackElemType e);

//
// 出栈
void Pop(Stack *s, StackElemType *e);

//
// 判断栈是否为空
int IsStackEmpty(Stack s);

//
// 取栈顶元素
int GetTop(Stack s, StackElemType *e);

#endif