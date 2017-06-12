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
#define N 100005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, m;
int c[N];
vector <int> a[N];
vector <int> p[N];
int dem0 = 0;
int dem1 = 0;

bool go(int u) {

    int tmp0 = dem0;
    int tmp1 = dem1;

    for (int i = 0; i < a[u].size(); i++) {
        if (c[a[u][i]] == 0) {
            dem1++;
            dem0--;
        }
        else {
            dem0++;
            dem1--;
        }
    }

    return (tmp1 == n);
}

bool go2(int u, int v) {
    int tmp0 = dem0;
    int tmp1 = dem1;
    for (int i = 0; i < a[u].size(); i++) {
        if (c[a[u][i]] == 0) {
            dem1++;
            dem0--;
        }
        else {
            dem0++;
            dem1--;
        }
        c[a[u][i]] = 1 - c[a[u][i]];
    }
    for (int i = 0; i < a[v].size(); i++) {
        if (c[a[v][i]] == 0) {
            dem1++;
            dem0--;
        }
        else{
            dem0++;
            dem1--;
        }
    }
    /// reset
    for (int i = 0; i < a[u].size(); i++)
        c[a[u][i]] = 1 - c[a[u][i]];

    return (dem1 == n);
}

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        dem0 += (c[i] == 0);
        dem1 += (c[i] == 1);
    }

    for (int i = 1; i <= m; i++) {
        int x, num;
        cin >> num;
        for (int j = 1; j <= num; j++) {
            cin >> x;
            a[i].pb(x);
            p[x].pb(i);
        }
    }

    bool ok = false;
    if (dem1 == n) ok = true;
    else {
        for (int i = 1; i <= n; i++)
        if (c[i] == 0) {
            ok |= go(p[i][0]);
            ok |= go(p[i][1]);
        }
        else {
            ok |= go2(p[i][0], p[i][1]);
            ok |= go2(p[i][1], p[i][0]);
        }
    }

    if (ok) cout << "YES";
    else
        cout << "NO";

    /**/ return 0;
}

