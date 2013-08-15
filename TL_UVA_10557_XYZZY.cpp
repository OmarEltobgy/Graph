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
int distances[1000], parent[1000], fromTo[1000][5], positiveCycleN;
int INF = -10000000, roomsN;

int positiveCycleBefore(int node, int cycleN)
{
	int now = fromTo[cycleN][1];
	while(now != fromTo[cycleN][0])
	{
		if(node == now && distances[now] > 0)
		{
			return 1;
		}
		now = parent[now];
	}
	if(node == 1)
	{
		return 0;
	}
	return positiveCycleBefore(parent[node], cycleN);
}

int verifyPath(int nowNode)
{
	int temp, flag;
	if(nowNode == 1)
	{
		if(distances[nowNode] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(distances[nowNode] > 0)
	{
		return (verifyPath(parent[nowNode]));
	}
	else
	{
		flag = 0; 
		for(int p=0; p<positiveCycleN; p++)
		{
			int temp = positiveCycleBefore(nowNode, p);
			if(temp == 1)
			{
				flag = 1;
			}
		}
		if(flag == 0)
		{
			return 0;
		}
		else
		{
			return (verifyPath(parent[nowNode]));
		}
	}
}
int checkParentToParent(int parentN, int childN)
{
	if(parentN == childN)
	{
		return 1;
	}
	if(parentN == 1)
	{
		return 0;
	}
	return checkParentToParent(parent[parentN], childN);
}
int SSSP()
{
	int i, j, k, childN, delay, result, effect = 0;
	distances[1] = 100;
	positiveCycleN = 0;
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
					if(distances[i] + delay > distances[childN])
					{
						if(checkParentToParent(i, childN) == 0)
						{
							distances[childN] = distances[i] + delay;
							parent[childN] = i;
						}
						else
						{
							fromTo[positiveCycleN][0] = childN;
							fromTo[positiveCycleN][1] = i;
							positiveCycleN ++;
						}
					}
				}
			}
		}
	}
	return verifyPath(roomsN);
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
