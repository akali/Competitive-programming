/*
 * Simple binary search
 */

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <time.h>
#include <cassert>
#include <map>
#include <set>
#include <stack>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <bitset>
#include <ctype.h>

#include <complex>

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

const int MAXN = 3e5 + 10;
int a[MAXN];
int main() { // _
#ifdef lcl
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout);
#endif
    
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        int l = 0, r = n;
        bool found = false;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (a[mid] > x) {
                r = mid;
            } else {
                l = mid;
                
            }
        }
        found = (a[l] == x);
        if (found) {
            puts("FOUND");
        } else {
            puts("NOT FOUND");
        }
    }
    
    return 0;
}

