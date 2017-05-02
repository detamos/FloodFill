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
  class dfsNode
  {
  public: 
    int pred;
    int discTime;
    int finishTime;
  };

  class bfsNode
  {
  public:
    int pred;
    int level;
  };

  class AbstractGraph 
  {
  protected:
    AdjacencyMatrix AdjMat;
    AdjacencyList AdjList;
    int vertices_;
    LinearList<bool> vis;
    LinearList<dfsNode> dfsTree;
    LinearList<bfsNode> bfsTree;
    int time;
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
    void Dfs(void (*work)(const int&),const int &src);
    void bfsUtil(void (*work)(const int&),const int &src);
    void Bfs(void (*work)(const int&),const int &src);
    LinearList<dfsNode> getDFSTree(const int &src);
    LinearList<bfsNode> getBFSTree(const int &src);
  };
}
#endif