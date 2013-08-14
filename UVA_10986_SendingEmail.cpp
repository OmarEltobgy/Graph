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
vi distances;
vi parent;
priority_queue<ii, vector<ii>, greater<ii> > pq;
int source, destination, INF = 10000000;

void SSSP()
{
	ii p;
	int i, childN, extraDelay, parentN, parentMinDelay;
	pq.push(ii(0, source));
	distances[source] = 0;
	while(!pq.empty())
	{
		p = pq.top();
		parentN = p.second;
		parentMinDelay = p.first;
		if(parentN == destination)
		{
			return;
		}
		pq.pop();
		if(distances[parentN] == parentMinDelay)
		{
			for(i=0; i<graph[parentN].size(); i++)
			{
				childN = graph[parentN][i].second;
				extraDelay = graph[parentN][i].first;
				if(parentMinDelay + extraDelay < distances[childN])
				{
					distances[childN] = parentMinDelay + extraDelay;
					parent[childN] = parentN;
					pq.push(ii(distances[childN], childN));
				}
			}
		}
	}
}
int main()
{
	int serversN, i, cablesN, j, first, second, delay, ttt, counter=0;
	scanf("%d",&ttt);
	while(ttt--)
	{
		counter ++;
		scanf("%d %d %d %d",&serversN,&cablesN,&source,&destination);
		graph.resize(serversN);
		distances.resize(serversN);
		parent.resize(serversN);
		for(i=0; i<serversN; i++)
		{
			distances[i] = INF;
		}
		for(i=0; i<cablesN; i++)
		{
			scanf("%d %d %d",&first,&second,&delay);
			graph[first].push_back(ii(delay, second));
			graph[second].push_back(ii(delay, first));
		}
		SSSP();
		if(distances[destination] != INF)
		{
			printf("Case #%d: %d\n", counter, distances[destination]);
		}
		else
		{
			printf("Case #%d: unreachable\n", counter);
		}
		while(!pq.empty())
		{
			pq.pop();
		}
		for(i=0; i<serversN; i++)
		{
			graph[i].clear();
		}
		graph.clear();
	}
	return 0;
}
