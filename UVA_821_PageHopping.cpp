#include <stdio.h>

int main()
{
	int first, second, flag1=1, flag2=1, graph[200][200], i, j, k, INF=10000000, number, sum, tt=0, pairsN;
	bool isTaken[200];
	double average;
	scanf("%d %d",&flag1,&flag2);
	while(flag1 != 0 || flag2 != 0)
	{
		tt ++;
		for(i=1; i<=100; i++)
		{
			isTaken[i] = false;
			for(j=1; j<=100; j++)
			{
				if(i == j)
				{
					graph[i][j] = 0;
				}
				else
				{
					graph[i][j] = INF;
				}
			}
		}
		first = flag1;
		second = flag2;
		number = 0;
		sum = 0;
		while(first != 0 || second != 0)
		{
			graph[first][second] = 1;
			sum ++;
			if(isTaken[first] == false)
			{
				number ++;
				isTaken[first] = true;
			}
			if(isTaken[second] == false)
			{
				number ++;
				isTaken[second] = true;
			}
			scanf("%d %d",&first,&second);
		}
		for(k=1; k<=100; k++)
		{
			for(i=1; i<=100; i++)
			{
				for(j=1; j<=100; j++)
				{
					if(graph[i][k] + graph[k][j] < graph[i][j])
					{
						if(graph[i][j] != INF)
						{
							sum -= graph[i][j];
						}
						sum += graph[i][k] + graph[k][j];
						graph[i][j] = graph[i][k] + graph[k][j];
					}
				}
			}
		}
		int tempSum = 0;
		pairsN = number * (number-1);
		average = (double)sum / pairsN;
		printf("Case %d: average length between pages = %.3lf clicks\n", tt, average);
		scanf("%d %d",&flag1,&flag2);
	}
}
