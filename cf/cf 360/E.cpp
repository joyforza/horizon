#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 1000001
typedef long long ll;
typedef long double ld;
using namespace std;
int n, k;
bool f[555][555];
bool g[555][555];
int c[555];
bool ret[555];

int main() {
    freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    sort(c + 1, c + n + 1);
    f[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 500; j >= 0; j--) {
            f[i][j] |= f[i - 1][j];
            if (j - c[i] >= 0)
                f[i][j] |= f[i - 1][j - c[i]];
        }
    }
    g[n + 1][0] = true;
    for (int i = n; i >= 1; i--) {
        for (int j = 500; j >= 0; j--) {
            g[i][j] |= g[i + 1][j];
            if (j - c[i] >= 0)
                g[i][j] |= g[i + 1][j - c[i]];
        }
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            if (f[i][j] && g[i + 1][k - j]) {
                ret[j] = true;
                ret[k - j] = true;
            }

    int cnt = 1;
    for (int i = 1; i <= k; i++)
        if (ret[i]) cnt++;
    cout << cnt << "\n";
    cout << 0 << " ";
    for (int i = 1; i <= k; i++)
        if (ret[i])
            cout << i << " ";

   /**/ return 0;
}
