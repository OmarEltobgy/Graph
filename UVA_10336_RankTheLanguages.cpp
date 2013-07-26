#include <stdio.h>

char grid[500][500], nowChar, counter;
bool visited[500][500];
int nRows, nColumns;

void visitSurroundings(int i, int j)
{
  int a, b;
	a = 1;
	b = 0;
	if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
	{
		visited[i+a][j+b] = true;
		visitSurroundings(i+a, j+b);
	}
	a = -1;
	b = 0;
	if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
	{
		visited[i+a][j+b] = true;
		visitSurroundings(i+a, j+b);
	}
	a = 0;
	b = 1;
	if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
	{
		visited[i+a][j+b] = true;
		visitSurroundings(i+a, j+b);
	}
	a = 0;
	b = -1;
	if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
	{
		visited[i+a][j+b] = true;
		visitSurroundings(i+a, j+b);
	}			
}

int main()
{
	int i, j, a, b;
	int worldN, output[30][2], minIndex, testN;
	char temp[100];
	worldN = 0;
	scanf("%d",&testN);
	while(testN--)
	{
		scanf("%d %d",&nRows,&nColumns);
		gets(temp);
		worldN ++;
		for(i=0; i<30; i++)
		{
			output[i][0] = 0;
			output[i][1] = 0;
		}
		for(i=0; i<nRows; i++)
		{
			gets(grid[i]);
			for(j=0; j<nColumns; j++)
			{
				visited[i][j] = false;
			}
		}
		for(i=0; i<nRows; i++)
		{
			for(j=0; j<nColumns; j++)
			{
				if(visited[i][j] == false)
				{
					nowChar = grid[i][j];
					visited[i][j] = true;
					a = 1;
					b = 0;
					if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
					{
						visited[i+a][j+b] = true;
						visitSurroundings(i+a, j+b);
					}
					a = -1;
					b = 0;
					if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
					{
						visited[i+a][j+b] = true;
						visitSurroundings(i+a, j+b);
					}
					a = 0;
					b = 1;
					if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
					{
						visited[i+a][j+b] = true;
						visitSurroundings(i+a, j+b);
					}
					a = 0;
					b = -1;
					if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
					{
						visited[i+a][j+b] = true;
						visitSurroundings(i+a, j+b);
					}					
					output[nowChar-'a'][0] ++;  
				}
			}
		}
		printf("World #%d\n", worldN);
		for(i=0; i<30; i++)
		{
			minIndex = 0;
			while(output[minIndex][1] == 1)
			{
				minIndex++;
			}
			for(j=0; j<30; j++)
			{
				if(output[j][1] == 0 && output[j][0] > output[minIndex][0])
				{
					minIndex = j;
				}
			}
			if(output[minIndex][0] == 0)
			{
				break;
			}
			else
			{
				printf("%c: %d\n", minIndex+'a', output[minIndex][0]);
				output[minIndex][1] = 1;
			}
		}
	}
	return 0;
}
