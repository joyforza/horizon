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

int nt;
int n, m;

bool f[110][110];
map<ll, int> M;
string T[110];
int sender[110];
ll bs[110];
ll h[110];
string mss[110];

vector <int> can[110]; /// candidate
string s;

ll get(int l, int r) {
    return h[r] - h[l - 1] * bs[r - l + 1];
}

bool dp[110][110];

void go(int m, int id) {
    sender[m] = id;
    if (m == 1) return;
    for (int i = 1; i <= n; i++)
        if (dp[m - 1][i]) {
            go(m - 1, i);
            break;
        }
}

int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    bs[0] = 1;
    for (int i = 1; i <= 101; i++)
        bs[i] = bs[i - 1] * base;

    cin >> nt;
    while (nt--) {
        memset(sender, -1, sizeof(sender));

        cin >> n;
        M.clear();
        memset(f, false, sizeof(f));
        for (int i = 1; i <= n; i++) {
            cin >> T[i];
            ll hs = 0;
            for (int j = 0; j < T[i].size(); j++)
                hs = hs * base + T[i][j];
            M[hs] = i;
        }

        cin >> m;
        getline(cin, s);

        for (int i = 1; i <= m; i++) {
            getline(cin, mss[i]);
            //cout << mss[i] << "\n";


            if (mss[i][0] == '?') {

                int sz = mss[i].size();
                h[0] = 0;
                for (int j = 0; j < mss[i].size(); j++)
                    h[j + 1] = h[j] * base + mss[i][j];

               // cout << sz << "\n";


                for (int u = 1; u <= sz; u++)
                for (int v = u; v <= sz; v++) {
                    ll val = get(u, v);
                    //cout << val << "\n";

                    if (M[val] != 0) {
                        f[i][M[val]] = true;
                      //  cout << M[val] << "\n";
                    }
                }
                /**/


            }
            else {
                ll hs = 0;
                for (int j = 0; j < mss[i].size(); j++) {
                    if (mss[i][j] == ':') break;
                    hs = hs * base + mss[i][j];
                }
                sender[i] = M[hs];
            }
        }

        bool ok = false;

        for (int i = 1; i <= m; i++) can[i].clear();

        for (int  i = 1; i <= m; i++) {
            if (sender[i] != -1) {
                can[i].pb(sender[i]);
                continue;
            }

            if (sender[i - 1] != -1)
                f[i][sender[i - 1]] = true;
            if (sender[i + 1] != -1)
                f[i][sender[i + 1]] = true;


            for (int j = 1; j <= n; j++)
                if (f[i][j] == false)
                    can[i].pb(j);
            if ((int)can[i].size() == 0)
                ok = true;

        }


       // for (int i = 1; i <= m; i++) {
       //      cout << i << " => " << can[i].size() << "\n";
       //      cout << can[i][0] << "\n";
        //}

        if (ok) cout << "Impossible\n";
        else {
            memset(dp, false, sizeof(dp));
            for (int i = 0; i < can[1].size(); i++) {
                dp[1][can[1][i]] = true;
            }

            for (int i = 2; i <= m; i++)
            for (int j = 1; j <= n; j++)
            if (dp[i - 1][j]) {
                for (int k = 0; k < can[i].size(); k++)
                    if (j != can[i][k]) {
                        dp[i][can[i][k]] = true;
                    }
            }

            int id = -1;

            for (int i = 1; i <= n; i++)
                if (dp[m][i]) {
                    id = i;
                    break;
                }

            if (id == -1) {
                cout << "Impossible\n";
            }
            else {
                go(m, id);
                for (int i = 1; i <= m; i++) {
                    if (mss[i][0] == '?') {
                        cout << T[sender[i]];
                        for (int j = 1; j < mss[i].size(); j++)
                            cout << mss[i][j];
                        cout << "\n";
                    }
                    else {
                        cout << mss[i] << "\n";
                    }
                }
            }
        }

    }

    /**/ return 0;
}
