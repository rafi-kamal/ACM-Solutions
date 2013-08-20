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

#define SIZE 50005
#define digit(c) ((c) - '0')
#define PI 3.141592654
#define INF 2147483646
#define DIFF 10E-7
#define MOD 1000000007

using namespace std;

struct Line
{
	int x;
	int y;
} lines[SIZE];
int tree[2*SIZE];
int pointArr[2*SIZE];
set<int> points;
map<int, int> myMap;
int maxIdx;

void freqUpdate(int x, int value)
{
	while(x <= maxIdx)
	{
		tree[x] += value;
		x += (x & -x);
	}
}

int query(int x)
{
	int sum = 0;
	while(x > 0)
	{
		sum += tree[x];
		x -= (x & -x);
	}
	return sum;
}	

void update(int i, int j)
{
	freqUpdate(myMap[i], 1);
	freqUpdate(myMap[j+1], -1);
}

int binarySearch(int value)
{
	int start = 1;
	int end = maxIdx;
	
	while(true)
	{
		if(value < pointArr[start]) return start-1;
		if(value > pointArr[end]) return end;
		
		int mid = (start+end)/2;
		if(value == pointArr[mid]) return mid;
		else if(value < pointArr[mid]) end = mid;
		else start = mid+1;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int i, j, k;
	int tc, t, n, m, p, q, len, choice, value;
	char ch;
	int sum;
	
	scanf("%d", &tc);
	
	for(t = 1; t <= tc; t++)
	{
		myMap.clear();
		points.clear();
		memset(tree, 0, sizeof tree);
		
		printf("Case %d:\n", t);
		scanf("%d %d", &n, &q);
		for(i = 0; i < n; i++)
		{
			scanf("%d %d", &lines[i].x, &lines[i].y);
			points.insert(lines[i].x);
			points.insert(lines[i].y+1);
		}
		
		i = 1;
		while(points.begin() != points.end())
		{
			pointArr[i] = *points.begin();
			myMap.insert(make_pair(*points.begin(), i));
			points.erase(points.begin());
			i++;
		}
		/*
		j = 0;
		for(map<int, int>::iterator it = myMap.begin(); it != myMap.end(); it++)
		{
			printf("%2d %d\t", it->first, it->second, pointArr[++j]);
		}
		printf("\n");*/
		
		maxIdx = --i;
		for(j = 0; j < n; j++)
		{
			update(lines[j].x, lines[j].y);
		}
		
		for(j = 0; j < q; j++)
		{
			scanf("%d", &value);
			value = binarySearch(value);
			sum = query(value);
			printf("%d\n", sum);
		}
	}
		
	return 0;
}
