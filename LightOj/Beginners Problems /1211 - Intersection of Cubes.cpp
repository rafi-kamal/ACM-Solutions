#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include <stack>
#include <utility>
#include <set>
#include <ctime>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <cctype>

#define LongInt long long
#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

#define BOUNDARY(i, j) (i < 0 || i > row-1 || j < 0 || j > column - 1) 

#define SIZE 1000005
#define digit(c) ((c) - '0')
#define PI 3.141592654
#define INF 2147483646
#define DIFF 10E-7
#define MOD 1000000007

using namespace std;
int members[SIZE];
bool Team[1005];
queue<int> q[1005];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int i, j, k, sum = 0, count;
	int tc, t, d = 0, x, y, n, m, p, value;
	char ch, str[1000];
	bool flag;
	int x1[102], x2[102], y1[102], y2[102], z1[102], z2[102];
	
	scanf("%d", &tc);
    for(t = 1; t <= tc; t++)
    {
            scanf("%d", &n);

            for(i = 0; i < n; i++)
                    scanf("%d %d %d %d %d %d", &x1[i], &y1[i], &z1[i], &x2[i], &y2[i], &z2[i]);
            
            int xLow = 0, yLow = 0, zLow = 0;
			int xHigh = 1001, yHigh = 1001, zHigh = 1001;
			
			for(i = 0; i < n; i++)
			{
				xLow = max(xLow, x1[i]);
				xHigh=  min(xHigh, x2[i]);
				yLow = max(yLow, y1[i]);
				yHigh = min(yHigh, y2[i]);
				zLow = max(zLow, z1[i]);
				zHigh = min(zHigh, z2[i]);
			}
			
			int volume = (xHigh-xLow) * (yHigh-yLow) * (zHigh-zLow);
			
			printf("Case %d: %d\n", t, volume < 0 ? 0 : volume);

    }
		
	return 0;
}

