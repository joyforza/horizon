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
#define N 200010
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int a[N];
int b[N];
int L[N], R[N];
vector <int> c;
vector <pp> mask[2 * N];
vector <pp> s[2 * N];
pp tmp[N];
vector <pp> dm;
map<int, int> M;

int main() {
    freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c.pb(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c.pb(b[i]);
    }

    sort(c.begin(), c.end());
    int cnt = 0;
    for (int i = 0; i < c.size(); i++) {
        if (M[c[i]] == 0) {
            cnt++;
            M[c[i]] = cnt;
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i] = M[a[i]];
        b[i] = M[b[i]];
    }

    a[0] = inf;
    a[n + 1] = inf;
    L[1] = 1;
    for (int i = 2; i <= n; i++) {
        int j = i - 1;
        while (a[i] > a[j]) j = L[j] - 1;
        L[i] = j + 1;
    }
    R[n] = n;
    for (int i = n - 1; i >= 1; i--) {
        int j = i + 1;
        while (a[i] > a[j]) j = R[j] + 1;
        R[i] = j - 1;
    }


    for (int i = 1;  i <= n; i++) {
        s[a[i]].pb(mp(L[i], R[i]));
    }

    for (int i = 1; i <= cnt; i++)
    if (s[i].size() > 0) {
        int m = 1;
        tmp[m] = s[i][0];
        for (int j = 1; j < s[i].size(); j++)
            if (tmp[m].se >= s[i][j].fi)
                tmp[m].se = s[i][j].se;
        else {
            m++;
            tmp[m] = s[i][j];
        }

        for (int j = 1; j <= m; j++) {
            mask[i].pb(mp(tmp[j].fi, 1));
            mask[i].pb(mp(tmp[j].se, 2));
        }
        s[i].clear();
    }

    b[0] = -inf;
    b[n + 1] = -inf;

    L[1] = 1;
    for (int i = 2; i <= n; i++) {
        int j = i - 1;
        while (b[i] < b[j]) j = L[j] - 1;
        L[i] = j + 1;
    }
    R[n] = n;
    for (int i = n - 1; i >= 1; i--) {
        int j = i + 1;
        while (b[i] < b[j]) j = R[j] + 1;
        R[i] = j - 1;
    }

    for (int i = 1;  i <= n; i++) {
        s[b[i]].pb(mp(L[i], R[i]));
    }

    for (int i = 1; i <= cnt; i++)
    if (s[i].size() > 0) {
        int m = 1;
        tmp[m] = s[i][0];
        for (int j = 1; j < s[i].size(); j++)
            if (tmp[m].se >= s[i][j].fi)
                tmp[m].se = s[i][j].se;
        else {
            m++;
            tmp[m] = s[i][j];
        }

        for (int j = 1; j <= m; j++) {
            mask[i].pb(mp(tmp[j].fi, 1));
            mask[i].pb(mp(tmp[j].se, 2));
        }
    }

    ll ret = 0;

    for (int i = 1; i <= cnt; i++)
    if (mask[i].size() > 0) {
        cout << i << ":\n";

        dm.clear();
        for (int j = 0; j < mask[i].size(); j++)
            dm.pb(mask[i][j]);


        int cur = 0;
        int head = 0;
        sort(dm.begin(), dm.end());

        for (int j = 0; j < dm.size(); j++)
            cout << dm[j].fi << " " << (dm[j].se == 1 ? "Open" : "Close") << "\n";

        for (int j = 0; j < dm.size(); j++) {
            if (dm[j].se == 1) {
                cur++;
                if (cur == 2) head = dm[j].fi;
            }
            else
            if (dm[j].se == 2) {
                    cur--;
                    if (cur == 1)  {
                    int rr = (dm[j].fi - head + 1);
                    ret += ((ll)rr * (rr + 1)) / 2;
                    cout << "new added: " << rr * (rr + 1) / 2 << "\n";
                }
            }
        }
    }

    cout << ret;
   /**/ return 0;
}
