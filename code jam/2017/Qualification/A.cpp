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
int nt;
string s;
int k;
int a[1010];
int n;
int d[1010];

int main() {
    freopen("A.in", "r", stdin);
    //freopen("A.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    for (int kk = 1; kk <= nt; kk++) {
        cin >> s >> k;
        n = s.size();

        for (int i = 0; i < n; i++)
            a[i + 1] = (s[i] == '+');

        int ret = -1;
        for (int j = 1; j <= 1000; j++) {
            memset(d, 0, sizeof(d));
            for (int i = 1; i <= n; i++)
                d[i] = d[i - 1] + a[i];
            if (d[n] == n) {
                ret = k - 1;
                break;
            }
            int l = -1;
            int r = -1;
            int best = 0;

            for (int i = 1; i <= n - k + 1; i++)
                if (k - d[i + k - 1] + d[i - 1] > best) {
                    best = k - d[i + k - 1] + d[i - 1];
                    l = i;
                    r = i + k - 1;
                }

            for (int i = l; i <= r; i++)
                a[i] = 1 - a[i];
        }
        cout << "Case #" << kk << ": ";
        if (ret == -1) cout << "IMPOSSIBLE\n";
        else
            cout << ret << "\n";
    }
    /**/ return 0;
}
