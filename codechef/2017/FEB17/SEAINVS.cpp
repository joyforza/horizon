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
#define N 1010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int nt;
int T[N];
int n, m;

int get(int x) {
    int ret = 0;
    while (x > 0) {
        ret += T[x];
        x = x - (x & (x ^ (x - 1)));
    }
    return ret;
}

void up(int x) {
    while (x < N) {
        T[x]++;
        x = x + (x & (x ^ (x - 1)));
    }
}

int a[N];
int b[N];
int nn;

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) {
            memset(T, 0, sizeof(T));
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            for (int j = l1; j <= r1; j++)
                up(a[j]);

            nn = 0;
            for (int j = l2; j <= r2; j++) {
                b[nn++] = get(a[j] - 1);
            }

            sort(b, b + nn);
            int ret = 1;
            for (int j = 0; j < nn; j++)
                ret = (ll)ret * (b[j] - j) % mod;

            cout << ret << "\n";
        }
    }
    /**/ return 0;
}
