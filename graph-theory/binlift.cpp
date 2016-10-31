#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <assert.h>
#include <math.h>
#include <vector>
#include <time.h>
#include <queue>

using namespace std;

#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define file ""
#define pb push_back
#define F first
#define S second
#define mk_pr make_pair
#define _bits __builtin_popcount                                                                                                          

typedef long long ll;
typedef double ld;
typedef pair <ll, int> PII;    

const int maxn = 100100;
const int max_log = 21;
const int INF = 2e9 + 9; 

ostream & operator << (ostream &out, PII x) {
	out << "(" << x.F << ", " << x.S << ")"; 
	return out;
}

int n; 
vector <int> g[maxn];
int size[maxn];
int lvl[maxn], up[maxn][max_log];

void dfs(const int &x, const int &p = -1) {
	if (p != -1) { 
		lvl[x] = lvl[p] + 1;
		up[x][0] = p;
		forn(i, 1, 20)
			up[x][i] = up[up[x][i - 1]][i - 1];		
	}
	size[x] = 1;
	for (auto to : g[x]) {
		if (to == p) continue;
		dfs(to, x);
		size[x] += size[to];
	}	
}

void build_tree() {
	lvl[0] = -1;
	dfs(1);
}

int lca(int x, int y) {
	if (lvl[x] < lvl[y]) swap(x, y);  

	for1(i, 20, 0)     
		if (lvl[up[x][i]] >= lvl[y])
			x = up[x][i];   
	if (x == y) return x;   

	for1(i, 20, 0) 
		if (up[x][i] != up[y][i])
			x = up[x][i], y = up[y][i];      
	                                   
	return up[x][0];
}

int ancestor(int x, int len) {
	int p_lvl = lvl[x] - len;               
	for1(i, 20, 0) 
		if (lvl[up[x][i]] > p_lvl)  
			x = up[x][i];                 
	return x;
}

int q;
  
int main() {
#ifndef ONLINE_JUDGE
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);                          
#endif          
	scanf("%d", &n);
	forn(i, 1, n - 1) {
		int f = 0, t = 0;
		scanf("%d %d", &f, &t);
		g[f].pb(t);
		g[t].pb(f);
	}

	build_tree();             

	scanf("%d", &q);
	forn(i, 1, q) {
		int f = 0, t = 0;     
		scanf("%d %d", &f, &t);
		if (f == t) {
			printf("%d\n", n);
			continue;
		}
		if (lvl[f] < lvl[t]) swap(f, t);
		
		int p = lca(f, t);
		int way1 = (lvl[f] - lvl[p]);
		int way2 = (lvl[t] - lvl[p]);
		int way = way1 + way2;
		if (way % 2 == 1) {
		    printf("0\n");
			continue;
		}           
//		fprintf(stderr, "%d %d %d\n", p, way1, way2);		
		
		int ans = 0;
		if (lvl[f] != lvl[t]) {
			int f_mid = ancestor(f, way / 2); 
		    int mid = up[f_mid][0];
		    ans += size[mid] - size[f_mid];
		}
		else {
			int f_mid = ancestor(f, way / 2);
			int t_mid = ancestor(t, way / 2);     
			ans += n - size[f_mid] - size[t_mid];
		}

		printf("%d\n", ans);
	}

	return 0;
}                     