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
#define N 100100
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m, q, t, u, v;
int a[1010][1010];
int ret[N];

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    int cnt = 0;
    for (int i = 1; i <= q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> u >> v;
            if (a[u][v] == 0) {
                a[u][v] = 1;
                cnt++;
            }
        }
        else
        if (t == 2) {
            cin >> u >> v;
            if (a[u][v] == 1) {
                a[u][v] = 0;
                cnt--;
            }
        }
        else
        if (t == 3) {

        }
        ret[i] =
    }

    /**/ return 0;
}
