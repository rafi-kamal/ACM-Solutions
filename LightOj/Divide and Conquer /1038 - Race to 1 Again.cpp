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
#define SIZE 100005
#define MOD 1000000009

using namespace std;
int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};
/* right, down, lft, up */
int M, N;

double dp[SIZE];

double solve (int n) {
	if (dp[n] ) {
		int m = sqrt(n + 1);
		double sum = 0;
		int div = 2;
		
		for (int i = 2; i <= m; i++) {
			if (n % i == 0) {
				sum += solve(n/i);
				div++;
				if (i != n/i) {
					sum += solve(i);
					div++;
				}
			}
		}
		
		sum /= (div - 1);
		sum += div * 1.0 / (div - 1);
		
		dp[n] = sum;
	}
	return dp[n];
}

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
	reset(dp);
	for (i = 0; i < SIZE; i++)
		dp[i] = -1;
	dp[1] = 0;
	
	for (t = 1; t <= tc; t++) {
		scanf("%d", &N);
		printf ("Case %d: %.6f\n", t, solve(N));
	}
   
	return 0;
}
