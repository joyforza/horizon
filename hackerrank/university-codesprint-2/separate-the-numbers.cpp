#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 50005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int nt;
string s;

int d1[101];
int d2[101];
int n1;
int n2;
int n;

bool check(int l, int r, int u, int v) {
    l--;
    r--;
    u--;
    v--;
    if (s[l] == '0') return false;
    if (s[u] == '0') return false;
    n1 = 0;
    n2 = 0;
    for (int i = r; i >= l; i--) {
        d1[n1++] = (s[i] - '0');
    }
    for (int i = v; i >= u; i--) {
        d2[n2++] = (s[i] - '0');
    }
    /// add one
    int mem = 1;
    for (int i = 0; i < n1; i++) {
        d1[i] = d1[i] + mem;
        if (d1[i] >= 10) {
            d1[i] -= 10;
            mem = 1;
        }
        else
            mem = 0;
    }
    if (mem > 0) d1[n1++] = mem;
    if (n1 != n2) return false;
    for (int i = 0; i < n1; i++)
        if (d1[i] != d2[i]) return false;
    return true;
}


bool dp[55][55][55];

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> s;
        n = s.size();

        memset(dp, false, sizeof(dp));

        dp[n][n][1] = true;

        for (int i = n - 1; i >= 1; i--)
            dp[i][n][1] = (s[i - 1] != '0');

        for (int p = 2; p <= n; p++) {
            for (int i = n - p + 1; i >= 1; i--)
                for (int j = i; j <= n; j++)
                    for (int k = j + 1; k <= n; k++)
                        if (dp[j + 1][k][p - 1]
                            && check(i, j, j + 1, k))
                            dp[i][j][p] = true;
        }

        int len = inf;
        for (int i = 1; i <= n; i++)
                for (int p = 2; p <= n; p++)
                    if (dp[1][i][p]) {
                        len = min(len, i);
                    }

        if (len == inf) cout << "NO\n";
        else {
            cout << "YES ";
            for (int i = 0; i < len; i++)
                cout << s[i];
            cout << "\n";
        }
    }

    /**/ return 0;
}

