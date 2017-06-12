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
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;

int n, m, s, t;
vector <int> a; // candidate
int c[N];
int v[N];
vector <int> pos;

bool check(int x) {
    int need = 2 * s;
    for (int i = 1; i < pos.size(); i++) {
        int del = pos[i] - pos[i - 1];
        if (del > x) return false;
        int remain = min(del, x - del);
        need -= remain;
    }
    return (need <= t);
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> v[i];
        a.pb(v[i]);
    }
    sort(a.begin(), a.end());
    pos.pb(0);
    pos.pb(s);
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        pos.pb(x);
    }
    sort(pos.begin(), pos.end());
    int l = 0, r = a.size() - 1;
    int rs = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(a[mid])) {
            rs = a[mid];
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    if (rs == -1) cout << -1;
    else {
        int cost = inf;
        for (int i = 1; i <= n; i++)
        if (v[i] >= rs) {
            cost = min(cost, c[i]);
        }
        cout << cost << "\n";
    }
    /**/ return 0;
}
