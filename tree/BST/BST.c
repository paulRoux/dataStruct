#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

/*****************************************************************************
* 方法名：CreateBinarySearchTree
* 描述：  递归创建一棵二叉树,按先序输入二叉树中结点的元素的值
* 参数：  pBSTree--指向BSTree结构体的指针的指针
* 返回值：返回OK--表示创建成功
*         返回ERROR--表示创建失败
******************************************************************************/
int InsertBinarySearchTree(BSTree **pBSTree, ElemType e)
{
	BSTree *tmp = (BSTree*)malloc(sizeof(BSTree));
	tmp->data = e;
	tmp->lchild = NULL;
	tmp->rchild = NULL;
	
	if(*pBSTree == NULL)
	{
		*pBSTree = tmp;
		return OK;
	}
	else
	{
		BSTree *current = *pBSTree;
        BSTree *parent = NULL;
		
		while(1)
		{
			parent = current;
			if(current->data > e)
			{
				current = current->lchild;
				if(current == NULL)
				{
					parent->lchild = tmp;
					return OK;
				}
			}
			else
			{
				current = current->rchild;
				if(current == NULL)
				{
					parent->rchild = tmp;
					return OK;
				}
			}
		}
	}

	free(tmp);
	return ERROR;
}

/*****************************************************************************
* 方法名：SearchBinarySearchTree
* 描述：  查找二叉树
* 参数：  pBSTree--指向BSTree结构体的指针
******************************************************************************/
BSTree *SearchBinarySearchTree(BSTree *pBSTree, ElemType e)
{
	if(pBSTree == NULL)
	{
		return NULL;
	}
	
	BSTree *current = pBSTree;
	
	while(current != NULL && current->data != e)
    {
        printf("visiting element: %d\n", current->data);
        if(current->data > e)
        {
            current = current->lchild;   
        }
        else if(current->data < e)
        {
            current = current->rchild;
        }
		
    }
	if(current->data != e)
	{
		return NULL;
	}
	else
	{
		return current;
	}
}

/*****************************************************************************
* 方法名：DeleteBinarySearchTree
* 描述：  删除二叉树结点
* 参数：  pBSTree--指向BSTree结构体的指针
******************************************************************************/
int DeleteBinarySearchTree(BSTree *pBSTree, ElemType e)
{
	if(pBSTree == NULL)
	{
		return ERROR;
	}
	
	BSTree *current = pBSTree;
	BSTree *parent = NULL;
	BSTree *tmp;
	
	while(current != NULL && current->data != e)
	{
		printf("visiting element: %d\n", current->data);
        if(current->data > e)
        {
			parent = current;
            current = current->lchild;   
        }
        else if(current->data < e)
        {
			parent = current;
            current = current->rchild;
        }
		else
		{
			//找到了
			if(current->lchild == NULL && current->rchild == NULL)
			{
				//叶子结点
				if(parent == NULL)
				{
					//根结点
					free(parent);
					parent = NULL;
				}
				else
				{
					//非根结点
					(parent->lchild == current)?(parent->lchild=NULL):(parent->rchild=NULL);
					free(current);
					current = NULL;
				}
			}
			else if(current->lchild != NULL && current->rchild == NULL)
			{
				//只有左孩子
				if(parent == NULL)
				{
					tmp = current;
					current = current->lchild;
					free(tmp);
				}
				else
				{
					(parent->lchild == current)?(parent->lchild = current->lchild):(parent->rchild = current->rchild);
					free(current);
				}
			}
			else if(current->lchild == NULL && current->rchild != NULL)
			{
				//只有右孩子
				if(parent == NULL)
				{
					tmp = current;
					current = current->rchild;
					free(tmp);
				}
				else
				{
					(parent->lchild == current)?(parent->lchild = current->rchild):(parent->rchild = current->lchild);
					free(current);
				}
			}
			else
			{
				//左右孩子都有
				BSTree *lchildTmp = current;
				
				while(lchildTmp->rchild != NULL)
				{
					parent = lchildTmp;
					lchildTmp = lchildTmp->rchild;
				}
				
				//交换
				int swapValue = lchildTmp->data;
				lchildTmp->data = current->data;
				current->data = swapValue;
				
				(parent->lchild == current)?(parent->lchild=NULL):(parent->rchild=NULL);
				
				free(current);
			}
		}
	}
	
	return ERROR;
}

/*****************************************************************************
* 方法名：PreOrderTraverse
* 描述：  先序遍历二叉树
* 参数：  pBSTree--指向BSTree结构体的指针
******************************************************************************/
void PreOrderTraverse(BSTree *pBSTree)
{
	if (pBSTree)
	{
		printf("%d\t", pBSTree->data);       // 先序访问根结点
		PreOrderTraverse(pBSTree->lchild); // 先序遍历左子树
		PreOrderTraverse(pBSTree->rchild); // 先序遍历右子树
	}
}

/*****************************************************************************
* 方法名：InOrderTraverse
* 描述：  中序遍历二叉树
* 参数：  pBSTree--指向BSTree结构体的指针
******************************************************************************/
void InOrderTraverse(BSTree *pBSTree)
{
	if (pBSTree)
	{
		InOrderTraverse(pBSTree->lchild); // 中序遍历左子树
		printf("%d\t", pBSTree->data);       // 中序访问根结点
		InOrderTraverse(pBSTree->rchild); // 中序遍历右子树
	}
}

/*****************************************************************************
* 方法名：PostOrderTraverse
* 描述：  后序遍历二叉树
* 参数：  pBSTree--指向BSTree结构体的指针
******************************************************************************/
void PostOrderTraverse(BSTree *pBSTree)
{
	if (pBSTree)
	{
		PostOrderTraverse(pBSTree->lchild);   // 后序遍历左子树
		PostOrderTraverse(pBSTree->rchild);   // 后序遍历右子树
		printf("%d\t", pBSTree->data); 		  // 后序访问根结点
	}
}


int main()
{
	BSTree *tree = NULL;
	int array[7] = {27, 14, 35, 10, 19, 31, 42};

	printf("按先序输入二叉树结点元素的值：\n");

	int i = 0;
	for (i = 0; i < 7; i++)
	{
		if (InsertBinarySearchTree(&tree, array[i]) == OK)  // 创建并插入二叉树
		{
			continue;
		}
		else
		{
			printf("二叉树创建失败！\n");
			return 0;
		}
	}

	printf("先序遍历：\n");
	PreOrderTraverse(tree);

	printf("\n中序遍历：\n");
	InOrderTraverse(tree);

	printf("\n后序遍历：\n");
	PostOrderTraverse(tree);

	printf("\n层序遍历：\n");
	LevelOrderTraverse(tree);
	
	int n = 31;
    BSTree *temp = SearchBinarySearchTree(tree, n);
    if(temp == NULL)
    {
        printf("element %d not found!\n", n);
    }
    else
    {
        printf("element %d found!\n", temp->data);
    }

	return 0;
}