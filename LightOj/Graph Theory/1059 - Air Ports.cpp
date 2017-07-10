/*
Algorithm: Kruskal + DFS

Explanation: We will build a road only if cost of building road is less than building an airport.
	     So take only edges(roads) which has less cost than building airport.
	     Finally apply DFS and get the number of connected components(number of airports). 
*/
#include<bits/stdc++.h>
using namespace std;
#define opt 	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define lli 	long long int
#define mod	1000000007
#define inf     1000000000000000000
#define MX1	100005
#define MX2	10000004
#define pi	acos(-1)
#define pb      push_back
#define vlli    vector<lli>
#define plli    vector<pair<lli,lli> >
#define mp      make_pair
#define all(v)  v.begin(),v.end()
#define test    int t;cin>>t;
lli m,n;
vector<pair<lli,pair<lli,lli> > >g;
vector<lli>v[10005];
bool visit[10005];
lli id[10005];
void initialize()
{
	for(lli i=0;i<10005;i++)id[i]=i;
}
lli root(lli x)
{
	while(x!=id[x])
	{
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}
void union1(lli x,lli y)
{
	id[root(x)]=id[root(y)];
}
lli minimum()
{
	lli i,j,k,l,mc=0;
	for(i=0;i<g.size();i++)
	{
		j=g[i].second.first;
		k=g[i].second.second;
		l=g[i].first;
		if(root(j)!=root(k))
		{
			mc+=l;
			v[j].pb(k);
			v[k].pb(j);
			union1(j,k);
		}
	}
	return mc;
}
void dfs(lli x)
{
	visit[x]=1;
	for(lli i=0;i<v[x].size();i++)
	{
		if(visit[v[x][i]]==0)
		dfs(v[x][i]);
	}
}
int main()
{
	lli t,tc=1;
	scanf("%lld",&t);
	while(t--)
	{
		g.clear();
		for(lli i=0;i<10005;i++)
		v[i].clear();
		memset(visit,0,sizeof(visit));
		lli ca; 					//cost of building airport
		scanf("%lld %lld %lld",&n,&m,&ca);
		lli i,j,k,l;
		for(i=0;i<m;i++)
		{
			scanf("%lld %lld %lld",&j,&k,&l);
			if(l<ca)                        	//If cost of building road is less than cost of airport 
			g.pb(mp(l,mp(j,k)));
		}
		sort(all(g));
		lli roads_min,airports=0;
		initialize();
		roads_min=minimum();
		for(i=1;i<=n;i++)
		{
			if(visit[i]==0)
			{
				dfs(i);
				airports++;
			}
		}
		lli total_cost = (airports*ca)+(roads_min);
		printf("Case %lld: %lld %lld\n",tc++,total_cost,airports);
	}
	return 0;
}
/*
Solution submitted by: Anil Kumar Kasaragadda,NIT Rourkela.

If you want to contribute, please fork this repository or send your solution to 
rafikamal93@gmail.com
*/
