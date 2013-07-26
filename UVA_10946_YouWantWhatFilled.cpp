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
		counter ++;
		visitSurroundings(i+a, j+b);
	}
	a = -1;
	b = 0;
	if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
	{
		visited[i+a][j+b] = true;
		counter ++;
		visitSurroundings(i+a, j+b);
	}
	a = 0;
	b = 1;
	if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
	{
		visited[i+a][j+b] = true;
		counter ++;
		visitSurroundings(i+a, j+b);
	}
	a = 0;
	b = -1;
	if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
	{
		visited[i+a][j+b] = true;
		counter ++;
		visitSurroundings(i+a, j+b);
	}			
}

int main()
{
	int i, j, a, b;
	int testN, potsN, output[10][40000], minIndex, t;
	char temp[100];
	testN = 0;
	scanf("%d %d",&nRows,&nColumns);
	while(nRows != 0 && nColumns != 0)
	{
		gets(temp);
		testN ++;
		for(i=0; i<nRows; i++)
		{
			gets(grid[i]);
			for(j=0; j<nColumns; j++)
			{
				visited[i][j] = false;
			}
		}
		potsN = 0;
		for(i=0; i<nRows; i++)
		{
			for(j=0; j<nColumns; j++)
			{
				if(grid[i][j] != '.' && visited[i][j] == false)
				{
					nowChar = grid[i][j];
					visited[i][j] = true;
					counter = 1;
					a = 1;
					b = 0;
					if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
					{
						visited[i+a][j+b] = true;
						counter ++;
						visitSurroundings(i+a, j+b);
					}
					a = -1;
					b = 0;
					if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
					{
						visited[i+a][j+b] = true;
						counter ++;
						visitSurroundings(i+a, j+b);
					}
					a = 0;
					b = 1;
					if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
					{
						visited[i+a][j+b] = true;
						counter ++;
						visitSurroundings(i+a, j+b);
					}
					a = 0;
					b = -1;
					if(grid[i+a][j+b] == nowChar && visited[i+a][j+b] == false)
					{
						visited[i+a][j+b] = true;
						counter ++;
						visitSurroundings(i+a, j+b);
					}					
					output[0][potsN] = nowChar;
					output[1][potsN] = counter;
					potsN ++;
				}
			}
		}
		printf("Problem %d:\n", testN);
		for(i=0; i<potsN; i++)
		{
			minIndex = i;
			for(j=i; j<potsN; j++)
			{
				if(output[1][j] > output[1][minIndex])
				{
					minIndex = j;
				}
				else if(output[1][j] == output[1][minIndex] && output[0][j] < output[0][minIndex])
				{
					minIndex = j;
				}
			}
			t = output[0][i];
			output[0][i] = output[0][minIndex];
			output[0][minIndex] = t;
			t = output[1][i];
			output[1][i] = output[1][minIndex];
			output[1][minIndex] = t;	
			printf("%c %d\n", output[0][i], output[1][i]);
		}
		scanf("%d %d",&nRows,&nColumns);
	}
	return 0;
}
