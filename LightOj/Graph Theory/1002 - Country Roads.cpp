/*
Algorithm: BFS + Kruskal 

Explanation: It is obvious that we need to find the Minimum Spanning Tree(MST) first 
so as to eliminate maximum weight edges.
Then in this MST we can use BFS to keep track of maximum edge to a vertex in each level.
 
*/
#include<bits/stdc++.h>
using namespace std;
#define opt ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
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
lli gcd(lli a, lli b){return b?gcd(b,a%b):a;}
lli power(lli a,lli b){lli ans=1;while(b){if(b&1){ans=(ans*a)%mod;}a=(a*a)%mod;b>>=1;}return ans;}
plli tr[505];
bool visit[505];
lli dist[505];
lli id[505];
lli n,m;
void initialize()
{
	for(lli i=0;i<505;i++)
	{
		id[i]=i;
	}
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
	lli p=root(x);
	lli q=root(y);
	id[p]=id[q];	
}
void kruskal(pair<lli,pair<lli,lli> >g[])
{
	lli i,j,k,l;
	for(i=0;i<m;i++)
	{
		j=g[i].second.first;
		k=g[i].second.second;
		l=g[i].first;
		if(root(j)!=root(k))
		{
			tr[j].pb(mp(k,l));
			tr[k].pb(mp(j,l));
			union1(j,k);
		}
	}
	
}
void bfs(lli s)
{
	lli i,j,k,l;
	queue<pair<lli,lli> >q;
	dist[s]=0;
	visit[s]=1;
	q.push(mp(s,0));
	while(!q.empty())
	{
		j=q.front().first;
		k=q.front().second;
		q.pop();
		for(i=0;i<tr[j].size();i++)
		{
			if(visit[tr[j][i].first]==0)
			{
				if(tr[j][i].second>k)
				{
				 dist[tr[j][i].first]=tr[j][i].second;
				 q.push(mp(tr[j][i].first,tr[j][i].second));
				}
				else
				{
				 dist[tr[j][i].first]=k;
				 q.push(mp(tr[j][i].first,k));
				}
				visit[tr[j][i].first]=1;
			}
		}
		
	}
}
int main()
{
	lli t,tc=1;
	scanf("%lld",&t);
	while(t--)
	{
		memset(visit,0,sizeof(visit));
		memset(dist,0,sizeof(dist));
		scanf("%lld %lld",&n,&m);
		lli i,j,k,l,s;
		pair<lli,pair<lli,lli> >g[m+5];
		for(i=0;i<505;i++)
		tr[i].clear();
		for(i=0;i<m;i++)
		{
			scanf("%lld %lld %lld",&j,&k,&l);
			g[i]=mp(l,mp(j,k));
		}
		scanf("%lld",&s);
		sort(g,g+m);
		initialize();
		kruskal(g);
		bfs(s);
		        printf("Case %lld:\n",tc++);
		for(i=0;i<n;i++)
		{
			if(i==s)
			printf("%lld\n",0);
			else if(dist[i]==0)
			printf("Impossible\n");
			else
			printf("%lld\n",dist[i]);
		}
	
	}
	return 0;
}
/*
Solution submitted by: Anil Kumar Kasaragadda,NIT Rourkela.
If you want to contribute, please fork this repository or send your solution to 
rafikamal93@gmail.com
*/
