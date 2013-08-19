#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int queriesN, edgesN, i, j, weight, counter, tt=0;
	int flag=0, nodesN, INF=1000000, adjMatrix[300][300], k, first, second;
	scanf("%d %d %d",&nodesN,&edgesN,&queriesN);
	while(nodesN != 0 || edgesN != 0 || queriesN != 0)
	{
		if(flag == 0)
		{
			flag = 1;
		}
		else
		{
			printf("\n");
		}
		tt ++;
		
		for(i=1; i<=nodesN; i++)
		{
			for(j=1; j<=nodesN; j++)
			{
				adjMatrix[i][j] = INF;
			}
			adjMatrix[i][i] = 0;
		}
		for(i=0; i<edgesN; i++)
		{
			cin >> first >> second >> weight;
			adjMatrix[second][first] = weight;
			adjMatrix[first][second] = weight;
		}
		for(k=1; k<=nodesN; k++)
		{
			for(i=1; i<=nodesN; i++)
			{
				for(j=1; j<=nodesN; j++)
				{
					adjMatrix[i][j] = min(adjMatrix[i][j], max(adjMatrix[i][k], adjMatrix[k][j]));
				}
			}
		}
		printf("Case #%d\n", tt);
		for(i=0; i<queriesN; i++)
		{
			scanf("%d %d",&first,&second);
			if(adjMatrix[first][second] == INF)
			{
				printf("no path\n");
			}
			else
			{
				printf("%d\n", adjMatrix[first][second]);
			}
		}
		scanf("%d %d %d",&nodesN,&edgesN,&queriesN);
	}
	return 0;
}
