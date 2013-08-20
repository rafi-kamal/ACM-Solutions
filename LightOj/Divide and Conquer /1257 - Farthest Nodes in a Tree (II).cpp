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

#define SIZE 30005
#define MOD 20071027
#define clr(a) memset(a, 0, sizeof a)
#define reset(a) memset(a, -1, sizeof a)

#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))

#define max3(x, y, z) max(max(x, y), max(y, z)) 

using namespace std;

int n, m, row, column;

int depth1[SIZE];
int depth2[SIZE];
int upCost[SIZE];
bool visited[SIZE];
list<pair<int, int> > children[SIZE];
int mx;

int calcDepth(int node)
{
	visited[node] = true;
	int cost;
	for(list<pair<int, int> >::iterator it = children[node].begin(); it != children[node].end(); it++)
	{
		if(!visited[it->first])
		{
			cost = calcDepth(it->first) + it->second;
			if(cost >= depth1[node])
			{
				depth2[node] = depth1[node];
				depth1[node] = cost;
			}
			else if(cost > depth2[node])
				depth2[node] = cost;
		}
	}
	return depth1[node];
}

void calcUpCost(int node)
{
	visited[node] = true;
	int cost;
	for(list<pair<int, int> >::iterator it = children[node].begin(); it != children[node].end(); it++)
	{
		if(!visited[it->first])
		{
			if(depth1[it->first] + it->second == depth1[node])
				cost = depth2[node];
			else
				cost = depth1[node];
			upCost[it->first] = max(upCost[node], cost) + it->second;
			calcUpCost(it->first);
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
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			children[i].clear();
		clr(depth1);
		clr(depth2);
		clr(upCost);
		mx = 0;
		
		for(i = 1; i < n; i++)
		{
			scanf("%d %d %d", &a, &b, &r);
			children[a].push_back(make_pair(b, r));
			children[b].push_back(make_pair(a, r));
		}
		
		clr(visited);
		calcDepth(0);
		clr(visited);
		upCost[0] = 0;
		calcUpCost(0);
		
		printf("Case %d:\n", t);
		for(i = 0; i < n; i++)
			printf("%d\n", max(depth1[i], upCost[i]));
	}
	
	return 0;
}



