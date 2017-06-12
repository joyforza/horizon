#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 1000100
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int nt, n;

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

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int nt;
    cin >> nt;
    while (nt--) {
        cin >> n;
        if (n < 3) cout << 0 << "\n";
        else
            cout << (pw(2, n - 1) - 2 + mod) % mod << "\n";
    }

    /**/ return 0;
}
