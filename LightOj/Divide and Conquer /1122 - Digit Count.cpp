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
#define SIZE 105
#define MOD 1000000009

using namespace std;
int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};
/* right, down, lft, up */
int N, M;
long long res;
typedef pair<int, int> Point;

int dp[SIZE][SIZE];
int A[SIZE];

int solve(int m, int n) {
	if (m == 1) return 1;
	if (dp[m][n] == -1) {
		int total = 0;
		for (int i = 1; i <= N; i++) {
			if (abs(A[n] - A[i]) <= 2)
				total += solve(m-1, i);
		}
		dp[m][n] = total;
	}
	
	return dp[m][n];
}

int main()
{
	int t, tc, z, x, y, w, k;
	int i, j, l, h;
	char ch;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif

	//ios::sync_with_stdio(false);

	cin >> tc;
	getchar();
	for (t = 1; t <= tc; t++) {
		reset(dp);
		cin >> N >> M;
		for (i = 1; i <= N; i++)
			cin >> A[i];
			
		res = 0;
		for (i = 1; i <= N; i++)
			res += solve(M, i);
		printf("Case %d: %lld\n", t, res);
	}

	return 0;
}

