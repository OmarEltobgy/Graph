#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	int testsN, tt, i, j, k, nodesN, edgesN, adjMat[300][300], INF=1000000, first, second, weight, max2;
	scanf("%d",&testsN);
	for(tt=1; tt<=testsN; tt++)
	{
		scanf("%d %d",&nodesN,&edgesN);
		for(i=0; i<nodesN; i++)
		{
			for(j=0; j<nodesN; j++)
			{
				adjMat[i][j] = INF;
			}
			adjMat[i][i] = 0;
		}
		for(i=0; i<edgesN; i++)
		{
			scanf("%d %d",&first,&second);
			adjMat[first][second] = 1;
			adjMat[second][first] = 1;
		}
		for(k=0; k<nodesN; k++)
		{
			for(i=0; i<nodesN; i++)
			{
				for(j=0; j<nodesN; j++)
				{
					adjMat[i][j] = min(adjMat[i][j], adjMat[i][k]+adjMat[k][j]);
				}
			}
		}
		scanf("%d %d",&first,&second);
		max2 = -1;
		for(k=0; k<nodesN; k++)
		{
			if(adjMat[first][k] + adjMat[k][second] > max2)
			{
				max2 = adjMat[first][k] + adjMat[k][second];
			}
		}
		printf("Case %d: %d\n", tt, max2);
	}
}
