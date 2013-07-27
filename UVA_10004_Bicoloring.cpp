#include <stdio.h>
#include <queue>
using namespace std;

int N, edgesN;
int node[500][500], nodesConnected[500], colors[500], flag;
void bicolor(int nodeN, int color)
{
  if(flag == 0)
		return;
		
	if(colors[nodeN] == -1)
	{
		colors[nodeN] = color;
		for(int i=0; i<nodesConnected[nodeN]; i++)
		{
			bicolor(node[nodeN][i], (color+1)%2);
		}
		colors[nodeN] = -1;
	}
	else if(colors[nodeN] != color)
	{
		flag = 0;
		return;
	}
}
int main()
{
	int i, first, second;
	scanf("%d",&N);
	while(N != 0)
	{
		for(i=0; i<N; i++)
		{
			nodesConnected[i] = 0;
			colors[i] = -1;
		}
		scanf("%d",&edgesN);
		for(i=0; i<edgesN; i++)
		{
			scanf("%d %d",&first,&second);
			node[first][nodesConnected[first]] = second;
			nodesConnected[first] ++;
			node[second][nodesConnected[second]] = first;
			nodesConnected[second] ++;
		}
		flag = 1;
		bicolor(0, 0);
		if(flag == 0)
		{
			flag = 1;
			bicolor(0, 1);
		}
		if(flag == 1)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
		scanf("%d",&N);	
	}
	return 0;
}
