#include <stdio.h>  
#include <stdlib.h>  
  
#include "Stack.h"  
  
//  
// 初始化栈  
int InitStack(Stack *s)  
{  
    s->base = (StackElemType *)malloc(sizeof(StackElemType) * STACK_INIT_SIZE);  
  
    if (!s->base) // 申请栈内存失败  
    {  
        exit(OVERFLOW);  
    }  
  
    s->top = s->base;  
    s->stackSize = STACK_INIT_SIZE;  
  
    return OK;  
}  
  
//  
// 销毁栈  
void DestroyStack(Stack *s)  
{  
    if (s != NULL)  
    {  
        free(s->base);  
  
        s->top = NULL;  
        s->base = NULL;  
  
        s->stackSize = 0;  
    }  
}  
  
//  
// 入栈  
void Push(Stack *s, StackElemType e)  
{  
    StackElemType *tmp;  
    if (s->top - s->base >= s->stackSize) // 栈已经满  
    {  
        tmp = (StackElemType *)realloc(s->base, (STACK_SIZE_INCREMENT + s->stackSize)   
                                                 * sizeof(StackElemType));  
        if (!tmp)  
        {  
            exit(OVERFLOW); // 重新分配失败则退出  
        }  
  
        s->base = tmp;  
        s->top = s->base + s->stackSize;  
        s->stackSize += STACK_SIZE_INCREMENT;  
    }  
  
    *(s->top) = e;  
    s->top++;  
}  
  
//  
// 出栈  
void Pop(Stack *s, StackElemType *e)  
{  
    if (s->top == s->base) // 如果栈为空栈  
    {  
        return;  
    }  
  
    *e = *(--s->top);  
}  
  
//  
// 判断栈是否为空  
// 返回非0表示空  
int IsStackEmpty(Stack s)  
{  
    return !(s.top - s.base);  
}  
  
//  
// 取栈顶元素  
int GetTop(Stack s, StackElemType *e)  
{  
    if (!IsStackEmpty(s))  
    {  
        *e = *(s.top--);   
  
        return OK;  
    }  
    else  
    {  
        return ERROR;  
    }  
}  