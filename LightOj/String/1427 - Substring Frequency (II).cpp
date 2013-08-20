#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<cstdlib>
#include<string>
#include<set>
#include<limits>
#include<iomanip>
#include<fstream>
#include<sstream>
#define INF 2147483647
#define LLD int
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define BD(i, j) (i >= 0 && i < n && j >= 0 && j < m)
#define PRINT_VAR(X) (cout << #X << " -> " << X << endl)
#define PI acos(0)
#define MAX_INT 2147483647
#define SIZE 5005
#define MOD 10056
using namespace std;
int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};
/* right, down, lft, up */
int m, n, res;
typedef pair<int, int> Point;

struct NODE {
	int cnt;
	bool vis;
	NODE *next[27];
	vector <NODE *> out;
	NODE() {
		for(int i = 0; i < 27; i++) {
            next[i] = NULL;
		}
		out.clear();
		vis = false;
		cnt=0;
	}
	
	~NODE(){
        for(int i = 1; i < 27; i++)
            if(next[i] != NULL && next[i] != this)
                delete next[i];
	}
}*root;

void buildtrie(char dic[][SIZE],int n) {

    root = new NODE();
	for(int i = 0; i < n; i++) {
		NODE *p = root;
		for(int j = 0; dic[i][j] ; j++) {
			char c = dic[i][j]- 'a' + 1;
			if(!p->next[c])
                p->next[c] = new NODE();
			p = p->next[c];
		}
	}
	queue <NODE *> q;
	for(int i = 0; i < 27; i++) {
		if(!root->next[i])
            root->next[i] = root;
		else {
			q.push(root->next[i]);
			root->next[i]->next[0] = root;
		}
	}
	while(!q.empty()) {
		NODE *u = q.front(); q.pop();
		for(int i = 1; i < 27; i++){
            if(u->next[i]) {
                NODE *v = u->next[i];
                NODE *w = u->next[0];
                while( !w->next[i] )
                    w = w->next[0];
                v->next[0] = w = w->next[i];
                w->out.push_back(v);
                q.push(v);
            }
		}
    }
}

void aho_corasick(NODE *p, char *word) {
	for(int i = 0; word[i]; i++) {
		char c = word[i]-'a'+1 ;
		while(!p->next[c])
            p = p->next[0];
		p = p->next[c];
		p->cnt++;
	}
}

int dfs( NODE *p ) {
	if(p->vis) return p->cnt;
	for(int i = 0; i < p->out.size(); i++)
        p->cnt += dfs(p->out[i]);
	p->vis = true;
	return p->cnt;
}

char query[1000100];
char dic[SIZE][SIZE];

int main()
{
	int t, tc, y, z;
    int i, j, k, l, h;
    char ch;

#ifndef ONLINE_JUDGE
   	freopen("input.txt", "r", stdin);
#endif
	scanf ("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int n;
        scanf("%d",&n);

        scanf("%s",query);

        for (int i=0;i<n;++i) {
            scanf("%s",dic[i]);
        }

        buildtrie(dic, n);

        aho_corasick(root, query);

        printf("Case %d:\n",t);

        for(int i = 0; i < n; i++) {
            NODE *p = root;
            for(int j = 0; dic[i][j]; j++) {
                char c = dic[i][j] -'a' +1;
                p = p->next[c];
            }
            printf("%d\n", dfs(p));
        }
        delete root;
	}
   
	return 0;
}


