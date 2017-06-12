#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
bool f[N];
int n, k, nt;
int L[N], R[N];

int main() {
    freopen("C.in", "r", stdin);
    //freopen("C.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    for (int kk = 1; kk <= nt; kk++) {
        cin >> n >> k;
        memset(f, false, sizeof(f));
        f[0] = true;
        f[n + 1] = true;
        for (int i = 1; i <= k; i++) {
            int curL = 0;
            int curR = n + 1;

            for (int j = 1; j <= n; j++)
            if (f[j] == false) {
                    L[j] = j - curL;
            }
            else
                curL = j;

            for (int j = n; j >= 1; j--)
            if (f[j] == false) {
                R[j] = curR - j;
            }
            else
                curR = j;

            int minval = 0;
            int maxval = 0;

            int pos = -1;
            for (int j = 1; j <= n; j++)
            if (f[j] == false){
                int minj = min(L[j], R[j]);
                int maxj = max(L[j], R[j]);
                if (minj > minval) {
                    pos = j;
                    minval = minj;
                }
                else
                if (minj == minval && maxj > maxval)
                {
                    pos = j;
                    maxval = maxj;
                }
            }

            if (i == k) cout << maxval - 1 << " " << minval - 1 << "\n";
            // mark it
            f[pos] = true;
            cout << "del = " << pos << "\n";
        }
    }
    /**/ return 0;
}
