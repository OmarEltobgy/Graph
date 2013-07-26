#include <stdio.h>

bool grid[200][200], visited[200][200];
int nRows, nColumns;

void visitSurroundings(int i, int j)
{
	int a, b;
	for(a=-1; a<=1; a++)
	{
		for(b=-1; b<=1; b++)
		{
			if((a!=0 || b!=0) && i+a>=0 && j+b>=0 && i+a<nRows && j+b<nColumns)
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
	int counter;
	char temp[200];
	scanf("%d %d",&nRows,&nColumns);
	gets(temp);
	while(nRows != 0)
	{
		for(i=0; i<nRows; i++)
		{
			gets(temp);
			for(j=0; j<nColumns; j++)
			{
				if(temp[j] == '*')
				{
					grid[i][j] = false;
				}
				else if(temp[j] == '@')
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
		for(i=0; i<nRows; i++)
		{
			for(j=0; j<nColumns; j++)
			{
				if(grid[i][j] == true && visited[i][j] == false)
				{
					counter ++;
					visited[i][j] = true;
					for(a=-1; a<=1; a++)
					{
						for(b=-1; b<=1; b++)
						{
							if((a!=0 || b!=0) && i+a>=0 && j+b>=0 && i+a<nRows && j+b<nColumns)
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
		printf("%d\n", counter);
		scanf("%d %d",&nRows,&nColumns);
		gets(temp);
	}
	return 0;
}
