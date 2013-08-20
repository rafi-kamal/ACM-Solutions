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
#define SIZE 50005
#define MOD 10056

using namespace std;
int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};
/* right, down, lft, up */
int m, n, res;
typedef pair<int, int> Point;

int b[SIZE];
string str;
string substr;

void kmpPreProcess(const string &substr) {
	int i = 0, j = -1;
	b[i] = j;
	
	while (i < substr.length()) {
		while (j >= 0 && substr[i] != substr[j])
			j = b[j];
			
		i++;
		j++;
		b[i] = j;
	}
}

long long fill1[SIZE];
long long fill2[SIZE];

long long dp[SIZE];

long long solve(int n) {
	if (n == 0)
		return 0;
	if (dp[n] == -1) {
		dp[n] = 1 + solve(b[n]);
	}
	
	return dp[n];
}

void kmp(const string &str, const string &substr, long long fill[]) {
	kmpPreProcess(substr);
	reset(dp);
	int i = 0, j = 0;
	
	while (i < str.length()) {
		while (j >= 0 && str[i] != substr[j])
			j = b[j];
		
		j++;
		fill[i] = solve(j);
		
		i++;
	}
}

int main()
{
	int t, tc, z, x, y;
    int i, j, k, l, h;
    char ch;

#ifndef ONLINE_JUDGE
   	freopen("input.txt", "r", stdin);
#endif
	
	cin >> tc;
	getchar();
	for (t = 1; t <= tc; t++) {
		cin >> str >> substr;
		
		kmp(str, substr.substr(0, substr.length()-1), fill1);
		
		reverse(str.begin(), str.end());
		reverse(substr.begin(), substr.end());
		kmp(str, substr.substr(0, substr.length()-1), fill2);
		
		/*for (i = 0; i <= substr.length(); i++)
			cout << dp[i] << ' ';
		cout << endl;
		
		for (i = 0; i < str.length()-1; i++) {
			cout << fill1[i] << ' ';
		}
		cout << endl;
		for (i = 0; i < str.length()-1; i++) {
			cout << fill2[i] << ' ';
		}
		cout << endl;*/
		
		long long total = 0;
		for (i = 0; i < str.length()-1; i++) {
			total += fill1[i]*fill2[str.length()-i-2];
		}
		
		printf("Case %d: %lld\n", t, total);
	}	
   
	return 0;
}

