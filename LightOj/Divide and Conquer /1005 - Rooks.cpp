#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include <stack>
#include <utility>
#include <ctime>
#include <string>
#include <map>

#define LongInt long long
#define SIZE 1000
#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

#define digit(c) (c - '0')

using namespace std;

int a[SIZE][SIZE];

unsigned LongInt solve(LongInt n, LongInt m, LongInt k)
{
	if(k > n || k > m)
		return 0;
	else if(k == 0)
		return 1;
	else if(m == 1)
		return n;
	else return n * solve(n - 1, m - 1, k - 1) + solve(n, m - 1, k);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int tc, k, n;
	unsigned LongInt l;
	
	scanf("%d", &tc);
	
	for(int p = 0; p < tc; p++)
	{
		scanf("%d %d", &n, &k);
		//for(int i = 0; i <
		
		printf("Case %d: %llu\n", p + 1, solve(n, n, k));
	}
	
	return 0;
}
