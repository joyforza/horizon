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
const long long oo = (ll)1e18;
using namespace std;
int n, m;
int L[N];
int R[N];
int a[N];

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    a[0] = -1;
    a[n + 1] = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) L[i] = L[i - 1];
        else
            L[i] = i;
    }

    for (int i = n; i >= 1; i--)
        if (a[i] == a[i + 1]) R[i] = R[i + 1];
    else
        R[i] = i;

    for (int i = 1; i <= m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        int mid = ((l + r) >> 1) + ((r - l + 1) % 2 != 0);

        bool ok = false;
        for (int j = max(l, mid - 10); j <= min(r, mid + 10); j++) {
            int ll = max(l, L[j]);
            int rr = min(r, R[j]);

            if (rr - ll + 1 >= k) {
                cout << a[j] << "\n";
                ok = true;
                break;
            }
        }
        if (!ok) cout << "-1\n";
    }
    /**/ return 0;
}
