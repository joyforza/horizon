#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, ll>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 10010
typedef long long ll;
typedef long double ld;
using namespace std;
map <pp, ll> M;
int q;

bool check(ll x, ll y) {
    while (y > 1) {
        ll ny = y / 2;
        if (ny == x) return true;
        y /= 2;
    }
    return false;
}

void addVal(ll x, int w) {
    while (x > 1) {
        ll nx = x / 2;
        M[mp(nx, x)] += w;
        x /= 2;
    }
}

void addVal2(ll x, ll y, int w) {
    addVal(y, w);
    addVal(x, -w);
}


ll getVal(ll x) {
    ll ret = 0;
    while (x > 1) {
        ll nx = x / 2;
        ret += M[mp(nx, x)];
        x /= 2;
    }
    return ret;
}

ll getVal2(ll x, ll y) {
    return (getVal(y) - getVal(x));
}

ll LCA(ll x, ll y) {
    ll c = 1;
    for (int i = 0; i <= 60; i++)
    for (int j = 0; j <= 60; j++){
        if ((x >> i) == (y >> j))
            c = max(c, x >> i);
    }
    return c;
}

int main() {
//    freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> q;
    int t;
    ll u, v, w;

    for (int i = 1; i <= q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> u >> v >> w;
            if (u > v) swap(u, v);
            ll c = LCA(u, v);
            addVal2(c, u, w);
            addVal2(c, v, w);
        }
        else {
            cin >> u >> v;
            if (u > v) swap(u, v);
            ll c = LCA(u, v);
            cout << getVal2(c, v) + getVal2(c, u) << endl;
        }
    }
   /**/ return 0;
}
