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
#define N 555
#define base 311097
#define M (1 << 16) + 1
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, m;
string s;
ll h[N + N][N];
ll b[N + N];

ll get(int id, int l, int r) {
    return (h[id][r] - h[id][l - 1] * b[r - l + 1]);
}

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    ios::sync_with_stdio(false);
    b[0] = 1;
    for (int i = 1; i < N + N; i++)
        b[i] = b[i - 1] * base;

    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++)
            h[i][j] = h[i][j - 1] * base + s[j - 1];
    }

    int ret = m;

    for (int i = 1; i <= m; i++)
        for (int j = i; j <= m; j++) {
            set<ll> s;
            for (int k = 1; k <= n; k++)
                s.insert(get(k, i, j));
            bool ok = true;
            for (int k = n + 1; k <= n + n; k++)
                if (s.contains(get(k, i, j))) {
                    ok = false;
                    break;
                }
            if (ok) ret = min(ret, j - i + 1);
        }
    cout << ret;
    /**/ return 0;
}
