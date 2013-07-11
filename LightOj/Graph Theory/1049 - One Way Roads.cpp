/*

The graph is a ring. Consider the third test case:
6
1 5 4
5 3 8
2 4 15
1 6 16
2 3 23
4 6 42

If we make a graph from these data, it will be look like the following:
1 --> 5 --> 3 <-- 2 --> 4 --> 6 <-- 1
and 2, 4 connected together.

You can easily decompose the edges in the two different directions:
1. Edges which goes to the left:
3 <-- 2 	23
6 <-- 1		16
Total cost: 39
2. Edges which goes to the left:
1 --> 5		 4
5 --> 3		 8
2 --> 4		15
4 --> 6		42
Total cost: 69

Remember, 'left' or 'right' is not important here, you can easily build a graph with left
and right altered. All we care is the two different direction of the edges.

Choose the direction in which cost is minimum (here, left, cost is 39). And build
roads in the opposite direction. So in this case you have to built two roads,
3 --> 2
6 --> 1

Look, now you can go from any city to another city!

The question is now, how to build this graph?
Again, look at the test case. The first edge is 1 --> 5. You can place 5 either left or right of 1.
1 --> 5 or
5 <-- 1

Both left and right of 1 & 5 is empty, so it's entirely up to you what will you choose.
Say, you choose the first option, you place 5 to the right of 1 (1 --> 5).
Now the second edge, 5 --> 3. You must place 3 right of 5, because left of 5 is already filled
by 1.
1 --> 5 --> 3
So all you need to do is keep track of whether the right or left of a node has already been filled,
and adding new edges accordingly. 

*/

#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <utility>

#define SIZE 105
#define MOD 20071027

#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))

using namespace std;

int row, column, n;

bool Left[SIZE];
bool Right[SIZE];

int weightLeft;
int weightRight;

int main()
{
	int tc, t = 0, i, j, k, m, x, y, z, a, b, c, value, l;
	unsigned d, mx;
	char ch;
	bool flag;
	
	//freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	
	for(t = 1; t <= tc; t++)
	{
		scanf("%d", &n);
		memset(Left, 0, sizeof Left);
		memset(Right, 0, sizeof Right);
		
		weightLeft = weightRight = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			/* If left of a, and right of b empty, then place b to the left of a (b <-- a) */
			if(!Left[a] && !Right[b])
			{
				Left[a] = Right[b] = true;
				weightLeft += c;
			}
			/* Otherwise place b to the right of a (a --> b) */
			else
			{
				Right[a] = Left[b] = true;
				weightRight += c;
			}
		}
		
		printf("Case %d: %d\n", t, min(weightLeft, weightRight));
	}	
	
	return 0;
}


/*
Solution submitted by: Rafi Kamal, BUET 10

If you want to contribute, please fork this repository or send your solution to 
rafikamal93 AT gmail DOT com

*/
