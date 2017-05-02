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
			Node<int> *trav = this->AdjList.getStart(u);
			while(trav != NULL)
			{
				int v = trav->data;
				if(vis[v] == false)
				{
					vis[v] = true;
					q.push(v);
				}
				trav = trav->next;
			} 
		}
		else
		{
			LinearList<int> trav = this->AdjMat.getAdjacent(u);
			for(int i=0;i<this->vertices_;i++)
			{
				if(trav[i] == 1)
				{
					int v = i;
					if(vis[v] == false)
					{
						vis[v] = true;
						q.push(v);
					}
				}
			}
		}
	}
}
void AbstractGraph :: Dfs(void (*work)(const int& ),const int &src = 0)
{
	if(src >= this->vertices_)
		return ;
	for(int i=0;i<vertices_;i++)
		vis[i] = false;
	dfsUtil(work,src);
	return ;
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
			Node<int> *trav = this->AdjList.getStart(u);
			while(trav != NULL)
			{
				int v = trav->data;
				if(vis[v] == false)
				{
					vis[v] = true;
					q.push(v);
				}
				trav = trav->next;
			} 
		}
		else
		{
			LinearList<int> trav = this->AdjMat.getAdjacent(u);
			for(int i=0;i<this->vertices_;i++)
			{
				if(trav[i] == 1)
				{
					int v = i;
					if(vis[v] == false)
					{
						vis[v] = true;
						q.push(v);
					}
				}
			}
		}
	}
}

void AbstractGraph :: Bfs(void (*work)(const int& ),const int &src = 0)
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