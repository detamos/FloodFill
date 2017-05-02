#include <iostream>
#include "UndirectedGraph.hpp"
#include "../lib/UndirectedGraph.cpp"

using namespace cs202;
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;

	char maze[n+2][m+2];
	for(int i=0;i<n+2;i++)
		for(int j=0;j<m+2;j++)
			maze[i][j] = 'O';

	for(int i=0;i<n+2;i++)
		maze[i][0] = maze[i][m+1] = 'X';
	for(int i=0;i<m+2;i++)
		maze[0][i] = maze[n+1][i] = 'X';

	int sx,sy,dx,dy;
	cin>>sx>>sy>>dx>>dy;

	int num,ivx,ivy;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cin>>ivx>>ivy;
		maze[ivx][ivy] = 'X';
	}

	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			cout<<maze[i][j]<<" ";
		}
		cout<<endl;
	}

	UndirectedGraph graph(n*m);

	int dir = {-1,0,1};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{

		}
	}

	return 0;
}