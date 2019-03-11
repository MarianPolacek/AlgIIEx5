#pragma once

class AdjacencyListGraph
{
public:
	AdjacencyListGraph(int countOfVertices);
	~AdjacencyListGraph();
	void addEdge(int from, int to);
	bool hasEdge(int from, int to);
	void printGraph();
};

