#include <stdio.h>
#include <vector>
#include <queue> 
#include <math.h> 
#include <iostream>
#include <functional>
#include <map>
#include <string>
using namespace std;

int nodesN, parent[40000], rank[40000], size[40000], max2;
map<string, int> names;
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
		max2 = max(max2, size[secondParent]);
	}
	else if(rank[firstParent] > rank[secondParent])
	{
		parent[secondParent] = firstParent;
		rank[secondParent] = -1;
		size[firstParent] += size[secondParent];
		size[secondParent] = -1;
		max2 = max(max2, size[firstParent]);
	}
	else if(rank[firstParent] == rank[secondParent])
	{
		parent[secondParent] = firstParent;
		rank[firstParent] ++;
		rank[secondParent] = -1;
		size[firstParent] += size[secondParent];
		size[secondParent] = -1;
		max2 = max(max2, size[firstParent]);
	}
}
int main()
{
	int edgesN, i;
	string temp, first, second;
	scanf("%d %d",&nodesN,&edgesN);
	while(nodesN != 0 || edgesN != 0)
	{
		createSet();
		for(i=0; i<nodesN; i++)
		{
			cin >> temp;
			names[temp] = i;
		}
		max2 = 1;
		for(i=0; i<edgesN; i++)
		{
			cin >> first >> second;
			mergeSet(names[first], names[second]);
		}
		printf("%d\n", max2);
		scanf("%d %d",&nodesN,&edgesN);
		names.clear();
	}
	return 0;
}
