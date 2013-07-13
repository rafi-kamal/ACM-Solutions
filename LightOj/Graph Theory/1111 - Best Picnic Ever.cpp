/*
Algorithm: BFS/DFS

Strightforward BFS/DFS problem. You can do BFS/DFS for each of the K people, and count how
many location can be reached by them all, but this can be done in a single BFS/DFS, too.
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
typedef pair<int, int> Node;

vector<int> adj[SIZE];

/* visited[n][i] denotes if n'th node is visited by i'th people */
bool visited[SIZE][100];

/* cnt[n] denotes how many people can reach node n */
int cnt[SIZE];

int main()
{	
	int i, j, k, l, sum = 0;
	int tc, t, d, x, y, a, b, r, current, first;
	bool flag;
	unsigned long long ln;

	scanf("%d", &tc);
	for(t = 1; t <= tc; t++)
	{
		scanf("%d %d %d", &k, &n, &m);
		clr(visited);
		clr(cnt);
		for(i = 0; i < n; i++)
			adj[i].clear();
			
		queue<Node> q;
		for(i = 0; i < k; i++)
		{
			scanf("%d", &x);
			q.push(make_pair(x, i));
			visited[x][i] = true;
		}
		
		for(i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
		}
		
		Node node;
		while(!q.empty())
		{
			node = q.front();
			q.pop();
			cnt[node.first]++;
			
			for(i = 0; i < adj[node.first].size(); i++)
			{
				if(!visited[adj[node.first][i]][node.second])
				{
					visited[adj[node.first][i]][node.second] = true;
					q.push(make_pair(adj[node.first][i], node.second));
				}
			}
		}
		
		/* If cnt[i] == k, that means i'th city can be reached by all K people, hence
		a possible picnic location */
		int result = 0;
		for(i = 1; i <= n; i++)
			result += (cnt[i] == k);
			
		printf("Case %d: %d\n", t, result);
	}
	
	return 0;
}

/*
Solution submitted by: Rafi Kamal, BUET 10

If you want to contribute, please fork this repository or send your solution to 
rafikamal93 AT gmail DOT com

*/
