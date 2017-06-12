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
#define N 1010
#define base 311097
#define M 10000001
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int dx[N];
int dy[N];
vector <int> a[N];
bool f[N];

int sq(int x) {
    return x * x;
}

void dfs(int u) {
    f[u] = true;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) {
            dfs(v);
        }
    }
}

bool check(int x) {
    for (int i = 1; i <= n; i++) a[i].clear();
    memset(f, false, sizeof(f));
    for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) {
        if (sq(dx[i] - dx[j]) + sq(dy[i] - dy[j]) <= x) {
            a[i].pb(j);
            a[j].pb(i);
        }
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (f[i] == false) return false;
    return true;
}

int main() {
    freopen("moocast.in", "r", stdin); freopen("moocast.out", "w", stdout);
    //freopen("in.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> dx[i] >> dy[i];

    int l = 0;
    int r = 1000000000;
    int ret = 1000000000;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ret = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ret;
    /**/ return 0;
}
