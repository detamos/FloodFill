#include <iostream>
#include "UndirectedGraph.hpp"
#include "../lib/UndirectedGraph.cpp"

using namespace cs202;
using namespace std;

void print(const int &a)
{
	cout<<a<<" ";
}

int main()
{
	UndirectedGraph a(5,'l');
	UndirectedGraph b(5,'m');
	a.add(0,1); b.add(0,1);
	a.add(0,2); b.add(0,2);
	a.add(3,4); b.add(3,4);
	a.add(1,3); b.add(1,3);
	a.add(2,4); b.add(2,4);
	a.print(); 
	cout<<"BFS : ";
	a.bfs(&print);
	cout<<"\tDFS : ";
	a.dfs(&print);
	cout<<endl;
	b.print();
	cout<<"BFS : ";
	b.bfs(&print);
	cout<<"\tDFS : ";
	b.dfs(&print);
	cout<<endl;
	return 0;
}