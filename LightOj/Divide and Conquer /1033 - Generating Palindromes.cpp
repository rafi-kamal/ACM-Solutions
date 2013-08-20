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
#define SIZE 105
#define MOD 1000000009

using namespace std;
int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};
/* right, down, lft, up */
int n, m;
long long res;
typedef pair<int, int> Point;

string str;
int dp[SIZE][SIZE];

int solve(int i, int j) {
	if (i >= j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (str[i] == str[j]) dp[i][j] = solve(i+1, j-1);
	else dp[i][j] = 1 + min(solve(i+1, j), solve(i, j-1));
	return dp[i][j];
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
		cin >> str;
		reset(dp);
		res = solve(0, str.size() - 1);
		printf("Case %d: %lld\n", t, res);
	}

	return 0;
}

