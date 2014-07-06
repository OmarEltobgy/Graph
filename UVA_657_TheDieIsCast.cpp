#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int width, height;
string grid[100];
int visited[100][100]; // for '.' and 'X'
int visited2[100][100];// for 'X' only
// the fifth coordinate 0, 0 because if we encountered X we will call the method with type 01
// so we need to call it again with type 2 
int dx[] = {0,  0, 1, -1, 0};
int dy[] = {1, -1, 0,  0, 0};
int nowNumber;
vector<int> dotsN;

void dfs(int x, int y, int type) // type = 1 '*' or 'X' / type = 2 'X'
{
    if(type == 1)
    {
        visited[x][y] = true;
    }
    if(type == 2)
    {
        visited2[x][y] = true;
    }

    for(int i=0; i<5; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(newX >=0 && newX < height && newY >= 0 && newY < width)
        {
            if(type == 1 && visited[newX][newY] == false && grid[newX][newY] != '.')
            {
                dfs(newX, newY, 1);
            }
            if(visited2[newX][newY] == false && grid[newX][newY] == 'X')
            {
                dfs(newX, newY, 2);
                if(type == 1)
                {
                    nowNumber ++;
                }
            }
        }
    }
}

int main()
{
    cin >> width >> height;
    int nowTest = 1;
    while(width != 0 || height != 0)
    {
        dotsN.clear();

        for(int i=0; i<height; i++)
        {
            cin >> grid[i];
            for(int j=0; j<width; j++)
            {
                visited[i][j] = false;
                visited2[i][j] = false;
            }
        }

        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                //cout << grid[i][j] << " ";
                if(visited[i][j] == false && grid[i][j] != '.')
                {
                    nowNumber = 0;
                    dfs(i, j, 1);
                    if(nowNumber != 0)
                    {
                        dotsN.push_back(nowNumber);
                        //cout << nowNumber << endl;
                    }
                }
            }
            //cout << endl;
        }

        sort(dotsN.begin(), dotsN.end());

        cout << "Throw " << nowTest << endl;
        for(int i=0; i<dotsN.size(); i++)
        {
            cout << dotsN[i];

            if(i != dotsN.size()-1)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
        cout << endl;

        cin >> width >> height;
        nowTest ++;
    }
    return 0;
}
