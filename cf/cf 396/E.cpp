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
#define N 100100
#define LOG 20
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

ll dp[N][2][22];
vector <int> a[N];
int n;
bool f[N];
int c[N];
int p[N];

ll chan[22];
ll le[22];


void dfs(int u) {
    f[u] = true;
    ll sum_chan[22];
    ll sum_le[22];

    ll tmp_chan[22];
    ll tmp_le[22];

    memset(sum_chan, 0, sizeof(chan));
    memset(sum_le, 0, sizeof(le));
    memset(tmp_chan, 0, sizeof(tmp_chan));
    memset(tmp_le, 0, sizeof(tmp_le));

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) {
            dfs(v);
            p[v] = u;
            for (int j = 0; j < LOG; j++) {
                sum_chan[j] += dp[v][0][j];
                sum_le[j] += dp[v][1][j];
            }
        }
    }


    for (int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if (p[v] == u) {

            for (int j = 0; j < LOG; j++) {
                tmp_le[j] += dp[v][1][j];
                tmp_chan[j] += dp[v][0][j];

                ll rm_le = sum_le[j] - tmp_le[j];
                ll rm_chan = sum_chan[j] - tmp_chan[j];

                ll tmpChan = 0;
                tmpChan += dp[v][0][j] * rm_chan;
                tmpChan += dp[v][1][j] * rm_le;

                ll tmpLe = 0;
                tmpLe += dp[v][1][j] * rm_chan;
                tmpLe += dp[v][0][j] * rm_le;

                if ((c[u] >> j) & 1) {
                    le[j] += tmpChan;
                    chan[j] += tmpLe;
                }
                else {
                    le[j] += tmpLe;
                    chan[j] += tmpChan;
                }
            }
        }
    }


    for (int i = 0; i < LOG; i++) {
        if ((c[u] >> i) & 1) {
            dp[u][1][i] += sum_chan[i] + 1;
            dp[u][0][i] += sum_le[i];
        }
        else {
            dp[u][0][i] += sum_chan[i] + 1;
            dp[u][1][i] += sum_le[i];
        }
        le[i] += dp[u][1][i];
    }

  /*  cout << "\n\n";

    cout << "at: " << u << "\n";
    cout << "le = " << dp[u][1][0] << "\n";
    cout << "chan = " << dp[u][0][0] << "\n";
    cout << "sum chan = " << sum_chan[0] << "\n";
    cout << "sum le = " << sum_le[0] << "\n"; */
}

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> c[i];

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    p[1] = -1;
    dfs(1);

    ll ret = 0;

    for (int i = 0; i < LOG; i++) {
        ret += le[i] * (1ll << i);
    }

    cout << ret;

    /**/ return 0;
}
