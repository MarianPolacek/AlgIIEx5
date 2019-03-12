#pragma once

// HINTS ON POSSIBLE IMPLEMENTATION:
//	- graph could use dynamic array of AdjacencyList objects, that will store 
// information about vertex and its adjancements
//	- constructor of graph would initialize array of lists, each vertex would have 1 entry
//	- addEdge in graph has to find correct edges and add adjancements
//		- NOTE: We want undirected graph 
//			-> both directions should be created (so addEdge(1,2) should create both (1,2) and (2,1))
//		- NOTE: It might be good idea to also check if edge is not already defined
//		- NOTE: addAdjanced in AdjacencyList will have to create new dynamic array and copy already present items
//	- hasEdge . printGraph on graph can just iterate through array of AdjacencyList objects and call correct method
//	- destructors should dispose any created objects

class AdjacencyList
{
public:
	AdjacencyList(int vertexId);
	~AdjacencyList();
	int getVertexId() const;
	void addAdjanced(int vertex);
	bool hasAdjanced(int vertex);
	void printList();

private:
	int vertexId;
	int *adjancedVertices;
};

class AdjacencyListGraph
{
public:
	AdjacencyListGraph(int countOfVertices);
	~AdjacencyListGraph();
	void addEdge(int from, int to);
	bool hasEdge(int from, int to);
	void printGraph();
private:
	AdjacencyList* adjacencyList;
};