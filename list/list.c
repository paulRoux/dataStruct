/*************************************************************************
	> File Name: list.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月23日 星期六 16时54分50秒
 ************************************************************************/

#include "list.h"

int main(void)
{
    Node *L;
    L = MakeEmpty();
    InsertList(&L, 4);
    InsertList(&L, 5);
    PrintList(L);
    FindList(L, 4);
    FindList(L, 5);
    DeleteList(&L, 5);
    PrintList(L);
    return 0;
}
