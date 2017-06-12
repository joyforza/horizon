#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, ll>
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
const long long oo = (ll)1e18;
using namespace std;
int n;
int a[111];
bool f[111];

int main() {
    freopen("lazy_loading.txt", "r", stdin);
    freopen("30.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int nt;
    cin >> nt;
    for (int kk = 1; kk <= nt; kk++) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);

        int ret = 0;
        memset(f, false, sizeof(f));
        for (int i = n; i >= 1; i--)
        if (f[i] == false) {
            int tot = a[i];
            for (int j = 1; j < i; j++)
            if (f[j] == false) {
                if (tot < 50) {
                        tot += a[i];
                        f[j] = true;
                }
                else
                    break;
            }
            f[i] = true;
            if (tot >= 50) {
                ret++;
            }
        }
        cout << "Case #" << kk << ": " << ret << "\n";
    }
    /**/ return 0;
}
