
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
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
map<int, int> M;

int dx[N];
int dy[N];
vector <int> c;
int dp[N];

vector <int> row[N + N];
vector <int> col[N + N];

int up[N];
int nxt[N];
int pre[N];

int L[N];
int R[N];

bool cmpx(int u, int v) {
    return dx[u] < dx[v];
}
bool cmpy(int u, int v) {
    return dy[u] < dy[v];
}

int main() {
    freopen("lasers.in", "r", stdin); freopen("lasers.out", "w", stdout);
    //freopen("in.in", "r", stdin);

    memset(up, -1, sizeof(up));
    memset(nxt, -1, sizeof(nxt));
    memset(pre, -1, sizeof(pre));

    cin >> n;
    cin >> dx[0] >> dy[0];
    cin >> dx[n + 1] >> dy[n + 1];

    if (dx[0] == dx[n + 1] || dy[0] == dy[n + 1]) {
        cout << 0;
        return 0;
    }

    if (dx[n + 1] < dx[0]) {
        swap(dx[0], dx[n + 1]);
        swap(dy[0], dy[n + 1]);
    }

    for (int i = 1; i <= n; i++) {
        cin >> dx[i] >> dy[i];
    }

    for (int i = 0; i <= n + 1; i++) {
        c.pb(dx[i]);
        c.pb(dy[i]);
    }
    sort(c.begin(), c.end());

    int cnt = 0;
    for (int i = 0; i < c.size(); i++) {
        if (M[c[i]] == 0) {
            M[c[i]] = ++cnt;
        }
    }

    for (int i = 0; i <= n + 1; i++) {
        dx[i] = M[dx[i]];
        dy[i] = M[dy[i]];
        row[dx[i]].pb(i);
        col[dy[i]].pb(i);
    }

    for (int i = 1; i <= cnt; i++) {
        vector <int> tmp;
        /// #1
        for (int j = 0; j < row[i].size(); j++)
            tmp.pb(row[i][j]);

        sort(tmp.begin(), tmp.end(), cmpy);

        //cout << "row = " << i << "\n";
        //for (int j = 0; j < tmp.size(); j++)
        //    cout << row[i][j] << " ";
        //cout << "\n";

        for (int j = 0; j < row[i].size(); j++) {
            row[i][j] = tmp[j];
        }

        tmp.clear();
        /// #2
        for (int j = 0; j < col[i].size(); j++)
            tmp.pb(col[i][j]);

        sort(tmp.begin(), tmp.end(), cmpx);

        for (int j = 0; j < col[i].size(); j++) {
            col[i][j] = tmp[j];
        }


        for (int j = col[i].size() - 2; j >= 0; j--)
            up[col[i][j]] = col[i][j + 1];
        //cout << "col = " << i << "\n";
        //for (int j = 0; j < tmp.size(); j++)
        //    cout << col[i][j] << " ";
        //cout << "\n";

    }

    for (int i = 0; i <= n + 1; i++) dp[i] = inf;
    dp[n + 1] = 0;

    for (int i = dx[n + 1]; i >= dx[0]; i--)
    if (row[i].size() > 0) {

        //cout << "******\n";

        for (int j = 0; j < row[i].size(); j++) {
            int id = row[i][j];
            int p = up[id];
            if (p != -1) {
                dp[id] = min(dp[id], dp[p]);
            }

          //  cout << id << " par = " << p << "\n";
          //  cout << "dp[ " << id << " ] = " << dp[id] << "\n";
        }

        //cout << "\n";

        for (int j = 0; j < row[i].size(); j++) {
            L[j] = inf;
            R[j] = inf;
        }

        int m = row[i].size();


        L[0] = dp[row[i][0]];
        R[m - 1] = dp[row[i][m - 1]];

       // cout << "l0 = " << L[0] << "\n";
       // cout << "rr = " << R[m - 1] << "\n";

        //cout << "first = " << row[i][0] << "\n";
        //cout << "last = " << row[i][m - 1] << "\n";

        for (int j = 1; j < m; j++) {
            L[j] = min(L[j - 1], dp[row[i][j]]);
            //cout << L[j] << "\n";
        }

        for (int j = m - 2; j >= 0; j--) {
            R[j] = min(R[j + 1], dp[row[i][j]]);
        }

        for (int j = 0; j < m; j++) {
            dp[row[i][j]] = min(dp[row[i][j]], min(L[j], R[j]) + 1);
        }
    /**/
    }

    if (dp[0] == inf) cout << -1;
    else
        cout << dp[0];

    /**/ return 0;
}
