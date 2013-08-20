#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <list>

#define SIZE 100

using namespace std;

int myTeam[SIZE];
int oponentTeam[SIZE];
int points[SIZE][SIZE];

bool compare(const int &i, const int &j)
{
	return i > j;
}

inline int max(int a, int b, int c)
{
	if(a >= b && a >= c)
		return a;
	else if(b >= a && b >= c)
		return b;
	else
		return c;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int N, tc;
	scanf("%d", &tc);
	
	for(int i = 0; i < tc; i++)
	{
		scanf("%d", &N);
		
		for(int j = 0; j < N; j++)
			scanf("%d", &myTeam[j]);
		for(int j = 0; j < N; j++)
			scanf("%d", &oponentTeam[j]);
		
		sort(myTeam, myTeam + N, compare);
		sort(oponentTeam, oponentTeam + N, compare);
		
		for(int j = 0; j <= N; j++)
			points[j][0] = points[0][j] = 0;
			
		int point;
		for(int j = 1; j <= N; j++)
			for(int k = 1; k <= N; k++)
			{
				if(myTeam[j - 1] > oponentTeam[k - 1])
					point = 2;
				else if(myTeam[j - 1] == oponentTeam[k - 1])
					point = 1;
				else
					point = 0;
					
				points[j][k] = max(points[j-1][k], points[j][k - 1], points[j - 1][k - 1] + point);
			}
		
		cout << "Case " << i + 1 << ": " << points[N][N] << endl;
	}
		
	return 0;
}


