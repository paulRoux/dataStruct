#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "Queue.h"
#include "Stack.h"

/*****************************************************************************
* 方法名：CreateBinaryTree
* 描述：  递归创建一棵二叉树,按先序输入二叉树中结点的元素的值，“#”号表示空树
* 参数：  pBTree--指向BTree结构体的指针的指针
* 返回值：返回OK--表示创建成功
*         返回ERROR--表示创建失败
******************************************************************************/
int CreateBinaryTree(BTree **pBTree)
{
	ElemType data;
	
	scanf("%c", &data);

	if (data == '#')
	{
		*pBTree = NULL;

		return OK;
	}
	else 
	{
		if (((*pBTree) = (BTree *)malloc(sizeof(BTree))) == NULL)
		{
			exit(OVERFLOW);
		}

		(*pBTree)->data = data;
		CreateBinaryTree(&(*pBTree)->lchild); // 创建左子树
		CreateBinaryTree(&(*pBTree)->rchild); // 创建右子树
	}

	return OK;
}

/*****************************************************************************
* 方法名：PreOrderTraverse
* 描述：  先序遍历二叉树
* 参数：  pBTree--指向BTree结构体的指针
******************************************************************************/
void PreOrderTraverse(BTree *pBTree)
{
	if (pBTree)
	{
		printf("%c", pBTree->data);       // 先序访问根结点

		PreOrderTraverse(pBTree->lchild); // 先序遍历左子树
		PreOrderTraverse(pBTree->rchild); // 先序遍历右子树
	}
}

/*****************************************************************************
* 方法名：InOrderTraverse
* 描述：  中序遍历二叉树
* 参数：  pBTree--指向BTree结构体的指针
******************************************************************************/
void InOrderTraverse(BTree *pBTree)
{
	if (pBTree)
	{
		InOrderTraverse(pBTree->lchild); // 中序遍历左子树
		printf("%c", pBTree->data);       // 中序访问根结点
		InOrderTraverse(pBTree->rchild); // 中序遍历右子树
	}
}

/*****************************************************************************
* 方法名：PostOrderTraverse
* 描述：  后序遍历二叉树
* 参数：  pBTree--指向BTree结构体的指针
******************************************************************************/
void PostOrderTraverse(BTree *pBTree)
{
	if (pBTree)
	{
		PostOrderTraverse(pBTree->lchild);   // 后序遍历左子树
		PostOrderTraverse(pBTree->rchild);   // 后序遍历右子树
				printf("%c", pBTree->data); // 后序访问根结点
	}
}

/*****************************************************************************
* 方法名：LevelOrderTraverse
* 描述：  层序遍历二叉树
* 参数：  pBTree--指向BTree结构体的指针
******************************************************************************/
void LevelOrderTraverse(BTree *pBTree)
{
	Queue queue;         // 队列变量
	QueueElemType e;     // 队列元素指针变量

	InitializeQueue(&queue); // 初始化队列

	if (pBTree != NULL)
	{
		EnQueue(&queue, *pBTree); // 将根结点指针入队
	}

	while (!IsQueueEmpty(queue))
	{
		DeQueue(&queue, &e);

		printf("%c", e.data);

		if (e.lchild != NULL)   // 若存在左孩子，则左孩子入队
		{
			EnQueue(&queue, *e.lchild);
		}

		if (e.rchild != NULL)   // 若存在右孩子，则右孩子入队
		{
			EnQueue(&queue, *e.rchild);
		}
	}
}

/*****************************************************************************
* 方法名：GetDepth
* 描述：  获取树的深度
* 参数：  pBTree--指向BTree结构体的指针
* 返回值：树的深度
******************************************************************************/
int GetDepth(BTree *pBTree)
{
	int depth = 0;
	int leftDepth = 0;
	int rightDepth = 0;

	if (pBTree)
	{
		leftDepth = GetDepth(pBTree->lchild);  // 获取左子树的深度
		rightDepth = GetDepth(pBTree->rchild); // 获取右子树的深度

		depth = leftDepth > rightDepth ? leftDepth + 1: rightDepth + 1;
	}

	return depth;
}

/*****************************************************************************
* 方法名：IsLeaf
* 描述：  判断该结点是否为叶子结点
* 参数：  node--结点
* 返回值：1--表示叶子结点，0--表示非叶子结点
******************************************************************************/
int IsLeaf(BTree node)
{
	if (node.lchild == NULL && node.rchild == NULL)
	{
		return 1;
	}

	return 0;
}

/*****************************************************************************
* 方法名：TraverseLeafNodes
* 描述：  遍历所有的叶子结点
* 参数：  pBTree--指向BTree结构体的指针
******************************************************************************/
void TraverseLeafNodes(BTree *pBTree)
{
	if (pBTree != NULL)
	{
		if (1 == IsLeaf(*pBTree))
		{
			printf("%c", pBTree->data);
		}
		else
		{
			TraverseLeafNodes(pBTree->lchild);
			TraverseLeafNodes(pBTree->rchild);
		}	
	}
}

//
// 判断一棵二叉树是否为平衡二叉树
// 平衡二叉树的定义: 如果任意节点的左右子树的深度相差不超过1，那这棵树就是平衡二叉树
// 算法思路：递归判断每个节点的左右子树的深度是否相差大于1，如果大于1，说明该二叉树不
//           是平衡二叉树，否则继续递归判断
int IsBalanceBinaryTree(BTree *pBTree)
{
	int leftDepth = 0;
	int rightDepth = 0;
	int distance = 0; 

	if (pBTree != NULL)
	{
		leftDepth = GetDepth(pBTree->lchild);  // 获取左子树的深度
		rightDepth = GetDepth(pBTree->rchild); // 获取右子树的深度
		distance = leftDepth > rightDepth ? leftDepth - rightDepth : rightDepth - leftDepth;

		return distance > 1 ? 0 : IsBalanceBinaryTree(pBTree->lchild) && IsBalanceBinaryTree(pBTree->rchild);
	}
}

//
// 获取叶子结点的个数
int GetLeafCount(BTree *pBTree)
{
	int count = 0;

	if (pBTree != NULL)
	{
		if (IsLeaf(*pBTree))
		{
			count++;
		}
		else
		{
			count = GetLeafCount(pBTree->lchild) + GetLeafCount(pBTree->rchild);
		}
	}

	return count;
}

//
// 获取度为1的结点的个数
int GetCountOfOneDegree(BTree *pBTree)
{
	int count = 0;

	if (pBTree != NULL)
	{
		if ((pBTree->lchild != NULL && pBTree->rchild == NULL) || (pBTree->lchild == NULL && pBTree->rchild != NULL))
		{
			count++;
		}

		count += GetCountOfOneDegree(pBTree->lchild) + GetCountOfOneDegree(pBTree->rchild);
	}

	return count;
}

//
// 获取度为2的结点的个数
int GetCountOfTwoDegree(BTree *pBTree)
{
	int count = 0;

	if (pBTree != NULL)
	{
		if (pBTree->lchild != NULL && pBTree->rchild != NULL)
		{
			count++;
		}

		count += GetCountOfTwoDegree(pBTree->lchild) + GetCountOfTwoDegree(pBTree->rchild);
	}

	return count;
}
//
// 获取二叉树的结点的总数
int GetNodesCount(BTree *pBTree)
{
	int count = 0;

	if (pBTree != NULL)
	{
		count++;

		count += GetNodesCount(pBTree->lchild) + GetNodesCount(pBTree->rchild);
	}

	return count;
}

//
// 交换左右子树
void SwapLeftRightSubtree(BTree **pBTree)
{
	BTree *tmp = NULL;

	if (*pBTree != NULL)
	{
		// 交换当前结点的左右子树
		tmp = (*pBTree)->lchild;
		(*pBTree)->lchild = (*pBTree)->rchild;
		(*pBTree)->rchild = tmp;

		SwapLeftRightSubtree(&(*pBTree)->lchild);
		SwapLeftRightSubtree(&(*pBTree)->rchild);
	}
}

//
// 判断值e是否为二叉树中某个结点的值，返回其所在的层数，返回0表示不在树中
int GetLevelByValue(BTree *pBTree, ElemType e)
{
	int leftDepth = 0;
	int rightDepth = 0;
	int level = 0;

	if (pBTree->data == e)//这里的1是相对于以pBTree为根节点的层数值。
	{
		return 1;
	}

	if (pBTree->lchild != NULL)//leftDepth所代表的层数是相对以pBTree的左节点为根的树的层数
	{
		leftDepth = GetLevelByValue(pBTree->lchild, e);
	}

	if (pBTree->rchild != NULL)
	{
		// rightDepth所代表的层数是相对以pBTree的右节点为根的树的层数
		rightDepth = GetLevelByValue(pBTree->rchild, e);
	}

	//
	// 查找结果要么在左子树找到，要么在右子树中找到，要么找不到
	if (leftDepth > 0 && rightDepth == 0) // 在左子树中找到
	{
		level = leftDepth;
	}
	else if (leftDepth == 0 && rightDepth > 0) // 在右子树中找到
	{
		level = rightDepth;
	}

	if (leftDepth != 0 || rightDepth != 0) // 判断是否找到该结点
	{
		level++;
	}

	return level;
}

//
// 非递归中序遍历
void NoneRecursionInOrder(BTree tree)
{
	Stack s;
	StackElemType *p = NULL, *q;

	q = (StackElemType *)malloc(sizeof(StackElemType)); // 用于指向退栈元素的地址
	InitStack(&s);
	p = &tree;

	while (p || !IsStackEmpty(s))
	{
		if (p)
		{
			Push(&s, *p); 
			p = p->lchild;
		}
		else
		{
			Pop(&s, q);
			printf("%c", q->data);
			p = q->rchild;
		}
	}

	free(q);
}

//
// 非递归前序遍历
void NoneRecursionPreOrder(BTree tree)
{
	Stack s;
	StackElemType *p = NULL, *q;

	q = (StackElemType *)malloc(sizeof(StackElemType)); // 用于指向退栈元素的地址
	InitStack(&s);
	p = &tree;

	while (p || !IsStackEmpty(s))
	{
		while (p)
		{
			printf("%c", p->data); // 访问根结点
			Push(&s, *p);           // 根结点指针入栈
			p = p->lchild;          // 一直向左走到底
		}

		Pop(&s, q);
		p = q->rchild;   // 向右走一步
	}

	free(q);
}

//
// 非递归后序遍历
void NoneRecursionPostOrder(BTree tree)
{
	StackElemType *stack[STACK_INIT_SIZE], *p;
	int tag[STACK_INIT_SIZE], // 值只有0和1，其中0表示该结点的左子树已经访问
		                      // 值为1表示该结点的右子树已经访问
		top = 0; // 栈顶指示器

	p = &tree;

	while (p || top != 0)// 树未遍历完毕或者栈不空
	{
		while (p)
		{
			top++;
			stack[top] = p; 
			tag[top] = 0;
			p = p->lchild; // 从根开始向左走到底
		}

		if (top > 0) // 栈不空
		{
			if (tag[top] == 1)// 表示已经访问该结点的右子树，并返回 
			{
				p = stack[top--]; // 退栈
				printf("%c", p->data);

				p = NULL; // 下次进入循环时，就不会再遍历左子树
			}
			else // 表示刚从该结点的左子树返回，现在开始遍历右子树
			{
				p = stack[top]; // 取栈顶元素
				if (top > 0) // 栈不空
				{
					p = p->rchild;
					tag[top] = 1; // 标识该结点的右子树已经访问
				}
			}
		}
	}
}

int main()
{
	BTree *tree = NULL;

	printf("按先序输入二叉树结点元素的值，输入#表示空树：\n");

	freopen("test.txt", "r", stdin);

	if (CreateBinaryTree(&tree) == OK)  // 创建二叉树
	{
		printf("二叉树创建成功！\n\n");
	}

	printf("先序遍历(#表示空子树)：\n");
	PreOrderTraverse(tree);

	printf("\n中序遍历(#表示空子树)：\n");
	InOrderTraverse(tree);

	printf("\n后序遍历(#表示空子树)：\n");
	PostOrderTraverse(tree);

	printf("\n树的深度为：%d\n", GetDepth(tree));

	printf("\n层序遍历：\n");
	LevelOrderTraverse(tree);

	printf("\n遍历叶子结点:\n");
	TraverseLeafNodes(tree);

	printf("\n叶子结点的个数：%d\n", GetLeafCount(tree));
	printf("度为1的结点的个数：%d\n", GetCountOfOneDegree(tree));
	printf("度为2的结点的个数：%d\n", GetCountOfTwoDegree(tree));
	printf("\n二叉树的结点总数为：%d\n", GetNodesCount(tree));

	printf("\n该二叉树是否为平衡二叉树？\n");
	if (IsBalanceBinaryTree(tree))
	{
		printf("Yes!\n");
	}
	else
	{
		printf("No!\n");
	}


	printf("\n结点值为A的结点在第%d层\n", GetLevelByValue(tree, 'A'));
	printf("\n结点值为B的结点在第%d层\n", GetLevelByValue(tree, 'B'));
	printf("\n结点值为C的结点在第%d层\n", GetLevelByValue(tree, 'C'));
	printf("\n结点值为D的结点在第%d层\n", GetLevelByValue(tree, 'D'));
	printf("\n结点值为E的结点在第%d层\n", GetLevelByValue(tree, 'E'));
	printf("\n结点值为F的结点在第%d层\n", GetLevelByValue(tree, 'F'));
	printf("\n结点值为G的结点在第%d层\n", GetLevelByValue(tree, 'G'));
	printf("\n结点值为M的结点在第%d层\n", GetLevelByValue(tree, 'M'));

	printf("\n非递归中序遍历：\n");
	NoneRecursionInOrder(*tree);

	printf("\n非递归前序遍历：\n");
	NoneRecursionPreOrder(*tree);

	printf("\n非递归后序遍历：\n");
	NoneRecursionPostOrder(*tree);

	printf("\n\n=======================================================\n\n");

	printf("下面执行交换左右子树操作：\n\n");
	SwapLeftRightSubtree(&tree);

	printf("先序遍历(#表示空子树)：\n");
	PreOrderTraverse(tree);

	printf("\n中序遍历(#表示空子树)：\n");
	InOrderTraverse(tree);

	printf("\n后序遍历(#表示空子树)：\n");
	PostOrderTraverse(tree);

	printf("\n树的深度为：%d\n", GetDepth(tree));

	printf("\n层序遍历：\n");
	LevelOrderTraverse(tree);

	printf("\n遍历叶子结点:\n");
	TraverseLeafNodes(tree);

	

	fclose(stdin);

	printf("\n");

	return 0;
}