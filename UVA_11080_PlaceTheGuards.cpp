#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > graph;
int visited[1000], taken[1000];
int solve(int source, int there)
{
  int counter = 0, t, flag = 0;
	queue<int> Q;
	visited[source] = there;
	taken[source] = 1;
	if(visited[source] == 1)
		counter ++;
	Q.push(source);
	while(!Q.empty())
	{
		t = Q.front();
		Q.pop();
		for(int i=0; i<graph[t].size(); i++)
		{
			if(visited[graph[t][i]] == -1)
			{
				visited[graph[t][i]] = (visited[t] + 1) % 2;
				taken[graph[t][i]] = 1;
				if((visited[t] + 1) % 2 == 1)
					counter ++;
				Q.push(graph[t][i]);
			}
			else if(visited[graph[t][i]] != (visited[t] + 1) % 2)
			{
				flag = 1;
			}
		}
	}
	if(flag == 0)
		return counter;
	else
		return -1;	
}
int main()
{
	int testN, v, e, i, first, second;
	scanf("%d",&testN);
	while(testN--)
	{
		graph.resize(1000);
		scanf("%d %d",&v,&e);
		for(i=0; i<v; i++)
		{
			graph[i].clear();
			visited[i] = -1;
			taken[i] = 0;
		}
		for(i=0; i<e; i++)
		{
			scanf("%d %d",&first,&second);
			graph[first].push_back(second);
			graph[second].push_back(first);
		}
		int minimum = 0, a, b, k;
		for(i=0; i<v; i++)
		{
			if(taken[i] == 0)
			{
				for(k=0; k<v; k++)
					visited[k] = -1;
				a = solve(i, 0);
				/* =================== */
				for(k=0; k<v; k++)
					visited[k] = -1;
				b = solve(i, 1); 
				if(a == -1 && b == -1)
				{
					minimum = -1;
					break;
				}
				// a == 0
				else if(a == -1 || a == 0)
				{
					minimum += b;
				}
				else if(b == -1 || b == 0)
				{
					minimum += a;
				}
				else if(a < b)
				{
					minimum += a;
				}
				else
				{
					minimum += b;
				}
			}
		}
		printf("%d\n", minimum);
		graph.clear();
	}
	return 0;
}
