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

bool A[SIZE];
char str[SIZE];
int tree[SIZE];
int maxIdx;

void changeFreq(int x, int value)
{
	while(x <= maxIdx)
	{
		tree[x] += value;
		x += x & -x;
	}
}

int query(int x)
{
	int sum = 0;
	while(x > 0)
	{
		sum += tree[x];
		x -= x & -x;
	}
	return sum;
}

void update(int i, int j)
{
	changeFreq(i, 1);
	changeFreq(j+1, -1);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int i, j, k, sum = 0, count;
	int tc, t, d = 0, x, y, n, m, p, q, value, len;
	char ch;
	bool flag;
	
	scanf("%d", &tc);
	
	for(t = 1; t <= tc; t++)
	{
		printf("Case %d:\n", t);
		scanf("%s", str);
		for(i = 0; str[i]; i++)
			A[i] = str[i] - '0';
		maxIdx = strlen(str);
		memset(tree, 0, sizeof(int)*(maxIdx+1));
		
		scanf("%d", &q);
		for(i = 1; i <= q; i++)
		{
			getchar();
			scanf("%c", &ch);
			switch(ch)
			{
				case 'I':
					scanf("%d %d", &j, &k);
					update(j, k);
					/*for(int l = 1; l <= maxIdx; l++) printf("%d ", query(l));
					printf("\n"); */
					break;
				case 'Q':
					scanf("%d", &j);
					printf("%d\n", A[j-1] ^ (query(j)%2));
					break;
			}
		}
	}
		
	return 0;
}

