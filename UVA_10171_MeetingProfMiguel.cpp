#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

char MMM[600], nodesN;
int find(char X)
{
	for(int i=0; i<nodesN; i++)
	{
		if(MMM[i] == X)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int roadsN, i, j, k, adjMatY[500][500], adjMatM[500][500];
	int weight, firstN, secondN, INF=1000000, min2;
	char age, direction, first, second;
	vector<char> best;
	scanf("%d",&roadsN);
	while(roadsN != 0)
	{
		for(i=0; i<500; i++)
		{
			for(j=0; j<500; j++)
			{
				adjMatY[i][j] = INF;
				adjMatM[i][j] = INF;
			}
			adjMatY[i][i] = 0;
			adjMatM[i][i] = 0;
		}
		nodesN = 0;
		for(i=0; i<roadsN; i++)
		{
			char temp = getchar();
			scanf("%c %c %c %c %d",&age,&direction,&first,&second,&weight);
			//printf("%c %c %c %c %d\n",age,direction,first,second,weight);
			firstN = find(first);
			if(firstN == -1)
			{
				MMM[nodesN] = first;
				firstN = nodesN;
				nodesN ++;
			}
			secondN = find(second);
			if(secondN == -1)
			{
				MMM[nodesN] = second;
				secondN = nodesN;
				nodesN ++;
			}
			if(age == 'Y')
			{
				adjMatY[firstN][secondN] = min(adjMatY[firstN][secondN], weight);
				if(direction == 'B')
				{
					adjMatY[secondN][firstN] = min(adjMatY[secondN][firstN], weight);
				}
			}
			else if(age == 'M')
			{
				adjMatM[firstN][secondN] = min(adjMatM[firstN][secondN], weight);
				if(direction == 'B')
				{
					adjMatM[secondN][firstN] = min(adjMatM[secondN][firstN], weight);
				}
			}
		}
		for(k=0; k<nodesN; k++)
		{
			for(i=0; i<nodesN; i++)
			{
				for(j=0; j<nodesN; j++)
				{
					adjMatY[i][j] = min(adjMatY[i][j], adjMatY[i][k]+adjMatY[k][j]);
					adjMatM[i][j] = min(adjMatM[i][j], adjMatM[i][k]+adjMatM[k][j]);
				}
			}
		}
		getchar();
		scanf("%c %c",&first,&second);
		firstN = find(first);
		secondN = find(second);
		if(firstN == -1 && secondN == -1 && first == second)
		{
			printf("0 %c\n", first);
		}
		else if(firstN == -1 || secondN == -1)
		{
			printf("You will never meet.\n");
		}
		else
		{
			min2 = INF;
			for(i=0; i<nodesN; i++)
			{
				if(adjMatY[firstN][i] + adjMatM[secondN][i] < min2)
				{
					min2 = adjMatY[firstN][i] + adjMatM[secondN][i];
					best.clear();
					best.push_back(MMM[i]);
				}
				else if(adjMatY[firstN][i] + adjMatM[secondN][i] == min2)
				{
					best.push_back(MMM[i]);
				}
			}
			sort(best.begin(), best.end());
			if(min2 == INF)
			{
				printf("You will never meet.\n");
			}
			else
			{
				printf("%d", min2);
				for(i=0; i<best.size(); i++)
				{
					printf(" %c", best[i]);
				}
				printf("\n");
			}
		}
		best.clear();
		scanf("%d",&roadsN);
	}
	return 0;
}
