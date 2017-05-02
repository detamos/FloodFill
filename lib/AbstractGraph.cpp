#include "AbstractGraph.hpp"


void AbstractGraph :: dfsUtil(void (*work)(const int& ),const int &src = 0)
{
	stack<int> q;
	q.push(src);
	vis[src] = true;
	while(!q.empty())
	{
		int u = q.pop();
		work(u);
		vis[u] = true;
		if(this->degree(u) == 0)
			continue;
		if(this->type == List)
		{
			
		}
		else
		{
			
		}
	}
}
void AbstractGraph :: dfs(void (*work)(const int& ),const int &src = 0)
{
	if(src >= this->vertices_)
		return ;
	for(int i=0;i<vertices_;i++)
		vis[i] = false;
	dfsUtil(work,src);
	for(int i=0;i<this->vertices_;i++)
	{
		if(vis[i] == false)
		{
			dfsUtil(work,i);
		}
	}
}

void AbstractGraph :: bfsUtil(void (*work)(const int& ),const int &src = 0)
{
	queue<int> q;
	q.push(src);
	vis[src] = true;
	while(!q.empty())
	{
		int u = q.pop();
		work(u);
		if(this->degree(u) == 0)
			continue;
		if(this->type == List)
		{
			
		}
		else
		{

		}
	}
}

void AbstractGraph :: bfs(void (*work)(const int& ),const int &src = 0)
{
	if(src >= this->vertices_)
		return ;
	for(int i=0;i<vertices_;i++)
		vis[i] = false;
	bfsUtil(work,src);
	for(int i=0;i<this->vertices_;i++)
	{
		if(vis[i] == false)
		{
			bfsUtil(work,i);
		}
	}
}