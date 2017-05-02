#ifndef ABSTRACT_GRAPH
#define ABSTRACT_GRAPH 

#include "queue.hpp"
#include "stack.hpp"
#include "../lib/queue.cpp"
#include "../lib/stack.cpp"
#include "AdjacencyMatrix.hpp"
#include "../lib/AdjacencyMatrix.cpp"
#include "AdjacencyList.hpp"
#include "../lib/AdjacencyList.cpp"

using namespace cs202;

enum GraphType{List,Matrix};

namespace cs202
{
  class AbstractGraph 
  {
  protected:
    AdjacencyMatrix AdjMat;
    AdjacencyList AdjList;
    int vertices_;
    LinearList<bool> vis;
  protected:
    GraphType type;
  public:
    virtual ~AbstractGraph(){}
    virtual bool edgeExists(int i, int j) = 0;
    virtual int edges() = 0;
    virtual int vertices() = 0;
    virtual void add(int i, int j) = 0;
    virtual void remove(int i, int j) = 0;
    virtual int degree(int i) = 0;
    void dfsUtil(void (*work)(const int& ),const int &src);
    void dfs(void (*work)(const int&),const int &src);
    void bfsUtil(void (*work)(const int&),const int &src);
    void bfs(void (*work)(const int&),const int &src);
  };
}
#endif