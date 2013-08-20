#include <stdio.h>
#include <vector>
#include <map> 
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int events[500], adjMat[500][500];
string MMM[500];
map<string, int> M;
int main()
{
	int NC, i, j, k, NE, nodesN, NNN, INF=1000000, NM, count, tt=0;
	string temp, temp2, result[2][2];
	for(i=0; i<500; i++)
	{
		for(j=0; j<500; j++)
		{
			adjMat[i][j] = INF;
		}
		adjMat[i][i] = 0;
	}
	scanf("%d",&NC);
	getchar();
	while(NC != 0)
	{
		tt++;
		nodesN = 0;
		for(i=0; i<NC; i++)
		{
			scanf("%d",&NE);
			for(j=0; j<NE; j++)
			{
				cin >> temp;
				//cout << temp << endl;
				if(M.count(temp) == 0)
				{
					M[temp] = nodesN;
					MMM[nodesN] = temp;
					NNN = nodesN;
					nodesN ++;
				}
				else
				{
					NNN = M[temp];
				}
				events[j] = NNN;
				for(k=0; k<j; k++)
				{
					adjMat[events[k]][events[j]] = j-k;
					//adjMat[events[j]][events[k]] = k-j;
				}
			}
		}
		scanf("%d",&NM);
		getchar();
		for(i=0; i<NM; i++)
		{
			cin >> temp >> temp2;
			//cout << temp << temp2 << endl;
			adjMat[M[temp]][M[temp2]] = 1;
			//adjMat[M[temp2]][M[temp]] = -1;
		}
		for(k=0; k<nodesN; k++)
		{
			for(i=0; i<nodesN; i++)
			{
				for(j=0; j<nodesN; j++)
				{
					adjMat[i][j] = min(adjMat[i][j], adjMat[i][k]+adjMat[k][j]);
				}
			}
		}
		count = 0;
		for(i=0; i<nodesN; i++)
		{
			for(j=i+1; j<nodesN; j++)
			{
				if(adjMat[i][j] == INF && adjMat[j][i] == INF)
				{
					if(count < 2)
					{
						result[count][0] = MMM[i];
						result[count][1] = MMM[j];
					}
					count ++;
					//printf("INF ");
				}
				/*else if(adjMat[i][j] == INF || adjMat[i][j] == INF)
				{
					printf("CAN ");
				}
				else
				{
					printf("%3d ",adjMat[i][j]);
				}*/
			}
			//printf("\n");
		}
		if(count == 0)
		{
			printf("Case %d, no concurrent events.\n", tt);
		}
		else
		{
			printf("Case %d, %d concurrent events:\n", tt, count);
			if(count >= 2)
			{
				cout <<"(" << result[0][0] << "," << result[0][1] << ") (" << result[1][0] << "," << result[1][1] << ") " << endl; 
			}
			else
			{
				cout <<"(" << result[0][0] << "," << result[0][1] << ") " << endl;
			}
		}
		M.clear();
		for(i=0; i<nodesN; i++)
		{
			for(j=0; j<nodesN; j++)
			{
				adjMat[i][j] = INF;
			}
			adjMat[i][i] = 0;
		}
		scanf("%d",&NC);
	}
	return 0;
}
