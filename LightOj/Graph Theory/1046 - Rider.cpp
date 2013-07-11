/*
Algorithm: BFS

First, there are multiple source nodes here, for each of the rider you need to do a BFS to find
the shortest path/minimum time. But the problem is different from a standard BFS problem in
mainly two different ways:

1. There is no specific destination. You need to find the minimal total number of moves necessary to move 
all the riders to the 'same square', but you don't know what square it actually is. So for each rider,
you have to calculate the shortest path/minimum time to reach 'each of the square' in the chess
board. And at the end, you have to find the square which is reachable for all the riders, and
the sum of the total time for all of the riders is minimum in that square. I've stored these sums
is the array 'result'.

2. A rider can perform K jumps in a time, instead of a single jump. So at any unit time, he can
perform 1/2/3... K jumps. How would you know which one is optimal?
The solution is, add an extra 'state' or an extra layer of node to the graph for this parameter.
Say, the rider is in (i, j) th square of the chess board. He can come to this square by a single
jump from 8 positions (as a general knight). But he can also come here by 2,3,4 or K jumps from
other nodes. And the minimum time to reach that node from the rider's initial position will
be different for each of these K cases. So, instead of storing only one shortest path/minimum time
for a node, we store K different shortest path/minimum time. In the end of the BFS, for each node,
we select only the minimum value from these K different values.

In my code I stored the shortest distance/minimum time in the array 'dist'. It's an 3D array,
first two dimensions denotes the (i, j) th position of the square, and the third dimension is
for K, it denotes how many jumps are left before we must increase the time once.
*/

#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <utility>

#define SIZE 12
#define MOD 20071027

#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))

using namespace std;

int row, column, n;

int X[] = {1, 1, 2, 2, -1, -1, -2, -2};
int Y[] = {2, -2, 1, -1, 2, -2, 1, -1};

struct point
{
	int x;
	int y;
	int k;
	
	point(int x, int y, int k){this->x = x; this->y = y; this->k = k;}
	point(){}
};

unsigned dist[SIZE][SIZE][11];
unsigned result[SIZE][SIZE];
int grid[SIZE][SIZE];

int main()
{
	int tc, t = 0, i, j, k, m, x, y, z, a, b, c, value, l;
	unsigned d, mx;
	char ch;
	bool flag;
	string str1, str2, s1, s2, s3;
	
	//freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	
	for(t = 1; t <= tc; t++)
	{
		memset(result, 0, sizeof result);
		scanf("%d %d", &row, &column);

		vector<pair<int, int> > points;
		
		getchar();
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < column; j++)
			{
				grid[i][j] = getchar()-'0';
				if(grid[i][j] > 0 && grid[i][j] < 10) points.push_back(make_pair(i, j));
			}
			getchar();
		}
		
		point p;
		/* We do a BFS for each rider */
		for(vector<pair<int, int> >::iterator it = points.begin(); it != points.end(); it++)
		{
			memset(dist, -1, sizeof dist);
			
			queue<point> q;
			q.push(point(it->first, it->second, grid[it->first][it->second]+1));
			dist[it->first][it->second][grid[it->first][it->second]+1] = 1;
			
			while(!q.empty())
			{
				x = q.front().x;
				y = q.front().y;
				k = q.front().k;
				q.pop();
				
				/* we can do l more jumps before time is increased (1 <= l <= K) */
				l = k - 1;
				if(l == 0) l = grid[it->first][it->second];
				
				for(i = 0; i < 8; i++)
				{
					a = x+X[i];
					b = y+Y[i];
					if(!BOUNDARY(a, b)) continue;
					
					/* increase the time if only one jump is left */
					d = dist[x][y][k] + (k == 1 ? 1 : 0);
					if(dist[a][b][l] > d)
					{
						dist[a][b][l] = d;
						q.push(point(a, b, l));
					}
				}
			}
			
			/* BFS is finished, now for each node, from K considerations, find the minimum one */
			for(i = 0; i < row; i++)
			{
				for(j = 0; j < column; j++)
				{
					if(i != it->first || j != it->second)
					{					
						mx = -1;
						for(k = 1; k <= 10; k++)
						{
							if(mx > dist[i][j][k]) mx = dist[i][j][k];
						}
						
						/* We have found the minimum value from K different values. Add it to the total */
						if(mx == -1) result[i][j] = -1;
						else if(result[i][j] != -1) result[i][j] += mx;
					} 
				}
			}
		}
		
		/* BFS is finished for all the riders. Now find the node with minimum total sum of the time */
		mx = -1;
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < column; j++)
			{
				if(result[i][j] < mx) mx = result[i][j];
			}
		}
		
		printf("Case %d: %d\n", t, mx);
	}	
	
	return 0;
}


/*
Solution submitted by: Rafi Kamal, BUET 10

If you want to contribute, please fork this repository or send your solution to 
rafikamal93 AT gmail DOT com

*/

