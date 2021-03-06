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
#define N 100005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e14;
using namespace std;
int n, k;
int a[N];
ll s[N];
vector <ll> val;
map<ll, int> M;

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s[i] = s[i - 1] + x;
    }


    val.pb(1);
    ll tmp = 1;
    if (k == -1) val.pb(-1);

    if (abs(k) != 1)
    for (int i = 1; ; i++) {
        tmp = tmp * k;
        if (abs(tmp) > oo) break;
        val.pb(tmp);
    }

    ll ret = 0;
    for (int i = 0; i < val.size(); i++) {
        M.clear();
        M[0] = 1;
        for (int j = 1; j <= n; j++) {
            ret += M[s[j] - val[i]];
            M[s[j]]++;
        }
    }

    cout << ret;
    /**/ return 0;
}

