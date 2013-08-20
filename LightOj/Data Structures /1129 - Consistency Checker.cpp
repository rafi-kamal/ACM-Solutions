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

#define SIZE 10005
#define MOD 20071027
#define clr(a) memset(a, 0, sizeof a)
#define reset(a) memset(a, -1, sizeof a)

#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))

#define max3(x, y, z) max(max(x, y), max(y, z)) 

using namespace std;

class Trie
{
	bool end;
	Trie *childs[10];
	
public:	
	Trie()
	{
		end = false;
		for(int i = 0; i < 10; i++) childs[i] = NULL;
	}
	void del()
	{
		for(int i = 0; i < 10; i++)
			if(childs[i] != NULL)
			{
				childs[i]->del();
				delete childs[i];
			}
	}
	bool addWord(string &word, int pos)
	{
		if(end) return false;
		if(pos == word.length()) return end = true;
		const char c = word[pos] - '0';
		if(childs[c] == NULL)
			childs[c] = new Trie();
		return childs[c]->addWord(word, ++pos);
	}
} *root;

bool cmp(const string &str1, const string &str2)
{
	return (str1.length() == str2.length() ? str1 < str2 : str1.length() < str2.length());
}

string str[SIZE];

int main()
{	
	//freopen("input.txt", "r", stdin);
	
	int m, n, i, j, k, sum;
	int a, b, x, y;
	int tc, t;
	
	scanf("%d", &tc);
	
	for(t = 1; t <= tc; t++)
	{
		bool flag = true;
		root = new Trie();
		scanf("%d", &n);
		getchar();
		
		for(i = 0; i < n; i++)
			cin >> str[i];
		
		sort(str, str+n, cmp);
		for(i = 0; i < n && flag; i++)
			flag = root->addWord(str[i], 0);
		root->del();
		delete root;
		
		printf("Case %d: %s\n", t, (flag ? "YES" : "NO"));
	}
	
	return 0;
}

