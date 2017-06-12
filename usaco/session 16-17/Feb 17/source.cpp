#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 50005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

int n;
vector <pp> a;
int T[N];

int get(int x) {
    int ret = 0;
    while (x < N) {
        ret += T[x];
        x = x + (x & (x ^ (x - 1)));
    }
    return ret;
}

void up(int x) {
    while (x > 0) {
        T[x]++;
        x = x - (x & (x ^ (x - 1)));
    }
}

bool giao(pp a, pp b) {
    if (a.se < b.fi) return false;
    if (a.fi > b.se) return false;
    if ((a.fi > b.fi && a.se < b.se) || (b.fi > a.fi && a.se > b.se)) return false;
    return true;
}

int main() {
    //freopen("circlecross.in", "r", stdin);
    //freopen("circlecross.out", "w", stdout);

    freopen("in.in", "r", stdin);

    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        a.pb(mp(u, v));
    }
    /*sort(a.begin(), a.end());
    ll ret = 0;
    for (int i = 0; i < a.size(); i++) {
        ret += get(a[i].fi);
        up(a[i].se);
    }
    cout << ret; */
    ll ret = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++)
            if (giao(a[i], a[j])) ret++;

    cout << ret;
    /**/ return 0;
}

