#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
vector<vector<int> > adjList;
int parent[1030], adjMat[1030][1030], src=0, dst=1021, visited[1030], INF=10000000, maxFlow;
int catN, probN;
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
	int i, j, temp, n, need;
	scanf("%d %d",&catN,&probN);
	while(catN!=0 || probN!=0)
	{
		need = 0;
		adjList.resize(1030);
		memset(adjMat, 0, sizeof(adjMat));
		for(i=1; i<=catN; i++)
		{
			scanf("%d",&temp);
			adjList[i+1000].push_back(1021);
			adjList[1021].push_back(i+1000);
			adjMat[i+1000][1021] = temp;
			adjMat[1021][i+1000] = 0;
			need += temp;
		}
		for(i=1; i<=probN; i++)
		{
			adjList[0].push_back(i);
			adjList[i].push_back(0);
			adjMat[0][i] = 1;
			adjMat[i][0] = 0;
			scanf("%d",&n);
			for(j=0; j<n; j++)
			{
				scanf("%d",&temp);
				adjList[temp+1000].push_back(i);
				adjList[i].push_back(temp+1000);
				adjMat[temp+1000][i] = 0;
				adjMat[i][temp+1000] = 1;
			}
		}
		maxFlow = 0;
		solve();
		if(maxFlow == need)
		{
			printf("1\n");
			for(i=1; i<=catN; i++)
			{
				int flag = 0;
				for(j=1; j<=1000; j++)
				{
					if(adjMat[i+1000][j] == 1)
					{
						if(flag == 0)
						{
							flag = 1;
						}
						else
						{
							printf(" ");
						}
						printf("%d", j);
					}
				}
				printf("\n");
			}
		}
		else
		{
			printf("0\n");
		}
		adjList.clear();
		scanf("%d %d",&catN,&probN);
	}
	return 0;
}
