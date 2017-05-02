#include <iostream>
#include <cstdlib>
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

	UndirectedGraph graph(n*m,'l');

	int dir[] = {-1,0,1};
	srand(time(NULL));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(maze[i][j] == 'X')
				continue;
			int startx = rand()%3;
			int starty = rand()%3;
			for(int k=startx;k<startx+3;k++)
			{
				for(int l=starty;l<starty+3;l++)
				{
					int nx = dir[k%3] + i;
					int ny = dir[l%3] + j;
					if(maze[nx][ny] == 'X' || (nx == i && ny == j))
						continue;
					graph.add((i-1)*m+(j-1),(nx-1)*m+(ny-1));
				}
			}
		}
	}

	int src = (sx-1)*m+(sy-1);
	int des = (dx-1)*m+(dy-1);

	LinearList<dfsNode> predTree;
	predTree = graph.getDFStree(des);

	if(predTree[src].pred == -1)
	{
		cout<<"Path does not exist\n";
		return 0;
	}

	int i = src;
	while(predTree[i].pred != -1)
	{
		int x = ((i)%m)+1;
		int y = ((i)/m)+1;
		cout<<y<<","<<x<<" -> ";
		i = predTree[i].pred;
	}

	cout<<(des%m)+1<<" "<<(des/m)+1<<endl;

	return 0;
}