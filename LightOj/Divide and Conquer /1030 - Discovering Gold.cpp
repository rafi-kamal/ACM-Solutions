#include <cstdio>
#include <iostream>

using namespace std;

double a[200];

int main()
{
    //freopen("input.txt", "r", stdin);
    int tc, i, n, j, k, m;
    double sum;

    scanf("%d", &tc);

    for(i = 1; i <= tc; i++)
    {
        scanf("%d", &n);
        for(j = 0; j < n; j++)
            scanf("%lf", &a[j]);
        for(j = n - 2; j >= 0; j--)
        {
            sum = m = 0;
            for(k = j + 1; k < n && m < 6; k++, m++)
                sum += a[k];
            a[j] += sum / m;
        }
        /*for(j = 0; j < n; j++)
            cout << a[j] << ' ';*/
        printf("Case %d: %.7lf\n", i, a[0]);
    }

    return 0;
}


