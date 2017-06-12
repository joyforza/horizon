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
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

int n;
int s[123];
int dp[123];
int tr[123];
vector <pp>ret;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    memset(tr, -1, sizeof(tr));

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s[i] = s[i - 1] + x;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] != 0) {
            dp[i] = true;
            tr[i] = 0;
        }
        if (dp[i])
        for (int j = i + 1; j <= n; j++)
            if (s[j] - s[i] != 0) {
                dp[j] = true;
                tr[j] = i;
            }
    }

    if (!dp[n])
        cout << "NO";
    else {
        int x = n;
        do {
           ret.pb(mp(tr[x] + 1, x));
           x = tr[x];
           if (x == 0) break;
        }
        while (true);
        cout << "YES\n";
        sort(ret.begin(), ret.end());
        cout << ret.size() << "\n";
        for (int i = 0; i < ret.size(); i++)
            cout << ret[i].fi << " " << ret[i].se << "\n";
    }
    /**/ return 0;
}
