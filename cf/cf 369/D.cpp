#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 256
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;

int n, x;
map<pp, int> M;

ll pw(ll a, ll b) {
    ll ret = 1;
    while (b > 0) {
        if (b & 1) {
            b--;
            ret = ret * a % mod;
        }
        else {
            b /= 2;
            a = a * a % mod;
        }
    }
    return ret;
}

int get(int u, int v) {
    if (M[mp(u, v)]) return 0;
    if (M[mp(v, u)]) return 1;
    return -1;
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        M[mp(i, x)] = 1;
    }

    int rr = 0;
    for (int i = 2; i <= n; i++) {
        rr += get(i, )
    }
    /**/ return 0;
}
