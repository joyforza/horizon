#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define N 44
typedef long long ll;
using namespace std;
vector<pp> pos[N * N];
bool f[N * N];
int n;
int sum[N][N];
int a[N][N];
int r1[N * N];
int r2[N * N];
int c1[N * N];
int c2[N * N];
int cnt[N * N];

int get(int r1, int r2, int c1, int c2) {
    return sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];
}

bool check(int x) {
    return get(r1[x], r2[x], c1[x], c2[x]) == x * cnt[x];
}

void updateSum() {
     for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
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
            a[i][j] = x;
            cnt[x]++;
            pos[x].pb(mp(i, j));
        }

    for (int i = 1; i <= n * n; i++)
        if (pos[i].size() == 0) f[i] = true;
    else {
        r1[i] = pos[i][0].fi;
        r2[i] = pos[i][0].fi;
        c1[i] = pos[i][0].se;
        c2[i] = pos[i][0].se;
        for (int j = 1; j < pos.size(); j++) {
            r1[i] = min(r1[i], pos[i][j].fi);
            r2[i] = max(r2[i], pos[i][j].fi);
            c1[i] = min(c1[i], pos[i][j].se);
            c2[i] = max(c2[i], pos[i][j].se);
        }
    }
    updateSum();
    int need = -1;
    while (true) {
        for (int i = 0; i < del.size(); i++) {
            int x = del[i];
            for (int j = 0; j < pos[x].size(); j++) {
                int u = pos[x][j].fi;
                int v = pos[x][j].se;
                a[u][v] = 0;
            }
        }
        need++;
        del.clear();
        updateSum();
        for (int i = 1; i <= n * n; i++)
            if (f[i] == false && check(i)) {
                f[i] = true;
                del.pb(i);
            }
        if (del.size() == 0) break;
    }

    cout << need;
    /**/ return 0;
}
