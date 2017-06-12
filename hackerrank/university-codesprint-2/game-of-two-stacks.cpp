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
int nt;
int n, m, x;
ll sa[N];
ll sb[N];
int maxA[N];
int maxB[N];
int a[N];
int b[N];

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {

        cin >> n >> m >> x;
        sa[n + 1] = 0;
        sb[m + 1] = 0;
        for (int i = n; i >= 1; i--) {
            cin >> a[i];
            sa[i] = sa[i + 1] + a[i];
        }
        for (int i = m; i >= 1; i--) {
            cin >> b[i];
            sb[i] = sb[i + 1] + b[i];
        }

        maxA[n] = a[n];
        for (int i = n - 1; i >= 1; i--)
            maxA[i] = max(maxA[i + 1], a[i]);
        maxB[m] = b[m];
        for (int i = m - 1; i >= 1; i--)
            maxB[i] = max(maxB[i + 1], b[i]);

        int ret = 0;

        for (int i = n + 1; i >= 1; i--) {
            ll cur = sa[i];
            int l = 1;
            int r = m + 1;
            int pos = -1;

            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sb[mid] + cur <= x) {
                    pos = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }

          //  cout << i << " " << pos << "\n";

            if (pos != -1) {
                ret = max(ret, max(maxA[i], maxB[pos]));
            }

        }

        cout << ret << "\n";
    }

    /**/ return 0;
}

