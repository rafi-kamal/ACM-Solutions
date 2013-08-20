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

#define SIZE 2005
#define digit(c) ((c) - '0')
#define PI 3.141592654
#define MAX_INT 2147483646
#define DIFF 10E-7
#define CONST 1000000007

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	unsigned i, j, k;
	int l, sum = 0;
	int tc, t, d, x, y, r, n, current, first;
	char ch;
	bool flag;
	
	scanf("%d", &tc);
	getchar();
	
	for(t = 1; t <= tc; t++)
	{
		scanf("%d", &n);
		
		for(i = 1; i <= 1<<31 ; i <<= 1)
		{
			if(i & n)
				break;
		}
		
		k = 0;
		while(i <= 1<<31)
		{
			if(!(i & n)) break;
			n &= ~i;
			k++;
			i <<= 1;
		}
		n |= i;
		
		for(j = 1, i = 1; j < k; i <<= 1, j++)
			n |= i;
			
		printf("Case %d: %d\n", t, n);
	}
		
	return 0;
}

