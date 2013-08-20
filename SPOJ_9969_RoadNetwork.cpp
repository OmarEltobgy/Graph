#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int testsN, tt, nodesN, excitingN, exciting;
	int k, ee, queriesN, first, second, INF=1000000, i, j;
	vector<vector<vector<int> > > adjMat;
	scanf("%d",&testsN);
	for(tt=1; tt<=testsN; tt++)
	{
		scanf("%d",&nodesN);
		adjMat.resize(nodesN+1);
		for(i=0; i<=nodesN; i++)
		{
			adjMat[i].resize(nodesN+1);
			for(j=0; j<=nodesN; j++)
			{
				adjMat[i][j].resize(nodesN+1);
			}
		}
		for(i=1; i<=nodesN; i++)
		{
			adjMat[0][i][i] = 0;
			for(j=i+1; j<=nodesN; j++)
			{
				scanf("%d",&adjMat[0][i][j]);
				if(adjMat[0][i][j] == -1)
				{
					adjMat[0][i][j] = INF;
				}
				adjMat[0][j][i] = adjMat[0][i][j];
			}
		}
		scanf("%d",&excitingN);
		for(ee=1; ee<=excitingN; ee++)
		{
			scanf("%d",&exciting);
			k = exciting;
			for(i=1; i<=nodesN; i++)
			{
				for(j=1; j<=nodesN; j++)
				{
					adjMat[ee][i][j] = min(adjMat[ee-1][i][j], adjMat[ee-1][i][k]+adjMat[ee-1][k][j]);
				}
			}
		}
		scanf("%d",&queriesN);
		printf("Case %d:", tt);
		for(i=1; i<=queriesN; i++)
		{
			scanf("%d %d %d",&ee,&first,&second);
			if(adjMat[ee][first][second] == INF)
			{
				printf(" -1");
			}
			else
			{
				printf(" %d", adjMat[ee][first][second]);
			}
		}
		printf("\n");
		adjMat.resize(nodesN+1);
		for(i=0; i<=nodesN; i++)
		{
			for(j=0; j<=nodesN; j++)
			{
				adjMat[i][j].clear();
			}
			adjMat[i].clear();
		}
		adjMat.clear();
	}
	
	return 0;
}
