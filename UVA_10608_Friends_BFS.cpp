#include <stdio.h>
#include <vector>
#include <queue> 
#include <math.h> 
#include <functional>
using namespace std;

int citizensN, visited[40000], max2;
vector<vector<int> > graph;

int bfs(int source)
{
	int top, i, counter=0;
	queue<int> Q;
	visited[source] = 1;
	Q.push(source);
	counter ++;
	while(!Q.empty())
	{
		top = Q.front();
		Q.pop();
		for(i=0; i<graph[top].size(); i++)
		{
			if(visited[graph[top][i]] == 0)
			{
				visited[graph[top][i]] = 1;
				Q.push(graph[top][i]);
				counter ++;
			}
		}
	}
	return counter;
}
int main()
{
	int testsN, friendsN, i, first, second, temp;
	scanf("%d",&testsN);
	while(testsN--)
	{
		scanf("%d %d",&citizensN,&friendsN);
		graph.resize(citizensN+1);
		for(i=1; i<=citizensN; i++)
		{
			visited[i] = 0;
		}
		for(i=0; i<friendsN; i++)
		{
			scanf("%d %d",&first,&second);
			graph[first].push_back(second);
			graph[second].push_back(first);
		}
		max2 = -1;
		for(i=1; i<=citizensN; i++)
		{
			if(visited[i] == 0)
			{
				max2 = max(bfs(i), max2); 
			}
		}
		printf("%d\n", max2);
		for(i=1; i<=citizensN; i++)
		{
			graph[i].clear();
		}
		graph.clear();
	}
	return 0;
}
