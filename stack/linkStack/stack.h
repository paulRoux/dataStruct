/*************************************************************************
	> File Name: stack.h
	> Author: 
	> Mail: 
	> Created Time: 2017年10月30日 星期一 21时28分52秒
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H

#define MAXSIZE 100

typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int top;
}Stack;

void InitStack(Stack *S);

int EmptyStack(Stack S);

ElemType GetStack(Stack *S);

void DestroyStack(Stack *S);

int PushStack(Stack *S, ElemType e);

int PopStack(Stack *S, ElemType *e);
#endif
