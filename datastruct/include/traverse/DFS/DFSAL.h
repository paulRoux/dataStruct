//
// Created by roux on 18-3-6.
// 邻接链表深度优先遍历
//


#ifndef DATASTRUCT_DFSAL_H
#define DATASTRUCT_DFSAL_H

#include "../include.h"

bool visited[MAXVEX];

void DFSAL(GraphAdjList GL, int i)
{
	EdgeNode* p;
	visited[i] = true;
	printf("%c ", GL.adjList[i].data);
	p = GL.adjList[i].firstedge;

	while (p) {
		if (!visited[p->adjvex]) {
			DFSAL(GL, p->adjvex);
		}

		p = p->next;
	}
}

void DFS(GraphAdjList GL)
{
	int i;
	for (i = 0; i < GL.numVertexes; ++i) {
		visited[i] = false;
	}

	for (i = 0; i < GL.numVertexes; ++i) {
		if (!visited[i]) {
			DFSAL(GL, i);
		}
	}
}

#endif //DATASTRUCT_DFSAL_H
