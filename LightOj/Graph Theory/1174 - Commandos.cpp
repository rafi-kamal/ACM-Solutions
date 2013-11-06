/*
Algorithm: BFS/DFS

There is an unlimited supply of commando troops for the mission, so we can assign one commando
for destroying one building. So, the i'th commando have to:
1. Start from the building s and go to the i'th building
2. From the i'th building, go to building d

So, we have to calculate (shortest path from s to i) + (shortest path from d to i)
for all commandos, and find the maximum value among these.
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

#define SIZE 105
#define MOD 20071027
#define clr(a) memset(a, 0, sizeof a)
#define reset(a) memset(a, -1, sizeof a)

#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))

#define max3(x, y, z) max(max(x, y), max(y, z)) 

using namespace std;

int n, m, row, column;
typedef pair<int, int> Node;

list<int> adj[SIZE];
bool visited[SIZE];
int time1[SIZE];
int time2[SIZE];

void bfs(int node, int *time)
{
	queue<int> q;
	visited[node] = true;
	q.push(node);
	time[node] = 0;
	
	while(!q.empty())
	{
		node = q.front();
		q.pop();
		for(list<int>::iterator it = adj[node].begin(); it != adj[node].end(); it++)
		{
			if(!visited[*it])
			{
				visited[*it] = true;
				time[*it] = time[node] + 1;
				q.push(*it);
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int i, j, k, l, sum = 0;
	int tc, t, d, x, y, a, b, r, current, first;
	bool flag;
	unsigned long long ln;

	scanf("%d", &tc);
	for(t = 1; t <= tc; t++)
	{
		scanf("%d %d", &n, &m);
		
		for(i = 0; i < n; i++)
			adj[i].clear();
		clr(time1);
		clr(time2);
		
		for(i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);	
		}
		
		scanf("%d %d", &a, &b);
		clr(visited);
		bfs(a, time1);
		clr(visited);
		bfs(b, time2);
		
		int mx = 0;
		for(i = 0; i < n; i++)
			mx = max(mx, time1[i] + time2[i]);
		
		printf("Case %d: %d\n", t, mx);
	}
	
	return 0;
}

/*
Solution submitted by: Rafi Kamal, BUET 10

If you want to contribute, please fork this repository or send your solution to 
rafikamal93 AT gmail DOT com

*/


