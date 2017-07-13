/*
Algorithm: Kruskal

Explanation: Here we need to apply kruskal algorithm directly. But the problem is that we need to handle strings as vertices.
	     So using a map data structure to map a value for each vertex. Finally we need to check for every vertex 
	     whether they are connected or not.
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
lli id[55];
void initialize()
{
	for(lli i=0;i<55;i++)
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
lli minimum(vector<pair<lli,pair<lli,lli> > >v,lli n)
{
	lli i,j,k1,k,l=0;
	for(i=0;i<v.size();i++)
	{
		j=v[i].second.first;
		k1=v[i].second.second;
		k=v[i].first;
		if(root(j)!=root(k1))
		{
			l+=k;
			union1(j,k1);
		}
	}
	k=root(1);
	for(lli i=2;i<=n;i++)
	{
		if(root(i)!=k)
		return -1;
	}
	return l;
}
int main()
{
	lli t,tc=1;
	scanf("%lld",&t);
	while(t--)
	{
	 lli n;
	 scanf("%lld",&n);
	 map<string,lli>m;
	 string s,s1;
	 char s2[100],s3[100];
	 lli i,j,k,l;
	 vector<pair<lli,pair<lli,lli> > >g;
	 for(i=0;i<n;i++)
	 {
	 	scanf(" %s %s %lld",s2,s3,&j);
	 	s=s2;
		s1=s3;
	 	if(m.find(s)==m.end())
	 	{
		 	m[s]=m.size();
		}
	 	if(m.find(s1)==m.end())
	 	{
		 	m[s1]=m.size();
		}
	 	g.pb(mp(j,mp(m[s],m[s1])));
         }
	 initialize();
	 sort(all(g));
	 k=minimum(g,m.size());
	 if(k!=-1)
	 printf("Case %lld: %lld\n",tc++,k);	
	 else
	 printf("Case %lld: Impossible\n",tc++);
	}
	return 0;
}
/*
Solution submitted by: Anil Kumar Kasaragadda,NIT Rourkela.
If you want to contribute, please fork this repository or send your solution to 
rafikamal93@gmail.com
*/
