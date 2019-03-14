#include "pch.h"
#include <iostream>
#include "AdjacencyListGraph.h"

AdjacencyList::AdjacencyList()
{
	this->vertexId = 0;
	this->countOfAdjacents = 0;
	this->adjancedVertices = nullptr;
}

AdjacencyList::~AdjacencyList()
{

}

void AdjacencyList::setVertexId(int vertexId)
{
	this->vertexId = vertexId;
}

int AdjacencyList::getVertexId() const
{
	return this->vertexId;
}

void AdjacencyList::addAdjanced(int vertex)
{
	this->countOfAdjacents += 1;
	int* newAdjancedVertices = new int[this->countOfAdjacents];

	if (this->adjancedVertices != nullptr) {
		for (int i = 0; i < this->countOfAdjacents - 1; i++) {
			newAdjancedVertices[i] = this->adjancedVertices[i];
		}

		delete[] this->adjancedVertices;
	}

	newAdjancedVertices[this->countOfAdjacents - 1] = vertex;
	this->adjancedVertices = newAdjancedVertices;
}

bool AdjacencyList::hasAdjanced(int vertex)
{
	for (int i = 0; i < this->countOfAdjacents; i++)
	{
		if (this->adjancedVertices[i] == vertex) {
			return true;
		}
	}

	return false;
}

void AdjacencyList::printList()
{
	for (int i = 0; i < this->countOfAdjacents; i++)
	{
		std::cout << this->adjancedVertices[i] << " ";
	}
}

int AdjacencyList::getVertexDegree()
{
	return this->countOfAdjacents;	
}

AdjacencyListGraph::AdjacencyListGraph(int countOfVertices)
{
	this->countOfVertices = countOfVertices;

	this->adjacencyList = new AdjacencyList[countOfVertices];
	for (int i = 0; i < countOfVertices; i++)
	{
		// NOTE: i+1 indexer starts with 0, but graph starts with 1
		this->adjacencyList[i].setVertexId(i + 1);
	}
}

AdjacencyListGraph::~AdjacencyListGraph()
{
	delete[] this->adjacencyList;
}

void AdjacencyListGraph::addEdge(int from, int to)
{
	for (int i = 0; i < this->countOfVertices; i++) {
		if (this->adjacencyList[i].getVertexId() == from) {
			this->adjacencyList[i].addAdjanced(to);
		}

		if (this->adjacencyList[i].getVertexId() == to) {
			this->adjacencyList[i].addAdjanced(from);
		}
	}
}

bool AdjacencyListGraph::hasEdge(int from, int to)
{
	for (int i = 0; i < this->countOfVertices; i++) {
		if (this->adjacencyList[i].getVertexId() == from) {
			return this->adjacencyList[i].hasAdjanced(to);
		}
	}

	return false;
}

void AdjacencyListGraph::printGraph()
{
	for (int i = 0; i < this->countOfVertices; i++)
	{
		this->adjacencyList[i].printList();
		std::cout << std::endl;
	}
}

int AdjacencyListGraph::getVertexDegree(int vertex)
{
	for (int i = 0; i < this->countOfVertices; i++) {
		if (this->adjacencyList[i].getVertexId() == vertex) {
			return this->adjacencyList[i].getVertexDegree();
		}
	}

	return 0;
}
