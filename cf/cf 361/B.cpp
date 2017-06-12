#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 200010
typedef long long ll;
typedef long double ld;
using namespace std;
int n, x;
priority_queue<pp> qu;
vector <int> a[N];
int d[N];
bool f[N];

int main() {
//    freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++) {
        a[i].pb(i + 1);
        a[i + 1].pb(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> x;
      //  a[x].pb(i);
        a[i].pb(x);
    }

    while (!qu.empty()) qu.pop();
    memset(f, false, sizeof(f));

    for (int i = 1; i <= n; i++)
        d[i] = inf;

    d[1] = 0;
    qu.push(mp(0, 1));

    for (int p = 1; p <= n; p++) {
        while (!qu.empty() && f[qu.top().se])
            qu.pop();
        int pos = qu.top().se;
        f[pos] = true;
        for (int i = 0; i < a[pos].size(); i++) {
            int v = a[pos][i];
            if (f[v] == false) {
                d[v] = min(d[v], d[pos] + 1);
                qu.push(mp(-d[v], v));
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
   /**/ return 0;
}
