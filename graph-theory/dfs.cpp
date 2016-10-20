/*
 * Simple depth first search
 * Counting amout of connected components in graph with n vertices and m edges
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define foreach(it, S) for (__typeof (S.begin()) it = S.begin(); it != S.end(); it++)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define _ ios_base :: sync_with_stdio(false); cin.tie(NULL);

#ifdef inputf
# define fname ""
#else
# define fname "" // <- Here
#endif

#ifndef lcl
# define cerr if (0) cout
#endif

inline void operator += (pair <int, int> &a, pair <int, int> b) {
	a.first += b.first;
	a.second += b.second;
}

template <typename T> T gcd(T a, T b) {
	return b ? gcd (b, a % b) : a;
}

const double eps = 1e-9;
const int MAXN = (int)2e5 + 256;
const int MOD = (int)1e9 + 7, INF = (int)1e9;
const ll INFLL = (ll)1e18;

vector <int> g[MAXN];
bool used[MAXN];
int cnt;

void dfs(int v) {
	used[v] = true;
	for (auto to : g[v])
		if (!used[to])
			dfs(to);
}

int main() { // _
	#ifdef lcl
		freopen(fname".in", "r", stdin);
		freopen(fname".out", "w", stdout);
	#endif
	
	int n, m; scanf("%d%d", &n, &m);

	for (int i = 1; i <= m; ++i) {
		int v, u; scanf("%d%d", &v, &u);
		g[v].push_back(u);
		g[u].push_back(v);
	}

	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			++cnt;
			dfs(i);
		}
	}

	printf("%d\n", cnt);
		
	return 0;
}

