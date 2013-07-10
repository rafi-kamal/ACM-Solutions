/*
Algorithm: KMP 
A nice tutorial on KMP: http://www.iti.fh-flensburg.de/lang/algorithmen/pattern/kmpen.htm

The brute force method of string matching requires O(n*m) time. In this problem 1 <= n,m <= 10^6,
so brute force solution won't work.

KMP (Knuth-Morris-Pratt Algorithm) is a string mathing algorithm which runs in O(m+n). So you
can use KMP in this problem. My solution is a straightforward implementation of KMP, I had to
just ensure that as soon as the algorithm finds a new match, instead of terminating there
it increments a counter.

*/

#include <stdio.h>
#include <string.h>

char str[1100000];
char substr[1100000];
int b[1100000];

void kmpPreprocess(char *substr)
{
    const int m = strlen(substr);
    int i = 0, j = -1;

    b[i] = -1;
    while(i < m)
    {
        while(j >= 0 && substr[i] != substr[j])
            j = b[j];

		i++;
        j++;
        b[i] = j;
    }
}

int kmp(char *str, char *substr)
{
    int i=0, j=0, count = 0;
    const int n = strlen(str);
    const int m = strlen(substr);

	kmpPreprocess(substr);
    while (i<n)
    {
        while (j>=0 && str[i]!=substr[j])
            j=b[j];

        i++;
        j++;

        if (j==m)
        {
            count++;
            j=b[j];
        }
    }
    return count;
}

int main()
{
	int tc, i;

	scanf("%d", &tc);

	for(i = 0; i <tc; i++)
	{
		scanf("%s %s", str, substr);

		printf("Case %d: %d\n", i + 1, kmp(str, substr));
	}

	return 0;
}

/*
Solution submitted by: Rafi Kamal, BUET 10

If you want to contribute, please fork this repository or send your solution with a breif 
description of your idea to rafikamal93 AT gmail DOT com

*/

