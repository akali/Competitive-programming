#include <bits/stdc++.h>

using namespace std;

const int K = 26;

struct node {
	int nxt[K];
	int len, num, lnk;
} t[500500];

string s;
int suff, sz;

void add (int pos) {
	char c = s[pos];
	int nxt = c - 'a';
	int cur = suff;
	int curlen = 0;

	while (true) {
		int curlen = t[cur].len;
		if (pos - curlen - 1 >= 0 && s[pos] == s[pos - curlen - 1])
			break;
		cur = t[cur].lnk;
	}

	if (t[cur].nxt[nxt]) {
		suff = t[cur].nxt[nxt];
		t[suff].num++;
		return;
	}

	int ver = ++sz;
	suff = ver;
	t[cur].nxt[nxt] = ver;
	t[ver].len = t[cur].len + 2;
	
	if (t[ver].len == 1) {
		t[ver].lnk = 2;
		t[ver].num = 1;
		return;
	}
	
	while (true) {
		cur = t[cur].lnk;
		curlen = t[cur].len;
		if (pos - curlen - 1 >= 0 && s[pos] == s[pos - curlen - 1]) {
			t[ver].lnk = t[cur].nxt[nxt];
			break;
		}
	}
	
	// t[ver].num++;
	t[ver].num += t[t[ver].lnk].num;
	// t[t[ver].lnk].num += t[ver].num;
}

void init () {
	t[1].lnk = 1; t[1].len = -1;
	t[2].lnk = 1; t[2].len = 0;
	suff = sz = 2;
}

vector <int> q;

int main () {
	#ifdef lcl
		freopen (".in", "r", stdin);
	#endif
	
	// freopen ("palindrome.in", "r", stdin);
	// freopen ("palindrome.out", "w", stdout);

	cin >> s;
	
	long long res = 0;
	
	init ();

	for (int i = 0; i < s.size(); ++i) {
		add (i);
		// res += t[suff].num;
		cerr << i << " " << t[suff].len << " " << t[suff].num << endl;
		if (res < 1ll * t[suff].len * t[suff].num) {
			res = 1ll * t[suff].len * t[suff].num;
		}
	}

	cout << res;
	
	return 0;
}
