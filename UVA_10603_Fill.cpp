#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;//a, b, c, litres
int maxLitres[3], litresNeeded, litres[300][300][300], minLitres[300], INF=10000000; 

void SSSP()
{
	priority_queue<iiii, vector<iiii>, greater<iiii> > pq;
	iiii topPair;
	int inLitres[3], litresN, from, to, newLitres[3], litresDiff;
	pq.push(iiii(ii(0, 0), ii(maxLitres[2], 0)));
	litres[0][0][maxLitres[2]] = 0;
	while(!pq.empty())
	{
		topPair = pq.top();
		pq.pop();
		inLitres[0] = topPair.first.first;
		inLitres[1] = topPair.first.second;
		inLitres[2] = topPair.second.first;
		litresN = topPair.second.second;
		if(litresN == litres[inLitres[0]][inLitres[1]][inLitres[2]])
		{
			minLitres[inLitres[0]] = min(litresN, minLitres[inLitres[0]]);
			minLitres[inLitres[1]] = min(litresN, minLitres[inLitres[1]]);
			minLitres[inLitres[2]] = min(litresN, minLitres[inLitres[2]]);
			for(from=0; from<3; from++)
			{
				if(inLitres[from] > 0)
				{
					for(to=0; to<3; to++)
					{
						if(to != from && inLitres[to] != maxLitres[to])
						{
							newLitres[0] = inLitres[0];
							newLitres[1] = inLitres[1];
							newLitres[2] = inLitres[2];
							if(inLitres[from] > maxLitres[to]-inLitres[to])
							{
								litresDiff = maxLitres[to]-inLitres[to];
								newLitres[from] -= litresDiff;
								newLitres[to] += litresDiff;
							}
							else
							{
								litresDiff = inLitres[from];
								newLitres[from] -= litresDiff;
								newLitres[to] += litresDiff;	
							}
							if(litresN+litresDiff < litres[newLitres[0]][newLitres[1]][newLitres[2]])
							{
								litres[newLitres[0]][newLitres[1]][newLitres[2]] = litresN+litresDiff;
								pq.push(iiii(ii(newLitres[0], newLitres[1]), ii(newLitres[2], litresN+litresDiff)));
							}
						}
					}
				}
			}
		}
	}
}
int main()
{
	int testN, i, j, k;
	scanf("%d",&testN);
	while(testN--)
	{
		for(i=0; i<300; i++)
		{
			minLitres[i] = INF;
		}
		scanf("%d %d %d %d",&maxLitres[0],&maxLitres[1],&maxLitres[2],&litresNeeded);
		for(i=0; i<=maxLitres[0]; i++)
		{
			for(j=0; j<=maxLitres[1]; j++)
			{
				for(k=0; k<=maxLitres[2]; k++)
				{
					litres[i][j][k] = INF;
				}
			}
		}
		SSSP();
		for(i=0; i<200; i++)
		{
			if(litresNeeded + i <= 200 && minLitres[litresNeeded + i] != INF)
			{
				printf("%d %d\n", minLitres[litresNeeded + i], litresNeeded + i); 
				break;
			} 
			else if(litresNeeded - i >= 0 && minLitres[litresNeeded - i] != INF)
			{
				printf("%d %d\n", minLitres[litresNeeded - i], litresNeeded - i);
				break;
			}
		}
	}
	return 0;
}
