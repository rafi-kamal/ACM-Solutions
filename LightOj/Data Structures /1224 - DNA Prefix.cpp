#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stack>
#include <string>     
#include <map>
#include <list>
#include <queue>
#include <utility>

#define SIZE 50005
#define MOD 20071027
#define clr(a) memset(a, 0, sizeof a)
#define reset(a) memset(a, -1, sizeof a)

#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))

#define max3(x, y, z) max(max(x, y), max(y, z)) 

using namespace std;

int mp[30];

class Trie
{
	public:
	int prefix;
	int level;
	Trie *childs[4];
	
	Trie(int level)
	{
		prefix = 0;
		this->level = level;
		for(int i = 0; i < 4; i++) childs[i] = NULL;
	}
	
	~Trie()
	{
		for(int i = 0; i < 4; i++)
			if(childs[i] != NULL) delete childs[i];
	}
	
	void add(char *word)
	{
		prefix++;
		if(*word == '\0') return;
		if(childs[mp[*word]] == NULL) childs[mp[*word]] = new Trie(level+1);
		childs[mp[*word]]->add(word+1);
	}
} *root;

long long dfs()
{
	long long mx = 0;
	
	stack<Trie *> s;
	s.push(root);
	
	Trie *node;
	while(!s.empty())
	{
		node = s.top();
		s.pop();
		if(node->level * node->prefix > mx) mx = node->level * node->prefix;
		for(int i = 0; i < 4; i++)
			if(node->childs[i] != NULL) s.push(node->childs[i]);
	}
	
	return mx;
}

int main()
{	
	//freopen("input.txt", "r", stdin);
	
	int m, n, i, j, k, sum;
	int a, b, x, y;
	int tc, t;
	
	scanf("%d", &tc);
	
	mp['A'] = 0;
	mp['C'] = 1;
	mp['G'] = 2;
	mp['T'] = 3;
	
	for(t = 1; t <= tc; t++)
	{
		bool flag = true;
		char str[SIZE];
		root = new Trie(0);
		scanf("%d", &n);
		getchar();
		
		for(i = 0; i < n; i++)
		{
			gets(str);
			root->add(str);
		}
		printf("Case %d: %lld\n", t, dfs());

		delete root;
	}
	
	return 0;
}

