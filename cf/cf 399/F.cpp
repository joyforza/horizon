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
#define N 200005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

int pw(int a, int b) {
    int ret = 1;
    while (b > 0) {
        if (b & 1) {
            ret = (ll)ret * a % mod;
            b--;
        }
        else {
            a = (ll) a * a % mod;
            b /= 2;
        }
    }
    return ret;
}

int f[N];
int inv[N];

int com(int n, int k) {
    if (n < k) return 0;
    return (ll)f[n] * inv[n - k] % mod * inv[k] % mod;
}

int F, g, h;

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = (ll)f[i - 1] * i % mod;
    for (int i = 0; i < N; i++)
        inv[i] = pw(f[i], mod - 2);

    cin >> F >> g >> h;
    int tot = 0;
    int ans = pw(com(F + g, F), mod - 2);

    //cout << ans << "\n";

    if (h == 0 || g == 0) {
        cout << 1;
        return 0;
    }
    else {
        for (int i = 1; i <= min(g / h, F + 1); i++) {
            tot = (tot + (ll)com(F + 1, i) * com(g - i * h - 1, i - 1) % mod) % mod;
            //cout << i << " " << (ll)com(F + 1, i) * com(g - i * (h - 1) - 1, i - 1) % mod << "\n";
        }
    }


    cout << ((ll) tot * ans % mod) << "\n";
    /**/ return 0;
}

