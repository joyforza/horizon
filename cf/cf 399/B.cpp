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

ll n;
ll l, r;
vector <ll> a;

ll get(int id, ll m) {
    if (m < (1ll << id)) return 0;

    ll ret = 1;
    ll len = (1ll << id);
    m -= len;

    ret += m / (2 * len);

    return ret;
}

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> n >> l >> r;


    while (n > 0) {
        a.pb(n);
        n /= 2;
    }

    sort(a.begin(), a.end());
    ll tot = 0;
    for (int i = 0; i < a.size(); i++) {

        if (a[i] % 2 == 0) continue;

        tot += get(i, r) - get(i, l - 1);
      //  cout << get(i, r) - get(i, l - 1);
    }

    cout << tot;
    /**/ return 0;
}

