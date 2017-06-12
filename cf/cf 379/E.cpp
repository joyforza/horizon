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
int lab[N];
vector <int> a[N];
int n;
int c[N];
set <int> sW;
set <int> sB;

int get(int u) {
    if (lab[u] < 0) return u;
    lab[u] = get(lab[u]);
    return lab[u];
}

void uni(int r1, int r2) {
    int x = lab[r1] + lab[r2];
    if (lab[r1] < lab[r2]) {
        lab[r1] = x;
        lab[r2] = r1;
    }
    else {
        lab[r2] = x;
        lab[r1] = r2;
    }
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    memset(lab, -1, sizeof(lab));
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (c[u] == c[v]) {
            int r1 = get(u);
            int r2 = get(v);
            if (r1 != r2) {
                uni(r1, r2);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    if (c[i] == 0) {
        sW.insert(get(i));
    }
    else
        sB.insert(get(i));

    cout << min(sW.size(), sB.size());
    /**/ return 0;
}
