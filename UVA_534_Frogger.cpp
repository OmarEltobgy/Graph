#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int nodesN, i, j, k, INF=10000000, tt=0, xy[300][2];
	double adjMat[300][300], dist;
	scanf("%d",&nodesN);
	while(nodesN != 0)
	{
		tt++;
		for(i=0; i<nodesN; i++)
		{
			scanf("%d %d",&xy[i][0],&xy[i][1]);
			for(j=0; j<i; j++)
			{
				dist = sqrt(pow(xy[i][0]-xy[j][0], 2) + pow(xy[i][1]-xy[j][1], 2));
				adjMat[i][j] = dist;
				adjMat[j][i] = dist;
			}
			adjMat[i][i] = 0;
		}
		for(k=0; k<nodesN; k++)
		{
			for(i=0; i<nodesN; i++)
			{
				for(j=0; j<nodesN; j++)
				{
					adjMat[i][j] = min(adjMat[i][j], max(adjMat[i][k], adjMat[k][j]));
				}
			}
		}
		printf("Scenario #%d\n", tt);
		printf("Frog Distance = %.3lf\n\n", adjMat[0][1]);
		scanf("%d",&nodesN);
	}
}
