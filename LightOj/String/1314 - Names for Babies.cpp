/*
Algorithm: KMP, Suffix Array 
A nice tutorial on KMP: http://www.iti.fh-flensburg.de/lang/algorithmen/pattern/kmpen.htm
Tutorial on Suffix Array: http://www.stanford.edu/class/cs97si/suffix-array.pdf

First you need to know how to find the number of distinct substrings of a string using suffix
array. The idea has been described on the solution of problem 4 in the tutorial link I've given. 
In code, you can do this in:
sum = 0;
for(i = 0; i < len; i++)
{
    k = (len - B[i]) - LCP[i];
    if(k > 0) sum += k;
}

B[i] deontes the starting index of the i-th suffix in sorted order. For example, for the string
abaab:
B[0] = 2 aab
B[1] = 3 ab
B[2] = 0 abaab
B[3] = 4 b
B[4] = 1 baab

so len - B[i] = length of the i-th suffix in sorted order
len - B[0] = 3 aab
len - B[1] = 2 ab
len - B[2] = 5 abaab
len - B[3] = 1 b
len - B[4] = 4 baab

LCP[i] deontes the longest common prefix of the i-th and (i-1)th suffix in sorted order.
LCP[0] = 0	aab		distinct substrings: aab aa a, no common prefix
			null	k = (len - B[i]) - LCP[i] = 3 - 0 = 3
			
LCP[1] = 1 	ab		distinct substrings: ab, common prefix: a; so a not counted
			aab		k = (len - B[i]) - LCP[i] = 2 - 1 = 1
			
LCP[2] = 2	abaab	distinct substrings: abaab abaa aba, common prefix: ab; so ab, a not counted
			ab		k = (len - B[i]) - LCP[i] = 5 - 2 = 3
			
LCP[3] = 0	b		distinct substrings: b, no common prefix
			abaab	k = (len - B[i]) - LCP[i] = 1 - 0 = 1
			
LCP[4] = 1	baab	distinct substrings: baab baa ba, common prefix: b; so b not counted
			b		k = (len - B[i]) - LCP[i] = 4 - 1 = 3
			
So total distinct substrings = 3+1+3+1+3 = 11.

All you need to do is now filter out the substrings which are not in the specified range (less then
p or greater then q). So the code becomes:

for(i = 0; i < len; i++)
{
    k = min(len - B[i], q) - max(LCP[i], p-1);
    if(k > 0) sum += k;
}

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

#define SIZE 100005
#define digit(c) ((c) - '0')
#define PI 3.141592654
#define MAX_INT 2147483646
#define DIFF 10E-7
#define CONST 1000000007

using namespace std;

int row, column, step;
int B[SIZE];
char str[SIZE];

#define MAXLG 20
struct entry 
{ 
    int first, second, p;
} L[SIZE];
int P[MAXLG][SIZE];
int LCP[SIZE];

int cmp(struct entry a, struct entry b) 
{ 
    return a.first == b.first ? (a.second < b.second ? 1 : 0) : (a.first < b.first ? 1 : 0); 
}

int comp2(const int& a, const int& b)
{	
	return P[step-1][a] < P[step-1][b];
}

void suffixArray(char *A) 
{ 
    int i, count;
    int len = strlen(A);
    
    for (i = 0; i < len; i ++) 
        P[0][i] = A[i] - 'a';
    
    for (step = 1, count = 1; count>>1 < len; step++, count <<= 1)
    { 
    	for (i = 0; i < len; i++)
    	{ 
			L[i].first = P[step - 1][i]; 
			L[i].second = i + count < len ? P[step - 1][i + count] : -1;
			L[i].p = i;
    	}
    	
 		sort(L, L + len, cmp);
 		
        for (i = 0; i < len; i ++) 
            P[step][L[i].p] = i > 0 && L[i].first == L[i - 1].first && L[i].second == L[i - 1].second ?
				P[step][L[i - 1].p] : i;
    }
    
    for(i = 0; i < len; i++) B[i] = i;
    sort(B, B + len, comp2);
    
    for(i = 1; i < len; i++)
    {
	    int k;
	    int x = B[i], y = B[i - 1];
	    
	    LCP[i] = 0; 
	    for (k = step - 1; k >= 0 && x < len && y < len; k--) 
	        if (P[k][x] == P[k][y]) 
	            x += 1 << k, y += 1 << k, LCP[i] += 1 << k; 
    }
    /*
    for(i = 0; i < len; i++) 
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
	int mx;
	bool flag;
	unsigned long long ln;
	
	scanf("%d", &tc);
	
	for(t = 1; t <= tc; t++)
	{
		int p, q;
		scanf("%s", str);
		scanf("%d %d", &p, &q);
		
		suffixArray(str);
		int len = strlen(str);
		sum = 0;
		for(i = 0; i < len; i++)
		{
			k = min(len - B[i], q) - max(LCP[i], p-1);
			if(k > 0) sum += k;
		}
		
		printf("Case %d: %d\n", t, sum);
		
	}
		
	return 0;
}

/*
Solution submitted by: Rafi Kamal, BUET 10

If you want to contribute, please fork this repository or send your solution with a brief 
description of your idea to rafikamal93 AT gmail DOT com

*/
