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
#define N 100010
#define base 311097
#define MAXN 505
#define MaxE 1000011
#define sqr(x) (x)*(x)
#define RL doubl e
#define EPS 1e-9
#define ll long long
using namespace std;
int n, L;
vector <int> c1;
vector <int> c2;
int a[111];
int b[111];

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> L;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i < n; i++) {
        c1.pb(a[i + 1] - a[i]);
        c2.pb(b[i + 1] - b[i]);
    }
    c1.pb(a[1] + L - a[n]);
    c2.pb(b[1] + L - b[n]);

    bool ret = false;

    for (int i = 1; i <= n; i++) {
        vector <int> c;
        c.pb(c1[c1.size() - 1]);
        c1.pop_back();
        for (int j = 0; j < c1.size(); j++)
            c.pb(c1[j]);

        bool ok = true;
        for (int j = 0; j < c.size(); j++)
            if (c[j] != c2[j]) ok = false;

        if (ok) ret = true;
        c1.clear();
        for (int j = 0; j < c.size(); j++)
            c1.pb(c[j]);
    }

    puts(ret ? "YES" : "NO");
    /**/ return 0;
}
