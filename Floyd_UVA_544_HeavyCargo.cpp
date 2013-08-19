#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int nodesN, rank[300], size[300], minimax[300], parent[300], INF = 1000000;
vector<vector<pair<int, int> > > adjList;
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
void bfs(int source, int destination)
{
	queue<int> Q;
	Q.push(source);
	minimax[source] = INF;
	while(!Q.empty())
	{
		int top = Q.front();
		Q.pop();
		if(top == destination)
		{
			minimax[source] = 0;
			return;
		}
		for(int i=0; i<adjList[top].size(); i++)
		{
			if(minimax[adjList[top][i].second] == INF)
			{
				Q.push(adjList[top][i].second);
				minimax[adjList[top][i].second] = min(minimax[top], adjList[top][i].first);
			}
		}
	}
	minimax[source] = 0;
}
int main()
{
	int edgesN, i, j, source, destination, weight, counter, tt=0, flag=0;
	vector<pair<int, pair<int, int> > > edgeList;
	map <string, int> graph;
	string first, second;
	scanf("%d %d",&nodesN, &edgesN);
	while(nodesN != 0 || edgesN != 0)
	{
		tt ++;
		createSet();
		edgeList.resize(edgesN);
		adjList.resize(nodesN);
		j = 0;
		for(i=0; i<edgesN; i++)
		{
			cin >> first >> second >> weight;
			if(graph.count(first) == 0)
			{
				graph[first] = j;
				minimax[j] = INF;
				j ++;
			}
			if(graph.count(second) == 0)
			{
				graph[second] = j;
				minimax[j] = INF;
				j ++;
			}
		//	cout << first << " " << graph[first] << " " << second << " " << graph[second] << endl;
			edgeList[i] = make_pair(weight, make_pair(graph[first], graph[second]));
		}
		sort(edgeList.begin(), edgeList.end());
		counter = nodesN;
		for(i=edgesN-1; i>=0 && counter>1; i--)
		{
			if(mergeSet(edgeList[i].second.first, edgeList[i].second.second) == 1)
			{
				adjList[edgeList[i].second.first].push_back(make_pair(edgeList[i].first, edgeList[i].second.second));
				adjList[edgeList[i].second.second].push_back(make_pair(edgeList[i].first, edgeList[i].second.first));
				counter --;
			}
		}
		cin >> first >> second;
		source = graph[first];
		destination = graph[second];
		bfs(source, destination);
		printf("Scenario #%d\n%d tons\n\n", tt, minimax[destination]);
		graph.clear();
		edgeList.clear();
		for(i=0; i<nodesN; i++)
		{
			adjList[i].clear();
		}
		adjList.clear();
		scanf("%d %d",&nodesN, &edgesN);
	}
	return 0;
}
