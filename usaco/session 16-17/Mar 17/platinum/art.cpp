#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define N 1010
typedef long long ll;
using namespace std;
vector<pp> pos[N * N];
int n;
int sum[N][N];
int cnt[N * N];

void add(int row, int l, int r) {
    sum[row][l]++;
    sum[row][r + 1]--;
}

void dominate(int r1, int c1, int r2, int c2) {
    for (int i = r1; i <= r2; i++)
        add(i, c1, c2);
}
vector<int> del;
int main() {
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            cnt[x]++;
            pos[x].pb(mp(i, j));
        }
    int ret = 0;
    for (int i = 1; i <= n * n; i++)
    if (pos[i].size() > 0) {
        int r1 = pos[i][0].fi;
        int r2 = pos[i][0].fi;
        int c1 = pos[i][0].se;
        int c2 = pos[i][0].se;
        for (int j = 1; j < pos[i].size(); j++) {
            r1 = min(r1, pos[i][j].fi);
            r2 = max(r2, pos[i][j].fi);
            c1 = min(c1, pos[i][j].se);
            c2 = max(c2, pos[i][j].se);
        }
        dominate(r1, c1, r2, c2);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) sum[i][j] = sum[i][j - 1] + sum[i][j];
    
    for (int i = 1; i <= n * n; i++)
        if (pos[i].size() > 0) {
            bool ok = true;
            for (int j = 0; j < pos[i].size(); j++) {
                int u = pos[i][j].fi;
                int v = pos[i][j].se;
                if (sum[u][v] > 1) {
                    ok = false;
                    break;
                }
            }
            ret += ok;
        }
        else
            ret++;

    cout << ret;
    /**/ return 0;
}
 

 