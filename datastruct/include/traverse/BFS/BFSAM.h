//
// Created by roux on 18-3-6.
// 邻接矩阵广度优先遍历
//

#ifndef DATASTRUCT_BFSAM_H
#define DATASTRUCT_BFSAM_H

#include "../include.h"
#include <queue>

bool visited[MAXVEX];

void BFSAM(MGraph G)
{
	int i, j;
	std::queue<VertexType> Q;
	for (i = 0; i < G.numVertexes; ++i) {
		visited[i] = false;
	}

	for (i = 0; i < G.numVertexes; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			printf("%c ", G.vexs[i]);

			Q.push(G.vexs[i]);

			while (!Q.empty()) {
				Q.pop();

				for (j = 0; j < G.numVertexes; ++j) {
					if (G.arc[i][j] == 1 && !visited[j]) {
						visited[j] = true;
						printf("%c ", G.vexs[j]);
						Q.push(G.vexs[j]);
					}
				}
			}
		}
	}
}


#endif //DATASTRUCT_BFSAM_H
