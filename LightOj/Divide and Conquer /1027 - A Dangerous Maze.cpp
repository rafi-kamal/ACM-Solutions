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
#define SIZE 1005
#define MOD 1000000009

using namespace std;
int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};
/* right, down, lft, up */
int M, N;
long long res;
typedef pair<int, int> Point;

inline int gcd (int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a%b);
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
	for (t = 1; t <= tc; t++) {
		int total = 0;
		int plus = 0;
		cin >> N;
		for (i = 0; i < N; ++i) {
			cin >> x;
			total += abs(x);
			plus += (x > 0);
		}
		
		printf ("Case %d: ", t);
		if (plus == 0) puts("inf");
		else {
			int g = gcd(total, plus);
			plus /= g;
			total /= g;
			printf("%d/%d\n", total, plus);
		}
	}
   
	return 0;
}
