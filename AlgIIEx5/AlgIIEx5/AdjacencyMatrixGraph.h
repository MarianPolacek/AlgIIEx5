#pragma once

class AdjacencyMatrixGraph
{
public:
	AdjacencyMatrixGraph(int countOfvertices);
	~AdjacencyMatrixGraph();
	void addEdge(int from, int to);
	bool hasEdge(int from, int to);
	void printGraph();
private:
	int countOfVertices;
};

