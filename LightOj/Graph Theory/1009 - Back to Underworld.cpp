/*
Algorithm: BFS

Check the second test case:
1 2
2 3
4 2

We denote the fighters as the nodes of a graph and the fights to be the edges of the graph.
Let's assume 1 is Vampire. So 2 must be a Lykan, as there is an edge between 1 and 2 (a fight). And
3 and 4 will be Vampires, as they have edges with 2. So there are 3 Vampires and 1 Lykan, 
the answer is 3. In short, if a node is Vampire, every node adjacent to it will be Lykans,
and vice versa.

Look, here we don't care about if the fighter is a Vampire of Lykan, we only care the maximum 
number of fighters of a certain kind. So if we assume 1 to be a Lykan, the result doesn't change,
we would have 3 Lykans and 1 Vampire, the answer being 3.

In my code I denoted Vampires and Lykans by two different colors, black and red. At first all
nodes are unassigned. Then I select an unassigned node and make it black (or red, whatever).
Using a BFS, I assign red to every node adjacent to a black node, and assign black
to every node adjacent to a red node. Then I take the maximum between the red and black nodes.

One thing to remember, the graph might not be connected.
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

#define SIZE 20005
#define MOD 20071027

using namespace std;

list<int> adj[SIZE];
int color[SIZE];

enum {NOT_VISITED, BLACK, RED};

int main()
{
	int tc, t = 0, i, j, k, m, n, mx = 0, x, y, q, value, node;
	char ch;
	long long sum = 0;
	
	//freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	
	for(t = 1; t <= tc; t++)
	{
		scanf("%d", &n);
		
		memset(color, 0, sizeof color);
		for(i = 0; i < SIZE; i++)
			adj[i].clear();
		
		for(i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		mx = 0;
		
		for(i = 0; i < SIZE; i++)
		{
			if(!adj[i].empty() && color[i] == NOT_VISITED)
			{
				int black = 0, red = 0;
				queue<int> q;
				q.push(i);
				color[i] = BLACK;
				black++;
				
				while(!q.empty())
				{
					node = q.front();
					q.pop();
					
					for(list<int>::iterator it = adj[node].begin(); it != adj[node].end(); it++)
					{
						if(color[*it] == NOT_VISITED)
						{
							q.push(*it);
							if(color[node] == BLACK)
							{
								color[*it] = RED;
								red++;
							}
							else
							{
								color[*it] = BLACK;
								black++;
							}
						}
					}
				}
				mx += max(red, black);
			}
		}
		
		printf("Case %d: %d\n", t, mx);
	}
	
	return 0;
}

/*
Solution submitted by: Rafi Kamal, BUET 10

If you want to contribute, please fork this repository or send your solution with a brief 
description of your idea to rafikamal93 AT gmail DOT com

*/
