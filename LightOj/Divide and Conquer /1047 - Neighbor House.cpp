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

int a[SIZE][4];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int tc, N;
	
	cin >> tc;
	
	for(int i = 0; i < tc; i++)
	{
		cin >> N;
		
		for(int j = 0; j < N; j++)
			scanf("%d %d %d", &a[j][0], &a[j][1], &a[j][2]);
		
		for(int j = 1; j < N; j++)
		{
			a[j][0] += min(a[j - 1][1], a[j - 1][2]);
			a[j][1] += min(a[j - 1][0], a[j - 1][2]);
			a[j][2] += min(a[j - 1][1], a[j - 1][0]);
		}
		
		//for(int j = 0; j < N; j++)
			//cout << a[j][0] << ' ' << a[j][1] << ' ' << a[j][2] << endl;
		
		printf("Case %d: %d\n", i + 1, min3(a[N - 1][0], a[N - 1][1], a[N - 1][2]));
	}
	
	return 0;
}
