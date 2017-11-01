#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkStack.h"

void InitStack(LinkStack *S){
    if(S == NULL){
        exit(1);
    }
    S = (LinkStack*)malloc(sizeof(LinkStack));
    S->count = 0;
    S->top = NULL;
}

int EmptyStack(LinkStack S)
{
    if(S.top == NULL && S.count == 0){
        return 0;
    }else{
        return 1;
    }
}

ElemType GetStack(LinkStack *S)
{
    if(S == NULL){
        exit(1);
    }else if(S->count == 0){
        printf("the stack is empty!\n");
        return -1;
    }


    return S->top->data;
}

void DestroyStack(LinkStack *S)
{
    if(S == NULL || S->count == 0){
        exit(1);
    }
    
    free(S);
}

int PushStack(LinkStack *S, ElemType e)
{
    if(S == NULL){
        return -1;
    }

    LinkStackPtr q = (LinkStackPtr)malloc(sizeof(StackNode));
    q->data = e;
    q->next = S->top;
    S->top = q;
    S->count++;

    return 1;
}

int PopStack(LinkStack *S, ElemType *e)
{
    if(S == NULL || S->count == 0){
        return -1;
    }

    LinkStackPtr q;
    q = S->top;
    *e = q->data;
    S->top = q->next;
    free(q);
    S->count--;

    return 1;
}

int main(void)
{
    LinkStack stack;
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
