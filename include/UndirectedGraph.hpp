#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 

#include "AbstractGraph.hpp"
#include "../lib/AbstractGraph.cpp"

using namespace cs202;

namespace cs202
{
  class UndirectedGraph : AbstractGraph 
  {
  public:
    UndirectedGraph(int vertices,char mode);
    int degree(int i);
    bool edgeExists(int i, int j);
    int edges();
    int vertices();
    void add(int i, int j);
    void remove(int i, int j);
    void print();
    void bfs(void (*work)(const int&),const int &src);
    void dfs(void (*work)(const int&),const int &src);
    LinearList<dfsNode> getDFStree();
    LinearList<bfsNode> getBFStree();
  };
}
#endif 