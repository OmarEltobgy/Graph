#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int nodesN, i, adjMat[500][500], j, k, edgesN, e, first, second, weight;
	long long sum;
	scanf("%d",&nodesN);
	sum = 0;
	for(i=1; i<=nodesN; i++)
	{
		for(j=1; j<=nodesN; j++)
		{
			scanf("%d",&adjMat[i][j]);
			if(j < i)
			{
				sum += adjMat[i][j];
			}
		}
	}
	scanf("%d",&edgesN);
	for(e=0; e<edgesN; e++)
	{
		scanf("%d %d %d",&first,&second,&weight);
		
		if(weight < adjMat[first][second])
		{
			sum -= adjMat[first][second];
			adjMat[first][second] = weight;
			adjMat[second][first] = weight;
			sum += adjMat[first][second];
			for(i=1; i<=nodesN; i++)
			{
				for(j=1; j<i; j++)
				{
					if(adjMat[i][first] + adjMat[first][second] + adjMat[second][j] < adjMat[i][j])
					{
						sum -= adjMat[i][j];
						adjMat[i][j] = adjMat[i][first] + adjMat[first][second] + adjMat[second][j];
						adjMat[j][i] = adjMat[i][first] + adjMat[first][second] + adjMat[second][j];
						sum += adjMat[i][j];
					}
					if(adjMat[i][second] + adjMat[second][first] + adjMat[first][j] < adjMat[i][j])
					{
						sum -= adjMat[i][j];
						adjMat[i][j] = adjMat[i][second] + adjMat[second][first] + adjMat[first][j];
						adjMat[j][i] = adjMat[i][second] + adjMat[second][first] + adjMat[first][j];
						sum += adjMat[i][j];
					}
				}
			}
		}
		
		if(e != edgesN-1)
		{
			cout << sum << " ";
		}
		else
		{
			cout << sum << endl;
		}
	}
}
