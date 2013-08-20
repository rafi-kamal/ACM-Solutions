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
#define BD(i, j) (i >= 0 && i < n && j >= 0 && j < m)
#define PRINT_VAR(X) (cout << #X << " -> " << X << endl)
#define PI acos(0)
#define MAX_INT 2147483647
#define SIZE 100005
#define MOD 1000000009

using namespace std;
int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};
/* right, down, lft, up */
int n, m;
long long res;
typedef pair<int, int> Point;

int val[16][16];
int dp[16][1<<16];

int solve (int pos, int mask)
{
	if (pos >= n) return 0;
	if (dp[pos][mask] == -1U) {
		for (int i = 0; i < n; i++) {
			if (!(mask & (1<<i))) {
				dp[pos][mask] = max(dp[pos][mask], val[pos][i] + solve(pos+1, mask | (1<<i)));
			}
		}
	}

	return dp[pos][mask];
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

	ios::sync_with_stdio(false);

	cin >> tc;
	for (t = 1; t <= tc; t++) {
		cin >> n;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				cin >> val[i][j];
		}

		reset(dp);

		res = solve(0, 0);
		cout << "Case " << t << ": " << res << endl;
	}

	return 0;
}

