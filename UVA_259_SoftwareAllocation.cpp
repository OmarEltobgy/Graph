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
int parent[40], adjMat[40][40], src=0, dst=37, visited[40], INF=10000000, maxFlow;
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
	int i, pos, n, total, j, flag;
	string temp;
	while(getline(cin, temp))
	{
		adjList.resize(40);
		memset(adjMat, 0, sizeof(adjMat));
		total = 0;
		while(temp[0] != '\0' && temp[0] != EOF)
		{
			pos = temp[0] - 'A' + 1;
			n = temp[1] - '0';
			total += n;
			adjList[0].push_back(pos);
			adjList[pos].push_back(0);
			adjMat[0][pos] = n;
			adjMat[pos][0] = 0;
			for(i=3; i<temp.length(); i++)
			{
				if(temp[i]>='0' && temp[i]<='9')
				{
					n = temp[i] - '0' + 27;
					adjList[pos].push_back(n);
					adjList[n].push_back(pos);
					adjMat[pos][n] = 1;
					adjMat[n][pos] = 0;
				}
			}
			getline(cin, temp);
		}
		for(i=27; i<=36; i++)
		{
			adjList[i].push_back(37);
			adjList[37].push_back(1);
			adjMat[i][37] = 1;
			adjMat[37][i] = 0;
		}
		maxFlow = 0;
		solve();
		if(maxFlow == total)
		{
			for(i=27; i<=36; i++)
			{
				flag = 0;
				for(j=1; j<=26 && flag==0; j++)
				{
					if(adjMat[i][j] == 1)
					{
						printf("%c", j+'A'-1);
						flag = 1;
					}
				}
				if(flag == 0)
				{
					printf("_");
				}
			}
			printf("\n");
		}
		else
		{
			printf("!\n");
		}
		//printf("%d\n", maxFlow);
		adjList.clear();
	}
	return 0;
}
