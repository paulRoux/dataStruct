/*************************************************************************
    > File Name: list.h
    > Author:
    > Mail:
    > Created Time: 2017年09月23日 星期六 14时40分57秒
 ************************************************************************/

#ifndef _LIST_H
#define _LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemenType;

typedef struct node
{
    ElemenType data;
    struct node *next;
}Node;

typedef Node *List;

/*
void LsitInit(List *list)
{
    (*list)->data = 0;
    (*list)->next = NULL;
}
*/

/*
MakeEmpty(List *list)
{
    llist -> data = 0;
    llist -> next = NULL;
}
*/

List MakeEmpty()
{
    List llist = (List)malloc(sizeof(Node));
    llist -> data = 0;
    llist -> next = NULL;
    return llist;
}

void PrintList(List list)
{
    assert(list != NULL);
    List tmp;
    do{
        tmp = list;
        printf("%d\n", tmp->data);
        list = tmp->next;
    }while(tmp->next != NULL);
}

List InsertList(List *list, ElemenType e)
{
    List L = (List)malloc(sizeof(Node));
    L->data = e;
    L->next = NULL;

    List tmp = *list;

    while((*list)->next != NULL){
        *list = (*list)->next;
    }

    (*list)->next = L;

    return tmp;
}

List Insert(List *list, ElemenType e)
{
    List L = (List)malloc(sizeof(Node));
    L->data = e;

    L->next = *list;

    return L;
}

void FindList(List list, ElemenType e)
{
    int count = 1;

    if(list->data != e){
        while(list->next != NULL){
            list = list->next;
            if(list->data != e){
                count++;
            }
            else{
                break;
            }
            if(list->next == NULL && list->data != e){
                printf("not found\n");
            }
        }
        printf("the data is located in %d\n", count+1);
    }
    else{
        printf("the data is located in %d\n", count);
    }

}

int EmptyList(List list)
{
    if(list->data == 0 && list->next == NULL)
    {
        printf("the list is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}

ElemenType DeleteList(List *list, ElemenType e)
{
    List *L = (List*)malloc(sizeof(Node));
    if(!EmptyList(*list)){
        if((*list)->data != e){
            while((*list)->next != NULL){
                *L = *list;
                (*list) = (*list)->next;
                if((*list)->data == e){
                    break;
                }
            }
            if((*list)->data == e){
                ElemenType t = (*list)->data;
                List tmp = (*list)->next;
                (*L)->next = tmp;
                *list = *L;
                free(tmp);
                printf("the data: %d was deleted\n", t);
                return t;
            }
        }
        else{
            ElemenType t = (*list)->data;
            List tmp = (*list)->next;
            (*L)->next = tmp;
            *list = *L;
            free(tmp);
            printf("the data: %d was deleted\n", t);
            return t;
        }
    }
}

void DeleteFullList(List *list)
{
    List *tmp;
    List L;
    while((*list)->next != NULL){
        *tmp = *list;
        L = (*list)->next;
        free(tmp);
        *list = L;
    }
}

#endif
