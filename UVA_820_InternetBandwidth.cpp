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

int nodesN, src, dst, adjMat[110][110], roadsN, parent[110], INF=1000000;
bool visited[110];
vector<vector<int> > adjList;
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
int findPath(int node, int minEdge)
{
	if(parent[node] == -1)
	{
		return minEdge;
	}
	int temp = findPath(parent[node], min(minEdge, adjMat[parent[node]][node]));
	adjMat[parent[node]][node] -= temp;
	adjMat[node][parent[node]] += temp;
	return temp;
}
int solve()
{
	int maxFlow=0;
	while(true)
	{
		int temp;
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
	int i, ttt=0, f, s, d;
	scanf("%d",&nodesN);
	while(nodesN != 0)
	{
		ttt++;
		adjList.resize(nodesN+1);
		memset(adjMat, 0, sizeof(adjMat));
		scanf("%d %d %d",&src,&dst,&roadsN);
		for(i=0; i<roadsN; i++)
		{
			scanf("%d %d %d",&f,&s,&d);
			if(adjMat[f][s] == 0)
			{
				adjList[f].push_back(s);
				adjList[s].push_back(f);
			}
			adjMat[f][s] += d;
			adjMat[s][f] += d;
		}
		printf("Network %d\n", ttt);
		printf("The bandwidth is %d.\n\n", solve());
		scanf("%d",&nodesN);
		adjList.clear();
	}
}
