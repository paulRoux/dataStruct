/*************************************************************************
	> File Name: stack.h
	> Author: 
	> Mail: 
	> Created Time: 2017年10月30日 星期一 21时28分52秒
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H

typedef int ElemType;

typedef struct stack{
    ElemType data;
    struct stack *next;
}StackNode, *LinkStackPtr;

typedef struct{
    LinkStackPtr top;
    int count;
}LinkStack;

void InitStack(LinkStack *S);

int EmptyStack(LinkStack S);

ElemType GetStack(LinkStack *S);

void DestroyStack(LinkStack *S);

int PushStack(LinkStack *S, ElemType e);

int PopStack(LinkStack *S, ElemType *e);
#endif
