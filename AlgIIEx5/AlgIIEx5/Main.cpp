#include "pch.h"
#include <iostream>
#include "AdjacencyMatrixGraph.h"
#include "AdjacencyListGraph.h"

int main()
{
	// EX 5.1: Implement graph with AdjacencyMatrix
	AdjacencyMatrixGraph graph1 = AdjacencyMatrixGraph(5);

	// NOTE: Matrices are indexed from 0, but graphs usually start from 1
	graph1.addEdge(1, 2);
	graph1.addEdge(1, 3);
	graph1.addEdge(1, 4);
	graph1.addEdge(1, 5);
	graph1.addEdge(2, 3);
	graph1.addEdge(3, 4);
	graph1.addEdge(4, 5);

	// NOTE: Expects undirected graph (1,5) == (5,1)
	std::cout << "Check edge (5,1): " << graph1.hasEdge(5, 1) << " (should be 1)" << std::endl;

	// NOTE: Expects following matrix output
	// 1 1 1 1 1
	// 1 0 1 0 0
	// 1 1 0 1 0
	// 1 0 1 0 1
	// 1 0 0 1 0
 	graph1.printGraph(); 

	// EX 5.2: Implement graph with AdjacencyList
	AdjacencyListGraph graph2 = AdjacencyListGraph(5);

	graph2.addEdge(1, 2);
	graph2.addEdge(1, 3);
	graph2.addEdge(1, 4);
	graph2.addEdge(1, 5);
	graph2.addEdge(2, 3);
	graph2.addEdge(3, 4);
	graph2.addEdge(4, 5);

	// NOTE: Expects undirected graph (1,5) == (5,1)
	std::cout << "Check edge (5,1): " << graph2.hasEdge(5, 1) << " (should be 1)" << std::endl;

	// NOTE: Expects similar output (depending on implementation, some space might be saved, if we don't store both directions)
	// 1: 2 3 4 5
	// 2: 1 3
	// 3: 1 4
	// 4: 1 3 5
	// 5: 1 4
	graph2.printGraph();
}