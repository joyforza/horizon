#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 10000000000000001ll
#define mod 1000000007
#define N 100010
#define lg 18
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
ll l1, r1, l2, r2, k;

ll cut(ll u, ll v, ll x, ll y) {
    if (u > v) return 0;
    if (x > y) return 0;
    if (u > y || v < x) return 0;
    return (min(v, y) - max(u, x) + 1);
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    if (k >= l1 && k <= r1) {
        cout << cut(l1, k - 1, l2, r2) + cut(k + 1, r1, l2, r2);
    }
    else
        cout << cut(l1, r1, l2, r2);
    /**/ return 0;
}
