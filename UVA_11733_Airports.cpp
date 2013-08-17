#include <stdio.h>
#include <vector>
#include <queue> 
#include <math.h> 
#include <algorithm>
#include <functional>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<iii> viii;
int nodesN, parent[40000], rank[40000], size[40000], airportCost;
viii edgeList;

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
int mergeSet(int first, int second)
{
	int firstParent = findSet(first);
	int secondParent = findSet(second);
	if(firstParent == secondParent)
	{
		return 0;
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
	return 1;
}
int main()
{
	int edgesN, i, first, second, weight, testsN, counter, cost, tt=0;
	scanf("%d",&testsN);
	while(testsN --)
	{
		tt ++;
		scanf("%d %d %d",&nodesN,&edgesN,&airportCost);
		createSet();
		for(i=0; i<edgesN; i++)
		{
			scanf("%d %d %d",&first,&second,&weight);
			if(weight < airportCost)
			{
				edgeList.push_back(iii(weight, ii(first, second)));
			}
		}
		sort(edgeList.begin(), edgeList.end());
		counter = nodesN;
		cost = 0;
		for(i=0; i<edgeList.size(); i++)
		{
			if(mergeSet(edgeList[i].second.first, edgeList[i].second.second) == 1)
			{
				cost += edgeList[i].first;
				counter --;
			}
		}
		cost += (counter*airportCost);
		printf("Case #%d: %d %d\n", tt, cost, counter);
		edgeList.clear();
	}
	return 0;
}
