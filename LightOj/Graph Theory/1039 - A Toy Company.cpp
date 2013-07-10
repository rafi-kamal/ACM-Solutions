/*
Algorithm: BFS

In this problem, three letters comprises a node/state. By changing any letter, you can go to
one node/state to another node/state. So, say now you are in node/state 'adx'. From this node
you can go the following nodes (assuming that the following nodes are not forbidden):
bdx -- changing first letter
zdx
aex -- changing second letter
acx
ady -- changing third letter
adw 

So you can say, these 6 nodes have an edge with the node 'adx'. So you have the nodes and edges,
construct the graph (keep forbidden words in mind) and then do a BFS from the calcuating the
shortest path between the starting and ending word.

*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <utility>

#define SIZE 26
#define MOD 20071027

#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))

#define FORBIDDEN -1
#define NOT_VISITED 0
#define VISITED 1

using namespace std;

int Time[SIZE][SIZE][SIZE];
int visited[SIZE][SIZE][SIZE];
int row, column, n;

int X[] = {0, 0, 1, 0, 0, -1};
int Y[] = {0, 1, 0, 0, -1, 0};
int Z[] = {1, 0, 0, -1, 0, 0};

struct point
{
	int x;
	int y;
	int z;
	
	point(){};
	point(int x, int y, int z){this->x = x; this->y = y; this->z = z;}
};

int main()
{
	int tc, t = 0, i, j, k, m, mx = 0, x, y, z, a, b, c, value;
	char ch;
	bool flag;
	string str1, str2, s1, s2, s3;
	
	//freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	
	for(t = 1; t <= tc; t++)
	{
		cin >> str1 >> str2 >> n;
		memset(visited, 0, sizeof visited);
		
		for(m = 0; m < n; m++)
		{
			cin >> s1 >> s2 >> s3;
			
			for(i = 0; i < s1.length(); i++)
				for(j = 0; j < s2.length(); j++)
					for(k = 0; k < s3.length(); k++)
						visited[s1[i]-'a'][s2[j]-'a'][s3[k]-'a'] = FORBIDDEN;
				
		}
		
		if(visited[str1[0]-'a'][str1[1]-'a'][str1[2]-'a'] == FORBIDDEN)
		{
			printf("Case %d: %d\n", t, -1);
			continue;
		}
		Time[str1[0]-'a'][str1[1]-'a'][str1[2]-'a'] = 0;
		
		queue<point> q;
		point p;
		q.push(point(str1[0]-'a', str1[1]-'a', str1[2]-'a'));
		value = -1;
		flag = true;
		while(!q.empty() && flag)
		{
			p = q.front();
			q.pop();
				
			if(p.x == str2[0]-'a' && p.y == str2[1]-'a' && p.z == str2[2]-'a')
			{
				flag = false;
				break;
			}
			
			for(m = 0; m < 6; m++)
			{
				a = (p.x+X[m])%26;
				b = (p.y+Y[m])%26;
				c = (p.z+Z[m])%26;
				
				if(a < 0) a += 26;
				if(b < 0) b += 26;
				if(c < 0) c += 26;
					
				if(visited[a][b][c] == NOT_VISITED)
				{
					visited[a][b][c] = VISITED;
					Time[a][b][c] = Time[p.x][p.y][p.z] + 1;
					q.push(point(a, b, c));
				}
			}
		}
		
		if(!flag) printf("Case %d: %d\n", t, Time[p.x][p.y][p.z]);
		else printf("Case %d: %d\n", t, -1);
	}	
	
	return 0;
}

/*
Solution submitted by: Rafi Kamal, BUET 10

If you want to contribute, please fork this repository or send your solution to 
rafikamal93 AT gmail DOT com

*/
