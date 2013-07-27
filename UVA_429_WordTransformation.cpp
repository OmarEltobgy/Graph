#include <stdio.h>
#include <string.h>

int wordsN, minCount, visited[500], graph[500][500], nodesConnected[500];
char words[500][100], first[100], second[100];
int compare(char* f, char* s)
{
	int c = 0;
	if(strlen(f) != strlen(s))
		return -1;
	else
	{
		for(int i=0; i<strlen(f); i++)
		{
			if(f[i] != s[i])
				c++;
		}
		return c;
	}
}
int getIndex(char* str)
{
	for(int i=0; i<wordsN; i++)
	{
		if(compare(words[i], str) == 0)
			return i;
	}
	return -1;
}
void tryy(int now, int counter)
{
	if(compare(words[now], second) == 0)
	{
		if(counter < minCount)
			minCount = counter;
		return;
	}
	for(int i=0; i<nodesConnected[now]; i++)
	{
		if(visited[graph[now][i]] == 0)
		{
			visited[graph[now][i]] = 1;
			tryy(graph[now][i], counter+1);
			visited[graph[now][i]] = 0;
		}
	}
}
int main()
{
	int testN, i, j;
	char temp[200];
	scanf("%d",&testN);
	while(testN--)
	{
		wordsN = 0;
		scanf("%s", words[wordsN]);
		while(words[wordsN][0] != '*')
		{
			visited[wordsN] = 0;
			nodesConnected[wordsN] = 0;
			wordsN ++;
			scanf("%s", words[wordsN]);
		}
		for(i=0; i<wordsN-1; i++)
		{
			for(j=i+1; j<wordsN; j++)
			{
				if(compare(words[i], words[j]) == 1)
				{
					graph[i][nodesConnected[i]] = j;
					nodesConnected[i] ++;
					graph[j][nodesConnected[j]] = i;
					nodesConnected[j] ++;
				}
			}
		}
		if(testN != 0)
		{
			gets(temp);
			gets(temp);
			while(temp[0] != '\0')
			{
				int fi=0, si=0, ww=0;
				while(temp[ww] != ' ')
				{
					first[fi] = temp[ww];
					ww++;
					fi++;
				}
				first[fi] = '\0';
				ww++;
				while(temp[ww] != '\0')
				{
					second[si] = temp[ww];
					ww++;
					si++;
				}
				second[si] = '\0';
				minCount = 100000;
				tryy(getIndex(first), 0);
				printf("%s %s %d\n", first, second, minCount);
				gets(temp);
			}
		}
		else
		{
			while(scanf("%s", first) != EOF)
			{
				scanf("%s", second);
				minCount = 100000;
				tryy(getIndex(first), 0);
				printf("%s %s %d\n", first, second, minCount);
			}
		}
		if(testN != 0)
			printf("\n");
	}
	return 0;
}
