/*
Algorithm: Kruskal + DSU

Explanation: Here we have to first check for edge,will it make a single connected component or not.
	     Once it is connected component then for each edge apply Kruskal Algorithm.
	     The useful optimization is we have to take only the MST as a graph each time.
             (If not understood,there is a clear cut expanation in forum.Have a look at it.) 
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
lli gcd(lli a, lli b){return b?gcd(b,a%b):a;}
lli power(lli a,lli b){lli ans=1;while(b){if(b&1){ans=(ans*a)%mod;}a=(a*a)%mod;b>>=1;}return ans;}
lli n,m;
lli id[205];
void initialize()
{
	for(lli i=0;i<205;i++)
	id[i]=i;
}
lli root(lli x)
{
	while(id[x]!=x)
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
lli minimum(vector<pair<lli,pair<lli,lli> > >g,vector<pair<lli,pair<lli,lli> > >&v)
{
	
	lli i,c,j,k,l=0;
	for(i=0;i<g.size();i++)
	{
		j=g[i].second.first;
		k=g[i].second.second;
		c=g[i].first;
		if(root(j)!=root(k))
		{  
		    l+=c;
			v.pb(mp(c,mp(j,k)));
			union1(j,k);
		}
	}
	return l;
}
bool dsu(vector<pair<lli,pair<lli,lli> > >g)
{
	lli i,j,k,l;
	for(i=0;i<g.size();i++)
	{
		union1(g[i].second.first,g[i].second.second);
	}
	k=root(1);
	for(i=2;i<=n;i++)
	{
		if(root(i)!=k)
		return 0;
	}
	return 1;
}
int main()
{
	lli t,tc=1;
	scanf("%lld",&t);
	while(t--)
	{
	   printf("Case %lld:\n",tc++);
	   scanf("%lld %lld",&n,&m);
	   vector<pair<lli,pair<lli,lli> > >g,v;
	   lli i,j,k,l,ok=0,min=0,s=0;
	   for(i=0;i<m;i++)
	   {
	   	initialize();
	   	min=0;
	   	scanf("%lld %lld %lld",&j,&k,&l);
	   	g.pb(mp(l,mp(j,k)));
	   	if(ok==0)
	   	{
			s=dsu(g);
			if(s==1)
			{
		 	     ok=1;
		 	     initialize();
			}
	   	}
	   	if(ok==1)
	   	{
	   		sort(all(g));
	   		min=minimum(g,v);
	   		g.clear();
       	    		g.assign(v.begin(),v.end());
        		v.clear();
	   		printf("%lld\n",min);
	   	}
	   	else
	   	{
	   		 printf("-1\n");	
		}
	   }
	}
	return 0;
}
/*
Solution submitted by: Anil Kumar Kasaragadda,NIT Rourkela.

If you want to contribute, please fork this repository or send your solution to 
rafikamal93@gmail.com
*/
