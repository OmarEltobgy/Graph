#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

int isForbidden[100000], firstN, secondN, distances[100000];
void bfs()
{
	queue<int> Q;
	int parent, digit, i, child, parentTemp;
	if(isForbidden[firstN] == 0)
	{
		Q.push(firstN);
		distances[firstN] = 0;
	}
	while(!Q.empty())
	{
		parent = Q.front();
		parentTemp = parent;
		if(parent == secondN)
			return;
		Q.pop();
		for(i=0; i<4; i++)
		{
			digit = parentTemp % 10;
			// Increasing
			if(digit != 9)
			{
				child = parent + ceil(pow(10, i));
			}	
			else
			{
				child = parent - 9*ceil(pow(10, i));
			}
			if(distances[child] == -1 && isForbidden[child] == 0)
			{
				Q.push(child);
				distances[child] = distances[parent] + 1;
			}
			// Decreasing
			if(digit != 0)
			{
				child = parent - ceil(pow(10, i));
			}
			else
			{
				child = parent + 9*ceil(pow(10, i));
			}
			if(distances[child] == -1 && isForbidden[child] == 0)
			{
				Q.push(child);
				distances[child] = distances[parent] + 1;
			}
			parentTemp = parentTemp / 10;
		}
	}
}
int main()
{
	int testN, temp, tt, i, tempN, forbiddenN;
	scanf("%d",&testN);
	for(i=0; i<100000; i++)
	{
		isForbidden[i] = 0;
		distances[i] = -1;
	}
	for(tt=0; tt<testN; tt++)
	{
		firstN = 0;
		secondN = 0;
		for(i=0; i<4; i++)
		{
			scanf("%d",&temp);
			firstN += temp*ceil(pow(10, 4-i-1));
		}
		for(i=0; i<4; i++)
		{
			scanf("%d",&temp);
			secondN += temp*ceil(pow(10, 4-i-1));
		}
		scanf("%d",&forbiddenN);
		for(int j=0; j<forbiddenN; j++)
		{
			tempN = 0;
			for(i=0; i<4; i++)
			{
				scanf("%d",&temp);
				tempN += temp*ceil(pow(10, 4-i-1));
			}
			isForbidden[tempN] = 1;
		}
		bfs();
		printf("%d\n", distances[secondN]);
		for(i=0; i<100000; i++)
		{
			isForbidden[i] = 0;
			distances[i] = -1;
		}
	}
}
