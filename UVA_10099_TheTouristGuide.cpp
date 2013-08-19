#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int edgesN, i, j, weight, counter, tt=0, touristsN, result;
	int flag=0, nodesN, INF=-1000000, adjMatrix[300][300], k, first, second;
	scanf("%d %d",&nodesN,&edgesN);
	while(nodesN != 0 || edgesN != 0)
	{
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
					adjMatrix[i][j] = max(adjMatrix[i][j], min(adjMatrix[i][k], adjMatrix[k][j]));
				}
			}
		}
		scanf("%d %d %d",&first,&second,&touristsN);
		//printf("%d %d\n", touristsN, adjMatrix[first][second]);
		result = touristsN / (adjMatrix[first][second]-1);
		if(touristsN % (adjMatrix[first][second]-1) != 0)
		{
			result ++;
		}
		printf("Scenario #%d\n", tt);
		printf("Minimum Number of Trips = %d\n", result);
		printf("\n");
		scanf("%d %d",&nodesN,&edgesN);
	}
	return 0;
}
