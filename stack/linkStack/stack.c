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

void InitStack(Stack *S)
{
    if(S == NULL){
        exit(1);
    }

    memset(S->data, 0, sizeof(S->data));
    S->top = -1;
}

int EmptyStack(Stack S)
{
    if(S.top == -1){
        return 0;
    }else{
        return 1;
    }
}

ElemType GetStack(Stack *S)
{
    if(S == NULL){
        exit(1);
    }else if(S->top == -1){
        printf("the stack is empty!\n");
        exit(1);
    }


    return S->data[S->top];
}

void DestroyStack(Stack *S)
{
    if(S == NULL || S->top == -1){
        exit(1);
    }
    
    S->top = -1; 
}

int PushStack(Stack *S, ElemType e)
{
    if(S == NULL || S->top == MAXSIZE-1){
        return -1;
    }

    S->top++;
    S->data[S->top] = e;

    return 1;
}

int PopStack(Stack *S, ElemType *e)
{
    if(S == NULL || S->top == -1){
        return -1;
    }

    *e = S->data[S->top];
    S->top--;

    return 1;
}

int main(void)
{
    Stack stack;
    ElemType e;

    printf("please input the elem: ");
    scanf("%d", &e);
    
    InitStack(&stack);
    printf("get elem: %d\n", GetStack(&stack));
    PushStack(&stack, e);
    printf("get elem: %d\n", GetStack(&stack));
    PopStack(&stack, &e);
    printf("get elem: %d\n", GetStack(&stack));
    
    return 0;
}
