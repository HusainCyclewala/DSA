// GRAPH SHOULD BE DAG. DIRECTED ACYCLIC GRAPH.
// Implement Topological Sort
#include <stdio.h>
#include <conio.h>
#define NODES 8
int visited[NODES] = {0};
int visitedCount = 0;
char nodes[NODES] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int adj[NODES][NODES] = {
	//   A  B  C  D  E  F  G  H
	{0, 1, 1, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 1, 0}};
int decOrder[NODES] = {0};
int incoming[NODES] = {0};

void calcIncoming()
{
	int i, j;
	for (i = 0; i < NODES; i++)
		for (j = 0; j < NODES; j++)
			if (adj[i][j] == 1)
				incoming[j]++;
}

void sort(int node)
{
	int i;
	printf("%c ", nodes[node]);
	visited[node] = 1;
	visitedCount++;
	for (i = 0; i < NODES; i++)
		if (adj[node][i] == 1)
			incoming[i]--;
}

void topologicalSort()
{
	int i, j, k;
	for (i = 0; i < NODES; i++)
		if (incoming[i] == 0 && visited[i] == 0)
			sort(i);

	if (visitedCount < NODES)
		topologicalSort();
}

int main()
{
	int i, j;
	calcIncoming();
	topologicalSort();
	return 0;
}