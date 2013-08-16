#include <stdio.h>
#include <vector>
#include <queue> 
#include <math.h> 
#include <algorithm>
#include <functional>
using namespace std;

int nodesN, parent[60000], rank[60000], size[60000], result;

int createSet()
{
	for(int i=1; i<=nodesN; i++)
	{
		parent[i] = i;
		rank[i] = 1;
		size[i] = 1;
	}
}
int findSet(int node)
{
	if(parent[node] == node)
	{
		return node;
	}
	return parent[node] = findSet(parent[node]);
}
void mergeSet(int first, int second)
{
	int firstParent = findSet(first);
	int secondParent = findSet(second);
	if(firstParent == secondParent)
	{
		return;
	}
	if(rank[firstParent] < rank[secondParent])
	{
		parent[firstParent] = secondParent;
		rank[firstParent] = -1;
		size[secondParent] += size[firstParent];
		size[firstParent] = -1;
		result --;
	}
	else if(rank[firstParent] > rank[secondParent])
	{
		parent[secondParent] = firstParent;
		rank[secondParent] = -1;
		size[firstParent] += size[secondParent];
		size[secondParent] = -1;
		result --;
	}
	else if(rank[firstParent] == rank[secondParent])
	{
		parent[secondParent] = firstParent;
		rank[firstParent] ++;
		rank[secondParent] = -1;
		size[firstParent] += size[secondParent];
		size[secondParent] = -1;
		result --;
	}
}
int main()
{
	int edgesN, i, first, second, counter=0;
	scanf("%d %d",&nodesN,&edgesN);
	while(nodesN != 0 || edgesN != 0)
	{
		counter ++;
		createSet();
		result = nodesN;
		for(i=0; i<edgesN; i++)
		{
			scanf("%d %d",&first,&second);
			mergeSet(first, second);
		}
		printf("Case %d: %d\n", counter, result);
		scanf("%d %d",&nodesN,&edgesN);
	}
	return 0;
}
