#include <stdio.h> 
#include <vector> 
#include <queue>
#include <math.h>
#include <functional>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> graph;
int distances[1000];
int visited[1000];
int INF = -10000000, roomsN;

int canReachEnd(int source)
{
	int top;
	queue<int> Q;
	for(int i=1; i<=roomsN; i++)
	{
		visited[i] = 0;
	}
	visited[source] = 1;
	Q.push(source);
	while(!Q.empty())
	{
		top = Q.front();
		Q.pop();
		for(int j=0; j<graph[top].size(); j++)
		{
			if(visited[graph[top][j].second] == 0)
			{
				visited[graph[top][j].second] = 1;
				Q.push(graph[top][j].second);
			}
		}
	}
	if(visited[roomsN] == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int SSSP()
{
	int i, j, k, childN, delay, result, effect = 0;
	distances[1] = 100;
	for(k=0; k<roomsN-1; k++)
	{
		for(i=1; i<=roomsN; i++)
		{
			if(distances[i] != INF)
			{		
				for(j=0; j<graph[i].size(); j++)
				{
					childN = graph[i][j].second;
					delay = graph[i][j].first;
					if(distances[i] + delay > 0 && distances[i] + delay > distances[childN])
					{
						distances[childN] = distances[i] + delay;
					}
				}
			}
		}
	}
	if(distances[roomsN] > 0)
	{
		return 1;
	}
	else
	{
		for(i=1; i<=roomsN; i++)
		{
			if(distances[i] != INF)
			{
				for(j=0; j<graph[i].size(); j++)
				{
					childN = graph[i][j].second;
					delay = graph[i][j].first;
					if(distances[i] + delay > 0 && distances[i] + delay > distances[childN])
					{
						if(canReachEnd(childN) == 1)
						{
							return 1;
						}
					}
				}
			}
		}
		return 0;
	}
}

int main()
{
	int canWin, i, j, temp, edgesN, tempValue;
	scanf("%d",&roomsN);
	while(roomsN != -1)
	{
		graph.resize(roomsN+1);
		for(i=1; i<=roomsN; i++)
		{
			distances[i] = INF;
			visited[i] = 0;
			scanf("%d",&tempValue);
			scanf("%d",&edgesN);
			for(j=0; j<edgesN; j++)
			{
				scanf("%d",&temp);
				graph[i].push_back(ii(tempValue, temp));
			}
		}
		canWin = SSSP();
		if(canWin == 1)
		{
			printf("winnable\n");
		}
		else
		{
			printf("hopeless\n");
		}
		for(i=1; i<=roomsN; i++)
		{
			graph[i].clear();
		}
		graph.clear();
		scanf("%d",&roomsN);
	}
	return 0;
}
