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

#define SIZE 1000005
#define digit(c) ((c) - '0')
#define PI 3.141592654
#define INF 2147483646
#define DIFF 10E-7
#define MOD 1000000007

using namespace std;

bool exist[2*SIZE];
int army[2*SIZE];
int tree[2*SIZE];
int maxIdx;
int largestBit;

void update(int x, int value)
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

void calcBit()
{
	int n = maxIdx;
	for(largestBit = 0; n; n >>= 1) largestBit++;
}

int search(int sum)
{
	int idx = 0;
	int bitmask = 1<<(largestBit-1);
	
	while(bitmask != 0 && idx < maxIdx)
	{
		int tdx = idx + bitmask;
		if(sum == tree[tdx]) return tdx;
		if(sum > tree[tdx])
		{
			idx = tdx;
			sum -= tree[tdx];
		}
		bitmask >>= 1;
	}
	
	if(sum != 0) return -1;
	else return idx;
}

int minSearch(int sum)
{
	int idx = search(sum);
	if(idx < 0) return idx;
	while(idx && !exist[idx]) idx--;
	return idx;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int i, j, k, sum = 0, count;
	int tc, t, d = 0, x, y, n, m, p, q, value;
	char ch, str[1000];
	bool flag;
	
	scanf("%d", &tc);
    for(t = 1; t <= tc; t++)
    {
	    memset(tree, 0, sizeof tree);
	    memset(exist, 0, sizeof exist);
	    
	    printf("Case %d:\n", t);
	    scanf("%d %d", &n, &q);
	    maxIdx = n + q;
	    calcBit();
	    for(i = 1; i <= n; i++)
	    {
		    scanf("%d", &army[i]);
		    update(i, 1);
		    exist[i] = true;
	    }
	    //for(i = 1; i <= maxIdx; i++) printf("%d ", tree[i]);
	    for(i = 1; i <= q; i++)
	    {
		    getchar();
		    scanf("%c %d", &ch, &value);
		    switch(ch)
		    {
		    	case 'a':
		    		army[++n] = value;
		    		update(n, 1);
		    		exist[n] = true;
		    		break;
		    	case 'c':
		    		x = minSearch(value);
		    		if(x < 0) printf("none\n");
		    		else
		    		{
		    			printf("%d\n", army[x]);
		    			exist[x] = false;
		    			update(x, -1);
		    		}
		    		break;
		    }
	    }
    }
		
	return 0;
}

