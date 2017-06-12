#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000009
#define N 17
#define base 311097
#define SEG 555
#define MAXF 20002
typedef long long ll;
typedef long double ld;
using namespace std;
int n, p, x;
ll T[555][555];
ll dp[501][501][501];

ll get(int u, int v, int x, int y) {
    return T[x][y] - T[x][v - 1] - T[u - 1][y] + T[u - 1][v - 1];
}

ll cal(int l, int r) {

}

vector <int> check(ll val) {
    int st = 1;
    vector <int> res;
    for (int i = 1; i <= p; i++) {
        int fn = -1;
        for (int j = st; j < n; j++)
        if (cal(st, j) <= val) {
            fn = j;
        }
        if (fn == -1) {
                res.clear();
                return res;
        }
        res.pb(fn);
    }
}

int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
        cin >> x;
        T[i][j] = T[i - 1][j] + T[i][j - 1] - T[i - 1][j - 1] + x;
    }

    vector <int> c;

    ll l = 0;
    ll r = 1000000000000000;
    while (l <= r) {
        ll mid = (l + r) >> 1;

    }

    /**/ return 0;
}
