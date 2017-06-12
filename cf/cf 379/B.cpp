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
typedef long long ll;
typedef long double ld;
using namespace std;

int d[8];
ll ret = 0;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> d[2] >> d[3] >> d[5] >> d[6];
    for (int i = 0; i <= min(min(d[5], d[6]), d[2]); i++) {
        int d2 = d[2] - i;
        int rr = min(d2, d[3]);

        ret = max(ret, (ll)i * 256 + (ll)rr * 32);
    }

    cout << ret;
    /**/ return 0;
}
