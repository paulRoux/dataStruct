#include <stdio.h>
#include <string.h>

int Board[50][50];
int title = 1;

/*************************
* 参数的含义：
* tr--当前棋盘左上角的棋号
* tc--当前棋盘左上角的列号
* dr--当前特殊方格所在的行号
* dc--当前特殊方格所在的列号
* size--当前棋盘的大小：2^k
************************/

void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
    if(1 == size)    //棋盘大小为1则停止递归
        return ;
    int mid = size/2,   //棋盘中间的行和列号
        t = title++;   //每种填充的方块每次递增1

    //检查特殊的方块是否在左上角的子棋盘中
    if(dr < tr + mid && dc < tc + mid)
        ChessBoard(tr, tc, dr, dc, mid);
    else
    {
         Board[tr + mid - 1][tc + mid -1] = t;
         ChessBoard(tr, tc, tr + mid - 1, tc + mid - 1, mid);
    }

    //检查特殊方块是否在右上角的子棋盘中
    if(dr < tr + mid && dc >= tc + mid)
        ChessBoard(tr, tc + mid, dr, dc, mid);
    else
    {
         Board[tr + mid - 1][tc + mid] = t;
         ChessBoard(tr, tc + mid, tr + mid - 1, tc + mid, mid);
    }

    //检查特殊方块是否在左下角的子棋盘中
    if(dr >= tr + mid && dc < tc + mid)
        ChessBoard(tr + mid, tc, dr, dc, mid);
    else
    {
         Board[tr + mid][tc + mid - 1] = t;
         ChessBoard(tr + mid, tc, tr + mid, tc + mid - 1, mid);
    }

    //检查特殊方块是否在右下角的子棋盘中
    if(dr >= tr + mid && dc >= tc + mid)
        ChessBoard(tr + mid, tc + mid, dr, dc, mid);
    else
    {
         Board[tr + mid][tc + mid] = t;
         ChessBoard(tr + mid, tc + mid, tr + mid, tc + mid, mid);
    }
}

int main()
{
    int dr = 0,
        dc = 0,
        size = 0,
        i = 0,
        j = 0;

    printf("请输入棋盘的大小：");
    scanf("%d", &size);
    printf("请输入特殊方块的位置：");
    scanf("%d %d", &dr, &dc);

    ChessBoard(0, 0, dr, dc, size);
    for(i = 0; i < size; ++i)
    {
        for(j = 0; j < size; ++j)
            printf("%d ", Board[i][j]);
        putchar(10);
    }
    return 0;
}
