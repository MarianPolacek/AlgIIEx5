#include "pch.h"
#include <iostream>
#include "AdjacencyMatrixGraph.h"

AdjacencyMatrixGraph::AdjacencyMatrixGraph(int countOfvertices)
{
	this->matrix = new int*[countOfvertices];
	this->countOfVertices = countOfvertices;

	for (int i = 0; i < countOfvertices; i++) {
		this->matrix[i] = new int[countOfvertices];
		for (int j = 0; j < countOfvertices; j++) {
			this->matrix[i][j] = 0;
		}
	}
}

AdjacencyMatrixGraph::~AdjacencyMatrixGraph()
{
	for (int i = 0; i < this->countOfVertices; i++) {
		delete[] this->matrix[i];
	}

	delete this->matrix;
}

void AdjacencyMatrixGraph::addEdge(int from, int to)
{
	// C++ indexes from 0, but graphs usually start from 1
	if (from == to) {
		this->matrix[from - 1][to - 1] = 2;
	}
	else {
		this->matrix[from - 1][to - 1] = 1;
		this->matrix[to - 1][from - 1] = 1;
	}
}

bool AdjacencyMatrixGraph::hasEdge(int from, int to)
{
	return this->matrix[from - 1][to - 1] != 0;
}

void AdjacencyMatrixGraph::printGraph()
{
	for (int i = 0; i < this->countOfVertices; i++) {
		for (int j = 0; j < this->countOfVertices; j++) {
			std::cout << this->matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}
}
