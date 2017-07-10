/*
Algorithm: Kruskal 

Explanation: In Kruskal's Algorithm if we sort the edges in ascending order we get minimum spanning tree,
			 if sorted in descending order we get maximum spanning tree.
			 If sort by ascending order we get best possible connection 
			 otherwise we get worst possible connection.  
*/
#include<bits/stdc++.h>
using namespace std;
#define opt 	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define lli 	long long int
#define mod		1000000007
#define inf     1000000000000000000
#define MX1		100005
#define MX2		10000004
#define pi		acos(-1)
#define pb      push_back
#define vlli    vector<lli>
#define plli    vector<pair<lli,lli> >
#define mp      make_pair
#define all(v)  v.begin(),v.end()
#define test    int t;cin>>t;
lli id[105];
void initialize()
{
	for(lli i=0;i<105;i++)
	{
	    id[i]=i;
	}	
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
	id[root(x)]=id[root(y)];
}
lli minimum(vector<pair<lli,pair<lli,lli> > >v)
{
	sort(v.begin(),v.end());
	initialize();
	lli i,j,k,l,m=0;
	for(i=0;i<v.size();i++)
	{
		j=v[i].first;
		k=v[i].second.second;
		l=v[i].second.first;
		if(root(k)!=root(l))
		{
			m+=j;
			union1(k,l);
		}
	}
	return m;
}
lli maximum(vector<pair<lli,pair<lli,lli> > >v)
{
    sort(v.rbegin(),v.rend());
	initialize();
	lli i,j,k,l,m=0;
	for(i=0;i<v.size();i++)
	{
		j=v[i].first;
		k=v[i].second.second;
		l=v[i].second.first;
		if(root(k)!=root(l))
		{
			m+=j;
			union1(k,l);
		}
	}
	return m;	
}
int main()
{
	lli t,tc=1;
	scanf("%lld",&t);
	while(t--)
	{
		lli n;
		scanf("%lld",&n);
		lli i,j,k,l;
		vector<pair<lli,pair<lli,lli> > >g;
		while(1)
		{
			scanf("%lld %lld %lld",&j,&k,&l);
			if(j==0 && k==0 && l==0)
			break;
			g.pb(mp(l,mp(j,k)));
		}
		lli a,b;
		a=minimum(g);
		b=maximum(g);
		if((a+b)%2==0)
		printf("Case %lld: %lld\n",tc++,(b+a)/2);
		else
		printf("Case %lld: %lld/%lld\n",tc++,a+b,2);
	}

	return 0;
}

/*
Solution submitted by: Anil Kumar Kasaragadda,NIT Rourkela.
If you want to contribute, please fork this repository or send your solution to 
rafikamal93@gmail.com
*/
