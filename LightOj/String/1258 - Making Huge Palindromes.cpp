/*
Algorithm: KMP 
A nice tutorial on KMP: http://www.iti.fh-flensburg.de/lang/algorithmen/pattern/kmpen.htm

Consider the 4th test case
P = anncbaaababaaa
Let
Q = aaababaaabcnna (reverse of P)

Now look how can we construct the shortest palindrome by adding character to the right of P,
with the help of Q

P : anncbaaababaaa|||||
Q : |||||aaababaaabcnna
Ans:anncbaaababaaabcnna

So all we need to do is search for the longes prefix of Q in P. You can do this by using KMP.
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

#define LongInt long long
#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

#define SIZE 1000005
#define digit(c) ((c) - '0')
#define PI 3.141592654
#define MAX 2147483646
#define DIFF 10E-7
#define CONST 1000000007

using namespace std;

int m, n;

char p[SIZE];
char q[SIZE];
int b[SIZE];


void kmpPreprocess(char *substr, int *n)
{
	int i = 0, j = -1;
	b[i] = j;
	
	while(i < m)
	{
		while(j >= 0 && substr[i] != substr[j])
			j = b[j];
		i++, j++;
		b[i] = j;
	}
}

int kmpSearch(char *str, char *substr, int *b)
{
	int i = 0, j = 0;
	
	while(i < n)
	{
		while(j >= 0 && str[i] != substr[j])
			j = b[j];
		i++, j++;
	}
	return j;
}	

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int i, j, k, sum = 0;
	int tc, t, d, x, y;
	unsigned char ch;
	int mx;
	
	scanf("%d", &tc);
	getchar();
	
	for(t = 1; t <= tc; t++)
	{
		gets(p);
		n = m = strlen(p);
		reverse_copy(p, p + n, q);
		kmpPreprocess(q, b);
		
		int match = kmpSearch(p, q, b);
		printf("Case %d: %d\n", t, 2*n - match);
	}
		
	return 0;
}

/*
Solution submitted by: Rafi Kamal, BUET 10

If you want to contribute, please fork this repository or send your solution with a breif 
description of your idea to rafikamal93 AT gmail DOT com

*/
