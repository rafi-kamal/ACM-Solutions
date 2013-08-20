#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include <stack>
#include <utility>
#include <set>
#include <ctime>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <cctype>

#define LongInt long long
#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

#define BOUNDARY(i, j) (i < 0 || i > row-1 || j < 0 || j > column - 1) 

#define SIZE 100005
#define digit(c) ((c) - '0')
#define PI 3.141592654
#define INF 2147483646
#define DIFF 10E-7
#define MOD 1000000007

using namespace std;

LongInt tree[4*SIZE];
LongInt lazy[4*SIZE];

void update(int node, int left, int right, int i, int j, int value)
{
	if(i > right || j < left) return;
	if(left >= i && right <= j) lazy[node] += value;
	else
	{
		tree[node] += value*(min(j, right) - max(i, left) + 1);
		update(2*node, left, (left+right)/2, i, j, value);
		update(2*node+1, (left+right)/2+1, right, i, j, value);
	}
}

LongInt query(int node, int left, int right, int i, int j)
{
	if(i > right || j < left) return 0;
	else  
	{
		tree[node] += lazy[node]*(right - left + 1); //printf("%d %d %d %d %d %lld\t", node, left, right, i, j, lazy[node]);
		if(left != right)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
		
		if(left >= i && right <= j) return tree[node];
		else return query(2*node, left, (left+right)/2, i, j) + query(2*node+1, (left+right)/2+1, right, i, j); 
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int i, j, k;
	int tc, t, n, m, p, q, len, choice, value;
	char ch;
	LongInt sum;
	
	scanf("%d", &tc);
	
	for(t = 1; t <= tc; t++)
	{
		printf("Case %d:\n", t);
		scanf("%d %d", &n, &q);
		
		memset(lazy, 0, sizeof lazy);
		memset(tree, 0, sizeof tree);
		
		for(k = 1; k <= q; k++)
		{
			scanf("%d", &choice);
			
			if(choice == 0)
			{
				scanf("%d %d %d", &i, &j, &value);
				update(1, 0, n - 1, i, j, value);
			}
			else
			{
				scanf("%d %d", &i, &j);
				sum = query(1, 0, n - 1, i, j);
				printf("%lld\n", sum);
				/*for(i = 1; i < 4*n; i++) printf("%d %d\t", i, lazy[i]);
				printf("\n");*/
			}
		}
	}
		
	return 0;
}
