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
int distances[100000];
int INF = 10000000, starsN;

int SSSP()
{
	int i, j, k, childN, delay, anyChange=1;
	distances[0] = 0;
	for(k=0; k<starsN-1 && anyChange==1; k++)
	{
		anyChange = 0;
		for(i=0; i<starsN; i++)
		{
			if(distances[i] != INF)
			{		
				for(j=0; j<graph[i].size(); j++)
				{
					childN = graph[i][j].second;
					delay = graph[i][j].first;
					if(distances[i] + delay < distances[childN])
					{
						distances[childN] = distances[i] + delay;
						anyChange = 1;
					}
				}
			}
		}
	}
	for(i=0; i<starsN; i++)
	{
		if(distances[i] != INF)
		{
			for(j=0; j<graph[i].size(); j++)
			{
				childN = graph[i][j].second;
				delay = graph[i][j].first;
				if(distances[i] + delay < distances[childN])
				{
					distances[childN] = distances[i] + delay;
					return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	int wormsN, i, testsN, isNegative, first, second, delay;
	scanf("%d",&testsN);
	while(testsN--)
	{
		scanf("%d %d",&starsN,&wormsN);
		graph.resize(starsN);
		//distances.resize(starsN);
		for(i=0; i<starsN; i++)
		{
			distances[i] = INF;
		}
		for(i=0; i<wormsN; i++)
		{
			scanf("%d %d %d",&first,&second,&delay);
			graph[first].push_back(ii(delay, second));
		}
		isNegative = SSSP();
		if(isNegative == 1)
		{
			printf("possible\n");
		}
		else
		{
			printf("not possible\n");
		}
		for(i=0; i<starsN; i++)
		{
			graph[i].clear();
		}
		graph.clear();
	}
	return 0;
}
