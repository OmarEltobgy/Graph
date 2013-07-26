#include <stdio.h>

bool grid[200][200], visited[200][200];
int N;

void visitSurroundings(int i, int j)
{
	int a, b;
	for(a=-1; a<=1; a++)
	{
		for(b=-1; b<=1; b++)
		{
			if((a!=0 || b!=0) && i+a>=0 && j+b>=0 && i+a<N && j+b<N)
			{
				if(grid[i+a][j+b] == true && visited[i+a][j+b] == false)
				{
					visited[i+a][j+b] = true;
					visitSurroundings(i+a, j+b);
				}
			}
		}
	}
}

int main()
{
	int i, j, a, b;
	int counter, testN;
	char temp[200];
	testN = 0;
	while(scanf("%d",&N) != EOF)
	{
		testN ++;
		gets(temp);
		for(i=0; i<N; i++)
		{
			gets(temp);
			for(j=0; j<N; j++)
			{
				if(temp[j] == '0')
				{
					grid[i][j] = false;
				}
				else if(temp[j] == '1')
				{
					grid[i][j] = true;
					visited[i][j] = false;
				}
				else
				{
					printf("7omar\n");
				}
			}
		}
		counter = 0;
		for(i=0; i<N; i++)
		{
			for(j=0; j<N; j++)
			{
				if(grid[i][j] == true && visited[i][j] == false)
				{
					counter ++;
					visited[i][j] = true;
					for(a=-1; a<=1; a++)
					{
						for(b=-1; b<=1; b++)
						{
							if((a!=0 || b!=0) && i+a>=0 && j+b>=0 && i+a<N && j+b<N)
							{
								if(grid[i+a][j+b] == true && visited[i+a][j+b] == false)
								{
									visited[i+a][j+b] = true;
									visitSurroundings(i+a, j+b);
								}
							}
						}
					}
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n", testN, counter);
	}
	return 0;
}
