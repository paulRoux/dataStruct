/*************************************************************************
	> File Name: linkList.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月18日 星期三 19时14分21秒
 ************************************************************************/

#include "cirList.h"

int CreateList(LinkList *L, int n)
{
    if(L == NULL || &L == NULL){
        return 0;
    }
    if(n > 0xFFFFFFF){
        printf("please input a right number!\n");
        return 0;
    }

    int i = 0;
    LinkList p;
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    (*L)->rear = NULL;

    for(i = 0; i < n; i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = 0;
        p->next = *L;
        p->rear = p;
        (*L)->next = p;
    }

    return 1;
}

int GetLength(LinkList L)
{
    if(L == NULL){
        return 0;
    }
    int k = 1;
    LinkList p = L->next;
    while(p->next != L){
        p = p->next;
        k++;
    }
    return k; 
}

int GetList(LinkList L, int i, ElemType *e)
{
    if(L == NULL){
        return 0;
    }
    int k = 0;
    if((k = GetLength(L)) == 0){
        return 0;
    }
    if(i > k){
        printf("please input a right location!\n");
        return 0;
    }

    int j = 0;
    LinkList tmp = L;

    while(tmp->next != L && j < i){
        tmp = tmp->next;
        ++j;
    }
    if(tmp->next == L || j > i){
        printf("not found the data!\n");
        return 0;
    }
    *e = tmp->data;

    return 1;
}

int InsertList(LinkList *L, int i, ElemType e)
{
    if(L == NULL || *L ==NULL){
        return 0;
    }
    int k = 0;
    if((k = GetLength(*L)) == 0){
        return 0;
    }
    if(i > k){
        printf("please input a right location to insert!\n");
        return 0;
    }

    LinkList p, q;
    p = *L;
    int j = 1;
    while(p->next != *L && j < i){
        p = p->next;
        ++j;
    }

    if(p->next == *L || j > i){
        return 0;
    }

    q = (LinkList)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;

    return 1;
}

int DelList(LinkList *L, int i, ElemType *e)
{
    if(L == NULL || *L ==NULL){
        return 0;
    }
    int k = 0;
    if((k = GetLength(*L)) == 0){
        return 0;
    }
    if(i > k){
        printf("please input a right location to delete!\n");
        return 0;
    } 

    int j = 1;
    LinkList p, q;
    p = *L;
    while(p->next != *L && j < i){
        p = p->next;
        ++j;
    }
    if(p->next == *L && j > i){
        return 0;
    }

    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);

    return 1; 
}

int ClearList(LinkList *L)
{
    if(L == NULL || *L == NULL){
        return 0;
    }

    LinkList p, q;
    p = (*L)->next;
    while(p->next != *L){
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    (*L)->rear = NULL;

    return 1;
}

int main(void)
{
    Node *list;
    int i = 0, n = 0;
    ElemType e = 0;
    ElemType res = 0;
    printf("please input number and length and data:");
    scanf("%d%d%d", &i, &n, &e);
    CreateList(&list, n);
    InsertList(&list, i, e);
    DelList(&list, i, &res);
    
    printf("the result is: %d %d %d %d\n", i, n, e, res);

    return 0;
}
