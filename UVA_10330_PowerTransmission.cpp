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

vector<vector<int> > adjList;
int parent[210], adjMat[210][210], src=0, dst=201, visited[210], INF=10000000, maxFlow, nodesN;
void bfs()
{
	int top, i;
	queue<int> Q;
	visited[src] = 1;
	Q.push(src);
	while(!Q.empty())
	{
		top = Q.front();
		if(top == dst)
		{
			return;
		}
		Q.pop();
		for(i=0; i<adjList[top].size(); i++)
		{
			int neighbour = adjList[top][i];
			if(visited[neighbour]==0 && adjMat[top][neighbour]>0)
			{
				visited[neighbour] = 1;
				parent[neighbour] = top;
				Q.push(neighbour);
			}
		}
	}
}
int findMin(int node, int mini)
{
	int temp;
	if(parent[node] == -1)
	{
		return mini;
	}
	temp = findMin(parent[node], min(mini, adjMat[parent[node]][node]));
	adjMat[parent[node]][node] -= temp;
	adjMat[node][parent[node]] += temp;
	return temp;
}
int solve()
{
	int temp, i;
	while(true)
	{
		memset(visited, 0, sizeof(visited));
		memset(parent, -1, sizeof(parent));
		bfs();
		temp = findMin(dst, INF);
		if(temp == INF)
		{
			break;
		}
		else
		{
			maxFlow += temp;
		}
	}
}
int main()
{
	int i, j, c, roadsN, f, s, srcN, dstN;
	while(scanf("%d",&nodesN) != EOF)
	{
		adjList.resize(210);
		memset(adjMat, 0, sizeof(adjMat));
		for(i=1; i<=nodesN; i++)
		{
			scanf("%d",&c);
			adjList[i].push_back(100+i);
			adjList[100+i].push_back(i);
			adjMat[i][100+i] = c;
			adjMat[100+i][i] = 0;
		}
		scanf("%d",&roadsN);
		for(i=0; i<roadsN; i++)
		{
			scanf("%d %d %d",&f,&s,&c);
			adjList[f+100].push_back(s);
			adjList[s].push_back(f+100);
			adjMat[f+100][s] = c;
			adjMat[s][f+100] = 0;
		}
		scanf("%d %d",&srcN,&dstN);
		for(i=0; i<srcN; i++)
		{
			scanf("%d",&f);
			adjList[f].push_back(0);
			adjList[0].push_back(f);
			adjMat[f][0] = 0;
			adjMat[0][f] = INF;
		}
		for(i=0; i<dstN; i++)
		{
			scanf("%d",&f);
			adjList[f+100].push_back(201);
			adjList[201].push_back(f+100);
			adjMat[f+100][201] = INF;
			adjMat[201][f+100] = 0;
		}
		maxFlow = 0;
		solve();
		printf("%d\n", maxFlow);
		adjList.clear();
	}
	return 0;
}
