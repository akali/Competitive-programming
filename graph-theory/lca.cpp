#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int MaxN = (int)(1e5);
vector <int> g[MaxN];
int n, m;
int lvl[MaxN], prnt[MaxN];
bool used[MaxN];

void dfs (int v, int level) {
	used[v] = true;
	lvl[v] = level;
	for (int i = 0; i < g[v].size(); i++) {
		if (!used[g[v][i]]) {
			prnt[g[v][i]] = v;
			dfs (g[v][i], level + 1);
		}
	}
}

int lca (int l, int r) {
	int h1 = lvl[l];
	int h2 = lvl[r];
	while (h1 != h2) {
		if (h1 > h2) {
			l = prnt[l];
			h1--;
		} else {
			r = prnt[r];
			h2--;
		}
	}
	while (l != r) {
		l = prnt[l];
		r = prnt[r];
	}
	return l;
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back (y);
		g[y].push_back (x);
	}
	dfs (1, 1);
	int t; cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		cout << lca (l, r) << endl;
	}
	return 0;
}
