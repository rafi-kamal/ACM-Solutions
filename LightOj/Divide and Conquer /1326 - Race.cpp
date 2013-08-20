#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<cstdlib>
#include<string>
#include<set>
#include<iomanip>
#define INF 2e9
#define LLD long long int
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define SIZE 1005
#define MOD 10056
using namespace std;
int n;

int dp[SIZE][SIZE];
int dp2[SIZE];

int solve(int n)
{
	if(dp2[n] == -1)
	{
		int i, j;
		int ans = 0;
		for(i = 0; i < n; i++) {
			j = (dp[n][n-i] * solve(i)) % MOD;
			if(j < 0) j += MOD;
			ans = (ans + j) % MOD;
		}
		dp2[n] = ans;
	}
	
	return dp2[n];
}

int main()
{
	int t, tc, a, b, c, d, w;
    int i, j, k, l, m;
    
   // freopen("input.txt", "r", stdin);
    for(i = 0; i < SIZE; i++)
    	dp[i][0] = 1;
    
    for(i = 1; i < SIZE; i++)
    	for(j = 1; j <= i; j++)
    		dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
    		
	reset(dp2);
	dp2[0] = 1;
	    		
    scanf("%d", &tc);
    for(t = 1; t <= tc; t++)
    {
	    scanf("%d", &n);
	    int ans = solve(n);
	    printf("Case %d: %d\n", t, ans);
    }
    	
    return 0;
}
