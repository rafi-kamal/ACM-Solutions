/*
Algorithm: BFS/DFS

This is an straight forward problem of DFS/BFS
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <utility>

#define SIZE 25
#define MOD 20071027

#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))

using namespace std;

char grid[SIZE][SIZE];
bool visited[SIZE][SIZE];
int row, column, n;

int X[] = {0, 1, 0, -1};
int Y[] = {-1, 0, 1, 0};
void dfs(int x, int y)
{
	for(int i = 0; i < 4; i++)
	{
		if(BOUNDARY(x+X[i], y+Y[i]) && grid[x+X[i]][y+Y[i]] == '.' && !visited[x+X[i]][y+Y[i]])
		{
			visited[x+X[i]][y+Y[i]] = true;
			n++;
			dfs(x+X[i], y+Y[i]);
		}
	}
}

int main()
{
	int tc, t = 0, i, j, k, m, mx = 0, x, y, q, value, node;
	char ch;
	long long sum = 0;
	
	//freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	
	for(t = 1; t <= tc; t++)
	{
		scanf("%d %d", &column, &row);
		memset(visited, 0, sizeof visited);
		
		getchar();
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < column; j++)
			{
				grid[i][j] = getchar();
				if(grid[i][j] == '@')
				{
					x = i;
					y = j;
					visited[x][y] = true;
				}
			}
			getchar();
		}
		
		n = 1;
		dfs(x, y);
		
		printf("Case %d: %d\n", t, n);
	}
	
	
	return 0;
}

/*
Solution submitted by: Rafi Kamal, BUET 10

If you want to contribute, please fork this repository or send your solution to 
rafikamal93 AT gmail DOT com

*/
