//
// Created by roux on 18-3-6.
// 邻接链表的广度优先搜索
//

#ifndef DATASTRUCT_BFSAL_H
#define DATASTRUCT_BFSAL_H

#include "../include.h"
#include <queue>

bool visited[MAXVEX];

void BFSAL(GraphAdjList GL)
{
	int i;
	EdgeNode* p;
	std::queue<VertexType> Q;

	for (i = 0; i <GL.numVertexes ; ++i) {
		visited[i] = false;
	}

	for (i = 0; i < GL.numVertexes; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			printf("%c ", GL.adjList[i].data);

			Q.push(GL.adjList[i].data);

			while (!Q.empty()) {
				Q.pop();
				p = GL.adjList[i].firstedge;

				while (p) {
					if (!visited[p->adjvex]) {
						visited[p->adjvex] = true;
						printf("%c ", GL.adjList[p->adjvex].data);
						Q.push(GL.adjList[p->adjvex].data);
					}

					p = p->next;
				}
			}
		}
	}
}


#endif //DATASTRUCT_BFSAL_H
