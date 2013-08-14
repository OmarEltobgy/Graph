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
int source, destination, INF = 10000000;
priority_queue<ii, vector<ii>, greater<ii> > pq;

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
			return;	
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
void printPath(int nowNode)
{
	if(nowNode == source)
	{
		printf(" %d", nowNode);
		return;
	}
	printPath(parent[nowNode]);
	printf(" %d", nowNode);
}
int main()
{
	int NI, i, roadsN, j, toWhere, delay, ttt=0;
	scanf("%d",&NI);
	while(NI != 0)
	{
		ttt ++;
		graph.resize(NI+1);
		distances.resize(NI+1);
		parent.resize(NI+1);
		for(i=1; i<=NI; i++)
		{
			distances[i] = INF;
			scanf("%d",&roadsN);
			graph[i].resize(roadsN);
			for(j=0; j<roadsN; j++)
			{
				scanf("%d %d",&toWhere,&delay);
				graph[i][j] = ii(delay, toWhere);
			}
		}
		scanf("%d %d",&source,&destination);
		SSSP();
		printf("Case %d: Path =", ttt);
		printPath(destination);
		printf("; %d second delay\n", distances[destination]);
		while(!pq.empty())
		{
			pq.pop();
		}
		for(i=0; i<NI; i++)
		{
			graph[i].clear();
		}
		graph.clear();
		scanf("%d",&NI);	
	}
	return 0;
}
