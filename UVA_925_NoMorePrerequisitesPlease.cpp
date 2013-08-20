#include <stdio.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int testsN, tt, i, j, k, NINF=-1000000, nodesN, nowN;
	int adjMat[200][200], edgesN, NN, firstN, secondN;
	string first, second, now, MM[200];
	vector<string> result;
	map<string, int> M;
	scanf("%d",&testsN);
	for(tt=0; tt<testsN; tt++)
	{
		scanf("%d",&nodesN);
		for(i=0; i<nodesN; i++)
		{
			cin >> first;
			M[first] = i;
			MM[i] = first;
			for(j=0; j<nodesN; j++)
			{
				adjMat[i][j] = NINF;
			}
			adjMat[i][i] = 0;
		}
		scanf("%d",&edgesN);
		for(i=0; i<edgesN; i++)
		{
			cin >> first;
			firstN = M[first];
			scanf("%d",&NN);
			for(j=0; j<NN; j++)
			{
				cin >> second;
				secondN = M[second];
				adjMat[firstN][secondN] = 1;
			}
		}
		for(k=0; k<nodesN; k++)
		{
			for(i=0; i<nodesN; i++)
			{
				for(j=0; j<nodesN; j++)
				{
					adjMat[i][j] = max(adjMat[i][j], adjMat[i][k]+adjMat[k][j]);
				}
			}
		}
		map<string, int>::iterator it;
		for(it=M.begin(); it!=M.end(); it++)
		{
			now = it->first;
			nowN = it->second;
			result.clear();
			for(i=0; i<nodesN; i++)
			{
				if(adjMat[nowN][i] == 1)
				{
					result.push_back(MM[i]);
				}
			}
			if(result.size() != 0)
			{
				sort(result.begin(), result.end());
				cout << now << " " << result.size();
				for(i=0; i<result.size(); i++)
				{
					cout << " " << result[i];
				}
				printf("\n");
			}
		}
		result.clear();
		M.clear();	
	}
	return 0;
}
