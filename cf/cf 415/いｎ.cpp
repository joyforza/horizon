#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 300010
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
typedef long long ll;
using namespace std;
int n;
int a[N];

int pw(int a, int b) {
    int ret = 1;
    while (b > 0) {
        if (b & 1) {
            ret = (ll)ret * a % mod;
            b--;
        }
        else {
            a = (ll)a * a % mod;
            b /= 2;
        }
    }
    return ret;
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll ret = 0;
    ll tmp = 0;
    ll len = 0;
    for (int i = 2; i <= n; i++) {
        len += a[i] - a[i - 1];
        ll mu = ((pw(2, i - 1) - 1) % mod + mod) % mod;
        ret = (ret + (len * mu % mod)) % mod;
        ret = (ret - tmp + mod) % mod;
        tmp = (tmp * 2 + len) % mod;
    }
    cout << ret;

    /**/return 0;
}
