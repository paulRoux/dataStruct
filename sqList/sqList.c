/*************************************************************************
	> File Name: sqList.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月17日 星期二 16时12分53秒
 ************************************************************************/

#include "sqList.h"

void initSqlist(sqList *sql)
{
    for(int i = 0; i < MAX; i++){
        sql->data[i] = 0;
    }
    sql->length = 0;
}

int getElem(sqList *sql, int i)
{
    if(sql->length == 0 || i < 1 || i > sql->length+1){
        return -1;
    }
    return sql->data[i-1];  
}

int insertElem(sqList *sql, int i, ElemType e)
{
    if(i > sql->length+1 || i < 1){
        printf("insert location error!\n");
        return -1;
    }
    if(sql->length == MAX){
        printf("sqlist is full!\n");
        return -1;
    }

    if(i <= sql->length+1){
        for(int k = sql->length; k >= i-1; k--){
            sql->data[k+1] = sql->data[k];
        }
    }

    sql->data[i-1] = e;
    sql->length++;
    
    return 1;
}

ElemType delElem(sqList *sql, int i)
{
    ElemType m = 0;

    if(sql->length == 0){
        printf("sqlist is empty!\n");
        return -1;
    }
    if(i > sql->length+1 || i < 1){
        printf("the location is error!\n");
        return -1;
    }

    m = sql->data[i-1];

    for(int k = i; k < sql->length; k++){
        sql->data[k-1] = sql->data[k];
    }

    sql->length--;

    return m;
}

int main(void)
{
    sqList *s;
    initSqlist(s);

    int i = 0;
    ElemType e = 0;
    printf("please input data and location:");
    scanf("%d%d", &e, &i);
    if(i > 20){
        printf("input location error!\n");
        return 0;
    }

    int flag = insertElem(s, i, e);
    if(flag == 1){
        printf("insert success!\n");
    }else{
        printf("insert error");
    }

    printf("getElem: %d\n", getElem(s, i));

    printf("delElem: %d\n", delElem(s, i));

    printf("getElem: %d\n", getElem(s, i));

    return 0;
}
