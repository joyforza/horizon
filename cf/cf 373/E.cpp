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
#define N 100010
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m;
ll T[4 * N];
ll sum[4 * N];
int a[N];
ll dp[1000010];
map<ll, ll> F;

ll f(ll n) {
	if (F.count(n)) return F[n];
	ll k = n / 2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % mod;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % mod;
	}
}


void init(int node, int l, int r) {
    if (l == r) {
        T[node] = f(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    T[node] = (T[node * 2] + T[node * 2 + 1]) % mod;
}

ll getSum(int node, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) {
        return (sum[node] * (r - l + 1) % mod + T[node]) % mod;
    }

    int mid = (l + r) >> 1;
    /// lazy
    if (sum[node] > 0) {
        sum[node * 2] += sum[node];
        sum[node * 2] %= mod;
        sum[node * 2 + 1] += sum[node];
        sum[node * 2 + 1] %= mod;
        sum[node] = 0;
    }

    ll tot = getSum(node * 2, l, mid, u, v);
    tot += getSum(node * 2 + 1, mid + 1, r, u, v);
    tot %= mod;

    /// lazy
    T[node] = T[node * 2] + T[node * 2 + 1] + sum[node * 2] * (mid - l + 1) + sum[node * 2 + 1] * (r - mid);
    T[node] %= mod;
    return tot;
}

void up(int node, int l, int r, int u, int v, ll val) {
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
        sum[node] += val;
        return;
    }
    int mid = (l + r) >> 1;
    /// lazy
    if (sum[node] > 0) {
        sum[node * 2] += sum[node];
        sum[node * 2] %= mod;
        sum[node * 2 + 1] += sum[node];
        sum[node * 2 + 1] %= mod;
        sum[node] = 0;
    }
    up(node * 2, l, mid, u, v, val);
    up(node * 2 + 1, mid + 1, r, u, v, val);
    /// lazy
    T[node] = T[node * 2] + T[node * 2 + 1] + sum[node * 2] * (mid - l + 1) % mod + sum[node * 2 + 1] * (r - mid) % mod;
    T[node] %= mod;
}

void Set(int node, int l, int r, int u, int v, ll val) {
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
        if (l == u && r == u) {
            T[node] = val;
            sum[node] = 0;
        }
        return;
    }
    int mid = (l + r) >> 1;
    /// lazy
    if (sum[node] > 0) {
        sum[node * 2] += sum[node];
        sum[node * 2] %= mod;
        sum[node * 2 + 1] += sum[node];
        sum[node * 2 + 1] %= mod;
        sum[node] = 0;
    }
    Set(node * 2, l, mid, u, v, val);
    Set(node * 2 + 1, mid + 1, r, u, v, val);
    /// lazy
    T[node] = T[node * 2] + T[node * 2 + 1] + sum[node * 2] * (mid - l + 1) % mod + sum[node * 2 + 1] * (r - mid) % mod;
    T[node] %= mod;
}


void Inc(int l, int r, int x) {
    ll fb1 = f(x);
    ll fb2 = f(x + 1);

    if (l < r) {
        up(1, 1, n, l, r - 1, fb1);
        up(1, 1, n, l + 1, r, fb2);
    }
    else {
        //    cout << fb1 << "\n";
        Set(1, 1, n, l, r, fb1);
    }
}

int main() {
    freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    F[0] = F[1] = 1;
    F[2] = 1;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= 1000000; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        F[i] = dp[i];
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    init(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int l, r, x, t;
        cin >> t >> l >> r;
        if (t == 1) {
            cin >> x;
            Inc(l, r, x);
        }
        else {
            cout << getSum(1, 1, n, l, r) << endl;
        }
    }
    /**/ return 0;
}
