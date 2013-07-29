#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

char maze[100][100][100];
int distances[100][100][100];
int L, R, C, s1, s2, s3, e1, e2, e3;
queue<pair<int,pair<int,int> > > Q;
void solve(int i, int j, int k)
{
  distances[i][j][k] = 0;
	Q.push(make_pair(i, make_pair(j, k)));
	while(!Q.empty())
	{
		i = Q.front().first;
		j = Q.front().second.first;
		k = Q.front().second.second;
		Q.pop();
		if(i==e1 && j==e2 && k==e3)
			return;
		//i+1 & j   & k
		if(i+1 < L && maze[i+1][j][k] != '#' && distances[i+1][j][k] == 100000)
		{
			distances[i+1][j][k] = distances[i][j][k]+1;
			Q.push(make_pair(i+1, make_pair(j, k)));
		}
		//i-1 & j   & k
		if(i-1 >= 0 && maze[i-1][j][k] != '#' && distances[i-1][j][k] == 100000)
		{
			distances[i-1][j][k] = distances[i][j][k]+1;
			Q.push(make_pair(i-1, make_pair(j, k)));
		}
		//i   & j+1 & k
		if(j+1 < R && maze[i][j+1][k] != '#' && distances[i][j+1][k] == 100000)
		{
			distances[i][j+1][k] = distances[i][j][k]+1;
			Q.push(make_pair(i, make_pair(j+1, k)));
		}
		//i   & j-1 & k
		if(j-1 >= 0 && maze[i][j-1][k] != '#' && distances[i][j-1][k] == 100000)
		{
			distances[i][j-1][k] = distances[i][j][k]+1;
			Q.push(make_pair(i, make_pair(j-1, k)));
		}
		//i   & j   & k+1
		if(k+1 < C && maze[i][j][k+1] != '#' && distances[i][j][k+1] == 100000)
		{
			distances[i][j][k+1] = distances[i][j][k]+1;
			Q.push(make_pair(i, make_pair(j, k+1)));
		}
		//i   & j   & k-1
		if(k-1 >= 0 && maze[i][j][k-1] != '#' && distances[i][j][k-1] == 100000)
		{
			distances[i][j][k-1] = distances[i][j][k]+1;
			Q.push(make_pair(i, make_pair(j, k-1)));
		}
	}
}
int main()
{
	int i, j, k;
	char temp;
	while(scanf("%d %d %d",&L,&R,&C))
	{
		if(L==0 && R==0 && C==0)
			break;
		scanf("%c",&temp);
		for(i=0; i<L; i++)
		{
			for(j=0; j<R; j++)
			{
				for(k=0; k<C; k++)
				{
					scanf("%c",&maze[i][j][k]);
					if(maze[i][j][k] == 'S')
					{
						s1 = i;
						s2 = j;
						s3 = k;
					}
					else if(maze[i][j][k] == 'E')
					{
						e1 = i;
						e2 = j;
						e3 = k;
					}
					distances[i][j][k] = 100000;
				}
				scanf("%c",&temp);
			}
			scanf("%c",&temp);
		}
		while(!Q.empty())
		{
			Q.pop();
		}
		solve(s1, s2, s3);
		if(distances[e1][e2][e3] == 100000)
		{
			printf("Trapped!\n");
		}
		else
		{
			printf("Escaped in %d minute(s).\n", distances[e1][e2][e3]);
		}
	}
}
