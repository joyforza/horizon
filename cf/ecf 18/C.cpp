#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
string s;
int n;
int d[N][11];
int a[22];
int m;
int dp[22][5];
int tr[22][5];
bool f[N];
///
int cnt = 0;
int pr[N];
vector<int> rs[N];

bool check(int st, int val) {

    if (val == 0) {
        cnt++;
        pr[cnt] = st - 1;
        return true;
    }

    m = 0;
    for (int i = 1; i <= 9; i++) {
        int x = min(2, d[st][i]);
        for (int j = 1; j <= x; j++)
            a[++m] = i;
    }

    /// dp in here (?)
    memset(tr, 0, sizeof(tr));
    for (int i = 0; i <= m; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = inf;

    dp[0][0] = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 3; j++)
            for (int k = i + 1; k <= m; k++)
        if (dp[k][(j + a[k]) % 3] > dp[i][j] + 1) {
            dp[k][(j + a[k]) % 3] = dp[i][j] + 1;
            tr[k][(j + a[k]) % 3] = i;
        }

    int ret = inf;
    for (int i = 1; i <= m; i++)
        ret = min(ret, dp[i][val]);


    if (ret == inf) return false;


    for (int i = 1; i <= m; i++)
    if (dp[i][val] == ret) {

        cnt++;
        pr[cnt] = st - 1;

        int new_i = i;
        int new_val = val;

        do {
            rs[cnt].pb(a[new_i]);
            int tmp_newval = new_val;

            new_val = ((new_val - a[new_i]) % 3 + 3) % 3;
            new_i = tr[new_i][tmp_newval];
        }
        while(new_i > 0);
        return true;
    }
}


int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> s;
    n = s.size();
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j <= 9; j++)
            d[i][j] = d[i + 1][j] + (j == s[i] - '0');

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += (s[i] - '0');

    if (sum % 3 == 0) {
        cout << s;
        return 0;
    }

    int need = (sum % 3);

    int bg = 0;
    while (true) {
        if (bg == n - 1) {
            if ((s[n - 1] - '0') % 3 == 0) {
                cnt++;
                pr[cnt] = n - 1;
            }
            break;
        }

        check(bg + 1, need);

        // del from bg

        f[bg] = true;
        sum -= (s[bg] - '0');

        for (int i = bg + 1; i < n; i++)
            if (s[i] - '0' != 0) {
                bg = i;
                break;
            }
        else {
            f[i] = true;
            sum -= (s[i] - '0');
        }

        if (f[n - 1]) {
            if ((s[n - 1] - '0') % 3 == 0) {
                cnt++;
                pr[cnt] = n - 1;
            }
            break;
        }
        need = sum % 3;
    }

    if (cnt == 0) {
        for (int i = 0; i < n; i++)
        if (s[i] == '0') {
            cout << 0;
            return 0;
        }
        cout << -1;
    }
    else {
        int ret = inf;
        int pos = -1;

        for (int i = 1; i <= cnt; i++)
        if (pr[i] + rs[i].size() < ret) {
            pos = i;
            ret = pr[i] + rs[i].size();
        }
        memset(f, false, sizeof(f));
        for (int i = 0; i < pr[pos]; i++) f[i] = true;
        for (int i = 0; i < rs[pos].size(); i++) {
            for (int j = n - 1; j >= 0; j--)
            if (f[j] == false && (s[j] - '0') == rs[pos][i]) {
                f[j] = true;
                break;
            }
        }

        for (int i = 0; i < n; i++)
            if (f[i] == false)
                cout << s[i];
    }
    /**/ return 0;
}
