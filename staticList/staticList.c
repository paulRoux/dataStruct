/*************************************************************************
	> File Name: staticList.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月19日 星期四 19时55分21秒
 ************************************************************************/

#include "staticList.h"

int InitList(StaticList space)
{
    if(space == NULL){
        return 0;
    }

    int i;
    for(i = 0; i < MAXSIZE-1; i++){
        space[i].cur = i+1;
    }
    space[MAXSIZE-1].cur = 0;

    return 1;
}

int Malloc_SLL(StaticList space)
{
    if(space == NULL){
        return -1;
    }

    int i = space[0].cur;
    
    if(space[0].cur){
        space[0].cur = space[i].cur;
    }

    return i;
}

int InsertList(StaticList L, int i, ElemType e)
{
    if(L == NULL){
        return 0;
    }

    int j, k, l;
    k = MAXSIZE - 1;

    if(i < 1 || i > LengthList(L)+1){
        return 0;
    }

    j = Malloc_SLL(L);

    if(j){
        L[j].data = e;
        for(l = 1; l <= i-1; l++){
            k = L[k].cur;
        }

        L[j].cur = L[k].cur;
        L[k].cur = j;

        return 1;
    }

    return 0;
}

int DelList(StaticList L, int i)
{
    if(L == NULL){
        return 0;
    }

    int j, k;
    if(i < 1 || i > LengthList(L)){
        return 0;
    }

    k = MAXSIZE-1;
    for(j = 1; j <= i-1; j++){
        k = L[k].cur;
    }
    
    j = L[k].cur;
    L[k].cur = L[j].cur;

    Free_SSL(L, j);

    return 1;
}

void Free_SSL(StaticList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

int LengthList(StaticList L)
{
    int j = 0;
    int i = L[MAXSIZE-1].cur;

    while(i){
        i = L[i].cur;
        ++j;
    }

    return j;
}

ElemType GetList(StaticList L, int n)
{
    if(L == NULL){
        return -1;
    }
    if(n < 1 || n > MAXSIZE-1){
        return -1;
    }

    int i = L[MAXSIZE-1].cur;


    while(L[i].cur-1 != n && L[i].cur < L[0].cur+1){
        if(L[i].cur == 0 && i == n){
            return L[i].data;
        }
        i = L[i].cur; 
    }

    if(L[i].cur > L[0].cur){
        printf("not found ");
        return -1;
    }
   
    return L[i].data;
}

int main(void)
{
    StaticList L;

    int n = 0;
    ElemType e;
    printf("please input number and data:");
    scanf("%d%d", &n, &e);

    if(!InitList(L)){
        printf("init error\n");
        return 0;
    }

    if(!InsertList(L, n, e)){
        printf("insert error\n");
        return 0;
    }

    printf("%d\n", GetList(L, n));

    if(!DelList(L, n)){
        printf("delete error\n");
        return 0;
    }

    printf("%d\n", GetList(L, n));

    return 0;
}
