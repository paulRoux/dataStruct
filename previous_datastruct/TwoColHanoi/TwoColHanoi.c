#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*已知n（n是偶数）个盘子，例子中是6个，大小相同的盘子有两个，叠放在一起，但下面的盘子是红色，上面的盘子是蓝色。
要求：
    1）每次只能移动一个盘子
    2）大盘子不能放在小盘子上面
    3）在移动的过程中不能出现两个大小相同的盘子叠在一起，且下面的盘子是蓝色而上面的盘子是红色的情况。
    问题：把n个盘子从A盘移动到C盘的时间复杂度是多少？编程实现盘子的移动操作。
*/
int i = 0;
int move(int n,char A,char C)
{
    printf ("第%d步：把第%d号从%c---->%c\n",++i,n,A,C);
    return 0;
}
int hano(int n ,char A,char B,char C)
{
    if(n==1){
        move(1,A,B);
        move(2,A,C);
        move(1,B,C);
    }
    else{
        hano( n-1,A,B,C );//1
        move( 2*(n-1)+1,A,B );
        hano( n-1,C,A,B );//2
        move( 2*n,A,C );
        hano( n-1,B,C,A );//3
        move( 2*(n-1)+1,B,C );
        hano( n-1,A,B,C );//4
    }

    return 0;
}

int main()
{
    int n;//n代表层数，n为1则塔数为2
    printf("aaaaaaa请输入n:");
    scanf("%d",&n);
    char start = 'A',help = 'B',end = 'C';
    hano(n,start,help,end);
    return 0;
}