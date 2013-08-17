#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <iostream>
using namespace std;
 
int wordsN;
bool visited[25200];
//vector< vector<pair<string, int> > > graph(25200);
pair<string, int> parent[25200];
map<string, int> words;
/*int compare(string f, string s)
{
	int c = 0;
	if(f.length() != s.length())
	{
		return -1;
	}
	else
	{
		for(int i=0; i<f.length(); i++)
		{
			if(c > 1)
			{
				return c;
			}
			if(f[i] != s[i])
			{
				c++;
			}
		}
		return c;
	}
}*/
void bfs(string source, string destination)
{
	int i, l;
	char j;
	string temp;
	pair<string, int> top;
	queue<pair<string, int> > Q;
	int sourceN = words[source], destinationN = words[destination];
	visited[sourceN] = true;
	parent[sourceN] = make_pair(source, sourceN);
	Q.push(make_pair(source, sourceN));
	while(!Q.empty())
	{
		top = Q.front();
		if(top.first == destination)
		{
			return;
		}
		Q.pop();
		for(i=0; i<top.first.length(); i++)
		{
			for(j='a'; j<='z'; j++)
			{
				temp = top.first;
				if(top.first[i] != j)
				{
					temp[i] = j;
					if(words.count(temp) != 0)
					{
						//cout << temp << " " << words[temp] << endl;
						if(visited[words[temp]] == false)
						{
							visited[words[temp]] = true;
							parent[words[temp]] = make_pair(top.first ,top.second);
							Q.push(make_pair(temp, words[temp]));
						}
					}
				}
			}
			/*if(distances[graph[top.second][i].second] == INF)
			{
				distances[graph[top.second][i].second] = distances[top.second] + 1;
				parent[graph[top.second][i].second] = make_pair(top.first ,top.second);
				Q.push(graph[top.second][i]);
			}*/
		}
	}
}
void printPath(int nowNode, string nowWord)
{
	if(parent[nowNode].second == nowNode)
	{
		cout << nowWord << endl;
		return;
	}
	printPath(parent[nowNode].second, parent[nowNode].first);
	cout << nowWord << endl;
}
int main()
{
	int i, j, ww;
	string temp, first, second;
	wordsN = 0;
	getline(cin, temp);
	while(temp[0] != '\0')
	{
		/*for(it=words.begin(); it!=words.end(); it++)
		{
			if(compare(temp, it->first) == 1)
			{
				graph[it->second].push_back(make_pair(temp, wordsN));
				graph[wordsN].push_back(make_pair(it->first, it->second));
			}
		}*/
		words[temp] = wordsN;
		visited[wordsN] = false;
		wordsN ++;
		getline(cin, temp);
	}
	int flag = 0;
	while(cin >> first >> second)
	{
		if(flag == 0)
			flag = 1;
		else
			printf("\n");
		if(words.count(first) != 0 && words.count(second) != 0)
		{
			bfs(first, second);
		}
		if(visited[words[second]] == true)
		{
			printPath(words[second], second);
		}
		else
		{
			printf("No solution.\n");
		}
		for(i=0; i<wordsN; i++)
		{
			visited[i] = false;
		}
	}
	return 0;
}
