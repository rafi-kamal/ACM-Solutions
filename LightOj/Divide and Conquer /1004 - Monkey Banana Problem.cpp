#include <cstdio>
using namespace std;
 
int maxBanana(int[1020][1020], int);
 
int main()
{
    int test, t = 1, n, k, M[1020][1020];
    register int i, j;
 
    for(scanf("%d", &test); t<=test; ++t)
    {
        scanf("%d", &n);
 
        for(i = 1; i<=n; ++i)
        {
            for(k = n-i, j = 1; j<=k; ++j)
                    M[i][j] = 0;
            for(; j<=n; ++j)
                scanf("%d", &M[i][j]);
            M[i][j] = 0;
        }
 
        for(; i<=2*n-1; ++i)
        {
            for(k = i-n, j = 1; j<=k; ++j)
                    M[i][j] = 0;
            for(; j<=n; ++j)
                scanf("%d", &M[i][j]);
            M[i][j] = 0;
        }
 
        printf("Case %d: %d\n", t, maxBanana(M, n));
    }
 
    return 0;
}
 
int maxBanana(int M[1020][1020], int n)
{
    register int i, j;
 
    for(i = 2*n-2; i>=n; --i)
        for(j = i-n+1; j<=n; ++j)
            M[i][j] += (M[i+1][j]>=M[i+1][j+1] ? M[i+1][j] : M[i+1][j+1]);
    for(; i; --i)
        for(j = n-i+1; j<=n; ++j)
            M[i][j] += (M[i+1][j-1]>=M[i+1][j] ? M[i+1][j-1] : M[i+1][j]);
 
    return M[1][n];
}
 
