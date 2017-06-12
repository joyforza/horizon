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
#define N 1000100
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int nt;
int n, m, L;
pp seg[N];
int a[N + N];
int sum0[N + N];
int sum1[N + N];

bool check(int l, int r) {
    return (sum0[r] - sum0[l - 1] > sum1[r] - sum1[l - 1]);
}

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> n >> m;
        L = n * m;
        for (int i = 1; i <= L; i++) {
            cin >> a[i];
        }
        for (int i = L + 1; i <= L + L; i++)
            a[i] = a[i - L];

        for (int i = 1; i <= L + L; i++) {
            sum0[i] = sum0[i - 1] + (a[i] == 0);
            sum1[i] = sum1[i - 1] + (a[i] == 1);
        }

        int cnt = 0;
        for (int i = 1; i <= L; i += m) {
            seg[cnt].fi = i;
            seg[cnt].se = i + m - 1;
            cnt++;
        }

       // cout << cnt << "\n";

        bool ok = false;
        for (int i = 0; i < m; i++) {
            int zero = 0;
            int one = 0;

            for (int j = 0; j < cnt; j++) {
                zero += check(seg[j].fi + i, seg[j].se + i);
                one += (!check(seg[j].fi + i, seg[j].se + i));
            }

            if (one > zero) {
                ok = true;
                break;
            }
        }
        if (ok) cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    /**/ return 0;
}
