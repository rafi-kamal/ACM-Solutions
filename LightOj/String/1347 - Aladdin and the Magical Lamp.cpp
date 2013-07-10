/*
Algorithm: KMP, Suffix Array 
A nice tutorial on KMP: http://www.iti.fh-flensburg.de/lang/algorithmen/pattern/kmpen.htm
Tutorial on Suffix Array: http://www.stanford.edu/class/cs97si/suffix-array.pdf

The solution idea is described on the solution of problem 6, in the tutorial link I've given.
*/

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

#define SIZE 5005
#define digit(c) ((c) - '0')
#define PI 3.141592654
#define MAX_INT 2147483646
#define DIFF 10E-7
#define CONST 1000000007

using namespace std;

int row, column, step;
int B[3*SIZE];
char str[3][SIZE];
int len[3], mx;

#define MAXLG 15
struct entry 
{ 
    int first, second, p, group;
} L[3*SIZE];
int P[MAXLG][3*SIZE];
int LCP[3*SIZE];

bool cmp(const struct entry& a, const struct entry& b) 
{ 
    return a.first == b.first ? (a.second < b.second) : (a.first < b.first); 
}

bool comp2(const int& a, const int& b)
{	
	return P[step-1][a] < P[step-1][b];
}

void suffixArray() 
{ 
    int i, j, count, group;
    int length;
    int total = len[2];
    
    for (i = 0; i < total; i ++) 
    {    
        if(i < len[0]) P[0][i] = str[0][i] - 'a';
        else if(i < len[1]) P[0][i] = str[1][i-len[0]] - 'a';
        else P[0][i] = str[2][i-len[1]] - 'a';
    }
    P[0][len[0]-1] = -3, P[0][len[1]-1] = -2, P[0][len[2]-1] = -1;
    
    for (step = 1, count = 1; count>>1 < mx; step++, count <<= 1)
    {
    	for (i = 0; i < total; i++)
    	{ 
	    	length = (i >= len[1] ? len[2] : (i >= len[0] ? len[1] : len[0]));
	   		
			L[i].first = P[step - 1][i]; 
			L[i].second = i + count < length ? P[step - 1][i + count] : -1;
			L[i].p = i;
    	}
    	
 		sort(L, L + total, cmp);
 		
        for (i = 0; i < total; i++)
            P[step][L[i].p] = i > 0 && L[i].first == L[i - 1].first && L[i].second == L[i - 1].second ? 
            	P[step][L[i - 1].p] : i;
    }
    
    for(i = 0; i < total; i++) B[i] = i;
    sort(B, B + total, comp2);
    
    for(i = 1; i < total; i++)
    {
	    int k;
	    int x = B[i], y = B[i - 1];
	    
	    LCP[i] = 0; 
	    for (k = step - 1; k >= 0 && x < total && y < total; k--) 
	        if (P[k][x] == P[k][y]) 
	            x += 1 << k, y += 1 << k, LCP[i] += 1 << k; 
    }
    
    /*for(i = 0; i < total; i++) 
    	cout << LCP[i] << ' ';
    cout << endl;*/
} 

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int i, j, k, l, sum = 0;
	int tc, t, d, x, y, a, b, r, n, current, first;
	char ch;
	bool flag;
	
	scanf("%d", &tc);
	
	for(t = 1; t <= tc; t++)
	{
		scanf("%s", str[0]);
		len[0] = strlen(str[0]) + 1;
		scanf("%s", str[1]);
		len[1] = strlen(str[1]) + 1 + len[0];
		scanf("%s", str[2]);
		len[2] = strlen(str[2]) + 1 + len[1];
		
		mx = max3(len[0], len[1] - len[0], len[2] - len[1]);
		
		suffixArray();
		
		int lcs = 0;
		bool c[3];
		for(i = 0; i+2 < len[2]; i++)
		{
			c[0] = c[1] = c[2] = false;
			for(j = i; j < i+3; j++)
				B[j] < len[0] ? c[0] = true : (B[j] < len[1] ? c[1] = true : c[2] = true);
			if(c[0] && c[1] && c[2])
				if(lcs < min(LCP[i+1], LCP[i+2])) lcs = min(LCP[i+1], LCP[i+2]);
		}
		
		printf("Case %d: %d\n", t, lcs);
		
	}
		
	return 0;
}

/*
Solution submitted by: Rafi Kamal, BUET 10

If you want to contribute, please fork this repository or send your solution with a brief 
description of your idea to rafikamal93 AT gmail DOT com

*/
