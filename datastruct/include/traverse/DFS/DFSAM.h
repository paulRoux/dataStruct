//
// Created by roux on 18-3-6.
// 邻接矩阵深度优先遍历
//

#ifndef DATASTRUCT_DFSAM_H
#define DATASTRUCT_DFSAM_H

#include "../include.h"

bool visited[MAXVEX];	/*访问标志*/

void DFSAM(MGraph G, int i)
{
	int j;
	visited[i] = true;
	printf("%c ", G.vexs[i]);

	for (j = 0; j < G.numVertexes; ++j) {
		if (G.arc[i][j] == 1 && !visited[j]) {
			DFSAM(G, j);
		}
	}
}

void DFS(MGraph G)
{
	int i;
	for (i = 0; i < G.numVertexes; ++i) {
		visited[i] = false;
	}

	for (i = 0; i < G.numVertexes; ++i) {
		if (!visited[i]) {
			DFSAM(G, i);
		}
	}
}

#endif //DATASTRUCT_DFSAM_H
