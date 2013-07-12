/*
Algorithm: BFS/DFS

This is a simple problem. Look at the first test case. You have to find the shortest path
from A to B (using BFS or DFS). Then you have to find the shortest path from B to C. And
then C to D and D to E. The result is the sum of all these paths.

There is only one thing you need to keep in mind. According to the problem description, 
"if he lands on a particular food he must collect it" and
"For some superstitious reason, Yogi decides to collect all the foods in order"

So, say you are finding the shortest path from C to D. Then you can't pass over E or any
character greater than E, otherwise you will break the order. But you can certainly pass
over A or B.
*/

#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stack>
#include <string>     
#include <map>
#include <set>
#include <list>
#include <queue>
#include <utility>

#define SIZE 1005
#define MOD 20071027
#define clr(a) memset(a, 0, sizeof a)
#define reset(a) memset(a, -1, sizeof a)

#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))

#define max3(x, y, z) max(max(x, y), max(y, z)) 

using namespace std;

int n, m, row, column;

char grid[12][12];
char last;
bool visited[12][12];

int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};

struct Node 
{
	int x, y, time;
	Node(int x, int y, int time){this->x = x; this->y = y; this->time = time;}	
	Node(){}
};

int bfs(Node node, char current)
{
	int i, a, b;
	
	if(current == last) return node.time;
	clr(visited);
	queue<Node> q;
	q.push(node);
	
	while(!q.empty())
	{
		node = q.front();
		q.pop();
		
		for(i = 0; i < 4; i++)
		{
			a = node.x + X[i];
			b = node.y + Y[i];
			
			if(!BOUNDARY(a, b)) continue;
			if(grid[a][b] == current + 1) 
				return bfs(Node(a, b, node.time+1), current+1);
			else if(!visited[a][b] && (grid[a][b] == '.' || (isalpha(grid[a][b]) && grid[a][b] <= current)))
			{
				q.push(Node(a, b, node.time+1));
				visited[a][b] = true;
			}
		}
	}
	return -1;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int i, j, k, l, sum = 0;
	int tc, t, d, x, y, a, b, r, n, current, first;
	bool flag;
	unsigned long long ln;

	scanf("%d", &tc);
	for(t = 1; t <= tc; t++)
	{
		scanf("%d", &row);
		column = row;
		getchar();
		last = 'A';
		Node node;
		for(i = 0; i < row; i++)
		{
			gets(grid[i]);
			for(j = 0; j < column; j++)
			{
				if(isalpha(grid[i][j]))
				{
					if(grid[i][j] == 'A') node = Node(i, j, 0);
					else last = max(last, grid[i][j]);
				}
				//putchar(grid[i][j]);
			}
			//putchar('\n');
		}
		
		int result = bfs(node, 'A');
		if(result >= 0)
			printf("Case %d: %d\n", t, result);
		else
			printf("Case %d: %s\n", t,  "Impossible");
	}
	
	return 0;
}




/*
Solution submitted by: Rafi Kamal, BUET 10

If you want to contribute, please fork this repository or send your solution to 
rafikamal93 AT gmail DOT com

*/
