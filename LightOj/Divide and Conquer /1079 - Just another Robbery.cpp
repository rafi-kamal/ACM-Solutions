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
#include<limits>
#include<iomanip>
#include<fstream>
#include<sstream>
#define INF 2147483647
#define LLD int
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define BD(i, j) (i >= 0 && i < N && j >= 0 && j < M)
#define PRINT_VAR(X) (cout << #X << " -> " << X << endl)
#define PI acos(0)
#define MAX_INT 2147483647
#define SIZE 10005
#define MOD 1000000009

using namespace std;
int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};
/* right, down, lft, up */
int M, N;

double dp[101][SIZE];
int money[101];
double p[101];

int main()
{
	int t, tc, x, y, z;
    int i, j, k, l, h;
    char ch;

#ifndef ONLINE_JUDGE
   	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	
	cin >> tc;
	
	for (i = 0; i < SIZE; i++)
		dp[0][i] = 2;
	for (i = 0; i < 101; i++)
		dp[i][0] = 0;
	
	for (t = 1; t <= tc; t++) {
		double P;
		scanf("%lf %d", &P, &N);
		
		int mx = 0;
		for (i = 1; i <= N; i++) {
			scanf("%d %lf", &money[i], &p[i]);
			mx += money[i];
		}
		
		int res = 0;
		for (j = 1; j <= mx; j++) {
			for (i = 1; i <= N; i++) {
				if (j < money[i])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = min(dp[i - 1][j], p[i] + (1 - p[i]) * dp[i - 1][j - money[i]]);
			}
			
			if (dp[N][j] - P < -1E-7)
				res = j;
		}
		printf("Case %d: %d\n", t, res);
	}
   
	return 0;
}
