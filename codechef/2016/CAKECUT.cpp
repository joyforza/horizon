#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, ll>
#define fi first
#define se second
#define esp 1e-9
#define vi vector<pp> // odd / even
#define inf 1000000001
#define mod 1000000007
#define N 100100
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m;
int dp[1555][1555];
int T[1555][1555];
string s[1555];

vi com(int l, int r) {
    if (l == r) {
        vi ret;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            int num = ((T[j][l] - T[i - 1][l]) % 2 == 0);
            ret.pb(mp(1 - num, num));
            cnt += num;
        }
        ret.pb(mp(0, cnt));
       // cout << cnt << "\n";
        return ret;
    }
    else {

        int mid = (l + r) >> 1;
        vi r1 = com(l, mid);
        vi r2 = com(mid + 1, r);
        vi ret;
        int sz = r1.size();
        for (int i = 0; i < sz - 1; i++) {
            ll ev = r1[i].fi * r2[i].fi + r1[i].se * r2[i].se;
            ll odd = r1[i].fi * r2[i].se + r1[i].se * r2[i].fi;
           // cout << "r1: " << r1[i].fi << " " << r1[i].se << "\n";
           // cout << "r2: " << r2[i].fi << " " << r2[i].se << "\n";
            ret.pb(mp(odd, ev));
        }
        ret.pb(mp(0, r1[sz - 1].se + r2[sz - 1].se));
        return ret;
    }
}

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        T[i + 1][j + 1] = T[i][j + 1] + (s[i][j] == '1');
    }
    vi ret = com(1, m);
    ll ans = 0;
    for (int i = 0; i < ret.size(); i++)
        ans += ret[i].se;
    cout << ans;
    return 0;
}
