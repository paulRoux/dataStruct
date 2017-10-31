/*************************************************************************
	> File Name: stack.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月30日 星期一 21时29分07秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void InitStack(DoubleStack *S)
{
    if(S == NULL){
        exit(1);
    }

    memset(S->data, 0, sizeof(S->data));
    S->top1 = -1;
    S->top2 = MAXSIZE;
}

int EmptyStack(DoubleStack S)
{
    if(S.top1 == -1){
        return -1;
    }else if(S.top2 == MAXSIZE){
        return 0;
    }else{
        return 1;
    }
}

ElemType GetStack(DoubleStack *S, int stackNumber)
{
    if(S == NULL || (stackNumber != 1 && stackNumber != 2)){
        exit(1);
    }

    if(stackNumber == 1){
        if(S->top1 == -1){
            printf("the stack1 is empty!\n");
            return -1;
        }
        return S->data[S->top1];
    }else{
        if(S->top2 == MAXSIZE){
            printf("the stack2 is empty!\n");
            return -1;
        }
        return S->data[S->top2];
    }

}

int DestroyStack(DoubleStack *S, int stackNumber)
{
    if(S == NULL || (stackNumber != 1 && stackNumber != 2)){
        return -1;
    }
    
    if(stackNumber == 1){
        if(S->top1 == -1){
            return -1;
        }
        S->top1 = -1;
    }else{
        if(S->top2 == MAXSIZE){
            return -1;
        }
        S->top2 = MAXSIZE;
    }
}

int PushStack(DoubleStack *S, ElemType e, int stackNumber)
{
    if(S == NULL || S->top1 == S->top2+1){
        return -1;
    }

    if(stackNumber == 1){
        S->top1++;
        S->data[S->top1] = e;
    }else{
        S->top2--;
        S->data[S->top2] = e;
    }

    return 1;
}

int PopStack(DoubleStack *S, ElemType *e, int stackNumber)
{
    if(S == NULL || (stackNumber != 1 && stackNumber != 2)){
        return -1;
    }

    if(stackNumber == 1){
        if(S->top1 == -1){
            return -1;
        }else{
            *e = S->data[S->top1];
            S->top1--;
        }
    }

    if(stackNumber == 2){
        if(S->top2 == MAXSIZE){
            return -1;
        }else{
            *e = S->data[S->top2];
            S->top2++;
        }
    }

    return 1;
}

int main(void)
{
    DoubleStack stack;
    ElemType e;
    int stackNumber;

    printf("please input the elem and stackNumber: ");
    scanf("%d%d", &e, &stackNumber);
    
    InitStack(&stack);
    printf("get elem: %d\n", GetStack(&stack, stackNumber));
    PushStack(&stack, e, stackNumber);
    printf("get elem: %d\n", GetStack(&stack, stackNumber));
    PopStack(&stack, &e, stackNumber);
    printf("get elem: %d\n", GetStack(&stack, stackNumber));
    
    return 0;
}
