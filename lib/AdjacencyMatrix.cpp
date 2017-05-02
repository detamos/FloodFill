#include "AdjacencyMatrix.hpp"

void AdjacencyMatrix :: resize(int vertices)
{
	this->vertices_ = vertices;
	this->AdjMat.resize(vertices);
	for(int i=0;i<vertices;i++)
		this->AdjMat[i].resize(vertices);

	for(int i=0;i<vertices;i++)
		for(int j=0;j<vertices;j++)
			this->AdjMat[i][j] = 0;
}

bool AdjacencyMatrix :: edgeExists(int i,int j)
{
	if(i >= this->vertices_ || j >= this->vertices_)
			return false;

	if(this->AdjMat[i][j] == 1)
		return true;
	return false;
}

int AdjacencyMatrix :: degree(int i)
{
	if(i >= this->vertices_)
		return -1;
	
	int deg = 0;
	for(int j=0;j<this->vertices_;j++)
		if(this->AdjMat[i][j] == 1)
			deg++;
	return deg;
}

int AdjacencyMatrix :: vertices()
{
	return this->vertices_;
}
void AdjacencyMatrix :: add(int i, int j)
{
	if(i >= this->vertices_ || j >= this->vertices_)
		return ;
	if(this->edgeExists(i,j))
		return ;
	
	this->AdjMat[i][j] = 1;
}
void AdjacencyMatrix :: remove(int i, int j)
{
	if(i >= this->vertices_ || j >= this->vertices_)
		return ;
	this->AdjMat[i][j] = 0;
}


void AdjacencyMatrix :: print()
{
	for(int i=0;i<this->vertices_;i++)
	{
		for(int j=0;j<this->vertices_;j++)
			cout<<this->AdjMat[i][j]<<" ";
		cout<<endl;
	}
}
