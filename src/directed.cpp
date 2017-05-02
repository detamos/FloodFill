#include <iostream>
#include "DirectedGraph.hpp"
#include "../lib/DirectedGraph.cpp"

using namespace cs202;
using namespace std;

void print(const int &a)
{
	cout<<a<<" ";
}

int main()
{
	DirectedGraph a(5,'l');
	DirectedGraph b(5,'m');
	a.add(0,1); b.add(0,1);
	a.add(0,2); b.add(0,2);
	a.add(3,4); b.add(3,4);
	a.add(1,3); b.add(1,3);
	a.add(2,4); b.add(2,4);
	a.print();  
	a.bfs(&print);
	b.print();	
	return 0;
}