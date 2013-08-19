#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	int nodesN, i, j, k, INF=10000000, testN, tt, xy[200][2];
	double adjMat[200][200], dist, max;
	scanf("%d",&testN);
	for(tt=1; tt<=testN; tt++)
	{
		scanf("%d",&nodesN);
		for(i=0; i<nodesN; i++)
		{
			scanf("%d %d",&xy[i][0],&xy[i][1]);
			for(j=0; j<i; j++)
			{
				dist = sqrt(pow(xy[i][0]-xy[j][0], 2) + pow(xy[i][1]-xy[j][1], 2));
				if(dist <= 10)
				{
					adjMat[i][j] = dist;
					adjMat[j][i] = dist;
				}
				else
				{
					adjMat[i][j] = INF;
					adjMat[j][i] = INF;
				}
			}
			adjMat[i][i] = 0;
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
		max = -1;
		for(i=0; i<nodesN; i++)
		{
			for(j=0; j<nodesN; j++)
			{
				if(adjMat[i][j] > max)
				{
					max = adjMat[i][j];
				}
			}
		}
		printf("Case #%d:\n", tt);
		if(max == INF)
		{
			printf("Send Kurdy\n\n");
		}
		else
		{
			printf("%.4lf\n\n", max);
		}
	}
}
