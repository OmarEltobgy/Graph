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
int nodesN, parent[1000], rank[1000], size[1000], airportCost, place[1000][1000];
vdii edgeList;

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
	int i, testsN, satN, j, counter;
	double length, min;
	scanf("%d",&testsN);
	while(testsN --)
	{
		scanf("%d %d",&satN,&nodesN);
		createSet();
		for(i=1; i<=nodesN; i++)
		{
			scanf("%d %d",&place[i][0],&place[i][1]);
			for(j=1; j<i; j++)
			{
				length = sqrt(pow(abs(place[i][0]-place[j][0]), 2) + pow(abs(place[i][1]-place[j][1]), 2));
				edgeList.push_back(dii(length, ii(i, j)));
			}
		}
		sort(edgeList.begin(), edgeList.end());
		counter = nodesN;
		for(i=0; i<edgeList.size()&&counter>satN; i++)
		{
			if(mergeSet(edgeList[i].second.first, edgeList[i].second.second) == 1)
			{
				min = edgeList[i].first;
				counter --;
			}
		}
		printf("%.2lf\n", min);
		edgeList.clear();
	}
	return 0;
}
