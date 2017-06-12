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
#define N 505
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

struct matrix {
    bitset<N> x[N];
};

int n, m;
ll dp[2][N][maxK + 1];
matrix can[2][maxK + 1];

matrix mult(matrix a, matrix b) {
    matrix ret, tmp;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tmp.x[i][j] = b.x[j][i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ret.x[i][j] = (a.x[i] & tmp.x[j]).any();

    return ret;
}

long long comdp(int st, int u, int len) {
    if (dp[st][u][len]) return dp[st][u][len];
    if (len == 0) {
        for (int v = 0; v < n; v++)
            if (can[st][0].x[u][v]) {
                dp[st][u][0] = 1;
                break;
            }
        return dp[st][u][0];
    }
    long long &ret = dp[st][u][len];

    for (int v = 0; v < n; v++)
        if (can[st][maxK - 1].x[u][v]) {
            ret = max(ret, (1 << (len - 1)) + comdp(1 - st, v, maxK - 1));
        }
    return ret;
}

int main() {
    freopen("in.in", "r", stdin);
    freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, tp;
        cin >> u >> v >> tp;
        u--;
        v--;
        can[tp][0].x[u][v] = 1;
    }

   // mult(can[0][2], can[1][2]);

    for (int i = 1; i < maxK; i++) {
        cout << i << "\n";
        can[0][i] = mult(can[0][i - 1], can[1][i - 1]);
        can[1][i] = mult(can[1][i - 1], can[0][i - 1]);
    }
/*
    for (int i = 0; i < n; i++)
    if (can[0][maxK - 1].x[i].any()) {
        cout << -1;
        return 0;
    }
/*
    long long ret = 0;
    for (int i = 0; i < n; i++)
            ret = max(ret, comdp(0, i, maxK - 1));

    if (ret > oo) cout << -1;
    else
        cout << ret;
    /**/ return 0;
}
