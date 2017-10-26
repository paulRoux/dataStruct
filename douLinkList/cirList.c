/*************************************************************************
	> File Name: linkList.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月18日 星期三 19时14分21秒
 ************************************************************************/

#include "cirList.h"

int CreateList(LinkList *L)
{
    if(L == NULL || &L == NULL){
        return 0;
    }

    *L = (LinkList)malloc(sizeof(Node));
    (*L)->prior = NULL;
    (*L)->next = NULL;

    return 1;
}


int GetList(LinkList L, int i, ElemType *e)
{
    if(L == NULL){
        return 0;
    }

    LinkList tmp = L;

    int k = 1;
    while(tmp->next != NULL && k < i){
        k++;
        tmp = tmp->next;
    }

    if(tmp->next == NULL){
        if(k < i){
            printf("please input right number!\n");
        }else{
            printf("can not found data!\n");
        }
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

    LinkList p, q;
    p = *L;
    int j = 1;
    while(p->next != NULL && j < i){
        p = p->next;
        ++j;
    }

    if(p->next == NULL){
        if(j < i){
            printf("please input right number!\n");
            return 0;
        }else if(j == i){
            q = (LinkList)malloc(sizeof(Node));
            q->data = e;
            q->next = p->next;
            p->next = q;
            q->prior = p;
            return 1;
        }
    }

    q = (LinkList)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    q->prior = q->next->prior;
    q->next->prior = q;

    return 1;
}

int DelList(LinkList *L, int i, ElemType *e)
{
    if(L == NULL || *L ==NULL){
        return 0;
    }

    int j = 1;
    LinkList p, q;
    p = *L;
    while(p->next != NULL && j < i){
        p = p->next;
        ++j;
    }
    if(p->next == NULL){
        printf("please input right number!\n");
        return 0;
    }

    q = p->next;
    p->next = q->next;
    if(q->next != NULL){
        q->next->prior = q->prior;
    }
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
    while(p != NULL){
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;

    return 1;
}

int main(void)
{
    Node *list;
    int i = 0, n = 0;
    ElemType e = 0;
    ElemType res = 0;
    printf("please input number and data:");
    scanf("%d%d", &i, &e);
    CreateList(&list);
    InsertList(&list, i, e);
    DelList(&list, i, &res);
    
    printf("the result is: %d %d %d\n", i, e, res);

    return 0;
}
