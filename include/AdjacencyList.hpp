#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 
#include "GraphAdjacencyBase.hpp"

namespace cs202
{
	class AdjacencyList : public GraphAdjacencyBase 
	{
		LinearList<list<int> > AdjList;
		int vertices_;
	public:
		void resize(int vertices);
		int degree(int i);
    	bool edgeExists(int i, int j);
	    int vertices();
	    void add(int i, int j);
	    void remove(int i, int j);
	    void print();
	};
}
#endif 