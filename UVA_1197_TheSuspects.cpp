#include <stdio.h>
#include <vector>
#include <queue> 
#include <math.h> 
#include <algorithm>
#include <functional>
using namespace std;

typedef pair<int, int> ii;
typedef pair<double, pair<int, int> > dii;
typedef vector<dii> vdii;
int nodesN, parent[40000], rank[40000], size[40000];

int createSet()
{
	for(int i=0; i<nodesN; i++)
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
	}
	else if(rank[firstParent] > rank[secondParent])
	{
		parent[secondParent] = firstParent;
		rank[secondParent] = -1;
		size[firstParent] += size[secondParent];
		size[secondParent] = -1;
	}
	else if(rank[firstParent] == rank[secondParent])
	{
		parent[secondParent] = firstParent;
		rank[firstParent] ++;
		rank[secondParent] = -1;
		size[firstParent] += size[secondParent];
		size[secondParent] = -1;
	}
}
int main()
{
	int testsN, i, groupsN, j, studentsN, temp1, temp2;
	double length;
	scanf("%d %d",&nodesN,&groupsN);
	while(nodesN != 0 || groupsN != 0)
	{
		createSet();
		for(i=0; i<groupsN; i++)
		{
			scanf("%d",&studentsN);
			scanf("%d",&temp1);
			for(j=1; j<studentsN; j++)
			{
				scanf("%d",&temp2);
				mergeSet(temp1, temp2);
			}
		}
		printf("%d\n", size[findSet(0)]);
		scanf("%d %d",&nodesN,&groupsN);
	}
	return 0;
}
