#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>
#include <math.h>
#include<map>
#include <vector>
#include <queue>
using namespace std;

long long src=1, dst=2, adjMat[200][200], parent[200], INF=1000000000, nodesN, roadsN;
bool visited[200];
vector<vector<long long> > adjList;
void bfs()
{
	int top, i, next;
	queue<int> Q;
	visited[src] = true;
	Q.push(src);
	while(!Q.empty())
	{
		top = Q.front();
		Q.pop();
		for(i=0; i<adjList[top].size(); i++)
		{
			next = adjList[top][i];
			if(adjMat[top][next] > 0 && visited[next] == false)
			{
				visited[next] = true;
				parent[next] = top;
				Q.push(next);
			}
		}
	}
}
long long findPath(int node, long long minEdge)
{
	if(parent[node] == -1)
	{
		return minEdge;
	}
	long long temp = findPath(parent[node], min(minEdge, adjMat[parent[node]][node]));
	adjMat[parent[node]][node] -= temp;
	adjMat[node][parent[node]] += temp;
	return temp;
}
long long solve()
{
	long long maxFlow=0;
	while(true)
	{
		long long temp;
		memset(visited, false, sizeof(visited));
		memset(parent, -1, sizeof(parent));
		bfs();
		temp = findPath(dst, INF);
		if(temp == INF)
		{
			return maxFlow;
		}
		else
		{
			maxFlow += temp;
		}
	}
	return maxFlow;
}
int main()
{
	int i, f, s, j, next, a, b;
	long long d;
	scanf("%d %d",&nodesN,&roadsN);
	while(nodesN != 0 || roadsN != 0)
	{
		adjList.resize(nodesN+1);
		memset(adjMat, 0, sizeof(adjMat));
		for(i=0; i<roadsN; i++)
		{
			scanf("%d %d %lld",&f,&s,&d);
			if(adjMat[f][s] == 0)
			{
				adjList[f].push_back(s);
				adjList[s].push_back(f);
			}
			adjMat[f][s] += d;
			adjMat[s][f] += d;
		}
		solve();
		for(i=1; i<=nodesN; i++)
		{
			if(visited[i] == true)
			{
				for(j=0; j<adjList[i].size(); j++)
				{
					next = adjList[i][j];
					if(visited[next] == false)
					{
						printf("%d %d\n", i, next);
					}
				}
			}
		}
		printf("\n");
		scanf("%d %d",&nodesN,&roadsN);
		adjList.clear();
	}
}
