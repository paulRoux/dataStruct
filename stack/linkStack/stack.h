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
    int top1;
    int top2;
}DoubleStack;


void InitStack(DoubleStack *S);

int EmptyStack(DoubleStack S);

ElemType GetStack(DoubleStack *S, int stackNumber);

int DestroyStack(DoubleStack *S, int stackNumber);

int PushStack(DoubleStack *S, ElemType e, int stackNumber);

int PopStack(DoubleStack *S, ElemType *e, int stackNumber);
#endif
