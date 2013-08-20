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

#define SIZE 1005
#define digit(c) ((c) - '0')
#define PI 3.141592654
#define MAX_INT 2147483646
#define DIFF 10E-7
#define MOD 1000000007

using namespace std;


bool f[SIZE][SIZE];
int tree[SIZE][SIZE];

int maxX;
int maxY;

int read(int x, int y)
{
	int sum = 0;
	while(x > 0)
	{
		int y1 = y;
		while(y1 > 0)
		{
			sum += tree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return sum;
}

int update(int x, int y, int val)
{
	while(x <= maxX)
	{
		int y1 = y;
		while(y1 <= maxY)
		{
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int query(int x1, int y1, int x2, int y2)
{
	return read(x2, y2) - read(x2, y1-1) - read(x1-1, y2) + read(x1-1, y1-1);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	unsigned i, j, k, l, sum = 0;
	int tc, t, d, x, y, r, n, m, p, q,current, first;
	char ch;
	bool flag;
	int x1, y1, x2, y2;
	
	scanf("%d", &tc);
	getchar();
	
	maxX = maxY = 1001;
	for(t = 1; t <= tc; t++)
	{
		scanf("%d", &n);
		printf("Case %d:\n", t);
		
		memset(tree, 0, sizeof tree);
		memset(f, 0, sizeof f);
		
		for(i = 0; i < n; i++)
		{
			scanf("%d", &m);

			switch(m)
			{
				case 0:
					scanf("%d %d", &x, &y); x++, y++;
					if(!f[x][y])
					{
						f[x][y] = true;
						update(x, y, 1);
					}
					break;
				case 1:
					scanf("%d %d %d %d", &x1, &y1, &x2, &y2); x1++, y1++, x2++, y2++;
					printf("%d\n", query(x1, y1, x2, y2));
					break;
			}
		}
	}
		
	return 0;
}

