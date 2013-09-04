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

typedef pair<int, int> ii;
vector<vector<int> > adjList;
map<string, int> size;
int parent[40], adjMat[40][40], src=0, dst=37, visited[40], INF=10000000, maxFlow, N, M;
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
	int i, j, testN, each;
	string a, b;
	scanf("%d",&testN);
	size["XS"] = 1;
	size["S"] = 2;
	size["M"] = 3;
	size["L"] = 4;
	size["XL"] = 5;
	size["XXL"] = 6;
	while(testN--)
	{
		scanf("%d %d",&N,&M);
		each = N/6;
		adjList.resize(40);
		memset(adjMat, 0, sizeof(adjMat));
		for(i=1; i<=6; i++)
		{
			adjList[0].push_back(i);
			adjList[i].push_back(0);
			adjMat[0][i] = each;
			adjMat[i][0] = 0;
		}
		for(i=7; i<=39; i++)
		{
			adjList[i].push_back(37);
			adjList[37].push_back(i);
			adjMat[i][37] = 1;
			adjMat[37][i] = 0;
		}
		for(i=0; i<M; i++)
		{
			cin >> a >> b;
			adjList[size[a]].push_back(i+7);
			adjList[i+7].push_back(size[a]);
			adjMat[size[a]][i+7] = 1;
			adjMat[i+7][size[a]] = 0;
			adjList[size[b]].push_back(i+7);
			adjList[i+7].push_back(size[b]);
			adjMat[size[b]][i+7] = 1;
			adjMat[i+7][size[b]] = 0;
		}
		maxFlow = 0;
		solve();
		if(maxFlow == M)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		//printf("%d\n", maxFlow);
		adjList.clear();
	}
	return 0;
}
