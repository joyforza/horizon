#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, ll>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 100010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, k;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int ret = 0;
    cin >> n >> k;
    int need = 240 - k;
    for (int i = 1; i <= n; i++) {
        if (need >= 5 * i) {
            ret++;
            need -= 5 * i;
        }
    }
    cout << ret;
    /**/ return 0;
}
