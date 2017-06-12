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
#define N 1000010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n;
ll L, R;
ll a[N];
int nt;

bool IsAn(int a, int b, int c) {
    return (a + b > c && a + c > b && b + c > a);
}

int main() {
    freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> n >> L >> R;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ret = 0;
        for (int i = L; i <= R; i++) {
            bool ok = false;
            for (int u = 1; u < n; u++)
                for (int v = u + 1; v <= n; v++)
                    ok |= IsAn(a[u], a[v], i);

            ret += ok;
        }
        cout << ret << "\n";
    }
    /**/ return 0;
}
