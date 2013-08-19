#include <stdio.h>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	int testsN, tt, i, j, k, edgesN2, edgesN1, isSame, nodesN;
	char first, second;
	bool canReach1[1000][1000], canReach2[1000][1000];
	map<char, int> M;
	scanf("%d",&testsN);
	for(tt=1; tt<=testsN; tt++)
	{
		nodesN = 0;
		isSame = true;
		scanf("%d",&edgesN1);
		for(i=0; i<1000; i++)
		{
			for(j=0; j<1000; j++)
			{
				canReach1[i][j] = false;
			}
			canReach1[i][i] = true;
		}
		for(i=0; i<edgesN1; i++)
		{
			getchar();
			scanf("%c %c",&first,&second);
			//printf("%c %c\n",first,second);
			if(M.count(first) == 0)
			{
				M[first] = nodesN;
				nodesN ++;
			}
			if(M.count(second) == 0)
			{
				M[second] = nodesN;
				nodesN ++;
			}
			canReach1[M[first]][M[second]] = true;
			canReach1[M[second]][M[first]] = true;
		}
		
		scanf("%d",&edgesN2);
		for(i=0; i<1000; i++)
		{
			for(j=0; j<1000; j++)
			{
				canReach2[i][j] = false;
			}
			canReach2[i][i] = true;
		}
		for(i=0; i<edgesN2; i++)
		{
			getchar();
			scanf("%c %c",&first,&second);
			//printf("%c %c\n",first,second);
			if(M.count(first) == 0)
			{
				M[first] = nodesN;
				nodesN ++;
				isSame = false;
			}
			if(M.count(second) == 0)
			{
				M[second] = nodesN;
				nodesN ++;
				isSame = false;
			}
			canReach2[M[first]][M[second]] = true;
			canReach2[M[second]][M[first]] = true;
		}
		
		if(isSame == true)
		{
			for(k=0; k<nodesN; k++)
			{
				for(i=0; i<nodesN; i++)
				{
					for(j=0; j<nodesN; j++)
					{
						canReach1[i][j] = canReach1[i][j] | (canReach1[i][k] & canReach1[k][j]);
						canReach2[i][j] = canReach2[i][j] | (canReach2[i][k] & canReach2[k][j]);
					}
				}
			}
		}
		
		for(i=0; i<nodesN && isSame ==true; i++)
		{
			for(j=0; j<nodesN && isSame ==true; j++)
			{
				if(canReach1[i][j] != canReach2[i][j])
				{
					isSame = false;
				}
			}
		}
		if(isSame == true)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		if(tt != testsN)
		{
			printf("\n");
		}
		M.clear();
	}
}
