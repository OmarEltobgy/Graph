#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

typedef pair<int, int> ii;
typedef pair<double, pair<int, int> > dii;
typedef vector<dii> vdii;
int nodesN, parent[300000], rank[300000], size[300000];
map<string, int> graph;

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
	int testsN, i, NN, firstN, secondN;
	string first, second;
	scanf("%d",&testsN);
	while(testsN --)
	{
		scanf("%d",&NN);
		nodesN = 0;
		for(i=0; i<NN; i++)
		{
			cin >> first >> second;
			if(graph.count(first) == 0)
			{
				graph[first] = nodesN;
				firstN = nodesN;
				parent[firstN] = firstN;
				rank[firstN] = 1;
				size[firstN] = 1;
				nodesN ++;
			}
			else
			{
				firstN = graph[first];
			}
			if(graph.count(second) == 0)
			{
				graph[second] = nodesN;
				secondN = nodesN;
				parent[secondN] = secondN;
				rank[secondN] = 1;
				size[secondN] = 1;
				nodesN ++;
			}
			else
			{
				secondN = graph[second];
			}
			mergeSet(firstN, secondN);
			printf("%d\n", size[findSet(firstN)]);
		}
		graph.clear();
	}
	return 0;
}
