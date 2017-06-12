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
#define N 200200
#define maxK 64
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, m;
int L[N], R[N];
int l[N], r[N];

int main() {
   // freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;

    int min_val = inf;
    int max_val = -inf;

    int ret = 0;

    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
        min_val = min(R[i], min_val);
        max_val = max(L[i], max_val);
    }
    cin >> m;

    int min_val2 = inf;
    int max_val2 = -inf;

    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
        if (min_val < l[i]) ret = max(ret, l[i] - min_val);
        if (max_val > r[i]) ret = max(ret, max_val - r[i]);

        min_val2 = min(r[i], min_val2);
        max_val2 = max(l[i], max_val2);
    }

   // cout << min_val2 << " " << max_val2 << "\n";

    for (int i = 1; i <= n; i++) {
        if (min_val2 < L[i]) ret = max(ret, L[i] - min_val2);
        if (max_val2 > R[i]) ret = max(ret, max_val2 - R[i]);
    }

    cout << ret;
    /**/ return 0;
}
