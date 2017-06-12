#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 100010
#define inf 1000000001
#define mod 1000000007
typedef long long ll;
using namespace std;
int n, k;
ll a[N];
bool f[N];
int gt[N];
int inv[N];

int mu(int a, int b) {
    int ret = 1;
    while (b > 0) {
        if (b & 1) {
            b--;
            ret = (ll) ret * a % mod;
        }
        else {
            b /= 2;
            a = (ll)a * a % mod;
        }
    }
    return ret;
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll ret = 0;
    for (int j = 60; j >= 0; j--) {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (f[i] == false && ((a[i] >> j) & 1)) cnt++;
        if (cnt >= k) {
            ret |= (1ll << j);
            for (int i = 1; i <= n; i++)
                if (f[i] == false && (((a[i] >> j) & 1) == 0))
                    f[i] = true;
        }
    }
    cout << ret << "\n";
    int m = 0;
    for (int i = 1; i <= n; i++)
        if (f[i] == false) m++;

    gt[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < N; i++) {
        gt[i] = (ll)gt[i - 1] * i % mod;
        inv[i] = mu(gt[i], mod - 2);
    }

    if (m < k) cout << 0;
    else
        cout << ((ll)gt[m] * inv[m - k] % mod * inv[k] % mod);
    /**/return 0;
}
