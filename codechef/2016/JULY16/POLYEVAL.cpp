#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 786433
#define N 100010
typedef long long ll;
typedef long double ld;
using namespace std;
int n, q;
int a[N];

ll pw(ll a, ll b) {
    ll ret = 1;
    while (b > 0) {
        if (b & 1) {
            ret = ret * a % mod;
            b--;
        }
        else {
            a = a * a % mod;
            b /= 2;
        }
    }
    return ret;
}

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x;
        int ret = 0;
        cin >> x;
        for (int j = 0; j <= n; j++)
            ret = (ret + ((ll)a[j] * pw(x, j) % mod)) % mod;
        cout << ret << endl;
    }
   /**/ return 0;
}
