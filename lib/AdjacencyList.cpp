#include "AdjacencyList.hpp"

void AdjacencyList :: resize(int vertices)
{
	this->vertices_ = vertices;
	this->AdjList.resize(vertices);
}

bool AdjacencyList :: edgeExists(int i,int j)
{
	if(i >= this->vertices_ || j >= this->vertices_)
			return false;

	if(this->AdjList[i].exists(j))
		return true;
	return false;
}

int AdjacencyList :: degree(int i)
{
	if(i >= this->vertices_)
		return -1;
	
	return this->AdjList[i].length();
}

int AdjacencyList :: vertices()
{
	return this->vertices_;
}
void AdjacencyList :: add(int i, int j)
{
	if(i >= this->vertices_ || j >= this->vertices_)
		return ;
	if(this->edgeExists(i,j))
		return ;
	this->AdjList[i].append(j);
}
void AdjacencyList :: remove(int i, int j)
{
	if(i >= this->vertices_ || j >= this->vertices_)
		return ;
	this->AdjList[i].remove(j);
}


void AdjacencyList :: print()
{
	for(int i=0;i<this->vertices_;i++)
	{
		cout<<i<<" : ";
		this->AdjList[i].print();
	}
}
