/*************************************************************************
	> File Name: kmp.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月06日 星期一 19时37分03秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1024

void getNext(char *str, int *next)
{
    //计算返回字串str的next数组
    int i, j;
    i = 0;
    j = -1;
    next[0] = -1;
    int len = strlen(str);

    while(i < len-1){  //str[0]表示串的长度
        if(j == -1 || str[i] == str[j]){
            //str[i]表示后缀的单个字符
            //str[j]表示前缀的单个字符
            ++i;
            ++j;
            next[i] = j;
        }else {
            //如果字符不相同，则j值回溯
            j = next[j];
        }
    }
}

int indexKmp(char *s, char *str, int pos)
{
    //返回字串str在主串s中第pos个字符之后的位置，若不存在，返回0
    //str非空，1<=pos<=strlen(s)

    int slen = strlen(s);
    int len = strlen(str);

    if(pos < 0){
        printf("the number is too little!\n");
        return 0;
    }else if(pos > slen){
        printf("the number is too big!\n");
        return 0;
    }

    int i = pos;  //记录主串当前的下标，若pos不为1，则从pos位置开始匹配
    int j = 0;  //记录字串当前的下标

    int next[MAXSIZE];  //定义next数组
    getNext(str, next);  //获取字串的next数组

    while(i < slen && j < len){
        //若i小于主串长度且j小于字串长度，则循环
        if(j == -1 || s[i] == str[j]){
            ++i;
            ++j;
        }else{
            //j回退，重新匹配
            j = next[j];   
        }
    }

    if(j == len){
        return i-len;
    }else{
        return 0;
    }
}

int main(void)
{
    int pos = 0;
    printf("please input a number: ");
    scanf("%d", &pos);

    char *s = "abcabc";
    char *str = "abc";
    int i = indexKmp(s, str, pos);
   
    if(i != 0){
        for(; i < strlen(s); i++){
            printf("%c", s[i]);
        }
    }
    putchar(10);

    return 0;
}
