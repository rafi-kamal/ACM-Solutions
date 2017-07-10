/*
Algorithm: Kruskal

Explanation: Here we make a adjacency list from the adjacency matrix only for those vertices 
			 which have non-zero value and are not self edges.
			 Get the total sum of cables and remove the least amount of cable required to 
			 connect all rooms which gives the maximum donation that can be made. 
*/
#include<bits/stdc++.h>
using namespace std;
#define opt ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
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
lli id[100];
lli n;
void initialize()
{
	for(lli i=0;i<100;i++)
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
	id[root(x)]=id[root(y)];
}
lli kruskal(vector<pair<lli,pair<lli,lli> > >v)
{
	lli i,j,k,l,p=0;
	for(i=0;i<v.size();i++)
	{
		j=v[i].second.first;
		k=v[i].second.second;
		l=v[i].first;
		if(root(j)!=root(k))
		{
		 p+=l;
		 union1(j,k);
		}
	}
	k=root(0);
	for(i=1;i<n;i++)
	if(root(i)!=k)
	return -1;
	else
	return p;
}
int main()
{
	lli t,tc=1;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		vector<pair<lli,pair<lli,lli> > >g;
	    lli i,j,k,l=0;
	    for(i=0;i<n;i++)
	    {
	    	for(j=0;j<n;j++)
	    	{
	    		scanf("%lld",&k);
	    		l+=k;
	    		if(k!=0 && i!=j)
	    		g.pb(mp(k,mp(i,j)));
			}
		}
		sort(all(g));
		initialize();
		k=kruskal(g);
		if(k!=-1)
		printf("Case %lld: %lld\n",tc++,l-k);
		else
		printf("Case %lld: -1\n",tc++);
	}
	return 0;
}
/*
Solution submitted by: Anil Kumar Kasaragadda,NIT Rourkela.

If you want to contribute, please fork this repository or send your solution to 
rafikamal93@gmail.com
*/
